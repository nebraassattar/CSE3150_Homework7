#include "FileReader.h"
#include "FileWriter.h"
#include "WarGame.h"
#include <iostream>
#include <string>
 
int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: war_game <input.csv> <output.csv>\n";
        return 1;
    }
 
    const std::string inputPath  = argv[1];
    const std::string outputPath = argv[2];
 
    Deck deck;
    try {
        deck = FileReader::readDeckFromCSV(inputPath);
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
        return 1;
    }
 
    FileWriter writer(outputPath);
 
    WarGame game(std::move(deck));
 
    return game.run(writer);
}
