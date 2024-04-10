class NODE{
    protected :
        NODE* next ;
        std::string username , room_type ;
        
    public :
        NODE();
        virtual void show_node(std::string)=0;
        ~NODE();
};

class NODE_in_Q : public NODE{
    private :
        int n_person ;

    public :
        NODE_in_Q();
        void show_node(std::string);
        ~NODE_in_Q();
}

class NODE_in_hotel : public NODE{
    private :
        int room_id ;
        int service ;
    public :
        NODE_in_hotel();
        void show_node(std::strings);
        ~NODE_in_hotel();
}