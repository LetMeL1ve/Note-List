#include <iostream>
#include "note.h"
#include <filesystem>
#include <fstream>


void add_note(Note* note, std::string* path);

int main(){
    // Path variable saves path to the notes.txt file.
    std::string path = std::filesystem::current_path().string() + "\\notes.txt";

}

// This function saves note to the file.
void add_note(Note* note, std::string* path) {
    std::ofstream fout;
    fout.open(*path, std::ios_base::app);
    std::string line = note->to_string();
    fout << line << '\n';
    fout.close();
}
