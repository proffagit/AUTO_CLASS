#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <unordered_set> // Added for jaccardSimilarity function
#include <algorithm>




// STUBBS
std::vector<std::string> readWordsFromFile(const std::string& filename);
float jaccardSimilarity(const std::vector<std::string>& set1, const std::vector<std::string>& set2);
float compareWordContexts(std::string comparison_word1, std::string comparison_word2, std::string large_text_data_file_path);



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






/*******************************************************************************
 * JACCARD SIMILARITY COEFFICIENT
 * Calculates the Jaccard similarity coefficient between two vectors of strings.
 * Returns a float value between 0 and 1, where 1 indicates identical sets.
 ******************************************************************************/
float jaccardSimilarity(const std::vector<std::string>& set1, const std::vector<std::string>& set2) {
    std::unordered_set<std::string> union_set;
    std::unordered_set<std::string> intersection_set;

    // Add all elements to the union set
    for (const auto& elem : set1) union_set.insert(elem);
    for (const auto& elem : set2) union_set.insert(elem);

    // Find intersection
    for (const auto& elem : set1) {
        if (std::find(set2.begin(), set2.end(), elem) != set2.end()) {
            intersection_set.insert(elem);
        }
    }

    // Calculate Jaccard similarity coefficient
    return static_cast<float>(intersection_set.size()) / union_set.size();
}




float compareWordContexts(std::string comparison_word1, std::string comparison_word2, std::string large_text_data_file_path) {

    std::vector<std::string> words = readWordsFromFile(large_text_data_file_path);


    std::vector<std::string> similar1;
    std::vector<std::string> similar2;

    std::vector<std::string> similar3;
    std::vector<std::string> similar4;

    /* LOOP THROUGH WORDS */
    for (size_t i = 0; i < words.size(); ++i) {
        // CHECK IF THE WORD EQUALS "find"
        if (words[i] == comparison_word1) {
            // PRINT THE PREVIOUS WORD (IF EXISTS) AND A SPECIAL MESSAGE

            /* std::string wrd1 = words[i-1];
            std::string wrd2 = words[i+1]; */

            /* CHECK FOR UNIQUE WORDS BEFORE AND AFTER*/
            if (std::find(similar1.begin(), similar1.end(), words[i-1]) == similar1.end()) {
                similar1.push_back(words[i-1]);
            }

            if (std::find(similar2.begin(), similar2.end(), words[i+1]) == similar2.end()) {
                similar2.push_back(words[i+1]);
            }

        }

        if (words[i] == comparison_word2) {
            // PRINT THE PREVIOUS WORD (IF EXISTS) AND A SPECIAL MESSAGE

            /* std::string wrd1 = words[i-1];
            std::string wrd2 = words[i+1]; */

            /* CHECK FOR UNIQUE WORDS BEFORE AND AFTER*/
            if (std::find(similar3.begin(), similar3.end(), words[i-1]) == similar3.end()) {
                similar3.push_back(words[i-1]);
            }

            if (std::find(similar4.begin(), similar4.end(), words[i+1]) == similar4.end()) {
                similar4.push_back(words[i+1]);
            }

           // print(words[i-1], words[i], words[i+1]);
            
        }

    }

    float res1 = jaccardSimilarity(similar1, similar3);
    float res2 = jaccardSimilarity(similar2, similar4);

    return (res1+res2)/2;


}


