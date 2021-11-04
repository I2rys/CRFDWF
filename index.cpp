//Dependencies
#include <iostream>
#include <fstream>
#include <dirent.h>

//Workspaces
using namespace std;

//Functions
string readFile(string fileName){
    string fileContent;
    ifstream file(fileName);

    if(file.is_open()){
        string line;

        while (getline(file, line)){
            fileContent += line + "\n";
        }

        file.close();

        return fileContent;
    }else{
        cout << "Unable to open file";
    }
}

string writeFile(string fileName, string fileContent){
    ofstream file(fileName);

    if(file.is_open()){
        file << fileContent;
        file.close();

        return "File successfully written.";
    }else{
        return "Unable to write file";
    }
}

string readDirectory(string directoryName){
    string directoryContent;
    DIR *dir;
    struct dirent *ent;

    if((dir = opendir (directoryName.c_str())) != NULL){
        while((ent = readdir (dir)) != NULL){
            directoryContent += ent->d_name;
            directoryContent += "\n";
        }

        closedir (dir);
    }else{
        return "Unable to open directory";
    }

    return directoryContent;
}

//Main
int main(){
    string results = writeFile("test.txt", "Test :)");
    cout << "Write file: " + results << endl;
    results = readFile("test.txt");
    cout << "Read file: " + results << endl;
    results = readDirectory("../");
    cout << "Read directory: " + results << endl;

    return 0;
}
