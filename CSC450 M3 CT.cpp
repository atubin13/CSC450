#include <iostream>
using namespace std;

int main() {
    // Declare three integer variables
    int num1, num2, num3;

    // Ask the user to input three integer values
    cout << "Enter first integer: ";
    cin >> num1;
    cout << "Enter second integer: ";
    cin >> num2;
    cout << "Enter third integer: ";
    cin >> num3;

    // Dynamically allocate memory for three integer pointers
    int* ptr1 = new int;
    int* ptr2 = new int;
    int* ptr3 = new int;

    // Store the values of the variables in the dynamically allocated memory
    *ptr1 = num1;
    *ptr2 = num2;
    *ptr3 = num3;

    // Display the contents of the variables and the pointers
    cout << "\nValues of the variables:" << endl;
    cout << "Number 1: " << num1 << endl;
    cout << "Number 2: " << num2 << endl;
    cout << "Number 3: " << num3 << endl;

    cout << "\nValues pointed to by the pointers:" << endl;
    cout << "Pointer 1: " << *ptr1 << endl;
    cout << "Pointer 2: " << *ptr2 << endl;
    cout << "Pointer 3: " << *ptr3 << endl;

    // Free the dynamically allocated memory using delete
    delete ptr1;
    delete ptr2;
    delete ptr3;

    // Indicate program ended successfully
    return 0;
}
