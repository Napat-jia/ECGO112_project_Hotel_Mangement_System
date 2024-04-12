#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
using namespace std ;

void create_csv(){

    ofstream myFile("NODE_in_Q.csv"); //w
    // Send data to the stream
    myFile << "Username" <<","<< "n_person" <<"," << "room_type"<<","<<"night"<<endl; 
    // Close the file
    myFile.close();
}

vector<string> read(){
    vector<string> result;  //vector
    string line,username,n_person,room_type,n_night ;
    stringstream ss;

    ifstream myFile("NODE_in_Q.csv"); //open file r

    if(!myFile.is_open()){
        cout << "can not open the file." ;
    }

    while (getline (myFile, line)) {
        stringstream ss(line);
        getline(ss,username,',');
        getline(ss,n_person,',');
        getline(ss,room_type,',');
        getline(ss,n_night,',');
        result.push_back(username);
        result.push_back(n_person);
        result.push_back(room_type);
        result.push_back(n_night);
    }

    return result;
}

int main(){
    create_csv();
    vector<string> a = read();
    cout <<a[0]<<a[1]<<a[2]<<a[3]<<a[4]<<a[5]<< endl;

    return 0 ;
}