#include <iostream>
#include <math.h>
using namespace std;



int main() {
	cout << "########" << endl;
    cout << "Problem One" << endl;
    cout << "########" << endl;
  // read how many number of elements you want to create
    int n;
    cout << "Please enter number of elements:";
    cin >> n;

    // Use function ReadElements() to read array (A) from the user with given number of elements
    // define new empty array dynamically with n number as int *A = new int[n];
    // write your code here
    int* A = new int[n];

    ReadElements(A, n);


    // Use function PrintElements() that can print the entered array
    // write your code here
    cout << "Print Array" << endl;
    PrintElements(A, n);


    // Use function PrintElementsRev() that can print the array in reverse order
    // write your code here
    cout << "Print Reverse Array" << endl;
    PrintElementsRev(A, n);


    // Use function OddsOnly that can print only the odd elements of the user array
    // define a null pointer *e to use it with OddsOnly function
    // and int m equal zero
    // write your code here
    // you can use NULL here or nullptr for *e


    int* e = nullptr; // null pointer
    int m = 0; // number of odd elements

    // print odds array
    cout << "Print Odds Only Array" << endl;
    // Use function
    OddsOnly(A, n, e, m);

    // do not forget
    delete [] A; // Do not forget to deallocate dynamically allocated memory
    delete [] e; // same as above

    cout << "====[ end ]====" << endl;
    cout << "               " << endl;

    cout << "########" << endl;
    cout << "Problem Two" << endl;
    cout << "########" << endl;
    // Read only this part of the problem

    //define the size of the array and the array
	const int N = 10; // Size of the array
    int arr[N];

    // Initialize the array with random values (for demonstration)
    for (int i = 0; i < N; i++) {
        //write code to generate random number between 0-99 and fill in the array
    }

    // Display the original array
    std::cout << "Original Array: ";

    std::cout << std::endl;

    int searchValue;
    std::cout << "Enter a value to search for: ";
    std::cin >> searchValue;

    bool found = false;
    int index = -1; // To store the index of the found value

    // Linear search algorithm
   //implement linear search algorithms

    if (found) {
        std::cout << "The value " << searchValue << " is found at index " << index << std::endl;
    } else {
        std::cout << "The value " << searchValue << " is not found in the array." << std::endl;
    }

    cout << "########" << endl;
    cout << "Problem Three" << endl;
    cout << "########" << endl;

    std::cout << "Enter the first integer: ";
    std::cin >> num1;
    std::cout << "Enter the second integer: ";
    std::cin >> num2;

    std::cout << "Before swapping: num1 = " << num1 << ", num2 = " << num2 << std::endl;

    // Call the swapValues function to swap the values of num1 and num2 using pointers
    //define swap value function before main function
    swapValues(&num1, &num2);

    // Display the values after swapping
    std::cout << "After swapping: num1 = " << num1 << ", num2 = " << num2 << std::endl;

}

