#include <iostream>
#include <string>

 

using namespace std;

// -------------- Design your Zebra class here ---------------
// -----------------------------------------------------------
// name the Class Zebra()
// name the function that count function getCount()
/// name the function that print name getName()
// private: create variable name as string and count as int make it static and set it externally before main()
/// Create constructor that take directly the name
// Once object is created inside constructor print the following
// Hello I'm just born! my name is:  "object name" and new line

// Create function that called getName that return name without printing

// Make a destructor, it should reduce count and print the following
//     Ugh! I'm dying and the current count

// Create a function that called getCount that return the current count

//}; end of class

// -------------- Design your ZebraKid class here ---------------
// -----------------------------------------------------------
// Create a another class ZebraKid that inherit Zebra functions (getName)
// ZebraKid only have constructor
// initial constructor based on Zebra constructor
// don't write any other function, you should be able to inherit Zebra function
//}; end of class

// Set Zebra count equal zero

// -------------- Design void function f() ---------------
// -----------------------------------------------------------
// Make function f() that do the following when used:
//   - Print out the current count
//   - add two Zebra object when called
//    - Zebra with name Joker
//      Zebra with name Alice
//   - Print the new count
// when the function is called it will construct object and when it scopes finish
//... it will destruct and print messages of object is dying in same time

// example of the main function
int main() {
    cout << "########" << endl;
    cout << "Main Problem" << endl;
    cout << "########" << endl;
    // You should be able to run main() with your classes
    // No need to edit this part unless for debugging
    // print the initial count number
    cout << Zebra::getCount() << '\n'; // zero!
    // Creat object a with name Morgana
    Zebra a("Morgana");
    // Print the current count number of Zerba object
    cout << Zebra::getCount() << '\n';
    // Use the function f() above
    f();
    cout << "####" << endl;
    // Use the function f() above again
    f();
    cout << "####" << endl;
    // print out the current number of zebra
    cout << Zebra::getCount() << '\n';
    // Get the name of the zebra object a
    cout << a.Zebra::getName() << '\n';
    cout << "####" << endl;

    // create  ZebraKid object
    ZebraKid e("James");
    // Use the getName() form Zebra class
    cout << e.getName() << '\n';
    cout << Zebra::getCount() << '\n';


    cout << "====[ end ]====" << endl;
    cout << "               " << endl;

    cout << " #### This is after the program is completely done #####" << endl;
    cout << " ### The last remaining object should get destructed ###" << endl;

    return 0;

}