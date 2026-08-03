#include <bits/stdc++.h>
using namespace std;

class Complaint {
public:
    string complain_id;
    string student_name;
    string complain;
    bool status; // false = Pending, true = Resolved

    Complaint(string id, string name, string query)
        : complain_id(id), student_name(name), complain(query), status(false) {}

    void view() const {
        cout << "Complain ID: " << complain_id << endl;
        cout << "Student Name: " << student_name << endl;
        cout << "Complain: " << complain << endl;
        cout << "Status: " << (status ? "Resolved" : "Pending") << endl;
        cout << "-----------------------------" << endl;
    }
};

class Mess_complain {
private:
    vector<Complaint> complaints;
    int next_id = 1;
    int choice;

    // Reads an integer choice safely; returns -1 on bad input.
    int read_choice() {
        int c;
        cin >> c;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return -1;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clear trailing newline
        return c;
    }

    void raise_complain() {
        string name, query;
        cout << "Enter your name: ";
        getline(cin, name);
        cout << "Enter your Complain: ";
        getline(cin, query);

        string id = "C" + to_string(next_id++);
        complaints.emplace_back(id, name, query);

        cout << "Your Complain is registered with ID " << id << endl
             << "We are working on it" << endl;
    }

    void view_all_complaints() {
        if (complaints.empty()) {
            cout << "No complaints found." << endl;
            return;
        }
        for (const auto& c : complaints) c.view();
    }

    void view_own_complaints(const string& name) {
        bool found = false;
        for (const auto& c : complaints) {
            if (c.student_name == name) {
                c.view();
                found = true;
            }
        }
        if (!found) cout << "No complaints found for " << name << endl;
    }

    void update_status() {
        cout << "Enter Complain ID to update: ";
        string id;
        cin >> id;
        for (auto& c : complaints) {
            if (c.complain_id == id) {
                c.status = true;
                cout << "Status updated to Resolved." << endl;
                return;
            }
        }
        cout << "Complain ID not found." << endl;
    }

    void search_complain() {
        cout << "Enter Complain ID or Student Name to search: ";
        string key;
        cin.ignore();
        getline(cin, key);
        bool found = false;
        for (const auto& c : complaints) {
            if (c.complain_id == key || c.student_name == key) {
                c.view();
                found = true;
            }
        }
        if (!found) cout << "No matching complaint found." << endl;
    }

    void display_menu() {
        cout << "\n******-Mess Complain-******" << endl
             << "1. Student" << endl
             << "2. Mess-Incharge" << endl
             << "3. Admin" << endl
             << "4. Exit" << endl
             << "Enter choice: ";
        choice = read_choice();
    }

    void student_menu() {
        int c;
        do {
            cout << "\n******-Student Menu-******" << endl
                 << "1. Raise Complain" << endl
                 << "2. View My Complains" << endl
                 << "3. Back" << endl
                 << "Enter choice: ";
            c = read_choice();

            if (c == 1) {
                raise_complain();
            } else if (c == 2) {
                string name;
                cout << "Enter your name: ";
                getline(cin, name);
                view_own_complaints(name);
            } else if (c != 3) {
                cout << "Please enter a valid choice." << endl;
            }
        } while (c != 3);
    }

    void mess_incharge_menu() {
        int c;
        do {
            cout << "\n1. View Complains" << endl
                 << "2. Update Status" << endl
                 << "3. Search Complain" << endl
                 << "4. Logout" << endl
                 << "Enter choice: ";
            c = read_choice();

            if (c == 1) view_all_complaints();
            else if (c == 2) update_status();
            else if (c == 3) search_complain();
            else if (c != 4) cout << "Please enter a valid choice." << endl;
        } while (c != 4);
    }

    void admin_menu() {
        int c;
        do {
            cout << "\n1. View Complains" << endl
                 << "2. Search Complains" << endl
                 << "3. Logout" << endl
                 << "Enter choice: ";
            c = read_choice();

            if (c == 1) view_all_complaints();
            else if (c == 2) search_complain();
            else if (c != 3) cout << "Please enter a valid choice." << endl;
        } while (c != 3);
    }

public:
    void run() {
        while (true) {
            display_menu();

            if (choice == 1) student_menu();
            else if (choice == 2) mess_incharge_menu();
            else if (choice == 3) admin_menu();
            else if (choice == 4) break;
            else cout << "Please Enter Valid Choice: " << endl;
        }
    }
};

int main() {
    Mess_complain m1;
    m1.run();
    return 0;
}