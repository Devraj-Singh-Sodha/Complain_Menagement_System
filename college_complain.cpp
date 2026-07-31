#include <iostream>
#include <fstream>
using namespace std;

class CollegeComplaint
{
protected:
    string name;
    string roll_no;
    string title;
    string details;
    string status;
    int ID = 0;
public:


    void readID();
    void addComplaint();
    void viewMyComplaint();
    void searchComplaint();
};
void CollegeComplaint :: readID(){
    ifstream infile("College_Complain.txt", ios::in);
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
    ID++;
}

void CollegeComplaint ::addComplaint()
{

    cout << "Enter Your Name : ";
    getline(cin, name);
    cout << "Enter Your Roll No : ";
    getline(cin,roll_no);
    cout << "Enter Complaint Title : ";
    getline(cin, title);
    cout << "Enter Complaint Details : ";
    getline(cin, details);
    status = "Pending";

    readID();

    ofstream outfile("College_Complain.txt", ios::app);
    outfile << ID << endl;
    outfile << name << endl;
    outfile << roll_no << endl;
    outfile << title << endl;
    outfile << details << endl;
    outfile << status << endl;
    outfile << "END................." << endl;
    outfile.close();
}
