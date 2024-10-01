#include <vector>
#include <string>
#include <fstream>
#include <iostream>

// stubbs
std::vector<std::string> readWordsFromFile(const std::string& filename);




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


/*******************************************************************************
 * USAGE
 * std::string filename = "../../en_wiki_31M_token_196k_words.txt";
 * std::vector<std::string> words = readWordsFromFile(filename);
 ******************************************************************************/
std::vector<std::string> readWordsFromFile(const std::string& filename) {
    std::vector<std::string> words;
    std::ifstream file(filename);
    std::string word;

    if (file.is_open()) {
        while (file >> word) {
            words.push_back(word);
        }
        file.close();
    } else {
        std::cerr << "Unable to open file: " << filename << std::endl;
    }

    return words;
}

