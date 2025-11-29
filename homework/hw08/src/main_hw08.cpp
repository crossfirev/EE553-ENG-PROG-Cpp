/*
 * Author: Matthew Lepis
 * Date:   11/22/2025
 *
 * Description:
 *   Implements a fully custom string class (`String`) for EE553 Homework 8,
 *   demonstrating dynamic memory management, deep copying, move semantics,
 *   operator overloading, and manual character-array handling in C++.
 *
 *   Unlike `std::string`, this implementation explicitly manages its own
 *   character buffer using raw pointers and `new[]`/`delete[]`. The class
 *   showcases the “Rule of Five” through properly implemented:
 *     • Default constructor
 *     • Non-default constructor from a C-style string
 *     • Destructor
 *     • Copy constructor
 *     • Move constructor
 *     • Copy assignment operator
 *
 *   The program also implements an overloaded `operator+` for string
 *   concatenation and `operator<<` for formatted output. All operations use
 *   manual loops to reinforce an understanding of pointer-based character
 *   storage and dynamic allocation.
 *
 *   Features:
 *     • Internally stores:
 *         – `int length`    : number of valid characters
 *         – `char* char_array` : dynamically allocated array (null-terminated)
 *
 *     • Constructors:
 *         – Default: creates an empty string (`length = 0`, `char_array = nullptr`)
 *         – From C-string: uses `strlen()` and deep-copies characters
 *         – Copy: allocates its own buffer and duplicates all characters
 *         – Move: transfers ownership of buffer with no allocation
 *
 *     • Operators:
 *         – `operator<<` prints characters directly (length-based)
 *         – `operator+` concatenates two Strings into a new dynamically
 *           allocated String object
 *         – Copy assignment handles self-assignment and cleans up old memory
 *
 *   The main() function:
 *     • Creates multiple `String` objects using different constructors
 *     • Prints each instance to verify correct behavior
 *     • Demonstrates:
 *         – copy construction (`String s3 = s2;`)
 *         – concatenation (`String s4 = s + s2;`)
 *         – move construction (`String s5 = std::move(s4);`)
 *     • Prints the moved-from object to illustrate valid-but-empty state
 *
 *   Notes / Assumptions:
 *     • Moved-from objects are left in a safe, empty state (`nullptr`, length = 0)
 *     • All buffers are null-terminated for clarity and debugging safety
 *     • Assignment does not implement move-assignment, as it was not required
 *     • No reliance on `std::string`—all character handling is manual, as intended
 *
 *   References:
 *     • EE553 Homework 8: Custom String Class
 *     • Lecture material on dynamic memory, copy/move semantics, and operator overloading
 *     • C++ Standard Library reference for `strlen()`, `std::move`, and stream operators
 */

#include <iostream>
#include <cstring>
#include <utility>

class String
{
private:
    int length;
    char* char_array;
public:

    String()
    {
        char_array = nullptr;
        length = 0;
    }
    String(const char* const in_char_array) : length(strlen(in_char_array))
    {
        this->char_array = new char[length + 1];
        for(int i = 0; i < this->length; i++)
        {
            this->char_array[i] = in_char_array[i];
        }
        char_array[length] = '\0';
    }
    ~String()
    {
        delete[] char_array;
    }
    friend std::ostream& operator<<(std::ostream& stream, const String& str)
    {
        for(int i = 0; i < str.length; i++)
        {
            stream << str.char_array[i];
        }
        return stream;
    }
    String(const String& other) : length(other.length)
    {
        this->char_array = new char[other.length + 1];
        for(int i = 0; i < this->length; i++)
        {
            this->char_array[i] = other.char_array[i];
        }
        this->char_array[length] = '\0';
    }
    String(String&& other) : length(other.length), char_array(other.char_array)
    {
        other.char_array = nullptr;
        other.length = 0;
    }
    String& operator=(const String& other)
    {
        // Guard against setting an object equal to itself.
        if (this == &other)
        {
            return *this;
        }

        delete [] char_array;
        
        // check if the assigning object actually has data.
        if(other.char_array == nullptr)
        {
            char_array = nullptr;
            length = 0;
            return *this;
        }
        
        // Setting this object to that object
        length = other.length;
        char_array = new char[length + 1];
        for (int i = 0; i < length; ++i)
        {
            char_array[i] = other.char_array[i];
        }
        char_array[length] = '\0';

        return *this;
    }
    friend String operator+(const String& left_hand, const String& right_hand)
    {
        int cum_sum = left_hand.length + right_hand.length;
        
        String result;
        result.length = cum_sum;
        result.char_array = new char[cum_sum + 1];

        for (int i = 0; i < left_hand.length; i++)
        {
            result.char_array[i] = left_hand.char_array[i];  
        }
        for (int i = 0; i < right_hand.length; i++)
        {
            result.char_array[i + left_hand.length] = right_hand.char_array[i];
        }
        result.char_array[cum_sum] = '\0';

        return result;
    }

};



int main() {
    std::cout << "########" << std::endl;
    std::cout << "Main Problem" << std::endl;
    std::cout << "########" << std::endl;

    // Create String s = abc
    String s = "abc";
    // std::cout s
    std::cout << "s is: " << s << '\n';
    // Create String s = def
    String s2 = "def";
    // std::cout s2
    std::cout  << "s2 is: " << s2 << '\n';
    // create String s3 equal s2
    String s3 = s2; // copy constructor
    // std::cout s3
    std::cout << "s3 is: " << s3 << " copy constructor "<<'\n';
    //    Create String s4 that is assigned to s added to s2
    String s4 = s + s2;  // abcdef // copy constructor
    // std::cout s4
    std::cout << "s4 is: " << s4 << " copy constructor of s + s2"<< '\n';
    // Create s5 and move s4
    String s5 = std::move(s4); // move constructor
    // std::cout s5
    std::cout << "s5 is: " << s5 << '\n';
    std::cout << "std::cout s4 should give you error after move()" << std::endl;
    std::cout << s4 << '\n';
    std::cout << "====[ end ]====" << std::endl;
    std::cout << "               " << std::endl;

    return 0;
}