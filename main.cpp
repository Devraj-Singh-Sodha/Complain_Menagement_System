#include <bits/stdc++.h>
using namespace std;

class Complain_Manegement
{
protected:
    string student_name;
    string roll_no;

public:
    string complain_title;
    string complain_detail;
    bool status = false;

    void raise_complain();
    void view_complain();
};

class Mess : public Complain_Manegement
{
public:
    int choice;
    void saveFile();
    void view_complain();
    void display_menu();
    void student_menu();
    void mess_incharge_menu();
    void admin_munu();
    void run();
};
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
        ifstream file("Complaints/mess.txt");

        if (!file)
        {
            cout << "\n[Error] No complaints found or file is missing." << endl;
            return;
        }

        cout << "\n=== ALL REGISTERED COMPLAINTS ===" << endl;
        string line;

        while (getline(file, line))
        {
            cout << line << endl;
        }

        cout << "=================================" << endl;

        file.close();
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

    file << student_name << endl;
    file << roll_no << endl;
    file << complain_title << endl;
    file << complain_detail << endl;
    file << status << endl;
    file << "-----------------" << endl;

    file.close();
}
void Mess::view_complain()
{
    cout << "Complain Title: " << complain_title << endl;
    cout << "Complain in detail: " << complain_detail << endl;
    cout << "Status: " << (status ? "Resolved" : "Pending") << endl;
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
}
void Complain_Manegement ::view_complain()
{
    cout << "Student : " << student_name << endl;
    cout << "Roll No : " << roll_no << endl;
    cout << "Title : " << complain_title << endl;
    cout << "Detail : " << complain_detail << endl;
}

int main()
{
    Mess m1;
    m1.run();
    return 0;
}