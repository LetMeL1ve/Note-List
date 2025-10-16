#include "note.h"
#include <iostream>

std::string Note::to_string() {
    return text + "##" + std::to_string(id);
}

Note Note::to_note(std::string string) {
    unsigned int separator_index = string.find_first_of('#');
    std::string text = string.substr(0, separator_index);
    unsigned int id = stoi(string.substr(separator_index + 2));
    return Note(id, text);
}

Note::Note(int _id, std::string _text) : id(_id) {
    if (_text.empty())
       _text = "<< Empty Note >>";
    text = _text;
}
bool Note::operator<(Note& note) {
    return this->get_id() < note.get_id();
}