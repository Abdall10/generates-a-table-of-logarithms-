#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
using namespace std;

// C++ program that generates a table of logarithms for a range of numbers and bases. This program allows the user to specify the range of numbers and the bases for which to generate logarithm values. The results are displayed in a table format.

void generateLogTable(double start, double end, double step, const vector<double>& bases) {
    cout << fixed << setprecision(4);

    // Print table header
    cout << "Number";
    for (double base : bases) {
        cout << " | log_" << base;
    }
    cout << endl;

    // Print table separator
    cout << "------";
    for (double base : bases) {
        cout << " | " << string(7, '-');
    }
    cout << endl;

    // Calculate and print logarithms
    for (double number = start; number <= end; number += step) {
        cout << setw(6) << number;
        for (double base : bases) {
            if (number > 0 && base > 0 && base != 1) {
                double result = log(number) / log(base);
                cout << " | " << setw(7) << result;
            } else {
                cout << " |   N/A";
            }
        }
        cout << endl;
    }
}

int main() {
    char choice;

    do {
        double start, end, step;
        int baseCount;
        
        cout << "Enter the start of the range: ";
        cin >> start;
        cout << "Enter the end of the range: ";
        cin >> end;
        cout << "Enter the step size: ";
        cin >> step;

        if (start <= 0 || end <= 0 || step <= 0 || start > end) {
            cout << "Invalid input range or step size." << endl;
            continue;  // Skip the rest of the loop and prompt again
        }

        cout << "Enter the number of bases: ";
        cin >> baseCount;

        vector<double> bases(baseCount);
        for (int i = 0; i < baseCount; ++i) {
            cout << "Enter base " << (i + 1) << ": ";
            cin >> bases[i];
        }

        generateLogTable(start, end, step, bases);

        cout << "Do you want to generate another table? (y/n): ";
        cin >> choice;
        
    } while (choice == 'Y' || choice == 'y');

    cout << "Thank you for using the program!" << endl;
    return 0;
}
