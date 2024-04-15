using namespace std;
#include"NODE.h"

#ifndef Linked_List_H
#define Linked_List_H

class Linked_List{
    protected :
        NODE * head ;
        int size ;
    public :
        void show_all(); 
        virtual void insert_node(NODE* &q)=0;
        virtual ~Linked_List();
};


class queue:public Linked_List{
    private :
        NODE *tail ;
    public :
        queue(int) ;
        void insert_node(NODE* &q);
        void destruct_Linked_List(queue* q);
        ~queue() ;
};


class list_in_hotel : public Linked_List{
    private :
        NODE *tail ;
    public :
        void insert_node(NODE* &q);
        void destruct_list_in_hotel(list_in_hotel* q);
        ~list_in_hotel() ;

};


#endif