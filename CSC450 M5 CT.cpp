#include <iostream>
#include <fstream>
#include <string>
#include <algorithm> // for reverse

// Function to reverse the contents of a file and store it in another file
void reverseFileContent(const std::string& inputFileName, const std::string& outputFileName) {
    // Open input file
    std::ifstream inputFile(inputFileName);
    if (!inputFile.is_open()) {
        std::cerr << "Error opening file: " << inputFileName << std::endl;
        return;
    }

    // Read the entire content of the file into a string
    std::string fileContent((std::istreambuf_iterator<char>(inputFile)),
                            std::istreambuf_iterator<char>());
    inputFile.close();

    // Reverse the content
    std::reverse(fileContent.begin(), fileContent.end());

    // Write the reversed content to the output file
    std::ofstream outputFile(outputFileName);
    if (!outputFile.is_open()) {
        std::cerr << "Error opening file: " << outputFileName << std::endl;
        return;
    }
    outputFile << fileContent;
    outputFile.close();
}

int main() {
    std::string userInput;
    std::string inputFileName = "CSC450_CT5_mod5.txt";
    std::string outputFileName = "CSC450-mod5-reverse.txt";

    // Prompt user for input
    std::cout << "Enter some text to append to the file: ";
    std::getline(std::cin, userInput);

    // Append the user's input to the file without overwriting the existing content
    std::ofstream file(inputFileName, std::ios::app);
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << inputFileName << std::endl;
        return 1;
    }
    file << userInput << std::endl; // Append the user's input to the file
    file.close();

    // Call the function to reverse the file content
    reverseFileContent(inputFileName, outputFileName);

    std::cout << "Content appended to " << inputFileName << " and reversed content stored in " << outputFileName << std::endl;

    return 0;
}
