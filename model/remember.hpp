//Remember.hpp

#ifndef REMEMBER_H
#define REMEMBER_H

#include <iostream>

class Remember {
    private:
        int Id;
        std::string Text;
    public:
        Remember(int id, std::string text);
        int getId();
        void setId(int newId);
        std::string getText();
        void setText(std::string newText);
        std::string toString();
};

#endif 