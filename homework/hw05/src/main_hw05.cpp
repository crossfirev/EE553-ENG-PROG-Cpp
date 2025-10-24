#include <iostream>
#include <string>
#include <vector> // use C++ STL vector with our struct
#include <cmath>
#include <random> // use this to generate random number
#include <fstream>


using namespace std;

// Define constant double here:
// 1. for G = universal gravitational constant equal 6.674E-11 or 6.674*10^(-11)
// 2. for pi = 3.14159265358979323846
// write your code here


// ----- Use 3d vector struct -----
// ------------------------------------
struct Vec3d
{
    int x, y, z;
};

// overload << operator for struct Vec3d
// when use << so it prints like this: x_value, y_value, z_value
// write your code here


// ----- Implement class body here ----
// ------------------------------------
// Body class will have private variables to save following information:
//  planet name: string
//  orbit name: string
//  the planet mass: double
//  position  using Vec3d: Vec3d
//  velocity  using Vec3d: Vec3d
//  acceleration using Vec3d: Vec3d

class Body {
// define the Body variable here
// name, orbit, mass (double), pos (Vec3d overload), v (Vec3d overload), a(Vec3d overload)

    // default body constructor set all variables to zero and string to "none"
    // name it Body()
    // write your code here

    //non-default constructor to initialize body information.
    // name same as default constructor
    // name, orbit, mass, pos (Vec3d overload), v (Vec3d overload), a(Vec3d overload)
    // write your code here

    // Overload << operator to print out body information as
    // name, orbit, mass, pos (Vec3d overload), v (Vec3d overload), a(Vec3d overload)
    // don't forget to use friend keyword here for overloading function
    // main program show an example of the output
    // write your code here

    // create setAccelerations() function that change the acceleration of planet in SolarSystem
    // this function should loop through Solarsystem object and change acceleration of each body planet
    // the input is vector of Body and integer acceleration
    // for function type use it as: static auto setAccelerations()
    // write your code here

    // make sure that SolarSystem class is a friend to Body()

};


// ----- Implement class solar system here ----
// --------------------------------------------
// SolarSystem class variable will be private vector of type class Body called bodies

class SolarSystem {
    // Solar have one variable that is vector of type Body called bodies
    // all planet Body you read should save in this vector


    // SolarSystem main function should take the location of .dat file
    // and read the complete file
    // SolarSystem()

    // open ifstream file


    //check if file exist or not
    if (solarfile.is_open()){

        cout << "File is open and ready" << '\n';
        cout << " " << '\n';
//            return; // use this for program testing to check file is open only without reading the data
    }else{
        cout << "File not found!" << '\n';
        cout << "check if path is .././src/***" << '\n';
        cout << " " << '\n';
        return;
    }

    // define variable you want to read some info will be saved and some will be used in calculation
    // don't forget to skip first line since it contain title only


    // read file line by line
    // you will need to save Sun mass to use in planet velocity calculation
    // only calculate the orbiting velocity for planet orbiting sun ,e.g., if you read Io moon that orbiting Venus you skip the calculation
    // print out planet: name  Orbit: Sun
    // print out the orbit velocity
    // print out centripetal acceleration
    // All calculation is simplified
    // check out this wiki https://en.wikipedia.org/wiki/Circular_orbit
    // 	v = sqrt( G"universal gravitational" * mass of the sun /radius )
    // approximation of radius of your orbit = (Perihelion  + Aphelion) /2

    // For x, y, and z of Vec3d pos"position" generate random number between 0 and 10
    // look up how to use rand function

    // we will calculate random angle between 0 and 2*pi
    // look up how to use uniform_real_distribution
    // check out https://en.cppreference.com/w/cpp/numeric/random/uniform_real_distribution

    // For x, y, and z of Vec3d velocity will be
    // x = r cos(ang)  ===> x*v"the calculated velocity"
    // y = r sin(ang) ====> y*v
    // z = zero

    // For x, y, and z of Vec3d acceleration, where a = v^2 / r,  will be
    // x = r cos(ang)  ===> x*a"the calculated velocity"
    // y = r sin(ang) ====> y*a
    // z = zero

    // Before reading the next planet create temp Body class object and save needed information
    // .push_back() the Body into the SolarSystem bodies class

    // don't forget to close the open .dat file after reading the complete file


    // add the value of accelerations in stepForward
    // this function take variable bodies inside Solarsystem and int acc and use it with function setAccelerations
    // function should be void
    // stepForward()

    // overload SolarSystem object, so it loops through list of bodies and cout it
    // this function also depend on the overload of Body class

};

int main() {
    cout << "########" << endl;
    cout << "Main Problem" << endl;
    cout << "########" << endl;

    // SolarSystem s should read the file to print and do calculation
    // when you creat object Solarsystem s('.dat path') it read the file and print only planets orbiting the sun  as shown below
    //    body name:Jupiter orbit: Sun
    //    orbital velocity is: 13058
    //    centripetal acceleration: 0.000219013
    //    body name:Saturn orbit: Sun
    //    orbital velocity is: 9623.1
    //    centripetal acceleration: 6.45977e-05
    //    ==================
    // Write your fullpath here to location where solarsystem.dat exist.
    SolarSystem s(".././src/solarsystem.dat");


    cout << s;
    // After reading the file print calculation done on Solarsystem
    // overload << operator in SolarSystem class to print out variables as follows
    //    Mercury, Sun, 3.3e+23, 8, 10, 4, -2147483648, -2147483648, 0, -1981977299, 1152671425, 0
    //    Venus, Sun, 4.87e+24, 9, 1, 3, -2147483648, -2147483648, 0, 1021382959, -679782887, 0


    cout << "=============" << endl;

    // add acceleration equal 100
    // Use function .stepForward() on object Solarsystem to set the new acceleration
    int acc = 5000;
    s.stepForward(acc);
    // print out the new solarsystem
    cout << s;

    cout << "====[ end ]====" << endl;
    cout << "               " << endl;
    return 0;

}