#include <iostream> 
using namespace std;
#include "room.h"

Room::Room(int id,int p,string type){

    room_id = id ;
    price = p ;
    room_type = type ;
    available = true ;
}


bool Room::show_available(){
    return available ;
}

int Room::show_price(){
    return price ;
} 

void Room::set_available(bool status){
    available = status ;
}