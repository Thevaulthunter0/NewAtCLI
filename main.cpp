#include <iostream>
#include <string>
#include <algorithm>

//Header
std::string toLowerCase(std::string text);
void helpOption();
void rememberOption();
void makeOption();
void todoOption();

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
    if(argc <= 1) //No argument was given
    {
        void helpOption();
        return 1;
    }
    else {
        std::cout << "Some argument was given." << std::endl;
        std::string option = toLowerCase(argv[1]); 
        if(option == "-help")
        {
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
            makeOption();
            return 1;
        }
        else{
            helpOption();
            return 1;
        }
        return 1;
    }

    return 0;
}

void helpOption(){
    std::cout << "Help of NewAtCLI\n";
    std::cout << "Usage : NewAtCLI [Option] [argument]\n";
    std::cout << "Options : \n";
    std::cout << "-help         Display this help message.\n";
    std::cout << "-remember     Display the list of command you whant to remember.\n";
    std::cout << "-make         Quickly create a folder and a file to start programming!\n";
    std::cout << "-todo         Display your todo list.\n";
}

void rememberOption(){
    std::cout<< "Remember option.";
}

void makeOption(){
    std::cout<< "make option.";
}

void todoOption(){
    std::cout<< "todo option.";
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