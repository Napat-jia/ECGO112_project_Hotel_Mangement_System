#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include "NODE.h"

using namespace std ;

NODE::NODE(string a,int b,string c, int d){
    username = a;
    n_person = b;
    room_type = c;
    night = d;
    next = NULL;
    room_id = 0 ;
    service = 0;
}


NODE::~NODE(){
    
    if(room_id==0){
        ofstream myFile("NODE_in_Q.csv",a); //w
        // Send data to the stream
        myFile << username <<","<< n_person <<"," << room_type <<"," << night<<endl; 
        // Close the file
        myFile.close();
    }

    else{
        ofstream myFile("NODE_in_hotel.csv",a); //w
        // Send data to the stream
        myFile << username <<","<< n_person <<"," << room_type <<night<<endl; 
        // Close the file
        myFile.close();
    }

}