#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>


using namespace std ;

string login(){

    vector<string> data;  //vector
    string line,username,password,hide_pass;
    stringstream ss;
    char c;

    ifstream myFile("username.csv"); //open file r

    if(!myFile.is_open()) cout << "can not open the file." ;
    
    while (getline (myFile, line)) {
        stringstream ss(line);
        getline(ss,username,',');
        getline(ss,password,',');
        
        data.push_back(username);
        data.push_back(password);
    }

    while(1){
    cout << "Username: ";
    cin >> username;

    cout << "Password: ";
    cin >> password;
    
    for(int i = 0 ;i < data.size();i += 2){ 
        if(username == data[i] && password == data[i+1]){ 
            cout << "Login Successful" << endl;
            return username;
            break;
        }
    }
    
    cout << "Incorrect Username or Password. Please Try Again." << endl;
    }
    /*
    
    ทำหน้าล็อกอินรับอินพุต แล้วนำไปเช็คกับค่าใน csv file 
    โดย data[เลขคู่] จะเป็น username data[เลขคี่] จะเป็น password
    วิธีการเข้าถึงคือ data[0] data[1] เป็นต้น
    
    ไกด์ไลน์ใช้ for loop เช็ค user ก็อาจจะ i เพิ่มทีละสอง แล้วก็ input == data[i] มั้ย เป็นต้น (ถ้า userก็ i เริม่ที่ 0 เพราะ username เริ่ม 0)
    
    */
    
}

int main(){
    login();
    return 0 ;
}