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
    Zebra(std::string in_name)
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
    
    void setName(std::string in_name)
    {
        name = in_name;
    }
};

class ZebraKid : public Zebra
{
public:
    ZebraKid() : Zebra() {}
    ZebraKid(std::string in_name) : Zebra(std::move(in_name)) {}
};

int Zebra::count = 0;

void f()
{
    std::cout << "Current count: " << Zebra::getCount() << "\n";
    
    Zebra z1;
    Zebra z2;
    Zebra z3("Joker");
    Zebra z4("Alice");
    
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