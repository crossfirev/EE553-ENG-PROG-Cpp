#include <iostream>
#include <cmath>

using namespace std; // if not used, must write std::cout or std::endl

// --- Problem 1 ---
int sumUpTo(int sumTo)
{
    int sum = 0; 
    for(int i = 1; i <= sumTo; i++)
    {
        sum += i;
    }
    return sum;
}

// --- Problem 2 ---
float sumReciprocalNormal(int sumTo_denominator)
{
    float sum = 0; 
    for(int i = 1; i <= sumTo_denominator; i++)
    {
        sum += 1.0/i;
    }
    return sum;
}

float sumReciprocalRev(int sumFrom_denominator)
{
    float sum = 0; 
    for(int i = sumFrom_denominator; i >= 1; i--)
    {
        sum += 1.0/i;
    }
    return sum;
}

int main() {
    // Problem One
    cout << sumUpTo(100) << '\n';

    // Problem Two
    cout << sumReciprocalNormal(100) << '\n';
    cout << sumReciprocalRev(100) << '\n';

    float sum1 = sumReciprocalNormal(100);  // compute the sum 1/1 + 1/2 + 1/3 + 1/4 + 1/5 + ... + 1/100 =5.18....
    float sum2 = sumReciprocalRev(100);     // compute the sum 1/100 + 1/99 + 1/98 + ... + 1/1 = 5.18
    cout << sum1 << '\n';
    cout << sum2 << '\n';
    cout << (sum1 - sum2) << '\n';

    // sum1 - sum2 isn't zero. This is expected, a result of floating point rounding.

    // Problem Three
    // cout << sumMysteryNormal(100) << '\n';
    // cout << sumMysteryRev(100) << '\n';
    // mystery1sum
    // be careful! if you calculate as int this will not work. use float!
    // compute 1.0/(1*1) + 1.0/(2.0*2.0) + 1/(3*3) + ... + 1/(n*n)  n-> infinity
    //float mystery1; //

    // mystery2sum
    // compute  1/(n*n) + 1/((n-1)*(n-1)) +  1/((n-2)*(n-2)) + ...
    //float mystery2; //

    return 0;
}
