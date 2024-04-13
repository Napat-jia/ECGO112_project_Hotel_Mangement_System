using namespace std;

class NODE{
    private :
        NODE* next ;
        std::string username , room_type ;
        int n_person ;
        int room_id ;
        int night;
        int food,laundry,shuttle,extrabed ;
    public :
        NODE(std::string a, int b,std::string c,int d);
        //show_node(std::string);
        ~NODE();
        NODE* move_next();
        string show_username();
        int show_nperson();
        int show_room_id();
        string show_roomtype();
        int show_night();
        int show_food();
        int show_laundry();
        int show_shuttle();
        int show_extrabed();
};
