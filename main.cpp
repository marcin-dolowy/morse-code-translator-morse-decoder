#include "MorseCode.h"

int main() {
    try {
/*        std::string text = MorseCode::read_file("main_file.txt");
        MorseCode c1;
        std::cout << text << '\n';
        std::cout << c1.convert_to_morse_alphabet(text) << '\n';*/
        //MorseCode::save_data(c1.convert_to_morse_alphabet(text), "save_data.txt");

        MorseCode c1;
        std::cout << c1.convert_to_morse_alphabet("abc SOS\n hello") << '\n';

    } catch (std::runtime_error& error) {
        std::cout << error.what() << '\n';
    }
}



