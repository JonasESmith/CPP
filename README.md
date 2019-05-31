# CPP
Learning CPP and wanted to store all my application I have created!

* Getting started - for a noob
    * Install mingw graphical installer - http://www.mingw.org/wiki/Getting_Started
    * Create a new variable path by - https://www.youtube.com/watch?v=40MWdFAGTzg
        * search for System
        * Advanced system settings
        * Environmental Variables
        * System variables
            * Double click path
        * New path to the wingw installation directory. 
    * We can now use bellow to build the .cpp application 
        * g++ ./{name}.cpp -o [name]
        * ./[name]
* For review, #include is a preprocessor directive that tells the compiler to include whatever library that follows.
    * example `#include <vector>`

* C++ functions can be split up modularly.
    * The declaration will be in a header file or .hpp or .h file.
        * header files must be included in main().
        * `#include "functions.hpp"`
    * The definitions will be in another .cpp file.
    * Compiling multiple .cpp files will look like this
        * g++ main.cpp {name0}.cpp {name1}.cpp
        * then just run ./a 
* A function can be defined as inline aboce the declaration to have the possibilty of increasing execution time.
* Declarations
    * default declarations can be set if values are genearlly the same.
    * you can of course overload functions so that they can have multiple input values
        * `ie. int    get_values(int num1, int num2) {...}`
        * `    double get_values(double num1, double num2) {...} `
    * as well a function template enables a function to behave the same with different types of parameters.
        * `ie.  template <typename T> `
        * `     T get_values(T num1, T num2) {...}`

* Classes notes
    * Classes have the form of
        * ` class class_Name { .... }; `
    