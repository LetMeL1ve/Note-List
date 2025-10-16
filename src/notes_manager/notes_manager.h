#include "../note/note.h"
#include <fstream>
#include <vector>
#include <sstream>

namespace notes_manager {
    
void add_note(Note* note, std::string* path);

void delete_note(unsigned int id, std::string* path);

Note get_note(unsigned int line_number, std::string* path);

void get_all_notes(std::vector<Note>* notes, std::string* path);

}