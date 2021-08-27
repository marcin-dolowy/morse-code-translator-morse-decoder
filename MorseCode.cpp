#include "MorseCode.h"

void MorseCode::print_map(const std::map<const char, const std::string> &map){
    for (const auto & [key, val] : map) {
        std::cout << key << " = " << val << '\n';
    }
}

void MorseCode::print_map_2(const std::map<std::string, char> &map) {
    for(const auto & [key, val] : morse_to_ascii) {
        std::cout << key << " | " << val << '\n';
    }
}

std::string MorseCode::convert_to_morse_alphabet(const std::string& word) const {
    std::string result;
    for(const char & i : word) {
        auto morse_string = alphabet.find(std::toupper(i));
        if(morse_string != alphabet.end()) {
            result += morse_string->second + " ";
        }
    }
    return result;
}

std::string MorseCode::convert_to_classic_alphabet(std::string& word) const {
    return word;
}

std::string MorseCode::read_file(const std::string &filename) {
    std::ifstream file;
    file.open(filename);
    if(!file.is_open()) {
        throw std::runtime_error("FILE NOT FOUND\n");
    }
    std::string text;
    while(!file.eof()) {
        std::getline(file, text);
    }
    return text;
}

void MorseCode::add_text() {
    MorseCode c1;
    std::string word;
    std::getline(std::cin, word);
    std::cout << c1.convert_to_morse_alphabet(word) << '\n';
}

void MorseCode::save_data(const std::string& word, const std::string &filename) {
    std::ofstream file;
    file.open(filename, std::ios::app);
    if(!file.is_open()) {
        throw std::runtime_error("ERROR\n");
    }
    else {
        file << word << '\n';
    }
    std::cout << "Saved successfully ;)" << '\n' << "You saved your text in: " << filename << '\n';
}

std::map<std::string, char> MorseCode::build_reversed_map(const std::map<char, std::string> &map) const {
    std::map<std::string, char> result;
    for(const auto & i : alphabet) {
        result[i.second] = i.first;
    }
    return result;
}


