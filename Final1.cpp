#include <bits/stdc++.h>
using namespace std;

class College_complaint
{
protected:
    string student_name;
    string roll_no;

public:
    string complain_title;
    string complain_detail;
    void raise_complain(string location);
    void view_complain();
    void specific_complain(string location);
};
class Student : public College_complaint
{
public:
    void run();
    void mess_menu();
    void hostel_menu();
    void college_menu();
};
class Admin : public College_complaint
{
public:
    void run();
};
class Warden : public College_complaint
{
public:
    void run();
};

void College_complaint :: specific_complain(string location)
{
    string Address = "Complaints/" + location + ".txt";

    ifstream file(Address);

    if (!file.is_open())
    {
        cout << "\n[Error] No complaints found or file is missing." << endl;
        return;
    }

    cout << "\n=== ALL REGISTERED " << location << " COMPLAINTS ===" << endl;
    string line;

    while (getline(file, line))
    {
        cout << line << endl;
    }

    cout << "=================================" << endl;

    file.close();
}
void College_complaint :: raise_complain(string location)
{
    cout << "Enter Your Name: ";
    getline(cin, student_name);

    cout << "Enter Your Roll_number: ";
    cin >> roll_no;
    cin.ignore();

    cout << "Enter your Complain Title: ";
    getline(cin, complain_title);

    cout << "Enter your Complain in Detail: ";
    getline(cin, complain_detail);

    cout << "Your Complain is register: " << endl
         << "We are working on it" << endl;
    string add = "Complaints/" + location + ".txt";
    ofstream file(add, ios::app);
    file << student_name << endl;
    file << roll_no << endl;
    file << complain_title << endl;
    file << complain_detail << endl;
    file << "-----------------" << endl;

    file.close();
}
inline void College_complaint :: view_complain()
{

    cout << "Student : " << student_name << endl;
    cout << "Roll No : " << roll_no << endl;
    cout << "Title : " << complain_title << endl;
    cout << "Detail : " << complain_detail << endl;
}

void Student ::hostel_menu()
{
    int choice;
    while (true)
    {

        cout << "******-Student Hostel Menu-******" << endl;
        cout << "1.Add compalint" << endl
             << "2.view complaint" << endl
             << "3.exit" << endl
             << "enter your choice" << endl;

        cin >> choice;
        cin.ignore();

        if (choice == 1)
        {
            raise_complain("hostel");
        }
        else if (choice == 2)
        {
            view_complain();
        }

        else if (choice == 3)
        {
            cout << "Exiting program..." << endl;
            break;
        }
        else
        {
            cout << "Invalid choice";
        }
    }
}
void Student::mess_menu()
{
    while (true)
    {
        int choice;
        cout << endl;
        cout << "******-Student Mess Menu-******" << endl
             << "1. Raise Complain: " << endl
             << "2. View Complain: " << endl
             << "3. Back: " << endl;
        cin >> choice;

        if (choice == 1)
        {
            raise_complain("mess");
        }
        else if (choice == 2)
        {
            view_complain();
        }
        else if (choice == 3)
        {
            break;
        }
        else
        {
            cout << "Enter A valid choice: ";
        }
    }
}
void Student ::college_menu()
{
    int choice;
    while (true)
    {
        cout << "******-Student College Menu-******" << endl;
        cout << "1. Add Complaint" << endl;
        cout << "2. View My Complaint" << endl;
        cout << "3. Back" << endl;
        cout << "Enter Your Choice : ";
        cin >> choice;

        if (choice == 1)
        {
            raise_complain("college");
        }
        else if (choice == 2)
        {
            view_complain();
        }
        else if (choice == 3)
        {
            break;
        }
        else
        {
            cout << "Enter A Valid choice: " << endl;
        }
        
        
        
    }
}
void Student ::run()
{
    int choice;
    while (true)
    {
        cout << "\n-------- Student Portal --------" << endl;
        cout << "1. For Mess Complaint" << endl;
        cout << "2. For hostel Complaint" << endl;
        cout << "3. For college Complaint" << endl;
        cout << "4. Exit" << endl;
        cin >> choice;

        if (choice == 1)
        {
            mess_menu();
        }
        else if (choice == 2)
        {
            hostel_menu();
        }
        else if (choice == 3)
        {
            college_menu();
        }
        
        else if (choice == 4)
        {
            break;
        }
        else
        {
            cout << "Invalid choice";
        }
    }
}

void Admin ::run()
{
    while (true)
    {
        int choice;
        cout << endl;
        cout << "******-Admin Menu-******" << endl;
        cout << "1. View Mess Complains: " << endl
             << "2. View Hostel Complains: " << endl
             << "3. View College Complains: " << endl
             << "4. Logout: " << endl;
        cin >> choice;

        if (choice == 1)
        {
            specific_complain("mess");
        }
        else if (choice == 2)
        {
            specific_complain("hostel");
        }
        else if (choice == 3)
        {
            specific_complain("college");
        }
        else if (choice == 4)
        {
            break;
        }

        else
        {
            cout << "Please Enter Valid choice: ";
        }
    }
}

void Warden ::run()
{
    while (true)
    {

        int choice;
        cout << endl;
        cout << "******-Warden Menu-******" << endl;
        cout << "1. View Mess Complains: " << endl
             << "2. View Hostel Complains: " << endl
             << "3. Logout: " << endl;
        cin >> choice;

        if (choice == 1)
        {
            specific_complain("mess");
        }
        else if (choice == 2)
        {
            specific_complain("hostel");
        }
        else if (choice == 3)
        {
            break;
        }

        else
        {
            cout << "Please Enter Valid choice: ";
        }
    }
}

int main()
{
    Student s1;
    Admin a1;
    Warden w1;
    while (true)
    {
        int choice;

        cout << "\n-------- Welcome Arya College Complaint System --------" << endl;
        cout << "1. Student Portal" << endl;
        cout << "2. Admin Portal" << endl;
        cout << "3. Warden Portal " << endl;
        cout << "4. Exit" << endl;
        cout << "Enter Your Choice: ";
        cin >> choice;

        if (choice == 1)
        {
            s1.run();
        }
        else if (choice == 2)
        {
            a1.run();
        }
        else if (choice == 3)
        {
            w1.run();
        }
        else if (choice == 4)
        {
            break;
        }
        else
        {
            cout << "invalid choice";
        }
    }
    return 0;
}