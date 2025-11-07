#include <iostream>
using namespace std;

 
// Recursive Fibonacci
 
int fibRecursive(int n) {
    // Base cases
    if (n <= 1)
        return n;
    // Recursive case: sum of previous two terms
    return fibRecursive(n - 1) + fibRecursive(n - 2);
}

 
// Non-Recursive (Iterative) Fibonacci
 
int fibIterative(int n) {
    // Base cases
    if (n <= 1)
        return n;

    int a = 0, b = 1, c;
    // Loop to calculate next Fibonacci numbers
    for (int i = 2; i <= n; i++) {
        c = a + b; // next term = sum of previous two
        a = b;     // move forward
        b = c;
    }
    return b; // final result
}

// -------------------------
// Main Function
// -------------------------
int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    cout << "\nUsing Recursive Method:\n";
    cout << "Fibonacci(" << n << ") = " << fibRecursive(n) << endl;

    cout << "\nUsing Non-Recursive (Iterative) Method:\n";
    cout << "Fibonacci(" << n << ") = " << fibIterative(n) << endl;

    return 0;
}
