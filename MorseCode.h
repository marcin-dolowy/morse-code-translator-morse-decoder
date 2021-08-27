#include <utility>

#include "libs.h"

class MorseCode {
private:
    const std::map<char, std::string> alphabet {
        {'A',  ".-"},       {'B',  "-..."},     {'C',  "-.-."},
        {'D',  "-.."},      {'E',  "."},        {'F',  "..-."},
        {'G',  "--."},      {'H',  "...."},     {'I',  ".."},
        {'J',  ".---"},     {'K',  "-.-"},      {'L',  ".-.."},
        {'M',  "--"},       {'N',  "-."},       {'O',  "---"},
        {'P',  ".--."},     {'Q',  "--.-"},     {'R',  ".-."},
        {'S',  "..."},      {'T',  "-"},        {'U',  "..-"},
        {'V',  "...-"},     {'W',  ".--"},      {'X',  "-..-"},
        {'Y',  "-.--"},     {'Z',  "--.."},     {'0',  "-----"},
        {'1',  ".----"},    {'2',  "..---"},    {'3',  "...--"},
        {'4',  "....-"},    {'5',  "....."},    {'6',  "-...."},
        {'7',  "--..."},    {'8',  "---.."},    {'9',  "----."},
        {'.',  ".-.-.-"},   {',',  "--..--"},   {'?',  "..--.."},
        {'\'', ".----."},   {'!',  "-.-.--"},   {'/',  "-..-."},
        {'(',  "-.--."},    {')',  "-.--.-"},   {'&',  ".-..."},
        {':',  "---..."},   {';',  "-.-.-."},   {'=',  "-...-"},
        {'+',  ".-.-."},    {'-',  "-....-"},   {'_',  "..--.-"},
        {'"',  ".-..-."},   {'$',  "...-..-"},  {'@',  ".--.-."},
        {' ', "/"},         {'\n', "/"}};
    std::map<std::string, char> morse_to_ascii = build_reversed_map(alphabet);

public:
    MorseCode() = default;
    ~MorseCode() = default;

    [[nodiscard]] std::map<std::string, char> build_reversed_map(const std::map<char, std::string>& map) const;
    [[nodiscard]] std::string convert_to_morse_alphabet(const std::string& word) const;
    [[nodiscard]] std::string convert_to_classic_alphabet(const std::string& word) const;

    static void from_ascii_to_morse();
    static void from_morse_to_ascii();
    static std::vector<std::string> str_to_vector_of_string(const std::string& word);
    static std::string read_file(const std::string& filename);
    static void save_data(const std::string& word, const std::string& filename);

};
