#include <iostream>
#include <fstream>
using namespace std;

class CollegeComplaint
{
private:
    void readID();
    void displayComplaint();
protected:
    string name;
    string roll_no;
    string title;
    string details;
    string status;
    const string file_name = "college_complaint.txt";
    int ID = 0;


public:

    void addComplaint();
    void viewMyComplaint();
    void deleteComplaint();
    void menu();
};
void CollegeComplaint ::readID()
{
    ifstream infile(file_name, ios::in);
    string line;
    while (getline(infile, line))
    {
        ID = stoi(line);

        for (int i = 0; i < 6; i++)
        {
            getline(infile, line);
        }
    }

    infile.close();
}


void CollegeComplaint ::addComplaint()
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
    outfile << "END................." << endl;
    outfile.close();
}

void CollegeComplaint ::viewMyComplaint()
{
    string fileID;
    string fileName;
    string fileRoll;
    string fileTitle;
    string fileDetails;
    string fileStatus;
    string endMarker;
    string searchRoll;

    cout << "Enter Roll Number : ";
    getline(cin, searchRoll);

    ifstream infile(file_name, ios ::in);
    bool found = false;
    if (!infile.is_open())
    {
        cout << "File not Found!" << endl;
        return;
    }
    else
    {  
        while (getline(infile, fileID))
        {
            getline(infile, fileName);
            getline(infile, fileRoll);
            getline(infile, fileTitle);
            getline(infile, fileDetails);
            getline(infile, fileStatus);
            getline(infile, endMarker);
            if (searchRoll == fileRoll)
            {
                found = true;
                cout << "==================================" << endl;
                cout << "Complaint ID : " << fileID << endl;
                cout << "Name         : " << fileName << endl;
                cout << "Roll No      : " << fileRoll << endl;
                cout << "Title        : " << fileTitle << endl;
                cout << "Details      : " << fileDetails << endl;
                cout << "Status       : " << fileStatus << endl;
                cout << "==================================" << endl;
            }
        }
    }
    infile.close();
    if (!found)
    {
        cout << "Roll No not Found...." << endl;
    }
}

void CollegeComplaint :: deleteComplaint()
{
    
}
void CollegeComplaint ::menu()
{
    int choice;
    cout << "====================================" << endl;
    cout << "      College Complaint System" << endl;
    cout << "====================================" << endl;
    cout << "1.Add Complaint" << endl
         << "2.View Complaint" << endl
         << "3.Back" << endl
         << "4.Exit" << endl
         << "Enter Your Choice : ";
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
        return;
    case 4:
        exit(0);
    default:
        cout << "Invalid Choice" << endl;
        cout << "Press Enter to Continue......";
        cin.get();
    }
}


