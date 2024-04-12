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
        void insert_node();
        ~Linked_List();
};


class list_in_hotel : public Linked_List{
    
    private :
    public :
        void insert_node();
        ~list_in_hotel();

};