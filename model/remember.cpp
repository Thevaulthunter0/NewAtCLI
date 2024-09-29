#include <iostream>
#include "remember.hpp"

Remember::Remember(int id, std::string text){
    Id = id;
    Text = text;
}

int Remember::getId(){
    return Id;
}

void Remember::setId(int newId){
    Id = newId;
}

std::string Remember::getText(){
    return Text;
}

void Remember::setText(std::string newText){
    Text = newText;
} 

std::string Remember::toString(){
    std::string def = "| " + std::to_string(getId()) + " |  " + getText() + "\n";
    return def; 
}

std::string Remember::formatTo(){
    std::string format = std::to_string(getId()) + " " + getText();
    return format;
}