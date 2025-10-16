#include <iostream>
#include <vector>
#include <algorithm>
#include "notes_manager/notes_manager.h"
#include <filesystem>

int get_number(std::string* message);

void setup(std::string* path, std::vector<Note>* notes);

unsigned int get_minimal_id(std::vector<Note>* notes);

void add_note(std::string* path, std::vector<Note>* notes);

void delete_note(std::string* path, std::vector<Note>* notes);

void print_notes(std::vector<Note>* notes);

int main() {
    // Path variable saves path to the notes.txt file.
    std::string path;
    // Vector that saves every existing note.
    std::vector<Note> notes;

    setup(&path, &notes);

    while (true) {
        std::sort(notes.begin(), notes.end());

        std::string message = "Enter operation:\n| 1.Add note.\n| 2.Delete note.\n| 3.See all notes.\n| 4.Quit.\n";
        int operation = get_number(&message);

        switch (operation)
        {
        case 1:
            add_note(&path, &notes);
            break;
        case 2:
            print_notes(&notes);
            delete_note(&path, &notes);
            break;
        case 3:
            print_notes(&notes);
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
    int i = 0;
    for (; i != notes->size(); ++i) {
        if ((*notes)[i].get_id() > i) {
            return i;
        }
    }
    return i;
}

void add_note(std::string* path, std::vector<Note>* notes) {
    std::string text;

    std::cout << "Enter text of note:\n";
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, text);

    unsigned int id = get_minimal_id(notes);
    Note note(id, text);
    // Addind to the note vector.
    notes->push_back(note);
    notes_manager::add_note(&note, path);
}

void delete_note(std::string* path, std::vector<Note>* notes) {
    std::string message = "Enter id:";
    unsigned int id = get_number(&message);
    // Deleting from notes vector.
    auto note_index = find_if(notes->begin(), notes->end(), [id](Note& note){
        return note.get_id() == id;
    });
    notes->erase(note_index);

    notes_manager::delete_note(id, path);
}

void print_notes(std::vector<Note>* notes) {
    for (Note& note : *notes) {
        std::cout << "| " << note.get_id() << ". " << note.get_text() << '\n';
    }
}