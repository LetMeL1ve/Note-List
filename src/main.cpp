#include <iostream>
#include "note.h"
#include <filesystem>
#include <fstream>


void add_note(Note* note, std::string* path);

void delete_note(unsigned int id, std::string* path);

int main(){
    // Path variable saves path to the notes.txt file.
    std::string path = std::filesystem::current_path().string() + "\\notes.txt";
    delete_note(1, &path);
}

// This function saves note to the file.
void add_note(Note* note, std::string* path) {
    std::ofstream fout;
    fout.open(*path, std::ios_base::app);
    std::string line = note->to_string();
    fout << line << '\n';
    fout.close();
}

// This function deletes note by its id.
void delete_note(unsigned int id, std::string* path) {
    std::ifstream fin;
    std::ofstream fout;
    std::stringstream buffer;

    // For every line checking if it is the correct one.
    fin.open(*path);

    std::string line;
    while (getline(fin, line)) {
        if (Note::to_note(line).get_id() != id)
            buffer << line << '\n';
    }
    fin.close();

    fout.open(*path);
    fout << buffer.rdbuf();
    fout.close();
}
