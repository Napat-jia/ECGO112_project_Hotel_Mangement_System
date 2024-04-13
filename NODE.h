using namespace std;

class NODE{
    private :
        NODE* next ;
        std::string username , room_type ;
        int n_person ;
        int room_id ;
        int room_type;
        int night;
        int food,laundry,shuttle,extrabed ;
    public :
        NODE(std::string a, int b,std::string c,int d);
        //show_node(std::string);
        ~NODE();
        NODE* move_next();
        string NODE:: show_username();
        int NODE:: show_nperson();
        int NODE:: show_room_id();
        string NODE:: show_roomtype();
        int NODE:: show_night();
        int NODE:: show_food();
        int NODE:: show_laundry();
        int NODE:: show_shuttle();
        int NODE:: show_extrabed();
};
