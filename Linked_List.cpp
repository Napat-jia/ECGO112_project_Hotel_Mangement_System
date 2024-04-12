using namespace std;
void queue::insert_node(queue *q){
    
    
    size++;
}

queue::~Linked_List(queue *q){
    NODE* temp=q->head;
    ifstream myFile("NODE_in_Q.csv");
    myFile.remove();
    if(temp){
        ofstream myFile("NODE_in_Q.csv");
        myFile << temp->show_sername() <<","<< temp->show_nperson() <<"," << temp->show_roomtype()<<","<<temp->show_night()<<endl;
        q->headPtr=t->nextPtr;
        if(q->size==1)q->tailPtr=NULL;
        q->size--;
        free(temp);
    }
    myFile.close();

}

void list_in_hotel::insert_node(list_in_hotel *q){
    
    
    size++;
}

list_in_hotel::~list_in_hotel(list_in_hotel *q){
NODE* temp=q->head;
    ifstream myFile("NODE_in_hotel.csv");
    myFile.remove();
    if(temp){
        ofstream myFile("NODE_in_hotel.csv");
        myFile << temp->show_sername() <<","<< temp->show_nperson() <<"," << temp->show_roomtype()<<","<<temp->show_night()<<endl;
        q->headPtr=t->nextPtr;
        if(q->size==1)q->tailPtr=NULL;
        q->size--;
        free(temp);
    }
    myFile.close();
}
