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
        mass_kg = 0;

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

    friend ostream& operator<<(ostream& stream, const Body& body)
    {
        stream << "Body Name: " << body.bodyName
             << "\nOrbit Name: " << body.orbitName
             << "\nMass: " << body.mass_kg
             << "\nPosition: " << body.position_m
             << "\nVelocity: " << body.velocity_mps
             << "\nAcceleration: " << body.acceleration_mps2;
        return stream;
    }

    string getBodyName() const
    {
        return bodyName;
    }
    double getBodyMass() const
    {
        return mass_kg;
    }

    static void setAcceleration(vector<Body>& in_bodies, const Vec3d in_acceleration_mps2)
    {
        for(Body& body : in_bodies)
        {
            body.acceleration_mps2 = in_acceleration_mps2;
        }
    }
};

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
            throw runtime_error("File not found.");
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

        random_device rd;
        mt19937 gen(rd());
        uniform_real_distribution<> dist(0.0, 10.0);
        uniform_real_distribution<> angle_dist(0.0, 2 * PI);

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
            // END: initialize position, velocity and acceleration of the body
        }
    }

    void stepForward(Vec3d in_acceleration_mps2)
    {
        Body::setAcceleration(bodies, in_acceleration_mps2);
    }

    friend ostream& operator<<(ostream& stream, const vector<Body>& in_bodies)
    {

    }
};

int main()
{
    cout << "########" << endl;
    cout << "Main Problem" << endl;
    cout << "########" << endl;

    string dat_file_path = "solarsystem.dat";

    try
    {
        SolarSystem s(dat_file_path);
    }
    catch(const exception& e)
    {
        cerr << e.what() << '\n';
        return 1;
    }

    cout << "====[ end ]====" << endl;
    cout << "               " << endl;
    return 0;
}