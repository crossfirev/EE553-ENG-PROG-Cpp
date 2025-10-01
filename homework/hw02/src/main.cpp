#include <cfloat>
#include <cmath> // double sin(double), double cos(double)
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>

// #include "functionWind.h"
// #include "functionPrime.h"

using namespace std;

// const for pi
const double pi = 3.14159265358979323846;
const string robotpath_file_path = "./robotpath.dat";

template <typename Func>
void printIsPrimeResult(const Func in_func, const string in_funcName, const int in_funcInput)
{
    bool result = in_func(in_funcInput);
    if (result)
        cout << in_funcName << "(" << in_funcInput << ") is true, " << in_funcInput << " is prime." << '\n';
    else
        cout << in_funcName << "(" << in_funcInput << ") is false, " << in_funcInput << " is not prime." << '\n';
}

bool isPrime(const int in_primeCandidate)
{
    if (in_primeCandidate <= 1)
        return false;

    for (int i = 2; i * i <= in_primeCandidate; i++)
    {
        // if dividing by i gives no remainder, it isn't prime.
        if (in_primeCandidate % i == 0)
        {
            return false;
        }
    }
    return true;
}

double angleWrap(const double in_radians)
{
    double twoPi = 2 * pi;
    double wrapped = fmod(in_radians, twoPi);
    if (wrapped < 0)
        wrapped += twoPi;
    return wrapped;
}

double calcWindChill(const double in_airTemperature, const double in_airVelocity)
{
    if (in_airTemperature > 50.0)
    {
        throw invalid_argument("ERR: Air temperature > 50°F not valid for wind chill.");
    }
    if (in_airVelocity < 3)
    {
        throw invalid_argument("ERR: Air velocity < 3 mph not valid for wind chill.");
    }

    constexpr double c_fahrenheit_baseline = 35.74;
    constexpr double c_airTempScalar = 0.6215;
    constexpr double c_airVelocityScalar = 35.75;
    constexpr double c_airTempVelocityScalar = 0.4275;

    const double airVelocityRaised = pow(in_airVelocity, 0.16);

    // Wind Chill = 35.74 + 0.6215T – 35.75(V^0.16) + 0.4275T(V^0.16)
    return c_fahrenheit_baseline
        + c_airTempScalar * in_airTemperature
        - c_airVelocityScalar * airVelocityRaised
        + c_airTempVelocityScalar * in_airTemperature * airVelocityRaised;
}

int main()
{
    cout << "###########" << endl;
    cout << "Problem One" << endl;
    cout << "###########" << endl;
    // For problem one, you only need to write your code in "functionPrime.cpp"

    // -----
    // You said in class that all of our work should be in THIS file when I asked. If you'd like I can give you it split for 'functionPrime.cpp'. I put it this way at your request against the instructions here.
    // -----

    // define isPrime
    // isPrime(19);
    printIsPrimeResult(isPrime, "isPrime", 19);
    cout << '\n';

    // isPrime(81);// trial divide, 81%3 == 0 therefore not prime
    printIsPrimeResult(isPrime, "isPrime", 81);
    cout << '\n';

    // isPrime(57) ; // 57 % 2, 57% 3, 57%4
    printIsPrimeResult(isPrime, "isPrime", 57);
    cout << '\n';

    cout << "====[ end ]====" << endl;

    cout << "###########" << endl;
    cout << "Problem Two" << endl;
    cout << "###########" << endl;
    // For problem Two, you will need to write your code here
    // first read file robotpath.dat and name it thefile by using ifstream
    // make sure you use the full path to .dat file, e.g., .././src/robotpath.dat

    // check if thefile exist or not
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
    cout << fixed << setprecision(8);
    string lineBuffer = "";
    int lineCounter = 0;
    while (getline(file, lineBuffer))
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

        double theta_rad = theta * (pi / 180.0);
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

    // print out message to enter wind speed and take the input
    // Check if speed meet condition

    // print out message to enter temperature and take the input
    // check if temperature  meet condition

    double airVelocity = -1;
    double airTemperature = DBL_MAX;
    double windChill = DBL_MAX;
    while (true)
    {
        cout << "-----------------------\n";
        cout << "Wind Chill Calculation:\n";
        cout << "-----------------------\n";
        cout << "  Input Air Velocity:\n  ";
        cin >> airVelocity;
        cout << "  -------------------\n";

        cout << "  Input Air Temperature:\n  ";
        cin >> airTemperature;
        cout << "  -------------------\n";

        // Cleans `cin` for the case of non-numeric input.
        if (!cin)
        {
            cerr << "ERR: Invalid input. Please enter a number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        try
        {
            windChill = calcWindChill(airTemperature, airVelocity);
            break;
        }
        catch (const exception& e)
        {
            cerr << e.what() << '\n';
        }
    }
    cout << "================\n";
    cout << "Wind Chill (°F): " << windChill << "\n";

    cout << "====[ end ]====" << endl;

    return 0;
}
