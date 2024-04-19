using namespace std;
#include <iostream>
#include <fstream>
#include <sstream>
#include <string> 
#include <iomanip>

#include"NODE.h"
#include"Linked_List.h"

void Linked_List::insert_node(NODE*&q) {cout << "test " ;}
bool check_username(string);

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

    ifstream myFile("NODE_in_hotel.csv");
    
    if(!myFile.is_open())
    {
        cout<<"** Cannot open the file! **"<<endl;
        //return false;
    }
    string line;
    string username,room_type;
    string n_person,room_id,night,food,laundry,shuttle,extrabed;
    while(getline(myFile,line))
    {
        stringstream ss(line);
        getline(ss,username,',');
        getline(ss,room_type,',');
        getline(ss,n_person,',');
        getline(ss,room_id,',');
        getline(ss,night,',');
        getline(ss,food,',');
        getline(ss,laundry,',');
        getline(ss,shuttle,',');
        getline(ss,extrabed,',');

        NODE* customer_in_hotel  = new NODE(username,room_type,stoi(n_person),stoi(room_id),stoi(night),stoi(food),stoi(laundry),stoi(shuttle),stoi(extrabed));
        insert_node(customer_in_hotel);
    }
}
/*

สร้างไว้ check constuctor list_in_hotel เฉยๆ

void list_in_hotel::show_all(){
    NODE* current = head;
    while (current != nullptr) {
        current->show_node();
        current = current->move_next();
    }
}
*/

void list_in_hotel::check_out(string username){
    NODE* temp=head;
    int total,cash;
    while(temp->show_username()!=username){
        temp=temp->move_next();
    }
    cout<<endl<<"Username : "<<temp->show_username()<<endl;
    cout<<"Room type : "<<temp->show_roomtype()<<"   price(per night) : "<<endl;
    cout<<"Total night : "<<temp->show_night()<<endl<<"Price : "<<3500*temp->show_night()<<endl;
    cout<<endl<<"Services"<<endl<<"--------------------------"<<endl;
    cout<<"Food(120 per dish)     : "<<setw(3)<<temp->show_food()<<"     Price : "<<120*temp->show_food()<<endl;
    cout<<"Laundry(50 per time)   : "<<setw(3)<<temp->show_laundry()<<"     Price : "<<50*temp->show_laundry()<<endl;
    cout<<"Shuttle(100 per time)  : "<<setw(3)<<temp->show_shuttle()<<"     Price : "<<100*temp->show_shuttle()<<endl;
    cout<<"Extra bed(250 per bed) : "<<setw(3)<<temp->show_extrabed()<<"     Price : "<<250*temp->show_extrabed()<<endl;
    total=3500*temp->show_night()+120*temp->show_food()+50*temp->show_laundry()+100*temp->show_shuttle()+250*temp->show_extrabed();
    cout<<"--------------------------"<<endl<<endl<<"Total price : "<<total<<endl<<endl;
    cout<<"Please enter the amount of cash : ";
    cin>>cash;
    if(cash!=total){
        while(cash<total){
            cout<<endl<<"!!Not enough cash!!"<<endl<<"Please enter again : ";
            cin>>cash;
        }
        cout<<endl<<"Change is "<<cash-total<<"."<<endl<<endl;
        cout<<" Thank you for stay with us"<<endl;
        cout<<"           * * *       "<<endl;
        cout<<"       *           *   "<<endl;
        cout<<"     *               *  "<<endl;
        cout<<"    *     O     O     * "<<endl;
        cout<<"    * ////       //// *   "<<endl;
        cout<<"     *       3       *  "<<endl;
        cout<<"       *           *     "<<endl;
        cout<<"           * * *    "<<endl<<endl;
    }
    else {
        cout<<endl<<" Thank you for stay with us"<<endl;
        cout<<"           * * *       "<<endl;
        cout<<"       *           *   "<<endl;
        cout<<"     *               *  "<<endl;
        cout<<"    *     O     O     * "<<endl;
        cout<<"    * ////       //// *   "<<endl;
        cout<<"     *       3       *  "<<endl;
        cout<<"       *           *     "<<endl;
        cout<<"           * * *    "<<endl;
    }

    //delete node
    NODE* previousPtr; // pointer to previous node in list
    NODE* currentPtr; // pointer to current node in list

   // delete first node
   if ( head->show_username() == username ) {
      temp = head; 
      head = ( head )->move_next();
      temp->set_room_id(-1);
      delete temp;
   }

   else if(temp->move_next()==NULL){
    previousPtr=head;

        while(previousPtr->move_next()!=temp){
        previousPtr=previousPtr->move_next();
        }

        previousPtr->set_next_NULL();
        temp->set_room_id(-1);
        delete temp;
   }

   else {
    previousPtr=head;

        while(previousPtr->move_next()!=temp){
        previousPtr=previousPtr->move_next();
        }

        NODE* a=temp->move_next();
        previousPtr->insert(a);
        temp->set_room_id(-1);
        delete temp;

   }
 
}

bool list_in_hotel::check_username(string username){
    NODE* temp;
    temp = head;
    while(temp != nullptr){
        if(temp->show_username() == username){
            return true;
        }
            temp = temp->move_next();
    }
    return false;
}