using namespace std;

class NODE{
    private :
        NODE* next ;
        std::string username , room_type ;
        int n_person ;
        int room_id ;
        int room_type;
        int night;
        int service ;
        
    public :
        NODE(std::string a, int b,std::string c,int d);
        //show_node(std::string);
        ~NODE();
        NODE* move_next();
        string NODE:: show_username();
        int NODE:: show_nperson();
        string NODE:: show_roomtype();
        int NODE:: show_night();
};
