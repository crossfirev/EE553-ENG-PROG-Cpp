#include <cmath>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <random> // use this to generate random number
#include <sstream>
#include <string>
#include <tuple>
#include <vector> // use C++ STL vector with our struct

using namespace std;

const double G = 6.674e-11; // m^3 kg^-1 s^-2
const double PI = 3.14159265358979323846;

struct Vec3d
{
    double x, y, z;

    Vec3d()
    {
        x = 0;
        y = 0;
        z = 0;
    }

    Vec3d(double in_x, double in_y, double in_z)
    {
        x = in_x;
        y = in_y;
        z = in_z;
    }

    Vec3d operator+(const Vec3d &vec) const
    {
        return Vec3d(
            x + vec.x,
            y + vec.y,
            z + vec.z
        );
    }
    Vec3d& operator+=(const Vec3d& vec)
    { 
        x += vec.x; 
        y += vec.y; 
        z += vec.z; 
        return *this; 
    }

    friend ostream& operator<<(ostream& stream, const Vec3d& vector)
    {
        stream << "x: " << vector.x << ", y: " << vector.y << ", z: " << vector.z;
        return stream;
    }
};

class Body
{
private:
    string bodyName;
    string orbitName;

    double mass_kg;

    Vec3d position_m;
    Vec3d velocity_mps;
    Vec3d acceleration_mps2;

public:
    // Allows SolarSystem to access Body's private variables
    friend class SolarSystem;

    //  Default Constructor, assigns all variables to null-esque values.
    Body()
    {

        bodyName = "none";
        orbitName = "none";

        position_m = { 0, 0, 0 };
        velocity_mps = { 0, 0, 0 };
        acceleration_mps2 = { 0, 0, 0 };
    }

    //  Non-default Constructor, assigns all variables via input arguments.
    Body(const string& in_bodyName, const string& in_orbitName, double in_mass_kg, Vec3d in_position_m, Vec3d in_velocity_mps, Vec3d in_acceleration_mps2)
    {

        bodyName = in_bodyName;
        orbitName = in_orbitName;
        mass_kg = in_mass_kg;

        position_m = in_position_m;

        velocity_mps = in_velocity_mps;

        acceleration_mps2 = in_acceleration_mps2;
    }

    friend ostream& operator<<(ostream& strm, const Body& obj)
    {
        strm << "Body Name: " << obj.bodyName
             << "\nOrbit Name: " << obj.orbitName
             << "\nMass: " << obj.mass_kg
             << "\nPosition: " << obj.position_m
             << "\nVelocity: " << obj.velocity_mps
             << "\nAcceleration: " << obj.acceleration_mps2;
        return strm;
    }

    string getBodyName() const
    {
        return bodyName;
    }
    double getBodyMass() const
    {
        return mass_kg;
    }

    void setAcceleration(double in_x_acceleration, double in_y_acceleration, double in_z_acceleration)
    {
        acceleration_mps2 = Vec3d { in_x_acceleration, in_y_acceleration, in_z_acceleration };
    }
};

// create setAccelerations() function that change the acceleration of body in SolarSystem
// this function should loop through Solarsystem object and change acceleration of each body body
// the input is vector of Body and integer acceleration
// for function type use it as: static auto setAccelerations()
// write your code here

// ----- Implement class solar system here ----
// --------------------------------------------
// SolarSystem class variable will be private vector of type class Body called bodies

tuple<bool, double> searchForMass(const vector<Body>& in_bodies, const string& in_bodyName)
{
    for (const Body& body : in_bodies)
    {
        if (in_bodyName == body.getBodyName())
        {
            return { true, body.getBodyMass() };
        }
    }
    return { false, 0 };
}

class SolarSystem
{
private:
    vector<Body> bodies;
    double sunMass_kg;

    // Auxilury Functions
    static void print_row(ostream& os, const string& label, double value, const char* unit)
    {
        os << "  "  << left  << setw(26) << label
           << " | " << right << setw(12) << scientific << setprecision(6) << value
           << " | " << left  << setw(8)  << unit
           << defaultfloat << '\n';
    }

    inline void print_header(ostream& os)
    {
        os  << "  "  << left  << setw(26) << "Metric"
            << " | " << right << setw(12) << "Value"
            << " | " << left  << setw(8)  << "Unit" << '\n';
    }

    inline void print_rule(ostream& os)
    {
        os << "  " << string(26 + 3 + 12 + 3 + 8, '-') << '\n';
    }

public:
    SolarSystem(const string& inFileName)
    {
        // START: read in data file line; 1 line = 1 body
        ifstream file;
        file.open(inFileName);

        if (!file.is_open())
        {
            cout << "File not found!" << '\n';
            cout << "check if path is .././src/***" << '\n';
            cout << " " << '\n';
            throw std::runtime_error("File not found.");
        }

        string bodyName;
        string orbitName;
        double mass_kg;
        double diameter_m;
        double perihelion_m;
        double aphelion_m;
        double orbitalPeriod_days;
        double rotationalPeriod_hours;
        double axialTilt_deg;
        double orbitalInclination_deg;

        double orbitalRadius_m;
        double orbitalVelocity_mps;
        double orbitalAcceleration_mps2;

        string line;
        getline(file, line); // Skips header line of file
        cout << "========================================================\n";

        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<> dist(0.0, 10.0);
        std::uniform_real_distribution<> angle_dist(0.0, 2 * PI);

        while (getline(file, line))
        {
            istringstream iss(line);

            iss >> bodyName
                >> orbitName
                >> mass_kg
                >> diameter_m
                >> perihelion_m
                >> aphelion_m
                >> orbitalPeriod_days
                >> rotationalPeriod_hours
                >> axialTilt_deg
                >> orbitalInclination_deg;

            if (bodyName == "Sun") // Establish the sun.
            {
                sunMass_kg = mass_kg;
            }

            auto [found, parent_mass_kg] = searchForMass(bodies, orbitName); // Assumes the parent orbits preceed the child bodies.
            if (found)
            {
                double mu = G * (parent_mass_kg + mass_kg);
                orbitalRadius_m = (perihelion_m + aphelion_m) / 2.0; // Approximate radius of an elliptical orbit.
                orbitalVelocity_mps = sqrt(mu / orbitalRadius_m);
                orbitalAcceleration_mps2 = orbitalVelocity_mps * orbitalVelocity_mps / orbitalRadius_m;
            }
            else
            {
                orbitalRadius_m = 0;
                orbitalVelocity_mps = 0;
                orbitalAcceleration_mps2 = 0;
            }


            cout << bodyName << "\n------\n\n";
            cout << "  Orbits: " << orbitName << "\n\n";

            print_header(cout);
            print_rule(cout);

            print_row(cout, "Body Mass:",              mass_kg,                "kg");
            print_row(cout, "Body Diameter:",          diameter_m,             "m");
            print_row(cout, "Body Rotational Period:", rotationalPeriod_hours, "hr");
            print_row(cout, "Body Axial Tilt:",        axialTilt_deg,          "deg");

            if (bodyName != "Sun")
            {
                print_rule(cout);

                print_row(cout, "Orbital Perihelion:",     perihelion_m,           "m");
                print_row(cout, "Orbital Aphelion:",       aphelion_m,             "m");
                print_row(cout, "Orbital Period:",         orbitalPeriod_days,     "day");
                print_row(cout, "Orbital Inclination:",    orbitalInclination_deg, "deg");

                print_rule(cout);

                print_row(cout, "Orbital Radius:",         orbitalRadius_m,         "m");
                print_row(cout, "Orbital Velocity:",       orbitalVelocity_mps,     "m/s");
                print_row(cout, "Orbital Acceleration:",   orbitalAcceleration_mps2,"m/s^2");   
            }

            cout << "========================================================\n";
            // END: read in data file line; 1 line = 1 body

            // START: initialize position, velocity and acceleration of the body
            Vec3d position = { 0, 0, 0 };
            Vec3d velocity = { 0, 0, 0 };
            Vec3d acceleration = { 0, 0, 0 };

            if (orbitalRadius_m > 0)
            {
                double orbital_phase = angle_dist(gen);

                // In-place of randomly generating the position of the bodies, favored using the data in the dataset to generate accurate orbits.
                //      Retained randomized angle - orbital phase, to show random value understanding.
                position = {
                    orbitalRadius_m * cos(orbital_phase),
                    orbitalRadius_m * sin(orbital_phase),
                    dist(gen)
                };

                velocity = {
                    -(orbitalVelocity_mps * sin(orbital_phase)),
                    orbitalVelocity_mps * cos(orbital_phase),
                    0,
                };

                acceleration = {
                    -orbitalAcceleration_mps2 * cos(orbital_phase),
                    -orbitalAcceleration_mps2 * sin(orbital_phase),
                    0
                };
            }
            bodies.push_back(
                Body(
                    bodyName,
                    orbitName,
                    mass_kg,
                    position,
                    velocity,
                    acceleration
                )
            );
        }
        
        for(const Body& body : bodies)
        {
            cout << body << endl;
        }
    }
    // SolarSystem main function should take the location of .dat file
    // and read the complete file
    // SolarSystem()

    // open ifstream file

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

    // we will calculate random angle between 0 and 2*PI
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

int main()
{
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
    string dat_file_path = "solarsystem.dat";

    try
    {
        SolarSystem s(dat_file_path);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return 1;
    }
    // After reading the file print calculation done on Solarsystem
    // overload << operator in SolarSystem class to print out variables as follows
    //    Mercury, Sun, 3.3e+23, 8, 10, 4, -2147483648, -2147483648, 0, -1981977299, 1152671425, 0
    //    Venus, Sun, 4.87e+24, 9, 1, 3, -2147483648, -2147483648, 0, 1021382959, -679782887, 0

    // cout << "=============" << endl;

    // // add acceleration equal 100
    // // Use function .stepForward() on object Solarsystem to set the new acceleration
    // int acc = 5000;
    // s.stepForward(acc);
    // // print out the new solarsystem
    // cout << s;

    cout << "====[ end ]====" << endl;
    cout << "               " << endl;
    return 0;
}