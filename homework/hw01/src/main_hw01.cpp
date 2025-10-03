/*
 * Author: Matthew Lepis
 * Date:   10/03/2025
 *
 * Description:
 *   Program demonstrating simple numerical summations in C++ across three problems:
 *
 *   1) Sum of Integers (Problem One)
 *      - Computes the sum of integers from 1 up to N using an iterative loop.
 *
 *   2) Harmonic Series Summation (Problem Two)
 *      - Computes the harmonic series sum (1/1 + 1/2 + ... + 1/N) in both forward and reverse order.
 *      - Demonstrates floating-point precision issues by comparing the results of the two methods.
 *      - Notes that precision errors can be reduced using `double` or `long double`.
 *
 *   3) Reciprocal-Squares Series (Problem Three)
 *      - Computes the sum of 1/n² up to N in both forward and reverse order.
 *      - Provides results to highlight convergence properties and floating-point behavior.
 *
 *   Notable Details:
 *     • All summations use iterative loops with `float` for demonstration.
 *     • Floating-point rounding errors are visible when comparing forward vs reverse accumulations.
 *     • Output is printed directly to standard output for clarity.
 */

#include <iostream>

using namespace std;

// --- Problem 1 ---
int sumUpTo(int sumTo)
{
    int sum = 0;
    for (int i = 1; i <= sumTo; i++)
    {
        sum += i;
    }
    return sum;
}

// --- Problem 2 ---
float sumReciprocalNormal(int sumTo_denominator)
{
    float sum = 0;
    for (int i = 1; i <= sumTo_denominator; i++)
    {
        sum += 1.0 / i;
    }
    return sum;
}

float sumReciprocalRev(int sumFrom_denominator)
{
    float sum = 0;
    for (int i = sumFrom_denominator; i >= 1; i--)
    {
        sum += 1.0 / i;
    }
    return sum;
}

// --- Problem 3 ---
float sumMysteryNormal(int sumTo_denominator)
{
    float sum = 0;
    for (int i = 1; i <= sumTo_denominator; i++)
    {
        sum += 1.0 / (i * i);
    }
    return sum;
}

float sumMysteryRev(int sumFrom_denominator)
{
    float sum = 0;
    for (int i = sumFrom_denominator; i >= 1; i--)
    {
        sum += 1.0 / (i * i);
    }
    return sum;
}

int main()
{
    // Problem One
    cout << sumUpTo(100) << '\n';

    // Problem Two
    float sum1 = sumReciprocalNormal(100); // compute the sum 1/1 + 1/2 + 1/3 + 1/4 + 1/5 + ... + 1/100 =5.18....
    float sum2 = sumReciprocalRev(100); // compute the sum 1/100 + 1/99 + 1/98 + ... + 1/1 = 5.18
    cout << sum1 << '\n';
    cout << sum2 << '\n';
    cout << (sum1 - sum2) << '\n';

    // sum1 - sum2 isn't zero. This is expected, a result of floating point rounding. This error can be ~reduced with `double` or `long double` implementations.

    // Problem Three
    cout << sumMysteryNormal(100) << '\n';
    cout << sumMysteryRev(100) << '\n';

    return 0;
}
