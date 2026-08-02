// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 3
// =============================================================================
//
// TASK: Array Statistics Calculator
//
// Write a C++ program that reads a collection of numbers from the user
// and computes key statistical values using separate functions.
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT / OUTPUT EXAMPLE
// -----------------------------------------------------------------------------
//
//   How many numbers? 5
//   Enter number 1: 4
//   Enter number 2: 7
//   Enter number 3: 2
//   Enter number 4: 9
//   Enter number 5: 1
//
//   Results:
//   Sum:     23
//   Average: 4.6
//   Maximum: 9
//   Minimum: 1
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - You MUST implement each calculation in its own function (see scaffold).
// - You may NOT use any standard library functions like accumulate(), max(),
//   or min(). Implement the logic yourself using loops.
// - N must be a positive integer. If the user enters 0 or a negative number,
//   print an error message and stop.
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
using namespace std;

int calculateSum(const int arr[], int n) {
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += arr[i];
    }
    return sum;
}

double calculateAverage(const int arr[], int n) {
    if (n <= 0) return 0.0; // Avoid division by zero
    int sum = calculateSum(arr, n);
    return static_cast<double>(sum) / n;
}

int calculateMaximum(const int arr[], int n) {
    if (n <= 0) return 0; 
    int max = arr[0];
    for (int i = 1; i < n; ++i) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

int calculateMinimum(const int arr[], int n) {
    if (n <= 0) return 0;
    int minimum = arr[0];
    for (int i = 1; i < n; ++i) {
        if (arr[i] < minimum) {
            minimum = arr[i];
        }
    }
    return minimum;
}
int main() {
    int n;
    cout << "How many numbers? ";
    cin >> n;

    if (n <= 0) {
        cout << "Error: Number of elements must be a positive integer." << endl;
        return 1; 
    }

    int* arr = new int[n]; 
    for (int i = 0; i < n; ++i) {
        cout << "Enter number " << (i + 1) << ": ";
        cin >> arr[i];
    }

    int sum = calculateSum(arr, n);
    double average = calculateAverage(arr, n);
    int max = calculateMaximum(arr, n);
    int min = calculateMinimum(arr, n);

    cout << "\nResults:" << endl;
    cout << "Sum:     " << sum << endl;
    cout << "Average: " << average << endl;
    cout << "Maximum: " << max << endl;
    cout << "Minimum: " << min << endl;

    delete[] arr; 
    return 0;
}
