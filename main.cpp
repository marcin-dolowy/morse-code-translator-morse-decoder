#include "MorseCode.h"

int main() {
    try {
        MorseCode c1;
        std::string asciiToMorse = c1.convert_to_morse_alphabet(MorseCode::read_file("main_file.txt"));
        std::cout << asciiToMorse;
        std::cout << "\n===================\n";
        std::string morseToAscii = c1.convert_to_classic_alphabet(MorseCode::read_file("coded_file.txt"));
        std::cout << morseToAscii << '\n';
        MorseCode::save_data(asciiToMorse, "asciiToMorse.txt");
        MorseCode::save_data(morseToAscii, "morseToAscii.txt");

    } catch (std::runtime_error& error) {
        std::cout << error.what() << '\n';
    }
}



