using namespace std;
#include <iostream>


#include"NODE.h"
#include"Linked_List.h"

void Linked_List::insert_node(NODE*&q) {cout << "test " ;}

void queue::insert_node(NODE*&q){
    
    if(head == NULL) head = tail = q;
    else {
        tail -> insert(q) ; 
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

    string file_name ;

    if(head->show_roomtype()=="standard") file_name = "NODE_in_Q_standard.csv" ;
    else if(head->show_roomtype()=="deluxe") file_name = "NODE_in_Q_deluxe.csv" ;
    else if(head->show_roomtype()=="family") file_name = "NODE_in_Q_family.csv" ;

    remove(file_name.c_str());

    while(head!=NULL){

        NODE* temp=head;
        if(temp){
            head=temp->move_next();
            //if(size==1)tail=NULL;
            size--;
            delete temp;
            }
    }
}

queue::queue(){
    size = 0 ;
    head = NULL ;
    tail = NULL ;
}

void list_in_hotel::insert_node(NODE* &q){
    if (head == NULL) {
        head = q;
        size++;
    }
    else {
    NODE* current = head;
    NODE* previous = NULL;
    int value = q->show_room_id();
    while (current != NULL && current->show_room_id() < value) {
        previous = current;
        current = current->move_next();
    }

    if (previous == NULL) 
    {
        //beginning
        q->insert(head);
        head = q;
    } 
    else 
    {
        q->insert(current);
        previous->insert(q);
    }

    size++;
    }
}


/*
void list_in_hotel::insert_node(NODE* &q){
    NODE* temp;
    if(head == NULL) head = q;
    else {
        temp = head;
        while(temp->move_next() != NULL)
        {
            temp = temp->move_next();
        }
        //temp->move_next() = q;
    }
    size++;
}
*/
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

   string file_name ;

    remove("NODE_in_hotel.csv");

    while(head!=NULL){

        NODE* temp=head;
        if(temp){
            head=temp->move_next();
            //if(size==1)tail=NULL;
            size--;
            delete temp;
            }
    }

}

Linked_List::~Linked_List(){
    
}


list_in_hotel::list_in_hotel(){


}
