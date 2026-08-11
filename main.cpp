
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
    void view_all_complains(string loc);
    void raise_complain();
    void view_complain();
    void searchComplaint(string location);
};
void Complain_Manegement::searchComplaint(string location)
{
    ifstream file(location);

    if (!file.is_open())
    {
        cout << "File not found!" << endl;
        return;
    }

    string searchValue;

    cout << "Enter Roll Number: ";
    getline(cin, searchValue);

    string name;
    string roll;
    string title;
    string detail;
    string separator;

    bool found = false;

    while (getline(file, name))
    {
        if (!getline(file, roll))
            break;

        if (!getline(file, title))
            break;

        if (!getline(file, detail))
            break;

        if (!getline(file, separator))
            break;

        if (roll == searchValue)
        {
            found = true;

            cout << "\n========== COMPLAINT ==========" << endl;
            cout << "Student Name : " << name << endl;
            cout << "Roll Number  : " << roll << endl;
            cout << "Title        : " << title << endl;
            cout << "Detail       : " << detail << endl;
            cout << "===============================" << endl;
        }
    }

    file.close();

    if (!found)
    {
        cout << "\nComplaint not found!" << endl;
    }
}
class hostelcomplaint : public Complain_Manegement
{
private:
    string roomNumber;

public:
    void mainmenu();
    void addComplaint();
};
class Mess : public Complain_Manegement
{
public:
    int choice;
    void saveFile();
    void display_menu();
    void student_menu();
    void Warden();
    void admin_munu();
    void run();
};
void hostelcomplaint ::mainmenu()
{
    int choice;
    while (true)
    {
        cout << "----------*----------*----------*" << endl;
        cout << "     Hostel Compalint System      " << endl;
        cout << "----------*----------*----------*" << endl;
        cout << "1.Add compalint" << endl
             << "2.search complaint" << endl
             << "3.view all complaint" << endl
             << "4.exit" << endl
             << "enter your choice" << endl;

        cin >> choice;
        cin.ignore();

        if (choice == 1)
        {
            addComplaint();
        }
        else if (choice == 2)
        {
            searchComplaint("hostel");
        }
        else if (choice == 3)
        {
            view_all_complains("hostel");
        }
        else if (choice == 4)
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
void hostelcomplaint::addComplaint()
{
    cout << "enter your name: " << endl;
    getline(cin, student_name);

    cout << "enter the roomnumber:" << endl;
    getline(cin, roomNumber);

    cout << "enter the category(ex electricity,plumbing,wifi):" << endl;
    getline(cin, complain_title);

    cout << "enetr the problem" << endl;
    getline(cin, complain_detail);

    ofstream outfile("Complaints/hostel.txt", ios::app);
    if (!outfile.is_open())
    {
        cout << "Error opening file for writing!" << endl;
        return;
    }

    outfile << student_name << endl;
    outfile << roomNumber << endl;
    outfile << complain_title << endl;
    outfile << complain_detail << endl;
    outfile << "END................." << endl;
    outfile.close();

    cout << "complaint registered successfully";
}

void Complain_Manegement ::view_all_complains(string loc)
{
    string Address = "Complaints/" + loc + ".txt";

    ifstream file(Address);

    if (!file.is_open())
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

void Mess::student_menu()
{
    cout << endl;
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
    cout << endl;
    cout << "******-Admin Menu-******" << endl;
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
            Warden();
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
void Mess::Warden()
{
    cout << endl;
    while (true)
    {
        cout << "******-Mess-Incharge Menu-******" << endl;
        cout << "1. View Complains: " << endl
             //<< "2. Update Status: " << endl
             << "2. Search complain: " << endl
             << "3. Logout: " << endl;
        cin >> choice;

        if (choice == 1)
        {
            view_all_complains("mess");
        }

        else if (choice == 2)
        {
            string loc = "Complaints/mess.txt";
            searchComplaint(loc);
        }
        else if (choice == 3)
        {
            break;
        }

        else
        {
            cout << "invalid choice";
        }
    }
}
void Mess::display_menu()
{
    cout << "******-Student Portal-******" << endl
         << "1. College Related Problem: " << endl
         << "2. Mess Related Problem: " << endl
         << "3. Hostel Related Problem: " << endl
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
    vector<Mess> mess(1);
    // vector<hostelcomplaint> hostel;
    hostelcomplaint h; // One Mess object stored dynamically

    while (true)
    {
        int choice;

        // cout << "\n-------- Welcome Arya College Complaint System --------" << endl;
        // cout << "1. For Mess Complaint" << endl;
        // cout << "2. For hostel Complaint" << endl;
        // cout << "3. For college Complaint" << endl;
        // cout << "4. Exit" << endl;
        // cout << "Enter Your Choice: ";
        // cin >> choice;
        cout << "\n-------- Welcome Arya College Complaint System --------" << endl;
        cout << "1. Student Portal" << endl;
        cout << "2. Admin Portal" << endl;
        cout << "3. Warden Portal " << endl;
        cout << "4. Exit" << endl;
        cout << "Enter Your Choice: ";
        cin >> choice;

        if (choice == 1)
        {
            mess[0].run();
        }
        else if (choice == 2)
        {
            h.mainmenu();
        }
        else
        {
            cout << "invalid choice";
        }
    }

    return 0;
}
