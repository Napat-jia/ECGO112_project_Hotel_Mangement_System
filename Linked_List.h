using namespace std;
#include"NODE.h"

class Linked_List{
    protected :
        NODE * head ;
        int size ;
    public :
        void show_all(); 
        virtual void insert_node()=0;
};


class queue:public Linked_List{
    private :
        NODE *tail ;
    public :
        void insert_node(NODE* q);
        void destruct_Linked_List(queue* q);
};


class list_in_hotel : public Linked_List{
    private :
        NODE *tail ;
    public :
        void insert_node(NODE* q);
        void destruct_list_in_hotel(list_in_hotel* q);

};