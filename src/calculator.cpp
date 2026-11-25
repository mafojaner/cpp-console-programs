// Menu-driven calculator
// Integer arithmetic (add, subtract, multiply, divide, modulus) plus a
// digit-to-binary conversion. Loops until the user chooses to exit, and
// recovers from non-numeric input instead of falling into an error state.

#include <iostream>
#include <limits>
using namespace std;

// Function to convert a number (0-9) to binary
string intToBinary(int n) {
    if (n < 0 || n > 9)
        return "Error: Can only convert digits 0-9 to binary.";

    string binary = "";
    for (int i = 3; i >= 0; --i) {
        binary += (n & (1 << i)) ? '1' : '0';
    }
    return binary;
}

int main() {
    int choice;

    do {
        cout << "\n--- Simple Calculator ---\n";
        cout << "1. Addition (+)\n";
        cout << "2. Subtraction (-)\n";
        cout << "3. Multiplication (*)\n";
        cout << "4. Division (/)\n";
        cout << "5. Modulus (%)\n";
        cout << "6. Convert digit (0-9) to binary\n";
        cout << "0. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;

        // Handle invalid input (non-numeric)
        if (cin.fail()) {
            cin.clear(); // clear error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input
            cout << "Invalid input! Please enter a number.\n";
            continue;
        }

        if (choice >= 1 && choice <= 5) {
            int a, b;
            cout << "Enter first integer: ";
            cin >> a;
            cout << "Enter second integer: ";
            cin >> b;

            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input! Integers only.\n";
                continue;
            }

            switch (choice) {
            case 1:
                cout << "Result: " << a << " + " << b << " = " << a + b << endl;
                break;
            case 2:
                cout << "Result: " << a << " - " << b << " = " << a - b << endl;
                break;
            case 3:
                cout << "Result: " << a << " * " << b << " = " << a * b << endl;
                break;
            case 4:
                if (b == 0)
                    cout << "Error: Division by zero is not allowed.\n";
                else
                    cout << "Result: " << a << " / " << b << " = " << a / b << endl;
                break;
            case 5:
                if (b == 0)
                    cout << "Error: Modulus by zero is not allowed.\n";
                else
                    cout << "Result: " << a << " % " << b << " = " << a % b << endl;
                break;
            }
        }
        else if (choice == 6) {
            int digit;
            cout << "Enter a digit (0-9): ";
            cin >> digit;

            if (cin.fail() || digit < 0 || digit > 9) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input! Please enter a digit between 0 and 9.\n";
            }
            else {
                cout << "Binary of " << digit << " is: " << intToBinary(digit) << endl;
            }

        }
        else if (choice == 0) {
            cout << "Calculator exiting... Goodbye!\n";
        }
        else {
            cout << "Invalid choice. Please select from the menu.\n";
        }

    } while (choice != 0);

    return 0;
}
