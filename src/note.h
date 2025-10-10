#include <string>

class Note {
private:
    const unsigned int id;
    std::string text;

public:
    // Constructor
    Note(int _id, std::string _text);
    
    // Getters
    std::string get_text() { return text; }
    unsigned int get_id() { return id; }

    std::string to_string();
    static Note to_note(std::string string);
};  