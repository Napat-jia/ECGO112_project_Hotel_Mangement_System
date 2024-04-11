#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include "NODE.h"

using namespace std ;

NODE::NODE(string user,string type){


    username = user;
    room_type = type ;
    next =NULL;

}

NODE::~NODE(){
    
    if
    ofstream myFile("NODE_in_Q.csv"); //w
    // Send data to the stream
    myFile << username <<","<< n_person <<"," << room_type <<endl; 
    // Close the file
    myFile.close();

}