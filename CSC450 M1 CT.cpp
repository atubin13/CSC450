/* Create a simple C++ console application using Eclipse IDE that will accomplish the following:
First Name,
Last Name,
Street Address
City
Zip code
Prints the following information for a fictional person:*/

#include <iostream>
#include <string>

using namespace std;

int main(){
    // Declare variables to store information
    string firstName, lastName, streetAddress, city;
    int zipCode;

    // Prompt for details
    cout << "Enter First Name: ";
    getline(cin, firstName);

    cout << "Enter Last Name: ";
    getline(cin, lastName);

    cout << "Enter Street Address: ";
    getline(cin, streetAddress);

    cout << "Enter City: ";
    getline(cin, city);

    cout << "Enter Zip Code: ";
    cin >> zipCode;

    // Print information gathered
    cout << "\nFictional Person's Information:\n";
    cout << "First Name: " << firstName << endl;
    cout << "Last Name: " << lastName << endl;
    cout << "Street Address: " << streetAddress << endl;
    cout << "City: " << city << endl;
    cout << "Zip Code: " << zipCode << endl;

    return 0;
}