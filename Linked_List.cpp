using namespace std;
#include"NODE.h"
#include"Linked_List.h"

void queue::insert_node(queue* q){
    if(q){ 
    q->next = NULL;
    if(head == NULL) head = this;
    else tail->next = this; 
    tail = this; 
    }
    size++;
}

void queue::destruct_Linked_List(queue* q){
    NODE* temp=q->head;
    ifstream myFile("NODE_in_Q.csv");
    myFile.remove();
    ofstream myFile("NODE_in_Q.csv");
    if(temp){
        myFile << temp->show_sername() <<","<< temp->show_nperson() <<"," << temp->show_roomtype()<<","<<temp->show_night()<<endl;
        q->head=temp->move_next();
        if(q->size==1)q->tail=NULL;
        q->size--;
        free(temp);
    }
    myFile.close();

}

void list_in_hotel::insert_node(list_in_hotel* q){
    q->next=this;
    size++;
}

void list_in_hotel::destruct_list_in_hotel(list_in_hotel* q){
NODE* temp=q->head;
    ifstream myFile("NODE_in_hotel.csv");
    myFile.remove();
    ofstream myFile("NODE_in_hotel.csv");
    if(temp){
        myFile << temp->show_sername() <<","<< temp->show_nperson() <<"," << temp->show_room_id()<<",";
        myFile<<temp->show_roomtype()<<","<<temp->show_night()<<","<< temp->show_food() <<",";
        myFile << temp->show_laundry() <<"," << temp->show_shuttle()<<","<<temp->show_extrabed()<<endl;
        q->head=temp->move_next();
        if(q->size==1)q->tail=NULL;
        q->size--;
        free(temp);
    }
    myFile.close();
}
