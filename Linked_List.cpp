void queue::insert_node(){
    
    
    size++;
}

void list_in_hotel::insert_node(){
    
    
    size++;
}

list_in_hotel::~list_in_hotel(){

    ofstream myFile("NODE_in_hotel.csv"); //w
    myFile.close();

}
