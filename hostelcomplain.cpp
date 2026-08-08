#include <iostream>
using namespace std;

class hostelcomplaint
{
private:
    string studentname;
    int roomNumber;
    string category; // like electicalissue,plumbing issue,wifi
    string problem;
    string status;
    public:
    void addComplaint();
    void viewComplaint();
    void mainmenu();
};

void hostelcomplaint::addComplaint()
{

    cout << "enter your name:" << endl;
    cin >> studentname;
    cout << "enter the roomnumber:" << endl;
    cin >> roomNumber;
    cout << "enter the category(ex electricity,plumbing,wifi):" << endl;
    cin >> category;
    cout << "enetr the problem" << endl;
    cin >> problem;
    status = "pending";

    cout<<"complaint registered successfully";
}

void hostelcomplaint::viewComplaint()
{
    cout << "Complaint Details" << endl;
    cout << studentname << endl;
    cout << roomNumber << endl;
    cout << category << endl;
    cout << problem << endl;
    cout << status << endl;
}

void hostelcomplaint::mainmenu()
{

    int choice;
    cout << "----------*----------*----------*" << endl;
    cout << "     Hostel Compalint System      " << endl;
    cout << "----------*----------*----------*" << endl;
    cout << "1.Add compalint" << endl
         << "2.view complaint" << endl
         << "enter your choice" << endl;

    cin >> choice;
    if (choice == 1)
    {
        addComplaint();
    }
    else if (choice == 2)
    {
        viewComplaint();
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

//generate a complaint id
//add searchig by complaints under specific room
//give problems a range how much it is necessary
//add array for storing all compliants

