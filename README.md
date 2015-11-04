# Stemex [![Build Status](https://api.travis-ci.org/awetzel/stemex.svg)](https://travis-ci.org/awetzel/stemex)

Stemex is a NIF wrapper above the snowball language (http://snowball.tartarus.org/index.php).

Add any snowball algorithm in the `algorithms` directory, for instance
`algorithms/ALGONAME.sbl` containing an external procedure named `stem` and
Stemex compiler will:

- Compile the nif shared library `priv/Elixir.Stemex_nif.so`
- Add dynamically the Elixir function `Stemex.ALGONAME/1` which takes an UTF8
  binary string and returned the result of the `ALGONAME.sbl` algorithm

It is MEANT to be used in your project with custom stemming snowball
algorithms, with a clone of this project. But by default porter stem
implementations are included and published in the HEX package.

## Stem algorithms in the Hex Published package

They are the ones present in the snowball distribution, available stemmers are :

```elixir
Stemex.danish/1
Stemex.dutch/1
Stemex.english/1
Stemex.finnish/1
Stemex.french/1
Stemex.german/1
Stemex.german2/1
Stemex.hungarian/1
Stemex.italian/1
Stemex.kraaij_pohlmann/1
Stemex.lovins/1
Stemex.norwegian/1
Stemex.portuguese/1
Stemex.romanian/1
Stemex.russian/1
Stemex.spanish/1
Stemex.swedish/1
Stemex.turkish/1
```

## Compilers

2 compilers are included in the mix.exs : 

- `:stemex_snowball` compiles `c_src/gen/ALGONAME.(c|h)` from your
  `algorithms/ALGONAME.sbl`
  - it needs to have the `snowball` executable in your PATH, explain you how to get it otherwise
  - so this compiler is only used on `:dev` Mix env in order to help you developing your snowball algorithms
- `:stemex_nif` compiles `priv/Elixir.Stemex_nif.so` used as the nif library.

## Tests

All files in `test/diffs/ALGONAME.txt` must contains one pair of word per line, 
every test case will be then tested : `Stemex.ALGONAME(first_elem) == second_elem`. 

The format is compatible with snowball test files and contains by default all
the tests from the snowball website but you can easily add tests for your own
snowball algorithm.
