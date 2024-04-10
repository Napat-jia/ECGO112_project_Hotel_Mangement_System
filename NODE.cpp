#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include "NODE.h"

using namespace std ;

NODE::NODE(){
    next =NULL;
    username = "pond";
    room_type = "deluxe" ;
    n_person = 1 ;
}

NODE::~NODE(){

    ofstream myFile("NODE_in_Q.csv"); //w
    // Send data to the stream
    myFile << username <<","<< n_person <<"," << room_type <<endl; 
    // Close the file
    myFile.close();

}