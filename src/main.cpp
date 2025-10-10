#include <iostream>
#include "note.h"
#include <filesystem>
#include <fstream>
#include <vector>

#pragma region Declaration of methods
void add_note(Note* note, std::string* path);

void delete_note(unsigned int id, std::string* path);

Note get_note(unsigned int line_number, std::string* path);

void get_all_notes(std::vector<Note>* notes, std::string* path);

#pragma endregion

int main(){
    // Path variable saves path to the notes.txt file.
    std::string path = std::filesystem::current_path().string() + "\\notes.txt";
}

#pragma region Realization of methods
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

// This fucntion returns one note that is saved on line [line_number].
Note get_note(unsigned int line_number, std::string* path) {
    std::ifstream fin;
    fin.open(*path);

    std::string line;
    for (int i = 0; i <= line_number; ++i) {
        std::getline(fin, line);
    }

    fin.close();
    return Note::to_note(line);
}

// This fucntion saves to the vector [notes] all of notes.
void get_all_notes(std::vector<Note>* notes, std::string* path) {
    std::ifstream fin;
    fin.open(*path);

    std::string line;
    while (std::getline(fin, line)) {
        notes->push_back(Note::to_note(line));
    }

    fin.close();
}
#pragma endregion