#include <iostream>
using namespace std;

class Members {
private:
    string member_name;
    int member_age;

public:
    int member_id;

    void read();
    void display() const;
};

void Members::read() {
    cout << "Enter membership ID: ";
    cin >> member_id;
    cout << "Enter member name: ";
    cin>>"member_name";
    cout << "Enter member age: ";
    cin >> member_age;
}

void Members::display() const {
    cout << "\nMembership ID: " << member_id;
    cout << "\nMember Name: " << member_name;
    cout << "\nMember Age: " << member_age << endl;
}

// Function prototypes
void acceptMembers(Members m[], int& n);
void displayMembers(const Members m[], int n);
void insertMember(Members m[], int& n);
void deleteMember(Members m[], int& n);
void searchMember(const Members m[], int n);
void updateMember(Members m[], int n);
void sortMembers(Members m[], int n);

int main() {
    Members m[50];
    int n = 0; // Number of members
    int choice;

    do {
        cout << "\nMenu:\n";
        cout << "1. Accept\n";
        cout << "2. Display\n";
        cout << "3. Insert\n";
        cout << "4. Delete\n";
        cout << "5. Search\n";
        cout << "6. Update\n";
        cout << "7. Sort\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            acceptMembers(m, n);
            break;
        case 2:
            displayMembers(m, n);
            break;
        case 3:
            insertMember(m, n);
            break;
        case 4:
            deleteMember(m, n);
            break;
        case 5:
            searchMember(m, n);
            break;
        case 6:
            updateMember(m, n);
            break;
        case 7:
            sortMembers(m, n);
            break;
        case 8:
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid choice, please enter a number between 1 and 8." << endl;
            break;
        }

    } while (choice != 8);

    return 0;
}

// Function definitions
void acceptMembers(Members m[], int& n) {
    cout << "\nHow many members? ";
    cin >> n;
    if (n > 50) {
        cout << "Cannot accept more than 50 members." << endl;
        n = 50; // Set to maximum allowed
    }
    for (int i = 0; i < n; i++) {
        m[i].read();
    }
}

void displayMembers(const Members m[], int n) {
    if (n == 0) {
        cout << "No members to display." << endl;
    } else {
        cout << "\nMember Details:\n";
        for (int i = 0; i < n; i++) {
            m[i].display();
        }
    }
}

void insertMember(Members m[], int& n) {
    if (n >= 50) {
        cout << "Cannot insert more members." << endl;
        return;
    }
    int loc;
    cout << "\nEnter the position to insert (1 to " << n + 1 << "): ";
    cin >> loc;
    if (loc < 1 || loc > n + 1) {
        cout << "Invalid position." << endl;
        return;
    }
    for (int i = n; i >= loc; i--) {
        m[i] = m[i - 1];
    }
    m[loc - 1].read();
    n++;
}

void deleteMember(Members m[], int& n) {
    if (n == 0) {
        cout << "No members to delete." << endl;
        return;
    }
    int del_id;
    cout << "\nEnter the membership ID to delete: ";
    cin >> del_id;
    bool found = false;
    for (int i = 0; i < n; i++) {
        if (m[i].member_id == del_id) {
            found = true;
            for (int j = i; j < n - 1; j++) {
                m[j] = m[j + 1];
            }
            n--;
            cout << "Member deleted." << endl;
            break;
        }
    }
    if (!found) {
        cout << "Member not found." << endl;
    }
}

void searchMember(const Members m[], int n) {
    if (n == 0) {
        cout << "No members to search." << endl;
        return;
    }
    int search_id;
    cout << "\nEnter the membership ID to search: ";
    cin >> search_id;
    bool found = false;
    for (int i = 0; i < n; i++) {
        if (m[i].member_id == search_id) {
            found = true;
            cout << "Member found at position " << i + 1 << ":" << endl;
            m[i].display();
            break;
        }
    }
    if (!found) {
        cout << "Member not found." << endl;
    }
}

void updateMember(Members m[], int n) {
    if (n == 0) {
        cout << "No members to update." << endl;
        return;
    }
    int update_id;
    cout << "\nEnter the membership ID to update: ";
    cin >> update_id;
    bool found = false;
    for (int i = 0; i < n; i++) {
        if (m[i].member_id == update_id) {
            found = true;
            cout << "Updating member at position " << i + 1 << ":" << endl;
            m[i].read();
            break;
        }
    }
    if (!found) {
        cout << "Member not found." << endl;
    }
}

void sortMembers(Members m[], int n) {
    if (n == 0) {
        cout << "No members to sort." << endl;
        return;
    }
    Members temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (m[j].member_id > m[j + 1].member_id) {
                temp = m[j];
                m[j] = m[j + 1];
                m[j + 1] = temp;
            }
        }
    }
    cout << "Members sorted by ID." << endl;
}
