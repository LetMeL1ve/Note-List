#include "note.h"

std::string Note::to_string() {
    return text + "##" + std::to_string(id);
}

Note::Note(int _id, std::string _text) : id(_id) {
    if (_text.empty())
       _text = "<< Empty Note >>";
    text = _text;
}