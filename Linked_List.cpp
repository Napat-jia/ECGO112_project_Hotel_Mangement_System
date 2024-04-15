using namespace std;
#include <iostream>


#include"NODE.h"
#include"Linked_List.h"

void queue::insert_node(NODE*&q){
    if(head == NULL) head = tail = q;
    else {
        tail = tail->move_next() ;
        tail = q; 
        }
    tail = q;
    size++;
}
/*
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

}*/

queue::~queue(){

    NODE* temp=head;

    remove("NODE_in_Q.csv");
   
    if(temp){
        head=temp->move_next();
        if(size==1)tail=NULL;
        size--;
        delete temp;
    }
}

queue::queue(int s){

    size = s ;
    head = NULL ;
    tail = NULL ;
}

void list_in_hotel::insert_node(NODE* &q){
    NODE* temp;
    if(head == NULL) head = q;
    else {
        temp = head;
        while(temp->move_next() != NULL)
        {
            temp = temp->move_next();
        }
        temp->move_next() = q;
    }
    size++;
}

/*
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
*/


list_in_hotel::~list_in_hotel(){


}

Linked_List::~Linked_List(){
    
}