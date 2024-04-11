#include <iostream>
#include "NODE.h"
using namespace std;
void Booking();
int main(){

    //NODE pond ;
    Booking();



}
void Booking(){
    cout<<"====== BOOKING MENU ======="<<endl<<endl;
    cout<<"____ Type of room _____"<<endl;
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
    int n=0,type=0,t=0;
    string room;
    while(!check_number)
    {
        cout<<"Please enter number of people: ";
        cin>>n;
        if(n>0 && n<=5) check_number = true;
        else cout<<"Invalid number of people!"<<endl;

    }
    
    while(!check_type)
    {
        cout<<"Select type of room you want to book in (1-3): ";
        cin>>type;
        if(type == 1){
            room = "standard";
            if(n>2)
            {
                cout<<"Too many people for a standard room!"<<endl<<"Please choose again!"<<endl;
                continue;
            }
            check_type = true;
        }
        else if(type == 2){
            room = "family";
            if(n<2)
            {
                cout<<"Minimum occupancy not met for a family room!"<<endl<<"Please choose again!"<<endl;
                continue;
            }
            check_type = true;
        }
        else if(type == 3){
            room = "deluxe";
            if(n>2)
            {
                cout<<"Too many people for a deluxe room!"<<endl<<"Please choose again!"<<endl;
                continue;
            }
            check_type = true;
        }
        else{
            cout<<"Invalid Input Please Select Again!"<<endl;
        }
    }
    cout<<"Please enter the number of nights you plan to stay: ";
    cin>>t;

}