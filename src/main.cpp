#include <iostream>
#include <vector>
#include "notes_manager.h"
#include <filesystem>

int get_number(std::string* message);

void setup(std::string* path, std::vector<Note>* notes);

unsigned int get_minimal_id(std::vector<Note>* notes);

int main() {
    // Path variable saves path to the notes.txt file.
    std::string path;
    // Vector that saves every existing note.
    std::vector<Note> notes;

    setup(&path, &notes);

    while (true) {
        std::string message = "Enter operation:\n| 1.Add note.\n| 2.Delete note.\n| 3.See all notes.\n| 4.Quit.\n";
        int operation = get_number(&message);
        switch (operation)
        {
        case 1:
            // Adding note realization.
            break;
        case 2:
            // Deleting note realization.
            break;
        case 3:
            // Showing notes  realization.
            break;
        case 4:
            return 0;
        default:
            break;
        }
    }
}

int get_number(std::string* message) {
    int number;
    while (true) {
        std::cout << *message;
        if (std::cin >> number)
            return number;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

void setup(std::string* path, std::vector<Note>* notes) {
    *path = std::filesystem::current_path().string() + "\\notes.txt";
    notes_manager::get_all_notes(notes, path);
}

// This function gets minimal unical id for new note.
unsigned int get_minimal_id(std::vector<Note>* notes) {
    for (int i = 0; i != notes->size(); ++i) {
        if ((*notes)[i].get_id() - 1 > i) {
            return i + 1;
        }
    }
    return -1;
}
