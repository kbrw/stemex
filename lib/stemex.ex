defmodule Stemex do
  @on_load :init
  def init, do: :erlang.load_nif('#{:code.priv_dir(:stemex)}/Elixir.Stemex_nif',0)

  for stemmer<-Mix.Project.get.stemmers do
    def unquote(:"#{stemmer}")(_str), do: exit(:nif_library_not_loaded)
  end
end
