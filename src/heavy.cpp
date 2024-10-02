#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <unordered_set> // Added for jaccardSimilarity function

// stubbs
/* std::vector<std::string> readWordsFromFile(const std::string& filename); */

/*******************************************************************************
 * PRINT FUNCTION
 * Mimics Python's print function by printing each argument followed by a space.
 * Supports multiple types of arguments.
 ******************************************************************************/
template<typename T>
void printSingle(const T& arg) {
    std::cout << arg << ' '; // Print single argument
}

template<typename... Args>
void print(const Args&... args) {
    (printSingle(args), ...); // Fold expression to handle multiple arguments
    std::cout << std::endl; // New line at the end
}







