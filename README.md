# Welcome to GPP_COMPILER

Language that provides an abstraction to a PART of GTK difficulty .

To get projet on your computer, clone it using the following command :

```
git clone https://github.com/RedRosh/GPP_COMPILER
```

Install gtk3 on your ubuntu machine: 

```
sudo apt-get install libgtk-3-dev
```

To test the compiler, on your terminal, do the following :

1- _change directory_ :

```
cd GPP_COMPILER
```

2- _Compile the compiler_ :

```
make all
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


```
WIDGET WIDGET_NAME : {
    PROPERTY : VALUE [,]
    [PROPERTY : VALUE ]
};

Begin
Start INTERFACE_NAME INTERFACE_PROPERTY;
Put WIDGET_NAME X Y ;
[Put WIDGET_NAME X Y ;]
Show INTERFACE_NAME;
End
```
* __WIDGET__ : one of the 4 previous types, written in PascalCase.
* __WIDGET_NAME__ : your variable name which can contain __numbers and letters only__, and starting with a __letter__.
* __PROPERTY__ : can be one of the following :

    * For any widget :

        * __Height__ : is the height of the widget, and has a __VALUE__ of a __positive Integer__.

        * __Width__ : is the width of the widget, and has a __VALUE__ of a __positive Integer__.
        
        * __Opacity__ : is the opacity of the widget, and has a __VALUE__ of a __positive Integer between 0 and 100__.

            The following properties are for styling purposes :
        ### __FONT PROPERTIES__

        * __FontSize__ : is the size of the font, and has an **Integer** value.
        * __FontStyle__ : is the style of the font, and can take one of the following __VALUES__ : "normal", "oblique", "italic".
        * __FontWeight__ : is the weight of the font, and can take one of the following **VALUES** : "normal", "bold", "bolder", "lighter".

        ### __COLOR PROPERTIES__
        

        * __BackgroundColor__ : A string that is the bachgroundcolor in hexadecimal. Ex : "#123456"
        * __Color__ : A string that is the widget color in hexadecimal. Ex : "#123456"

        ### __FONT PROPERTIES__


        * __LetterSpacing__ : The lenght between letters, take an **Integer** value.
        * __TextDecorationLine__ : Can be one of these **VALUES** : "none", "underline", "line-through".
        * __TextDecorationStyle__ : Can be one of these **VALUES** : "solid", "double", "wavy".

        ### __BOX PROPERTIES__


        * __MarginTop__
        * __MarginLeft__
        * __MarginRight__
        * __MarginBottom__
        
            The margin lenght in each side, takes an **Integer** value

        * __PaddingTop__
        * __PaddingLeft__
        * __PaddingRight__
        * __PaddingBottom__

            The margin lenght in each side, takes an **Integer** value

        * __MinWidth__ : The minimum value of the widget's width, takes an **Integer** value.
        * __MinHeight__ : The minimum value of the widget's height, takes an **Integer** value.

        ### __BORDER PROPERTIES__

        
        * __BorderWidth__ : The width of the border, takes an **Integer** value
        * __BorderRadius__ : The width of the border, takes an **Integer** value.
        * __BorderStyle__ : Can be one of these **VALUES** : "none", "solid", "dotted", "dashed".
        * __BorderColor__ : A string that is the widget's border color in hexadecimal. Ex : "#123456".

        For more informations about styling props, [Click here](https://docs.gtk.org/gtk3/css-properties.html)

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

#### _PS1 : If you want to add more properties to a widget, you need to end your line with a comma \( , \)_. 

* __INTERFACE_NAME__ : is the name of your predefined **Interface** variable.
    
    * __INERFACE_PROPERTY__ : is the property in which you want your interface to show up. It can be:
        
        * __"CENTER"__ : if you want your interface to appear in the center of your string.
        
        * __"MOUSE__ : if you want your interface to appear in the current position of your mouse.

        _Note that "CENTER" and "MOUSE" are strings and not keywoards_.

* __X__ : The x position of your widget, it has the value of an **Integer**.
* __Y__ : The y position of your widget, it has the value of an **Integer**.

#### _PS2 : all the keywords are written in PascalCase_.

## TO DO :

- [x] Lexer
- [x] Parser
- [x] Testing the code
- [x] Semantic
- [x] Styles
- [ ] Testing the code :

![Test Image](https://i.ibb.co/4Yy35NP/Screenshot-from-2022-01-26-19-48-09.png)
