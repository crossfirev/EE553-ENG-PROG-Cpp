/*
 * Author: Matthew Lepis
 * Date:   11/06/2025
 *
 * Description:
 *   Implements a simple C++ program demonstrating object-oriented
 *   design principles through class construction, inheritance, and
 *   static data member management.
 *
 *   The program defines a base class `Zebra` that tracks the number
 *   of active Zebra objects via a static counter, and a derived class
 *   `ZebraKid` that inherits all base functionality.
 *
 *   Features:
 *     • Demonstrates default and parameterized constructors.
 *     • Shows constructor and destructor execution order.
 *     • Implements a static `count` variable to track total living Zebras.
 *     • Provides accessor (`getName`, `getCount`) and mutator (`setName`) methods.
 *     • Defines a helper function `f()` that creates local Zebras to illustrate
 *       object lifetime and scope-based destruction.
 *     • Demonstrates class inheritance through `ZebraKid`, which calls
 *       its parent constructor via initializer lists.
 *
 *   Classes:
 *     • Zebra
 *         – Attributes: private `name`, static `count`.
 *         – Methods:
 *             ▪ Default constructor assigns auto-generated name.
 *             ▪ Parameterized constructor accepts custom name.
 *             ▪ Destructor decrements the shared object counter.
 *             ▪ `getCount()` returns the total active object count.
 *             ▪ `getName()` returns the Zebra’s name.
 *     • ZebraKid
 *         – Inherits all members of `Zebra`.
 *         – Uses parent constructors to initialize derived objects.
 *
 *   The main() function:
 *     • Displays initial Zebra count.
 *     • Creates multiple Zebra objects to demonstrate lifecycle tracking.
 *     • Calls `f()` twice to show creation/destruction within function scope.
 *     • Instantiates a `ZebraKid` object and verifies inherited behavior.
 *     • Prints messages showing constructor and destructor sequencing.
 *
 *   Notes / Assumptions:
 *     • Output text includes explicit messages for births and deaths
 *       to visualize object lifecycle behavior.
 *     • No dynamic allocation is used; all destruction occurs automatically
 *       when objects go out of scope.
 *     • The `ZebraKid` class adds no new members; it exists solely to
 *       illustrate inheritance mechanics.
 *
 *   References:
 *     • EE553-WS Homework 6: C++ Class Design and Inheritance prompt.
 */


#include <limits>
#include <iostream>
#include <string>
#include <stdexcept>

class Zebra
{
private:
    std::string name;
    static int count;

public:
    Zebra()
    {
        name = "Zebra_" + std::to_string(count);
        count++;

        std::cout << "Hello I was just born! My name is: " << getName() << ".\n";
    }
    Zebra(const std::string& in_name)
    {
        name = in_name;
        count++;

        std::cout << "Hello I was just born! My name is: " << getName() << ".\n";
    }
    ~Zebra()
    {
        count--;

        std::cout << "Ugh! I'm " << getName() << ", I'm dying. Current Count: " << getCount() << ".\n";
    }

    static int getCount() { return count; }
    std::string getName() { return name; }
    
    void setName(const std::string& in_name)
    {
        name = in_name;
    }
};

class ZebraKid : public Zebra
{
public:
    ZebraKid() : Zebra() {}
    ZebraKid(const std::string& in_name) : Zebra(in_name) {}
};

int Zebra::count = 0;

void f()
{
    std::cout << "Current count: " << Zebra::getCount() << "\n";
    
    Zebra z1("Joker");
    Zebra z2("Alice");
    
    std::cout << "New count: " << Zebra::getCount() << "\n";
}


int main()
{
    std::cout << "########" << std::endl;
    std::cout << "Main Problem" << std::endl;
    std::cout << "########" << std::endl;
    // You should be able to run main() with your classes
    // No need to edit this part unless for debugging
    // print the initial count number
    std::cout << Zebra::getCount() << '\n'; // zero!
    // Creat object a with name Morgana
    Zebra a("Morgana");
    // Print the current count number of Zerba object
    std::cout << Zebra::getCount() << '\n';
    // Use the function f() above
    f();
    std::cout << "####" << std::endl;
    // Use the function f() above again
    f();
    std::cout << "####" << std::endl;
    // print out the current number of zebra
    std::cout << Zebra::getCount() << '\n';
    // Get the name of the zebra object a
    std::cout << a.Zebra::getName() << '\n';
    std::cout << "####" << std::endl;

    // create  ZebraKid object
    ZebraKid e("James");
    // Use the getName() form Zebra class
    std::cout << e.getName() << '\n';
    std::cout << Zebra::getCount() << '\n';


    std::cout << "====[ end ]====" << std::endl;
    std::cout << "               " << std::endl;

    std::cout << " #### This is after the program is completely done #####" << std::endl;
    std::cout << " ### The last remaining object should get destructed ###" << std::endl;

    return 0;
}