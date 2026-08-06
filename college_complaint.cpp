#include <iostream>
#include <fstream>
#include <cstdio>
using namespace std;

class BaseComplaint
{
protected:
    string name;
    string roll_no;
    string title;
    string details;
    string status;
    string file_name;
    int ID = 0;
    struct FileData
    {
        string id, name, roll, title, details, status, endMarker;
    };
    bool readRecord(ifstream & infile, FileData & data);
    void printRecord(FileData data);
    void writeRecord(ofstream& outfile, FileData data);
    void readID();

public:
    BaseComplaint(string f_name)
    {
        file_name = f_name;
    }
    void addComplaint();
    void viewMyComplaint();
    void deleteComplaint();
    bool findComplaint(string searchRoll);
    void updateComplaintStatus();
    void viewAllComplaint();
    void studentMenu();
    void adminMenu();
    void run();
};

bool BaseComplaint::readRecord(ifstream& infile, FileData& data) {
    if (getline(infile, data.id)) {
        getline(infile, data.name);
        getline(infile, data.roll);
        getline(infile, data.title);
        getline(infile, data.details);
        getline(infile, data.status);
        getline(infile, data.endMarker);
        return true;
    }
    return false; 
}

void BaseComplaint::printRecord(FileData data) {
    cout << "==================================" << endl;
    cout << "Complaint ID : " << data.id << endl;
    cout << "Name         : " << data.name << endl;
    cout << "Roll No      : " << data.roll << endl;
    cout << "Title        : " << data.title << endl;
    cout << "Details      : " << data.details << endl;
    cout << "Status       : " << data.status << endl;
    cout << "==================================" << endl;
}

void BaseComplaint::writeRecord(ofstream& outfile, FileData data) {
    outfile << data.id << endl;
    outfile << data.name << endl;
    outfile << data.roll << endl;
    outfile << data.title << endl;
    outfile << data.details << endl;
    outfile << data.status << endl;
    outfile << data.endMarker << endl;
}

class CollegeComplaint : public BaseComplaint
{
public:
    CollegeComplaint() : BaseComplaint("Complaints/college.txt") {}
};

void BaseComplaint ::readID()
{
    ifstream infile(file_name, ios::in);
    string line;
    while (getline(infile, line))
    {
        if (line.empty())
            continue;

        ID = stoi(line);

        for (int i = 0; i < 6; i++)
            getline(infile, line);
    }

    infile.close();
}

bool BaseComplaint ::findComplaint(string searchRoll)
{
    ifstream infile(file_name);
    if (!infile.is_open()) return false;

    FileData data;
    bool found = false;
    {
        while (readRecord(infile, data)){
            if (searchRoll == data.roll)
            {
                printRecord(data);
            }
        }
    }
    infile.close();
    if (!found)
    {
        cout << "Roll No not Found...." << endl;
    }
    return found;
}

void BaseComplaint ::addComplaint()
{
    readID();
    ID++;

    cout << "Enter Your Name : ";
    getline(cin, name);
    cout << "Enter Your Roll No : ";
    getline(cin, roll_no);
    cout << "Enter Complaint Title : ";
    getline(cin, title);
    cout << "Enter Complaint Details : ";
    getline(cin, details);
    status = "Pending";

    ofstream outfile(file_name, ios::app);
    outfile << ID << endl;
    outfile << name << endl;
    outfile << roll_no << endl;
    outfile << title << endl;
    outfile << details << endl;
    outfile << status << endl;
    outfile << "_____________________" << endl;
    outfile.close();
}

void BaseComplaint ::viewMyComplaint()
{
    string searchRoll;
    cout << "Enter Your Roll No";
    getline(cin, searchRoll);
    findComplaint(searchRoll);
}

void BaseComplaint ::deleteComplaint()
{
    string searchRoll;
    cout << "Enter Your Roll NO : ";
    getline(cin, searchRoll);
    if (findComplaint(searchRoll))
    {
        int deleteID;
        cout << "Enter Your ID : ";
        cin >> deleteID;
        cin.ignore();

        ifstream infile(file_name);
        ofstream outfile("temp.txt");
        FileData data;
        bool deleted = false;
        while (readRecord(infile, data))
        {
            if (deleteID == stoi(data.id) && searchRoll == data.roll)
            {
                deleted = true;
                continue;
            }
            writeRecord(outfile, data);
        }
        infile.close();
        outfile.close();
        remove(file_name.c_str());
        rename("temp.txt", file_name.c_str());
        if (deleted)
            cout << "Complaint Deleted Successfully." << endl;
        else
            cout << "Complaint ID Not Found." << endl;
    }
}
void BaseComplaint::viewAllComplaint()
{
    ifstream infile(file_name);

    if (!infile.is_open())
    {
        cout << "File Not Found!" << endl;
        return;
    }
    FileData data;
    bool found = false;

    while (readRecord(infile ,data))
    {
        found = true;

        printRecord(data);
    }

    infile.close();

    if (!found)
    {
        cout << "No Complaint Found." << endl;
    }
}
void BaseComplaint::updateComplaintStatus()
{
    viewAllComplaint();

    int updateID;
    cout << "Enter Complaint ID : ";
    cin >> updateID;
    cin.ignore();

    int choice;
    cout << "\nSelect New Status\n";
    cout << "1. Pending\n";
    cout << "2. In Progress\n";
    cout << "3. Resolved\n";
    cout << "Enter Choice : ";
    cin >> choice;
    cin.ignore();

    string newStatus;

    switch (choice)
    {
    case 1:
        newStatus = "Pending";
        break;
    case 2:
        newStatus = "In Progress";
        break;
    case 3:
        newStatus = "Resolved";
        break;
    default:
        cout << "Invalid Choice!" << endl;
        return;
    }

    ifstream infile(file_name);
    ofstream outfile("temp.txt");
    FileData data;
    bool updated = false;

    while (readRecord(infile, data))
    {
        if (updateID == stoi(data.id))
        {
            data.status = newStatus;
            updated = true;
        }
        writeRecord(outfile, data);
    }

    infile.close();
    outfile.close();

    remove(file_name.c_str());
    rename("temp.txt", file_name.c_str());

    if (updated)
        cout << "Complaint Status Updated Successfully." << endl;
    else
        cout << "Complaint ID Not Found." << endl;
}

void BaseComplaint::studentMenu()
{
    int choice;

    while (true)
    {
        cout << "\n====================================" << endl;
        cout << "     Student Complaint Menu" << endl;
        cout << "====================================" << endl;
        cout << "1. Add Complaint" << endl;
        cout << "2. View My Complaint" << endl;
        cout << "3. Delete Complaint" << endl;
        cout << "4. Back" << endl;
        cout << "Enter Your Choice : ";
        cin >> choice;
        cin.ignore();

        switch (choice)
        {
        case 1:
            addComplaint();
            break;
        case 2:
            viewMyComplaint();
            break;
        case 3:
            deleteComplaint();
            break;
        case 4:
            return;
        default:
            cout << "Invalid Choice!" << endl;
        }
        cout << "\nPress Enter to Continue...";
        cin.get();
    }
}

void BaseComplaint::adminMenu()
{
    int choice;

    while (true)
    {
        cout << "\n====================================" << endl;
        cout << "         Admin Menu" << endl;
        cout << "====================================" << endl;
        cout << "1. View All Complaints" << endl;
        cout << "2. Update Complaint Status" << endl;
        cout << "3. Back" << endl;
        cout << "Enter Your Choice : ";
        cin >> choice;
        cin.ignore();

        switch (choice)
        {
        case 1:
            viewAllComplaint();
            break;
        case 2:
            updateComplaintStatus();
            break;
        case 3:
            return;
        default:
            cout << "Invalid Choice!" << endl;
        }
        cout << "\nPress Enter to Continue...";
        cin.get();
    }
}

void BaseComplaint::run()
{
    int choice;

    while (true)
    {
        cout << "\n===== College Complaint System =====\n";
        cout << "1. Student\n";
        cout << "2. Admin\n";
        cout << "3. Back\n";
        cout << "4. Exit\n";
        cout << "Enter Choice : ";
        cin >> choice;
        cin.ignore();

        switch (choice)
        {
        case 1:
            studentMenu();
            break;

        case 2:
            adminMenu();
            break;

        case 3:
            return;

        case 4:
            exit(0);

        default:
            cout << "Invalid Choice!" << endl;
        }
    }
}