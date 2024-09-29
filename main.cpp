#include <iostream>
#include <string>
#include <filesystem>
#include <fstream>
#include "service/DataService.hpp"

//Header
std::string toLowerCase(std::string text);
void rememberOption();
void makeOption(std::filesystem::path currentPath, std::string folderName, std::string fileName);
void todoOption();
void helpOption();
void helpRemember();
void helpMake();
void helpTodo();

/* List of command to support
NewCli -Option <argument1> <argument2>
$ NewCli -Make <foldername> <filename>
----------------------------------------
$ NewCli -remember
$ NewCli -remember Add <texte>
$ NewCli -remember Remove <id>
$ NewCli -remember Modify <id>
----------------------------------------
$ NewCli -todo 
$ NewCli -todo add <texte> <date>
$ NewCli -todo remove <id>
$ NewCli -todo modify <id>
----------------------------------------
$ NewCli -Help
If no arguments is given, give the same output as -help.

Transform all char in all the input as lowercase.
*/

int main(int argc, char* argv[]){
    if(argc <= 1) //No argument was given, return help
    {
        void helpOption();
        return 1;
    }
    else {
        std::string option = toLowerCase(argv[1]);  //Transform option input to lowercase
        if(option == "-help") 
        {
            if(argc <= 2){
                helpOption();
                return 1;
            }
            else{
                std::string arg1 = toLowerCase(argv[2]);
                if(arg1 == "-remember"){
                    helpRemember();
                    return 1;
                } 
                else if(arg1 == "-todo"){
                    helpTodo();
                    return 1;
                }
                else if(arg1 == "-make"){
                    helpMake();
                    return 1;
                }
                else{
                    helpOption();
                    return 1;
                }
            }
            helpOption();
            return 1;
        }
        else if(option == "-remember")  
        {
            rememberOption();
            return 1;
        }
        else if(option == "-todo")
        {
            todoOption();
            return 1;
        }
        else if(option == "-make")
        {
            if(argc != 4)
            {
                helpMake();
                return 1;
            }
            else{
                std::filesystem::path currentPath = std::filesystem::current_path();
                std::string arg1 =  toLowerCase(argv[2]);
                std::string arg2 =  toLowerCase(argv[3]);
                makeOption(currentPath, arg1, arg2);
            } 
            return 1;
        }
        else{   //Option wasnt a choice return help
            helpOption();
            return 1;
        }
        return 1;
    }

    return 0;
}

void rememberOption(){
    DataService service = DataService();
    std::cout<< "Remember option.";             /////////////////////ICI////////////////////////////FAIRE AFFICHER getAllRemember()
    std::string text = service.getAllRemember();
    std::cout << text << std::endl;
}

void todoOption(){
    std::cout<< "todo option.";
}

void makeOption(std::filesystem::path currentPath, std::string folderName, std::string fileName){
    std::filesystem::path folderDir = currentPath / folderName;
    if(!std::filesystem::exists(folderDir)){
        std::filesystem::create_directories(folderDir);
        std::cout << "Directory create at : " << folderDir << std::endl;
    } 
    else {
        std::cout << "Directory already exists.";
        return;
    }

    std::filesystem::path fileDir = folderDir / fileName;
    std::ofstream file(fileDir);
}

//Description : Transform all character of a string to lowercase
//Input : std::string
//Output : std::string 
std::string toLowerCase(std::string text){
    std::string str_return = text;
    for(int i = 0; i < std::size(text); i++)
    {
        str_return[i] = (char)std::tolower(text[i]);
    }
    return str_return;
}

//All the help display call
void helpOption(){
    std::cout << "************************************************************************************\n";
    std::cout << "Help of NewAtCLI\n";
    std::cout << "Usage : NewAtCLI [Option] [argument]\n";
    std::cout << "For a list of possible arguments for a certain option : NewAtCLI -help [Option].\n";
    std::cout << "Options : \n";
    std::cout << "-help         Display this help message.\n";
    std::cout << "-remember     Display the list of command you whant to remember.\n";
    std::cout << "-make         Quickly create a folder and a file to start programming!\n";
    std::cout << "-todo         Display your todo list.\n";
    std::cout << "************************************************************************************\n";
}

void helpRemember(){
    std::cout << "************************************************************************************\n";
    std::cout << "Help -remember\n";
    std::cout << "Usage : NewAtCLI -remember [argument]\n";
    std::cout << "Arguments : \n";
    std::cout << "add [command]    Enter the command and explication you whant to remember.\n";
    std::cout << "remove [id]      Enter the id of the command you whant to remove\n";
    std::cout << "modify [id]      Enter the id of the the command you whant to modify\n";
    std::cout << "************************************************************************************\n";
}

void helpMake(){
    std::cout << "************************************************************************************\n";
    std::cout << "Help -make\n";
    std::cout << "Usage : NewAtCLI -make [folder name] [file name]\n";
    std::cout << "************************************************************************************\n";
}

void helpTodo(){
    std::cout << "************************************************************************************\n";
    std::cout << "Help -todo\n";
    std::cout << "Usage : NewAtCLI -todo [argument1] [argument2] [argument3]\n";
    std::cout << "Arguments : \n";
    std::cout << "add [task] [Date]     Create a new task with a date.\n";
    std::cout << "remove [id]           Remove a task with his id.\n";
    std::cout << "modify [id]           Modify a task with his id.\n";
    std::cout << "************************************************************************************\n";
}