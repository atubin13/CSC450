// Console application to write a program that will take two string inputs from a user
// and cocatenate the strings, take input 3 times for varying string lengths

#include <iostream>>
#include <string>

int main() {
    std::string str1, str2, result;

    // Loop for three inputs
    for (int i = 0; i < 3; i++) {
        std::cout << "Please provide the first string: ";
        std::getline(std::cin, str1);

        std::cout << "Please provide the second string: ";
        std::getline(std::cin, str2);

        // Cocatenate
        result = str1 + " " + str2;

        //Output
        std::cout << "Here is your cocatenated string: " << result << std::endl << std::endl ;
    }

    return 0;
}