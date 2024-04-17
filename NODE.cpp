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

    string file_name ;
    if(show_roomtype()=="standard") file_name = "NODE_in_Q_standard.csv" ;
    else if(show_roomtype()=="deluxe") file_name = "NODE_in_Q_deluxe.csv" ;
    else if(show_roomtype()=="family") file_name = "NODE_in_Q_family.csv" ;
    
    if(room_id==0){
        ofstream myFile(file_name,ios::app); //w
        // Send data to the stream
        myFile << username <<","<< n_person <<"," << room_type <<"," << night<<endl; 
        // Close the file
        myFile.close();
    }

    else{
        ofstream myFile("NODE_in_hotel.csv",ios::app); //w
        // Send data to the stream username,room_type,n_person,room_id,night,food,laundry,shuttle,extrabed
        myFile << username <<"," << room_type <<"," << n_person <<"," << room_id <<","<<night<<","<<food<<","<<laundry<<","<<shuttle<<","<<extrabed<<endl; 
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

void NODE::insert(NODE*& x){
     this -> next = x ;
    }