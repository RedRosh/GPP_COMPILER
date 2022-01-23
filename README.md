# Welcome to GPP_COMPILER

Language that provides an abstraction to a PART of GTK difficulty .

To get projet on your computer, clone it using the following command :

```
git clone https://github.com/RedRosh/GPP_COMPILER
```

To test the compiler,on your terminal, do the following :

1- _change directory_ :

```
cd GPP_COMPILER
```

2- _Compile the compiler_ :

```
gcc -g *.c ./utils/*.c -o gpp
```

3-_finally, run your test file_:

```
./gpp test.gpp
```

## TO DO :

- [x] Lexer
- [x] Parser
- [ ] Testing the code
- [ ] Semantic
