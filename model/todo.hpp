//todo.hpp

#ifndef TODO_H
#define TODO_H

#include <iostream>

class Todo {
    private:
        int Id;
        std::string Text;
        std::string Date;
        bool Done;
    public :
        Todo(int id, std::string text, std::string date);
        int getId();
        void setId(int newId);
        std::string getText();
        void setText(std::string newText);
        std::string getDate();
        void setDate(std::string newDate);
        bool getDone();
        void setDone();
        std::string toString();
};

#endif