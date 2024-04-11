class NODE{
    private :
        NODE* next ;
        std::string username , room_type ;
        int n_person ;
        int room_id ;
        int night;
        int service ;
        
    public :
        NODE();
        show_node(std::string);
        ~NODE();
};
