#include <iostream>
#include <cmath>  // double sin(double), double cos(double)
#include <fstream>
#include <cstdlib>
#include <string>
#include <sstream>
#include <iomanip>
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

double angleWrap(double radians)
{
    double twoPi = 2 * pi;
    double wrapped = std::fmod(radians, twoPi);
    if (wrapped < 0) 
        wrapped += twoPi;
    return wrapped;
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
// SETTING FLOATING POINT PRECISION FOR CLEANER OUTPUT.
    std::cout << std::fixed << std::setprecision(8);
    string lineBuffer = "";
    int lineCounter = 0;
    while(getline(file, lineBuffer))
    {
        // Skip empty lines
        if (lineBuffer == "")
            continue;

        double r = -1.0;
        double theta = -1.0;

        // Grab each word on the line individually
        istringstream iss(lineBuffer);
        string word;

        int counter = 0; // to control which which value is taken in, important for typing (int vs. double)
        while (iss >> word)
        {
            switch (counter)
            {
                case 0:
                    r = stod(word);
                    break;
                case 1:
                    theta = stod(word);
                    break;
            }
            counter++;
        }
        if (r == -1 || theta == -1) // Ensure we obtained the values
        {
            cout << "Failed to assign r or theta.\n";
            exit(1);
        }

        cout << "---\n";
        cout << "Line " << lineCounter << ".\n";
        cout << "-\n";

        cout << "Distance (m): " << r << "\n";
        cout << "Angle (deg): " << theta << "\n";
        cout << "-\n";
        
        double theta_rad = theta * (pi/180.0);
        cout << "Angle (rad): " << theta_rad << "\n";
        cout << "-\n";

        double pos_x = r * cos(theta_rad);
        double pos_y = r * sin(theta_rad);
        cout << "Position (x): " << pos_x << "\n";
        cout << "Position (y): " << pos_y << "\n";
        
        double theta_from_cartesian = angleWrap(atan2(pos_y, pos_x));
        cout << "Angle from Cartesian (rad): " << theta_from_cartesian << "\n";

        lineCounter++;
    }
    file.close();
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
