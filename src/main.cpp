//      ¯\_(ツ)_/¯
// g++ main.cpp -o out.exe
#include <iostream>
#include <vector>
#include <string>

#include "heavy.cpp" // --



 // MAIN FUNCTION
int main() {

    
    std::string filename = "../../en_wiki_31M_token_196k_words.txt";
    std::vector<std::string> words = readWordsFromFile(filename);
    
    // Print the words (for demonstration purposes)
    
    for (const auto& word : words) {
        //std::cout << word << std::endl;
        print(word);
    }
   
    
    return 0;
}

