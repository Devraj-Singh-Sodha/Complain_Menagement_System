// #include<bits/stdc++.h>
// using namespace std;



// class Mess_complain{
//     private:
//         string complain_id;
//         string student_name;
//         bool status = false;
//         string complain;

//     public:
//         int choice;
//         void raise_complain(){
//                 cout<<"Enter your Complain"<<endl;
//                 cin>>complain;
//                 cout<<"Your Complain is register: "<<endl
//                     <<"We are working on it"<<endl;
//         }
//         void view_complain(){
//                 cout << "Complain ID: " << complain_id << endl;
//                 cout << "Student Name: " << student_name << endl;
//                 cout << "Complain: " << complain << endl;
//                 cout << "Status: " << (status ? "Resolved" : "Pending") << endl;
    
//             }
//         void complaint(string id, string name, string query) {
//                 complain_id = id;
//                 student_name = name;
//                 complain = query;
//                 status = false;
//     }
//         void display_menu(){
//             cout << "******-Mess Complain-******" <<endl
//                  << "1. Student: " << endl
//                  << "2. Mess-Incharge: " << endl
//                  << "3. Admin: " << endl
//                  << "4. Exit: " << endl;
//             cin >> choice;

//         }

//         void student_menu(){
//                 cout<< "******-Student Menu-******" <<endl
//                     << "1. Raise Complain: " <<endl
//                     << "2. View Complain: " <<endl
//                 << "3. Back: " <<endl;
//             cin >> choice;

//             if(choice == 1){
//                     raise_complain();
//                 }
//                 else if(choice == 2){
//                         view_complain();
//                     }

        
//         }

//         void mess_incharge_menu(){
//                 cout << "1. View Complains: " <<endl
//                  << "2. Update Status: " <<endl
//                  << "3. Search complain: " <<endl
//                  << "4. Logout: " <<endl;
//             cin >> choice;

//         }

//         void admin_munu(){
//             cout <<"1. View Complains: " <<endl
//                  <<"2. Search Complains: " <<endl
//                  <<"3. Logout: "<<endl;
//             cin >> choice;

//         }

//         void run(){
//             // int choice;
//             while (true)
//             {
//                 display_menu();

//                 if (choice == 1)
//                 {
//                     student_menu();
//                 }

//                 else if(choice == 2){
//                         mess_incharge_menu();
//                 }

//                 else if(choice == 3){
//                         admin_munu();
//                     }

//                     else if(choice == 4){
//                             break;
//                 }

//                 else{
//                     cout<<"Please Enter Valid Choice:  "<<endl;
//                 }

//             }
            
//         }

// };


// class user{
    
// };
// int main(){
    
//     Mess_complain m1;
//     m1.run();

//     return 0;
// }


#include<iostream>
#include "main.cpp"
using namespace std;

class mess : public Complain_Manegement{
    public:
        void saveFile();
};
void Mess_complain::saveFile()
{
    raise_complain();

    ofstream file("Complaints/mess.txt",ios::app);

    file<<student_name<<endl;
    file<<roll_no<<endl;
    file<<complain_title<<endl;
    file<<complain_detail<<endl;
    file<<status<<endl;
    file<<"------------------"<<endl;

    file.close();

    cout<<"Complaint Saved Successfully"<<endl;
}

int main(){
    
    return 0;
}
