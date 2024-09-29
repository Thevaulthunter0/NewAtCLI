#include <iostream>
#include <filesystem>
#include <fstream>
#include <vector>
#include "DataService.hpp"
#include "../model/remember.hpp"
#include "../model/todo.hpp"

void DataService::getAllRemember(){
    std::cout << " ---------------------------" << std::endl;
    std::cout << "| id |  Command to remember" << std::endl;
    std::cout << " ---------------------------" << std::endl;
    std::ifstream file(DataService::remember_path);
    std::string line;

    if(file.is_open()){
        while(std::getline(file, line)){
            size_t whiteSpacePos = line.find(' ');
            int id =std::stoi(line.substr(0,whiteSpacePos));
            std::string text = line.substr(whiteSpacePos);
            Remember rem = Remember(id, text);
            std::cout << rem.toString();
        }
        file.close();
    }
    else {
        std::cout << "Error" << std::endl;
    }
    std::cout << " ---------------------------" << std::endl;
}

void DataService::AddRemember(std::string text){
    int* p_id = getLastIdRemember();
    int id;
    if(p_id == nullptr)
    {
        id = 0;
    }
    else{
        id = *p_id;
    }

    delete p_id;
    p_id = nullptr;

    Remember remember = Remember(id + 1,text);
    Write(DataService::remember_path, remember.formatTo());
    std::cout << "Line added!" << std::endl;
}

void DataService::RemoveRemember(int searchId){
    std::ifstream file(DataService::remember_path);
    std::string line;
    std::vector<std::string> lines;
    if(file.is_open()){
        while(std::getline(file,line)){
            size_t whiteSpacePos = line.find(' ');
            int id = std::stoi(line.substr(0,whiteSpacePos));
            if(searchId != id)
            {
                lines.push_back(line);
            }
        }
        file.close();
        std::ofstream file(DataService::remember_path, std::ios::trunc);
        file.close();
    }
    else {
        std::cout << "Error" << std::endl;
    }
    for(int i = 0; i < lines.size(); i++){
        Write(DataService::remember_path, lines[i]);
    }
    std::cout << "Id removed" << std::endl;
}

void DataService::ModifyRemember(int searchId, std::string newText){
    std::ifstream file(DataService::remember_path);
    std::string line;
    std::vector<std::string> lines;
    if(file.is_open()){
        while(std::getline(file,line)){
            size_t whiteSpacePos = line.find(' ');
            std::string id = line.substr(0,whiteSpacePos);
            if(searchId == std::stoi(id)){
                std::string modifiedLine = id + " " + newText;
                lines.push_back(modifiedLine);
            }
            else{
                lines.push_back(line);
            }
        }
        file.close();
        std::ofstream file(DataService::remember_path, std::ios::trunc);
        file.close();
    }
    else{
        std::cout << "Error" << std::endl;
    }
    for(int i = 0; i < lines.size(); i++){
        Write(DataService::remember_path, lines[i]);
    }
    std::cout<< "Id modified" << std::endl;
}

Remember* DataService::getRemember(int searchId){
    std::string display {};
    std::ifstream file(DataService::remember_path);
    if(file.is_open()){
            std::string line;
        while(std::getline(file,line)){  
            size_t whiteSpacePos = line.find(' ');
            int id = std::stoi(line.substr(0,whiteSpacePos));
            if(searchId == id)
            {
                std::string text = line.substr(whiteSpacePos);
                file.close();
                return new Remember(id,text);
            }
        }
        file.close();
    }
    else {
        std::cout << "Error" << std::endl;
    }
    return nullptr;
}

int* DataService::getLastIdRemember(){
    int* p_id{nullptr};
    std::ifstream file(DataService::remember_path);
    std::string lastLine;
    if(file.peek() == std::ifstream::traits_type::eof())
    {
        return nullptr;
    }
    else{
        if(file.is_open()){
        std::string line;
        size_t whiteSpacePos = line.find(' ');
        while(std::getline(file,line)){
            lastLine = line; 
        }
        int* p_id = {new int(std::stoi(lastLine.substr(0,whiteSpacePos)))};
        return p_id;
        }   
        else {
            std::cout << "Error" << std::endl;
        }
    }
    return nullptr;
}

void DataService::Write(std::filesystem::path path, std::string line)
{
    std::ofstream file(path, std::ios::app);
    if(file.is_open()){
        file << line << std::endl;
        file.close();
    }
    else {
        std::cout << "Error" << std::endl;
    }
}