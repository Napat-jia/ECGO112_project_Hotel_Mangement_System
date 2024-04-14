#include <iostream>
#include <sstream>
#include <fstream>

#include "NODE.h"
#include "Linked_List.h"

using namespace std;
NODE* Booking(string username);
bool check_user(string username);
int main(){
    
    //ลอง check เฉยๆ ************
    /*
    string username;
    cout<<"Enter username: ";
    cin>>username;
    */
    //username = login(); เอามาจาก login.cpp ?
    queue Q;
    bool exist = check_user(username);
    if(!exist)
    {
        NODE *t = Booking(username);
        Q.insert_node(t); //insert node เข้าไปใน linked list queue

        //cout << "User '" << username << "' does not exists in the system." << endl;
    }
    //else cout << "User '" << username << "' exists in the system." << endl;
    return 0;
}

bool check_user(string username)
{
    ifstream myFile("username.csv");
    string line,csv_username;
    if(!myFile.is_open())
    {
        cout<<"** Cannot open the file! **"<<endl;
        return false;
    }
    while(getline(myFile,line))
    {
        stringstream ss(line);
        getline(ss,csv_username,',');
        if(username == csv_username) return true;
    }
    return false;
}
    

NODE* Booking(string username) //รับ username มาจาก main หลัง login?? ใช่ปะ??
{  
    cout<<"====== BOOKING MENU ======="<<endl<<endl;
    cout<<"---------------------------"<<endl;
    cout<<">>>>>> Type of room <<<<<<"<<endl;
    cout<<"---------------------------"<<endl;
    cout<<"1.Standard Room (1)"<<endl;
    cout<<" - Room Capacity : 1-2"<<endl;
    cout<<" - Price/Night : 2000 Baht"<<endl;
    cout<<"---------------------------"<<endl;
    cout<<"2.Family Room (2)"<<endl;
    cout<<" - Room Capacity : 2-5"<<endl;
    cout<<" - Price/Night : 3500 Baht"<<endl;
    cout<<"---------------------------"<<endl;
    cout<<"3.Deluxe Room (3)"<<endl;
    cout<<" - Room Capacity : 1-2"<<endl;
    cout<<" - Price/Night : 2700 Baht"<<endl;
    cout<<"---------------------------"<<endl;
    bool check_type = false;
    bool check_number = false;
    int n=0,type=0,night=0;
    string room;
    while(!check_number)
    {
        cout<<"Please enter number of people: ";
        cin>>n;
        if(n>0 && n<=5) check_number = true;
        else cout<<"** Invalid number of people! **"<<endl;

    }
    while(!check_type)
    {
        cout<<"---------------------------"<<endl;
        cout<<"Select type of room you want to book in (1-3): ";
        cin>>type;
        if(type == 1){
            room = "standard";
            if(n>2)
            {
                cout<<">>> Too many people for a standard room! <<<"<<endl<<"Please choose again! "<<endl;
                continue;
            }
            check_type = true;
        }
        else if(type == 2)
        {
            room = "family";
            if(n<2)
            {
                cout<<">>> Minimum occupancy not met for a family room! <<<"<<endl<<"Please choose again!"<<endl;
                continue;
            }
            check_type = true;
        }
        else if(type == 3)
        {
            room = "deluxe";
            if(n>2)
            {
                cout<<">>> Too many people for a deluxe room! <<<"<<endl<<"Please choose again!"<<endl;
                continue;
            }
            check_type = true;
        }
        else{
            cout<<"** Invalid Input Please Select Again! **"<<endl;
        }
    }
    cout<<"---------------------------"<<endl;
    cout<<"Please enter the number of nights you plan to stay: ";
    cin>>night;
    NODE* t = new NODE(username,n,room,night);
    return t;
} 

