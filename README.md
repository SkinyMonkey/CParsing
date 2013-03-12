CParsing
========

A simple recursive descent parser framework in C

At the beginning it was suppose to be used in parser generation,
so this code was build so you can use it like some kind of BNF and stay simple for the generation.

No malloc are used except for the capture of the result of an expression.

An example is in tests/test.c.

TODO
====

- Correct names
- Cut the code to be less "generation oriented"
- Make it a lib
- Remove malloc into the capture
- Add the wrappers like in Pyrser
