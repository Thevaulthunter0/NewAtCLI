//DataService.hpp
#ifndef DATASERVICE_HPP
#define DATASERVICE_HPP

#include <string>
#include <filesystem>

class DataService {
    std::filesystem::path rememeber_path = "src\\remember.txt" ;
    std::filesystem::path todo_path = "src\\todo.txt";
public:
    std::string getAllRemember();
    std::string getRemember(int id);
};

#endif // DATASERVICE_HPP