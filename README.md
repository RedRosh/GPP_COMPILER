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


# How to write a gpp code :

The syntaxe of a gpp file is pretty simple , it contains 4 types of widgets that are :


* **Interface** : The root component, a window that contains the other ones.

* **Button** : A simple button that you can click.

* **InputField** : A field where you can write your input.
* **Label** : A place holder in which you can write titles, names ...


The correct way to write the code is such as the following :


```gtk plus plus
WIDGET NAME : {
    PROPERTY : VALUE [,]
    [PROPERTY : VALUE ]
}; 
```
* __WIDGET__ : one of the 4 previous types, written in PascalCase.
* __NAME__ : your variable name which can contain __numbers and letters only__, and starting with a __letter__.
* __PROPERTY__ : can be one of the following :

    * For any widget :

        * __Height__ : is the height of the widget, and has a __VALUE__ of a __positive Integer__.

        * __Width__ : is the width of the widget, and has a __VALUE__ of a __positive Integer__.
        
        * __Opacity__ : : is the opacity of the widget, and has a __VALUE__ of a __positive Integer between 0 and 100__.

    * For the __Interface__ widget :

        * __Title__ : is the title of the interface, and has a __VALUE__ of a 
        **String**.

    * For the __Button__ widget :

        * __Text__ : is the text inside the button, and has a __VALUE__ of a **String**.

    * For the __InputField__ widget :

        * __Text__ : is the text inside the input field, and has a __VALUE__ of a **String**.

        * __PlaceHolder__ : is the default appearing text in the input field, and has a __VALUE__ of a **String**.
        * __MaxLengthç__ : is the maximum length of the input, and has a __VALUE__ of a **positive Integer**.

    * For the __Label__ widget :
        * __Text__ : is the text in the label, and has a __VALUE__ of a **String**.

        * __Angle__ : is the angle in which the text is written, and has a __VALUE__ of an **Integer between 0 and 359**.
        * __Xalign__ : is the horizontal text alignment, and has a __VALUE__ of a **positive Integer**.
        * __Yalign__ : is the vertical text alignment, and has a __VALUE__ of a **positive Integer**.

#### _PS1 : If you want to add more properties, you need to end your line with a comma \( , \)_. 

#### _PS2 : all the keywords are written in PascalCase_.

## TO DO :

- [x] Lexer
- [x] Parser
- [x] Testing the code
- [ ] Semantic(ghda nchaellah ysali lprojet(inchallah)²)
- [ ] Styles

