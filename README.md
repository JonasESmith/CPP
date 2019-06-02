# C++
Learning CPP and wanted to store all my application I have created!

* Getting started - for a noob
    * Install mingw graphical installer - http://www.mingw.org/wiki/Getting_Started
    * Create a new variable path by - https://www.youtube.com/watch?v=40MWdFAGTzg
        * search for System
        * Advanced system settings
        * Environmental Variables
        * System variables
            * Double click path
        * New path to the wingw/bin installation directory. 
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
    * Classes are user-defined types.
    * Objects are instances of classes.
    * Classes have the form of
        * ` class class_Name { .... }; `
    * Components of a class are called class members, you can get access to these the same way you would using .length() on a string
        * by using objectName.class_member
        * There are two types of class members
            * Attributes, also known as member data, consisting of information about an instance of a class.
            * Methods, Also known as member functions, are functions that you can use with an instance of the class. 
    * Creating a new Object from a class is called an instantiation.
    * C++ classes have public and private domains for encapsulation just like C# classes
    * C++ classes also have access to Constructors!

    * oh neat we can destroy OBJECTS! >:) with ...
        * ` City::~City() { ... } `

* References and Pointers
    * References   
        * ` int &sonny = songqiao` will reference the same variables, any changes made to sonny or songqiao will also be made to the other. 
    * Pointers  
        * We can get the address of a variable with ` std::cout << &variable_name << " \n";`
        * note from CodeAcadamy ``` While references are a newer mechanism that originated in C++, pointers are an older mechnaism that was inherited from C. We recommend avoiding pointers as much as possible;  ```
        * just like & before a variable stood for a reference with pointers we use ` *int, *double, etc..`
        * the `*` can be called the dereference operator.
        * When `*` is used in a declaration, it is creating a pointers.
        * When `*` is not used in a declaration, it is a dereference operator. 
        * We should try and avaoid settings `int* pointer;` as this points somewhere in memory and that is dangerouse. 
        * Instead we should use `int* ptr = nullprt`

* SFML
    * For setting up an environment with winGW and SFML - https://www.youtube.com/watch?v=UM93glM0Fhs
    * 
    
