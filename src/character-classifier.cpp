// Character classifier
// Reads a single character and reports what kind it is: uppercase letter,
// lowercase letter, digit, whitespace, or a special character.

#include <iostream>
using namespace std;

int main()
{
    char temp;
    cout << "Enter any character: ";
    cin >> temp;

    if (isupper(temp))
    {
        cout << "Uppercase letter." << endl;
    }
    else if (islower(temp))
    {
        cout << "Lowercase letter." << endl;
    }
    else if (isdigit(temp))
    {
        cout << "Digit." << endl;
    }
    else if (isspace(temp))
    {
        cout << "White-space character." << endl;
    }
    else if (!isalpha(temp) && !isdigit(temp) && !isspace(temp))
    {
        // Not a letter, not a digit, not whitespace.
        cout << "Special character." << endl;
    }

    return 0;
}
