#include <iostream>
#include <filesystem>
#include <fstream>
#include "DataService.hpp"
#include "../model/remember.hpp"
#include "../model/todo.hpp"

std::string DataService::getAllRemember(){
    std::string displayAll {"-------------------------------\n"};
    std::ifstream file(DataService::rememeber_path);
    std::string line;
    if(file.is_open()){
        while(std::getline(file, line)){
            size_t whiteSpacePos = line.find(' ');
            int id =std::stoi(line.substr(0, whiteSpacePos));
            std::string text = line.substr(whiteSpacePos, 1);
            Remember rem = Remember(id, text);
            displayAll += rem.toString();
        }
        file.close();
    }
    else {
        std::cout << "Error" << std::endl;
    }
    displayAll += "--------------------------------------------\n";
    return displayAll;
}

std::string DataService::getRemember(int id){
    
    return " ";
}
