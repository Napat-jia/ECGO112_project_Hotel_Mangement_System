using namespace std;
#include <iostream>
#include <fstream>
#include <sstream>
#include <string> 
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include"NODE.h"
#include"Linked_List.h"
#include "room.h"

void Linked_List::insert_node(NODE*&q) {cout << "test " ;}
bool check_username(string);
bool confirmOrder();

bool confirmOrder(){
    string confirm;
    cout<<"Please Confirm Your Orders (Confirm/Deny): ";
    cin.clear();
    cin.ignore(50,'\n') ;
    getline(cin, confirm);
    if (confirm == "Confirm" ) return true;
    else return false;
}

bool Linked_List::check_username(string username){
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

void Linked_List::show_all(){
    NODE* current = head;
    while (current != nullptr) {
        current->show_node();
        current = current->move_next();
    }
}

Linked_List::~Linked_List(){
    
}

queue::queue(){
    size = 0 ;
    head = NULL ;
    tail = NULL ;
}

void queue::insert_node(NODE*&q){
    
    if(head == NULL) head = tail = q;
    else {
        tail -> insert(q) ; 
        }
    tail = q;
    size++;
}

void queue::check_in(string username,Room room[],Linked_List* hotel){

    NODE* temp = head;
    int i;
    string type =  head->show_roomtype() ;
    NODE* empty = new NODE("",type,0,-1,0,0,0,0,0) ;
    if(head -> show_username() == username){
        for(i=0;i<9;i++)
        {
            if(room[i].show_available() == true && room[i].show_room_type() == type)
            {
                head->set_room_id(room[i].show_room());
                room[i].set_available(false);

                head = head->move_next();
                if(head==NULL) 
                {
                    tail = NULL;
                    queue::insert_node(empty);
                }
                temp -> set_next_NULL();
                hotel->insert_node(temp);

                cout<<"Check-in successfully"<<endl;
                break;
            }
        } 
        //cout<<"No available room"<<endl;
    }
    else cout<<"It's not your queue now"<<endl;

}

int queue::check_queue(string username){
    NODE* temp = head;
    int count=0;
    if(head!=NULL){

        if(head -> show_username() == username)
        {
            return 0;
        }
        else{
            while(temp -> show_username() != username && temp != NULL)
            {
                temp = temp->move_next();
                count++;
                if(temp==NULL) break ;
            }
            return count;
        }
    }else return 0 ;
}

void queue::cancel_queue(string username){
    NODE* temp = head;
    NODE* current = head;
    NODE* previous = head;
    while((temp->show_username()) != username && temp != NULL){
        temp = temp->move_next();
    }

    if(head == tail){
        string myfile,type = temp->show_roomtype();
        head = nullptr;
        tail = nullptr;
        if(type == "standard") myfile = "NODE_in_Q_standard.csv";
        else if(type == "deluxe") myfile = "NODE_in_Q_deluxe.csv";
        else if(type == "family") myfile = "NODE_in_Q_family.csv";
        ofstream myFile(myfile); //w
        myFile.close();
        temp->set_room_id(-1);
        delete temp;
    }
    else if(temp==head){
        head = head->move_next();
        temp->set_room_id(-1);
        delete temp;
    }
    else if(tail == temp){
        while(current->move_next() != temp  && current != NULL){
            current = current->move_next();
        }
            current->set_next_NULL();
            tail = current;
            temp->set_room_id(-1);
            delete temp;
    }
    else{
        while(previous->move_next() != temp && previous != NULL){
            previous = previous->move_next();
        }
        NODE* a = temp->move_next();
        previous->insert(a);
        temp->set_room_id(-1);
        delete temp;
    }
    cout<<"Canceled successfully"<<endl;
}

queue::~queue(){

    string file_name ;
    if(head!=NULL){
        if(head->show_roomtype()=="standard") file_name = "NODE_in_Q_standard.csv" ;
        else if(head->show_roomtype()=="deluxe") file_name = "NODE_in_Q_deluxe.csv" ;
        else if(head->show_roomtype()=="family") file_name = "NODE_in_Q_family.csv" ;

        remove(file_name.c_str());

        if(head->show_room_id()==-1){
            ofstream myFile(file_name); //w
            myFile.close();
        }
        
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


void list_in_hotel::check_out(string username,Room room[]){
    NODE* temp=head;
    int total,cash,id = (temp->show_room_id()) - 1;
    while(temp->show_username()!=username){
        temp=temp->move_next();
    }
    cout<<endl<<"Username : "<<temp->show_username()<<endl;
    cout<<"Room type : "<<temp->show_roomtype()<<"   price(per night) : "<<endl;
    cout<<"Total night : "<<temp->show_night()<<endl<<"Price : "<<(room[id].show_price())*temp->show_night()<<endl;
    cout<<endl<<"Services"<<endl<<"--------------------------"<<endl;
    cout<<"Food(120 per dish)     : "<<setw(3)<<temp->show_food()<<"     Price : "<<120*temp->show_food()<<endl;
    cout<<"Laundry(50 per item)   : "<<setw(3)<<temp->show_laundry()<<"     Price : "<<50*temp->show_laundry()<<endl;
    cout<<"Shuttle(100 per time)  : "<<setw(3)<<temp->show_shuttle()<<"     Price : "<<100*temp->show_shuttle()<<endl;
    cout<<"Extra bed(250 per bed) : "<<setw(3)<<temp->show_extrabed()<<"     Price : "<<250*temp->show_extrabed()<<endl;
    total=(room[id].show_price())*temp->show_night()+120*temp->show_food()+50*temp->show_laundry()+100*temp->show_shuttle()+250*temp->show_extrabed();
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

void list_in_hotel::call_service(string username) 
{
    NODE* temp = head;
    while (temp->show_username() != username) {
        temp = temp->move_next();
    }

    cout<<"================= SERVICE MENU ================="<<endl;
    cout<<"       ----------------------------------        "<<endl;
    cout<<"       >>>>>>> Available Services <<<<<<<"<<endl;
    cout<<"       ----------------------------------"<<endl;
    cout<<"             1. Food Service (1)"<<endl;
    cout<<"             - Cost: 120 Baht per Dish"<<endl;
    cout<<"       ----------------------------------"<<endl;
    cout<<"             2. Laundry Service (2)"<<endl;
    cout<<"             - Cost: 50 Baht per Item"<<endl;
    cout<<"       ----------------------------------"<<endl;
    cout<<"             3. Shuttle Service (3)"<<endl;
    cout<<"             - Cost: 100 Baht per Ride"<<endl;
    cout<<"       ----------------------------------"<<endl;
    cout<<"             4. Extra Bed (4)"<<endl;
    cout<<"             - Cost: 250 Baht per Bed"<<endl;
    cout<<"       ----------------------------------"<<endl;
    cout<<"       # Enter Number '0'  to Exit Menu #"<<endl;
    cout<<"       ----------------------------------"<<endl;
    cout<<"================================================="<<endl<<endl;

    int select= -1;
    while(select!=0)
    {
        cout<<"       --------------------------------"<<endl;
        cout<<"       >>>>>>> Current Services <<<<<<<"<<endl;
        cout<<"       --------------------------------"<<endl;
        cout<<"       # Food Service: "<<temp->show_food()<<" Dish"<<endl;
        cout<<"       # Laundry Service: "<<temp->show_laundry()<<" Item"<<endl;
        cout<<"       # Shuttle Service: "<<temp->show_shuttle()<<" Ride"<<endl;
        cout<<"       # Extra Beds: "<<temp->show_extrabed()<<" Bed"<<endl;
        cout<<"       --------------------------------"<<endl<<endl;
        try
        {
            cout<<">> Please select the service you want(0 to exit): ";
            cin>>select;
            if(cin.fail()){
                cin.clear();
			    cin.ignore(10000,'\n');
                throw("** Invalid Input. Please Enter Again! **");
            }
            if(select<0 ||select>4){
                throw("** Invalid Selection. Please Select a Number of Service from 0 to 4! **");
            }
            if(select == 1){
                int quantity=0;
                cout<<">> Enter the number of orders: ";
                cin>>quantity;
                if (cin.fail() || quantity <= 0){
                    throw("** Invalid Quantity. Please Enter Again! **");
                }
                if(quantity > 10){
                    throw("** Too many Orders placed! **");
                }
                if(confirmOrder()){
                    temp->set_food(temp->show_food()+quantity);
                    cout<<"Order Confirmed!"<<endl;
                }
                else{
                    throw("** Your orders have been canceled! **");
                }
                
            }
            else if(select == 2){
                int quantity=0;
                cout<<">> Enter the number of clothes/items: ";
                cin>>quantity;
                if (cin.fail() || quantity <= 0){
                    throw("** Invalid Quantity. Please Enter Again! **");
                }
                if(quantity > 15){
                    throw("** Too many Items to be laundered! **");
                }
                if(confirmOrder()){
                    temp->set_laundry(temp->show_laundry()+quantity);
                    cout<<"Order Confirmed!"<<endl;
                }
                else{
                    throw("** Your orders have been canceled! **");
                }
                
            }
            else if(select == 3){
                int quantity=0;
                cout<<">> Enter the number of shuttle rides you require: ";
                cin>>quantity;
                if (cin.fail() || quantity <= 0){
                    throw("** Invalid Quantity. Please Enter Again! **");
                }
                if(quantity > 10){
                    throw("** Too many Rides required! **");
                }
                if(confirmOrder()){
                    temp->set_shuttle(temp->show_shuttle()+quantity);
                    cout<<"Order Confirmed!"<<endl;
                }
                else{
                    throw("** Your orders have been canceled! **");
                }
                
            }
            else if(select == 4){
                int quantity=0;
                cout<<">> Enter the number of Extra Beds you require: ";
                cin>>quantity;
                if (cin.fail() || quantity <= 0){
                    throw("** Invalid Quantity **");
                }
                if(quantity > 2){
                    throw("** Too many Beds requsted! **");
                }
                if(confirmOrder()){
                    temp->set_extrabed(temp->show_extrabed()+quantity);
                    cout<<"Order Confirmed!"<<endl;
                }
                else{
                    throw("** Your orders have been canceled! **");
                }
            }
            cout<<"================================================="<<endl<<endl;
        }
        catch(const char* error){
            int i;
            cout<<endl;
            for(i=0; i<strlen(error); i++){
                cout<<"-";
            }cout<<endl;
            cout<<error<<endl;
            for(i=0; i<strlen(error); i++){
                cout<<"-";
            }cout<<endl;
        }
    }

}

void list_in_hotel::init_room_in_hotel(Room room[]){

    int id  ;
    NODE * temp = head ; 
    while(temp!=NULL){
        id  = temp->show_room_id() ; 
        room[id-1].set_available(false);
        temp = temp->move_next();
    }

}

list_in_hotel::~list_in_hotel(){

   string file_name ;
    remove("NODE_in_hotel.csv");
    if(head==NULL){
        ofstream myFile("NODE_in_hotel.csv"); //w
        myFile.close();
    }
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