//DataService.hpp
#ifndef DATASERVICE_HPP
#define DATASERVICE_HPP

#include <string>
#include <filesystem>
#include "../model/remember.hpp"

class DataService {
    std::filesystem::path remember_path = "src\\remember.txt" ;
    std::filesystem::path todo_path = "src\\todo.txt";
public:
    void getAllRemember();
    void AddRemember(std::string text);
    void RemoveRemember(int id);
    void ModifyRemember(int id, std::string newText);
private:
    Remember* getRemember(int id);
    int* getLastIdRemember();
    void Write(std::filesystem::path path, std::string line);
};

#endif // DATASERVICE_HPP