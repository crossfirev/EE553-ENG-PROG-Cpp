#include <time.h>

#include <iostream>

using namespace std;

// complete the JulianDate class
// write your code in the JulianDae class
// complete the code in main
class JulianDate
{
    // Make all your class access is public
public:
    // first define your variable type and variable (year, month, day, hour, mins, sec)
    int year, month, day, hour, min, sec;
    double JulianNumber;

    // write your non-default constructor that set variables today's date
    // write your code here
    // Name it JulianDate
    JulianDate(int in_year, int in_month, int in_day, int in_hour = 0, int in_min = 0, int in_sec = 0)
    {
        year = in_year;
        month = in_month;
        day = in_day;
        hour = in_hour;
        min = in_min;
        sec = in_sec;

        JulianNumber = calc_juliandate();
    }
    // Write your default constructor that takes nothing
    JulianDate()
    {
        time_t t = time(0);
        struct tm* time = gmtime(&t);

        year = time->tm_year + 1900;
        month = time->tm_mon + 1;
        day = time->tm_mday;
        hour = time->tm_hour;
        min = time->tm_min;
        sec = time->tm_sec;

        JulianNumber = calc_juliandate();
    }

    // write function that calculate julian number from given date
    // your function should return the value
    // use calc_juliandate as the function name
    // write your code here
    double calc_juliandate() const
    {
        int a = (14 - month) / 12;
        int m = month + 12 * a - 3;
        int y = year + 4800 - a;

        int nDate = day
            + (153 * m + 2) / 5
            + 365 * y
            + y / 4
            - y / 100
            + y / 400
            - 32045;

        double fullDate = nDate + (hour + (min / 60.0) + (sec / 3600.0)) / 24.0;
        return fullDate;
    }

    // write function that calculate difference between two Julian date
    // use diff_calc_juliandate as the function name
    // write your code here
    double diff_calc_juliandate(const JulianDate& jd_to_diff) const
    {
        return this->JulianNumber - jd_to_diff.JulianNumber;
    }
};

ostream& operator<<(ostream& os, const JulianDate& date)
{
    os << date.JulianNumber;
    return os;
}

/*

Use the formula in the below web page in the calculate julian function

http://www.c-jump.com/bcc/c155c/Homework/a4_Serial_Julian_Date/a4_Serial_Julian_Date.html
https://www.aavso.org/jd-calculator

hh:mm:ss

00:00:00  0.0
12:00:00  0.5

18*365+18/4 - 18/100 + 18/400
18*364+4 = 6574

6574.041666666 --> Jan 1, 2018, 01:00:00
 */
// int JulianDate::EPOCH = 2000; // Jan.1 2000, 00:00:00 = 0

int main()
{

    cout << "########" << endl;
    cout << "Main Problem" << endl;
    cout << "########" << endl;

    // Run your class on this code and calculate the difference of Julian number below

    cout.precision(20);

    JulianDate a(1776, 7, 4);
    JulianDate b(2000, 12, 31);
    JulianDate c(2007, 2, 8);
    JulianDate d(2007, 2, 9);

    cout << "7/4/1776   -> " << a << "\n12/31/2000 -> " << b << "\n2/8/2007   -> " << c << "\n2/9/2007   -> " << d << "\n---\n";

    JulianDate x(2007, 2, 8, 0, 0, 0); // how many days since day 0? dy = (2018 - 2000) * 365
    double x1 = x.calc_juliandate();
    cout << "x1: " << x1 << endl;

    JulianDate y(2000, 12, 31, 0, 0, 1);
    double y1 = y.calc_juliandate();
    cout << "y1: " << y1 << "\n---\n";

    // manual calculation of the difference between two dates, e.g., x1 - y1 = results
    // print out the result
    //  write your code here
    double result = x1 - y1;
    cout << "Manual diff calculation (x1 - y1): " << result << endl;

    // Now use your class function to find the difference between two dates
    // print out the result
    // write your code here
    result = x.diff_calc_juliandate(y);
    cout << "Function diff calculation (x - y): " << result << endl;

    // example of date to Julian date format without hour/min/sec
    // 7/4/1776   2369916
    // 12/31/2000 2451910
    // 2/8/2007   2454140
    // 2/9/2007   2454141

    cout << "====[ end ]====" << endl;

    return 0;
}
