using namespace std;
#include"NODE.h"
#include "room.h"

#ifndef Linked_List_H
#define Linked_List_H

class Linked_List{
    protected :
        NODE * head ;
        int size ;
    public :
        bool check_username(string username);
        virtual void insert_node(NODE* &q)=0;
        virtual ~Linked_List();
        
};


class queue:public Linked_List{
    private :
        NODE *tail ;
    public :
        queue() ;
        
        void insert_node(NODE* &q);
        void destruct_Linked_List(queue* q);
        ~queue() ;
};


class list_in_hotel : public Linked_List{
    private :
        NODE *tail ;
    public :
        list_in_hotel();
        void show_all();
        void insert_node(NODE* &q);
        void destruct_list_in_hotel(list_in_hotel* q);
        void check_out(string username);
<<<<<<< HEAD
        void call_service(string username);
        bool check_username(string username);
=======
        void init_room_in_hotel(Room room[]);
>>>>>>> faf6fbe5c26a6aa70be72a97327d9e54952c57c0
        ~list_in_hotel() ;
        

};


#endif