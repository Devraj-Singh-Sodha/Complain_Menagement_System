#include <bits/stdc++.h>
using namespace std;
static int id = 0; 
class Complain_Manegement
{
protected:
    string student_name;
    string roll_no;

public:
    string complain_title;
    string complain_detail;
    void view_all_complains(string loc);
    void raise_complain();
    void view_complain();
    void start();
};

class Mess : public Complain_Manegement
{
public:
    int choice;
    void saveFile();
    void display_menu();
    void student_menu();
    void mess_incharge_menu();
    void admin_munu();
    void run();
};
void Complain_Manegement ::view_all_complains(string loc)
{
    string Address = "Complaints/" + loc + ".txt";
    
    ifstream file(Address);

        if (!file)
        {
            cout << "\n[Error] No complaints found or file is missing." << endl;
            return;
        }

        cout << "\n=== ALL REGISTERED COMPLAINTS ===" << endl;
        string line;

        while (getline(file, line))
        {
            if(line == student_name){
                continue;
            }
            cout << line << endl;
        }

        cout << "=================================" << endl;

        file.close();
    }

void Mess::student_menu()
{
    cout << "******-Student Menu-******" << endl
         << "1. Raise Complain: " << endl
         << "2. View Complain: " << endl
         << "3. Back: " << endl;
    cin >> choice;

    if (choice == 1)
    {
        saveFile();
    }
    else if (choice == 2)
    {
        view_complain();
    }
}
void Mess::admin_munu()
{
    cout << "1. View Complains: " << endl
         << "2. Search Complains: " << endl
         << "3. Logout: " << endl;
    cin >> choice;
    if (choice == 1)
    {
        view_all_complains("mess");
    }
}
void Mess::run()
{
    while (true)
    {
        display_menu();

        if (choice == 1)
        {
            student_menu();
        }

        else if (choice == 2)
        {
            mess_incharge_menu();
        }

        else if (choice == 3)
        {
            admin_munu();
        }

        else if (choice == 4)
        {
            break;
        }

        else
        {
            cout << "Please Enter Valid Choice:  " << endl;
        }
    }
}
void Mess::mess_incharge_menu()
{
    cout << "1. View Complains: " << endl
         << "2. Update Status: " << endl
         << "3. Search complain: " << endl
         << "4. Logout: " << endl;
    cin >> choice;

    if (choice == 1)
    {
       view_all_complains("mess");
    }
}
void Mess::display_menu()
{
    cout << "******-Mess Complain-******" << endl
         << "1. Student: " << endl
         << "2. Mess-Incharge: " << endl
         << "3. Admin: " << endl
         << "4. Exit: " << endl;
    cin >> choice;
}
void Mess::saveFile()
{
    raise_complain();

    ofstream file("Complaints/mess.txt", ios::app);
    file << id << endl;
    file << student_name << endl;
    file << roll_no << endl;
    file << complain_title << endl;
    file << complain_detail << endl;
    file << "-----------------" << endl;

    file.close();
}
void Complain_Manegement ::raise_complain()
{
    cout << "Enter Your Name: ";
    cin >> student_name;

    cout << "Enter Your Roll_number: ";
    cin >> roll_no;
    cin.ignore();

    cout << "Enter your Complain Title: ";
    getline(cin, complain_title);

    cout << "Enter your Complain in Detail: ";
    getline(cin, complain_detail);

    cout << "Your Complain is register: " << endl
         << "We are working on it" << endl;
    id++;
    cout << "Your Complain Id is " << id << endl;
}
void Complain_Manegement ::view_complain()
{
    if (id == 0){
        cout << "No complaints found." << endl;
        return;
    }
    else{
        cout << "Complain Id : " << id << endl;
        cout << "Student : " << student_name << endl;
        cout << "Roll No : " << roll_no << endl;
        cout << "Title : " << complain_title << endl;
        cout << "Detail : " << complain_detail << endl;

    }
}


int main()
{
    vector<Mess> mess(1);   // One Mess object stored dynamically

    while (true)
    {
        int choice;

        cout << "\n-------- Welcome Arya College Complaint System --------" << endl;
        cout << "1. For Mess Complaint" << endl;
        cout << "2. For College Complaint" << endl;
        cout << "3. For Hostel Complaint" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter Your Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            mess[0].run();
            break;

        case 2:
            cout << "\nCollege Complaint Module is under development.\n";
            break;

        case 3:
            cout << "\nHostel Complaint Module is under development.\n";
            break;

        case 4:
            cout << "\nThank You for using Arya College Complaint System.\n";
            return 0;

        default:
            cout << "\nInvalid Choice! Please Try Again.\n";
        }
    }

    return 0;
}
