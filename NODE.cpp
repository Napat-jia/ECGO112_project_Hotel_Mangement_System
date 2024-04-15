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
    food = 0;
    laundry=0;
    shuttle=0;
    extrabed = 0;
}


NODE::~NODE(){
    
    if(room_id==0){
        ofstream myFile("NODE_in_Q.csv",ios::app); //w
        // Send data to the stream
        myFile << username <<","<< n_person <<"," << room_type <<"," << night<<endl; 
        // Close the file
        myFile.close();
    }

    else{
        ofstream myFile("NODE_in_hotel.csv",ios::app); //w
        // Send data to the stream
        myFile << username <<","<< n_person <<"," << room_type <<","<<night<<endl; 
        // Close the file
        myFile.close();
    }

}

NODE* NODE::move_next(){
    return next;
}

string NODE:: show_username(){
    return username;
}

int NODE:: show_nperson(){
    return n_person;
}

int NODE:: show_room_id(){
    return room_id;
}

string NODE:: show_roomtype(){
    return room_type;
}

int NODE:: show_night(){
    return night;
}

int NODE:: show_food(){
    return food;
}

int NODE:: show_laundry(){
    return laundry;
}

int NODE:: show_shuttle(){
    return shuttle;
}

int NODE:: show_extrabed(){
    return extrabed;
}