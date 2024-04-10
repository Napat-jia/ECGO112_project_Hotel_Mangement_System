#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std ;

string login(){

    vector<string> data;  //vector
    string line,username,password ;
    stringstream ss;

    ifstream myFile("username.csv"); //open file r

    if(!myFile.is_open()) cout << "can not open the file." ;
    
    while (getline (myFile, line)) {
        stringstream ss(line);
        getline(ss,username,',');
        getline(ss,password,',');
        
        data.push_back(username);
        data.push_back(password);
    }

    return data[0] ;

}

int main(){
    
    return 0 ;
}