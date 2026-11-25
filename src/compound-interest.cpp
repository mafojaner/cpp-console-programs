// Compound interest calculator
// Takes a principal, an annual rate and a term, works out the final amount,
// and optionally prints a year-by-year breakdown. Every input is validated
// before it is used. Amounts are in rands.

#include <iostream>
#include <iomanip>
#include <cmath>
#include <limits>
using namespace std;

// Function to get validated positive double input
double getValidatedDouble(string prompt) {
    double value;
    while (true) {
        cout << prompt;
        cin >> value;

        if (cin.fail() || value <= 0) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a positive number.\n";
        }
        else {
            return value;
        }
    }
}

// Function to get validated yes/no input
char getYesOrNo(string prompt) {
    char choice;
    while (true) {
        cout << prompt << " (y/n): ";
        cin >> choice;
        choice = tolower(choice);
        if (choice == 'y' || choice == 'n') {
            return choice;
        }
        else {
            cout << "Invalid choice. Please enter 'y' or 'n'.\n";
        }
    }
}

int main() {
    cout << "=== Compound Interest Calculator ===\n\n";

    // Get validated inputs
    double P = getValidatedDouble("Enter the principal amount (R): ");
    double r = getValidatedDouble("Enter the annual interest rate (in %): ") / 100;
    double t = getValidatedDouble("Enter the time in years: ");

    // Calculate compound interest
    double A = P * pow(1 + r, t);

    cout << fixed << setprecision(2);
    cout << "\nFinal amount after " << t << " years: R" << A << endl;

    // Ask if user wants a yearly breakdown
    char showBreakdown = getYesOrNo("Do you want a yearly breakdown?");
    if (showBreakdown == 'y') {
        cout << "\nYearly Breakdown:\n";
        cout << "-----------------\n";
        for (int year = 1; year <= t; year++) {
            double yearAmount = P * pow(1 + r, year);
            cout << "Year " << year << ": R" << yearAmount << endl;
        }
    }

    cout << "\nThank you for using the calculator!\n";
    return 0;
}
