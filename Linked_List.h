using namespace std;

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
        void insert_node(queue* q);
        ~Linked_List(queue* q);
};


class list_in_hotel : public Linked_List{
    private :
        NODE *tail ;
    public :
        void insert_node(list_in_hotel* q);
        ~list_in_hotel(list_in_hotel* q);

};