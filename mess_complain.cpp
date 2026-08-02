#include<bits/stdc++.h>
using namespace std;

class Mess_complain{
    private:
        string complain_id;
        string student_name;
        bool status;
        string complai;

    public:
        int choice;
        
        void display_menu(){
            cout << "******-Mess Complain-******" <<endl
                 << "1. Student: " << endl
                 << "2. Mess-Incharge: " << endl
                 << "3. Admin: " << endl
                 << "4. Exit: " << endl;
            cin >> choice;

        }

        void student_menu(){
            cout << "1. Raise Complain: " <<endl
                 << "2. View Complain: " <<endl
                 << "3. Back: " <<endl;
            cin >> choice;

        }

        void mess_incharge_menu(){
            cout << "1. View Complains: " <<endl
                 << "2. Update Status: " <<endl
                 << "3. Search complain: " <<endl
                 << "4. Logout: " <<endl;
            cin >> choice;

        }

        void admin_munu(){
            cout <<"1. View Complains: " <<endl
                 <<"2. Search Complains: " <<endl
                 <<"3. Logout: "<<endl;
            cin >> choice;

        }

        void run(){
            // int choice;
            while (true)
            {
                display_menu();

                if (choice == 1)
                {
                    student_menu();
                }
                else if(choice == 2){
                    mess_incharge_menu();
                }
                else if(choice == 3){
                    admin_munu();
                }
                else if(choice == 4){
                    break;
                }
                else{
                    cout<<"Please Enter Valid Choice:  "<<endl;
                }
            }
            
        }

};

int main(){

    Mess_complain m1;
    m1.run();

    return 0;
}