#include <iostream>
#include <math.h>
using namespace std;

void ReadElements(int* arr, int num_elements)
{
    cout << "-----\n";
    cout << "Taking in " << num_elements << " values. Continue entering until exhausted.\n";
    for(int i = 0; i < num_elements; i++)
    {
        cout << "Element " << i << ": ";

        while(true)
        {
            cin >> arr[i];
            if (!cin)
            {
                cerr << "ERR: Invalid input. \n\tPlease enter a integer number.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }
            break;
        }
    }
    cout << "-----\n";
}

void PrintElements(int* arr, int num_elements)
{
    for(int i = 0; i < num_elements; i++)
    {
        cout << arr[i];
        if (!(i == num_elements-1))
        {
            cout << ", ";
        }
    }
    cout << "\n";
    cout << "-----\n";
}

void PrintElementsRev(int* arr, int num_elements)
{
    for(int i = num_elements-1; i >= 0; i--)
    {
        cout << arr[i];
        if (!(i == 0))
        {
            cout << ", ";
        }
    }
    cout << "\n";
    cout << "-----\n";
}

void OddsOnly(int* arr, int num_elements, int*& return_arr, int& return_num_odds)
{
    cout << "\tCounting odd values...\n";
    int num_odds = 0;
    for(int i = 0; i < num_elements; i++)
    {
        if(arr[i] % 2 != 0)
        {
            num_odds++;
        }
    }
    return_num_odds = num_odds; // Return the number of odds by reference

    cout << "\tAllocating a new array based on the number of odd values in the original array...\n";
    return_arr = new int[num_odds];
    int return_arr_idx = 0;
    for(int i = 0; i < num_elements; i++)
    {
        if(arr[i] % 2 != 0)
        {
            return_arr[return_arr_idx] = arr[i]; 
            return_arr_idx++;
        }
    }

    PrintElements(return_arr, return_num_odds);
}

int main() 
{
	cout << "########" << endl;
    cout << "Problem One" << endl;
    cout << "########" << endl;
    // read how many number of elements you want to create
    int n;
    
    while(true)
    {
        cout << "Please enter number of elements: ";
        cin >> n;
        
        if (!cin)
        {
            cerr << "ERR: Invalid input. \n\tPlease enter a integer number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        if(n <= 0)
        {
            cout << "ERR: Invaild input. \n\t≤ 0 is not valid.\n";
        }
        else
        {
            break;
        }
    }


    // Use function ReadElements() to read array (arr) from the user with given number of elements
    // define new empty array dynamically with n number as int *arr = new int[n];
    // write your code here
    int* A = new int[n];

    ReadElements(A, n);


    // Use function PrintElements() that can print the entered array
    // write your code here
    cout << "Printing Array..." << endl;
    PrintElements(A, n);


    // Use function PrintElementsRev() that can print the array in reverse order
    // write your code here
    cout << "Printing Reverse Array..." << endl;
    PrintElementsRev(A, n);


    // Use function OddsOnly that can print only the odd elements of the user array
    // define a null pointer *e to use it with OddsOnly function
    // and int m equal zero
    // write your code here
    // you can use NULL here or nullptr for *e


    int* e = nullptr; // null pointer
    int m = 0; // number of odd elements

    // print odds array
    cout << "Printing Odds Only Array..." << endl;
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
    for (int i = 0; i < N; i++)
    {
        arr[i] = rand() % 100;
    }
    
    // Display the original array
    std::cout << "Original Array: ";
    PrintElements(arr, N);
    std::cout << std::endl;


    std::cout << "Enter a value to search for: ";
    int searchValue;
    while(true)
    {
        std::cin >> searchValue;

        if(!cin)
        {
            cerr << "ERR: Invalid input. \n\tPlease enter a integer number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        break;
    }

    bool found = false;
    int index = -1; // To store the index of the found value

    // Linear search algorithm
    //implement linear search algorithms
    for(int i = 0; i < N; i++)
    {
        if(arr[i] == searchValue)
        {
            found = true;
            index = i;
            break;
        }
    }

    if (found)
    {
        std::cout << "The value " << searchValue << " is found at index " << index << "." << std::endl;
    }
    else
    {
        std::cout << "The value " << searchValue << " is not found in the array." << std::endl;
    }
    
    cout << "########" << endl;
    cout << "Problem Three" << endl;
    cout << "########" << endl;

    int num1 = 0, num2 = 0;
    std::cout << "Enter the first integer: ";
    while(true)
    {
        std::cin >> num1;

        if(!cin)
        {
            cerr << "ERR: Invalid input. \n\tPlease enter a integer number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        break;
    }

    std::cout << "Enter the second integer: ";
    while(true)
    {
        std::cin >> num2;

        if(!cin)
        {
            cerr << "ERR: Invalid input. \n\tPlease enter a integer number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        break;
    }

    std::cout << "Before swapping: num1 = " << num1 << ", num2 = " << num2 << std::endl;

    // Call the swapValues function to swap the values of num1 and num2 using pointers
    //define swap value function before main function
    swapValues(&num1, &num2);

    // Display the values after swapping
    std::cout << "After swapping: num1 = " << num1 << ", num2 = " << num2 << std::endl;
}

