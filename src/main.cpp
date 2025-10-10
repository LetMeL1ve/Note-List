#include <iostream>
#include "note.h"
#include "notes_manager.h"
#include <filesystem>

int main(){
    // Path variable saves path to the notes.txt file.
    std::string path = std::filesystem::current_path().string() + "\\notes.txt";
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
            // Showing notes realization.
            break;
        case 4:
            return;
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
