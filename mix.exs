defmodule Mix.Tasks.Compile.StemexSnowball do
  @shortdoc "Compiles stemmers c source, meant to be used only for algorithms development"
  def run(_) do
    File.touch!("lib/stemex.ex") # force recompilation of stemex
    File.write!("c_src/gen/wrapper.c",EEx.eval_file("c_src/wrapper.c.eex", stemmers: Mix.Project.get.stemmers))
    if System.find_executable("snowball") do
      for stemmer<-Mix.Project.get.stemmers do
        opts = ["algorithms/#{stemmer}.sbl","-o","c_src/gen/#{stemmer}","-utf8","-eprefix","#{stemmer}_","-vprefix","#{stemmer}_var","-r","../runtime"]
        System.cmd "snowball", opts, into: IO.stream(:stdio, :line)
      end
    else
      Mix.Shell.IO.error("""
        Missing snowball compiler on your path
        install it for instance doing : 
          wget http://snowball.tartarus.org/dist/snowball_code.tgz
          tar xvzf snowball_code.tgz
          cd snowball_code
          make
          cp snowball ~/bin/snowball
      """)
    end
  end
end

defmodule Mix.Tasks.Compile.StemexNif do
  @shortdoc "Compiles stemmer nif .so library"
  def run(_) do
    System.cmd "cc", cc_args++["-o","priv/Elixir.Stemex_nif.so"]++Path.wildcard("c_src/*/*.c"), into: IO.stream(:stdio, :line)
  end

  defp cc_args do
    [i_erts]=Path.wildcard("#{:code.root_dir}/erts*/include")
    i_ei=:code.lib_dir(:erl_interface,:include)
    l_ei=:code.lib_dir(:erl_interface,:lib)
    args = ["-L#{l_ei}", "-lerl_interface","-lei","-I#{i_ei}","-I#{i_erts}","-Wall","-shared","-fPIC"] #,"-v"]
    args ++ if {:unix,:darwin}==:os.type, do: ["-undefined","dynamic_lookup","-dynamiclib"], else: []
  end 
end

defmodule Stemex.Mixfile do
  use Mix.Project

  def stemmers do
    Enum.map(File.ls!("algorithms"),&Path.rootname/1)
  end

  def project do
    [app: :stemex,
     version: "0.1.0",
     elixir: "~> 1.0",
     compilers: compilers(Mix.env),
     package: [
       maintainers: ["Arnaud Wetzel"],
       licenses: ["MIT"],
       links: %{
         "GitHub" => "https://github.com/awetzel/stemex"
       }
     ],
     description: """
       Stemex is a NIF wrapper above snowball containing stemmers for : 
       danish, dutch, english, finnish, french, german, hungarian, italian, kraaij_pohlmann, 
       lovins, norwegian, portuguese, romanian, russian, spanish, swedish, turkish.
     """,
     deps: []]
  end

  def application do
    [applications: []]
  end

  defp compilers(:dev), do: [:stemex_snowball] ++ compilers(:all) 
  defp compilers(_), do: [:stemex_nif] ++ Mix.compilers
end
