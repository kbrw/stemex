defmodule StemexTest do
  use ExUnit.Case

  for diff_file<-Path.wildcard("test/diffs/*.txt") do
    stemmer =  diff_file |> Path.basename |> Path.rootname

    test "test #{stemmer} snowball algorithm" do
      for [_,source,target]<-Regex.scan(~r/^([^\s]+)\s+([^\s]+)/m,File.read!(unquote(diff_file))) do 
        assert target == Stemex.unquote(:"#{stemmer}")(source)
      end
    end

  end
end
