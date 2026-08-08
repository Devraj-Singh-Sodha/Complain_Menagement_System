#include <iostream>
#include <fstream>

using namespace std;

class hostelcomplaint
{
private:
    string studentname;
    string roomNumber;
    string category; // like electicalissue,plumbing issue,wifi
    string problem;
    string status;
    string urgency;
    const string file_name = "hostel_complaint.txt";

public:
    void addComplaint();
    void searchComplaint();
    void viewAllComplaints();
    void mainmenu();
};

void hostelcomplaint::addComplaint()
{

    cout << "enter your name:" << endl;
    getline(cin, studentname);

    cout << "enter the roomnumber:" << endl;
    getline(cin, roomNumber);

    cout << "enter the category(ex electricity,plumbing,wifi):" << endl;
    getline(cin, category);

    cout << "enetr the problem" << endl;
    getline(cin, problem);

    cout << "how urgent it is rate it from 1-5(1.very inportant-5.not very important)";
    getline(cin, urgency);

    status = "pending";

    ofstream outfile(file_name, ios::app);
    if (!outfile.is_open())
    {
        cout << "Error opening file for writing!" << endl;
        return;
    }

    outfile << studentname << endl;
    outfile << roomNumber << endl;
    outfile << category << endl;
    outfile << problem << endl;
    outfile << urgency << endl;
    outfile << status << endl;
    outfile << "END................." << endl;
    outfile.close();

    cout << "complaint registered successfully";
}

void hostelcomplaint::searchComplaint()
{

    string fileName;
    string fileRoomNumber;
    string fileCategory;
    string fileProblem;
    string fileStatus;
    string fileUrgency;
    string endMarker;
    string searchRoomNumber;

    cout << "Enter Room Number : ";
    getline(cin, searchRoomNumber);

    ifstream infile(file_name, ios ::in);
    bool found = false;
    if (!infile.is_open())
    {
        cout << "File not Found!" << endl;
        return;
    }
    else
    {
        while (getline(infile, fileName))
        {
            getline(infile, fileRoomNumber);
            getline(infile, fileCategory);
            getline(infile, fileProblem);
            getline(infile, fileUrgency);
            getline(infile, fileStatus);
            getline(infile, endMarker);
            if (searchRoomNumber == fileRoomNumber)
            {
                found = true;
                cout << "==================================" << endl;
                cout << "Name         : " << fileName << endl;
                cout << "Roll No      : " << fileRoomNumber << endl;
                cout << "Title        : " << fileCategory << endl;
                cout << "Details      : " << fileProblem << endl;
                cout << "urgency      : " << fileUrgency << endl;
                cout << "Status       : " << fileStatus << endl;
                cout << "==================================" << endl;
            }
        }
    }
    infile.close();
    if (!found)
    {
        cout << "Room number not Found...." << endl;
    }
}
void hostelcomplaint::viewAllComplaints()
{
    ifstream infile(file_name, ios::in);

    if (!infile.is_open())
    {
        cout << "File not Found or no complaints registered yet!" << endl;
        return;
    }

    string fileName, fileRoomNumber, fileCategory, fileProblem, fileUrgency, fileStatus, endMarker;
    bool hasRecords = false;

    cout << "\n================ ALL REGISTERED COMPLAINTS ================\n"
         << endl;

    while (getline(infile, fileName))
    {
        getline(infile, fileRoomNumber);
        getline(infile, fileCategory);
        getline(infile, fileProblem);
        getline(infile, fileUrgency);
        getline(infile, fileStatus);
        getline(infile, endMarker); 

        hasRecords = true; 

        cout << "Name      : " << fileName << endl;
        cout << "Room No   : " << fileRoomNumber << endl;
        cout << "Category  : " << fileCategory << endl;
        cout << "Details   : " << fileProblem << endl;
        cout << "Urgency   : " << fileUrgency << endl;
        cout << "Status    : " << fileStatus << endl;
        cout << "----------------------------------------------------" << endl;
    }

    infile.close();

    if (!hasRecords)
    {
        cout << "No complaints found in the file." << endl;
    }
}

void hostelcomplaint::mainmenu()
{

    string choice;
    cout << "----------*----------*----------*" << endl;
    cout << "     Hostel Compalint System      " << endl;
    cout << "----------*----------*----------*" << endl;
    cout << "1.Add compalint" << endl
         << "2.search complaint" << endl
         << "3.view all complaint" << endl
         << "4.exit" << endl
         << "enter your choice" << endl;

    getline(cin, choice);

    if (choice == "1")
    {
        addComplaint();
    }
    else if (choice == "2")
    {
        searchComplaint();
    }
    else if (choice == "3")
    {
        viewAllComplaints();
    }
    else if (choice == "4")
    {
        cout << "Exiting program..." << endl;
    }
    else
    {
        cout << "Invalid choice";
    }
}

int main()
{

    hostelcomplaint student;
    while (1)
    {

        student.mainmenu();
    }
}
