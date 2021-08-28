#include "MorseCode.h"

std::map<std::string, char> MorseCode::build_reversed_map(const std::map<char, std::string>& map) const {
    std::map<std::string, char> result;
    for(const auto & i : alphabet) {
        result[i.second] = i.first;
    }
    return result;
}

std::vector<std::string> MorseCode::str_to_vector_of_string(const std::string& word) {
    std::string str;
    std::stringstream ss(word);
    std::vector<std::string> vec;
    while (std::getline(ss, str, ' ')) {
        vec.emplace_back(str);
    }
    return vec;
}

std::string MorseCode::convert_to_morse_code(const std::string& word) const {
    std::string result;
    for(const char & i : word) {
        auto morse_string = alphabet.find(std::toupper(i));
        if(morse_string != alphabet.end()) {
            result += morse_string->second + " ";
        }
    }
    return result;
}

std::string MorseCode::convert_to_ascii_code(const std::string& word) const {
    std::string result;
    std::vector<std::string> vec = MorseCode::str_to_vector_of_string(word);
    for(const auto & i : vec) {
        auto morse_string = morse_to_ascii.find(i);
        if (morse_string != morse_to_ascii.end()) {
            result += morse_string->second;
        }
    }
    return result;
}

void MorseCode::from_ascii_to_morse() {
    MorseCode c1;
    std::string word;
    std::cout << "Text: ";
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, word);
    std::cout << c1.convert_to_morse_code(word) << '\n';
}

void MorseCode::from_morse_to_ascii() {
    MorseCode c1;
    std::string word;
    std::cout << "Morse Code: ";
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, word);
    std::cout << c1.convert_to_ascii_code(word);
}

std::string MorseCode::read_file(const std::string& filename) {
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

void MorseCode::save_data(const std::string& word, const std::string& filename) {
    std::ofstream file;
    file.open(filename, std::ios::app);
    if(!file.is_open()) {
        throw std::runtime_error("ERROR\n");
    }
    else {
        file << word << '\n';
    }
    std::cout << "Saved successfully" << '\n' << "You saved your text in: " << filename << '\n';
}

void MorseCode::display() {
    std::cout << "===================================================\n";
    std::cout << "****** Morse Code Translator - Morse Decoder ******\n";
    std::cout << "===================================================\n";
    std::cout << "1. Load Ascii Code from file\n";
    std::cout << "2. Load Morse Code from file\n";
    std::cout << "3. Convert Ascii Code from file and save to another file\n";
    std::cout << "4. Convert Morse Code from file and save to another file\n";
    std::cout << "5. Convert your Ascii Code to Morse Code\n";
    std::cout << "6. Convert your Morse Code to Ascii Code\n";
    std::cout << "0. Exit\n";
}

void MorseCode::menu() {
    char choice{};
    std::cout << "\nEnter Your Choice: ";
    std::cin >> choice;
    switch (choice) {
        case '1': {
            MorseCode c1;
            std::string ascii_to_morse = c1.read_file("main_file.txt");
            std::cout << ascii_to_morse << '\n';
            break;
        }
        case '2': {
            MorseCode c1;
            std::string morse_to_ascii = c1.read_file("coded_file.txt");
            std::cout << morse_to_ascii << '\n';
            break;
        }
        case '3': {
            MorseCode c1;
            std::string asciiToMorse = c1.convert_to_morse_code(MorseCode::read_file("main_file.txt"));
            MorseCode::save_data(asciiToMorse, "ascii_to_morse.txt");
            break;
        }
        case '4': {
            MorseCode c1;
            std::string asciiToMorse = c1.convert_to_ascii_code(MorseCode::read_file("coded_file.txt"));
            MorseCode::save_data(asciiToMorse, "morse_to_ascii.txt");
            break;
        }
        case '5': {
            MorseCode::from_ascii_to_morse();
            break;
        }
        case '6': {
            MorseCode::from_morse_to_ascii();
            break;
        }
        case '0': {
            exit(0);
        }
        default: {
            std::cout << "Wrong Choice!";
            break;
        }
    }
}