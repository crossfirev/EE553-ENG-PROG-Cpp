#include <iostream>
#include <cmath>  // double sin(double), double cos(double)
#include <fstream>
#include <cstdlib>
#include <string>
//#include "functionWind.h"
//#include "functionPrime.h"

using namespace std;

// const for pi
const double pi = 3.14159265358979323846;
const string robotpath_file_path = "./robotpath.dat";

template <typename Func>
void printIsPrimeResult(Func func, string funcName, int funcInput)
{
    bool result = func(funcInput);
    if (result)
        cout << funcName << "(" << funcInput << ") is true, " << funcInput << " is prime." << '\n';
    else
        cout << funcName << "(" << funcInput << ") is false, " << funcInput << " is not prime." << '\n';
}

int main() {
    cout << "###########" << endl;
    cout << "Problem One" << endl;
    cout << "###########" << endl;
    // For problem one, you only need to write your code in "functionPrime.cpp"
    // define isPrime
    //isPrime(19);
    printIsPrimeResult(isPrime, "isPrime", 19);
    cout << '\n';

    //isPrime(81);// trial divide, 81%3 == 0 therefore not prime
    printIsPrimeResult(isPrime, "isPrime", 81);
    cout << '\n';

    //isPrime(57) ; // 57 % 2, 57% 3, 57%4
    printIsPrimeResult(isPrime, "isPrime", 57);
    cout << '\n';

    cout << "====[ end ]====" << endl;

    cout << "###########" << endl;
    cout << "Problem Two" << endl;
    cout << "###########" << endl;
    // For problem Two, you will need to write your code here
    // first read file robotpath.dat and name it thefile by using ifstream
    // make sure you use the full path to .dat file, e.g., .././src/robotpath.dat

    //check if thefile exist or not
    ifstream file;
    file.open(robotpath_file_path);

    if (file.is_open())
    {
        cout << "File is open and ready" << '\n';
    }
    else
    {
        cout << "File not found!" << '\n';
        exit(1);
    }
    
    // define your variables each line r and theta from the polar coordinates
    // use defined constant pi value in your calculation
    // start reading file and do calculation


    // while reading print the following for each line:
    //  - print distance and angle
    //  - print angle in radian, 1 degree is equal (pi/180degree)
    //  - print x and y location
    //  - check your conversion and print angle in rad after finding x and y with cartesian coordinates conversion
    // don't forget to close your opened file


    cout << "====[ end ]====" << endl;

    cout << "###########" << endl;
    cout << "Problem Three" << endl;
    cout << "###########" << endl;
    //Write your code here


    // use Boolean CanRun to decide to do calculation or not based on condition
    bool canRun = true;
    // define your input value and other variable

    // print out message to enter wind speed and take the input
    // Check if speed meet condition

    // print out message to enter temperature and take the input
    // check if temperature  meet condition

    // check if all condition is met and use canRun to start calculation of wind chill
    // print out the value



    cout << "====[ end ]====" << endl;

    return 0;
}
