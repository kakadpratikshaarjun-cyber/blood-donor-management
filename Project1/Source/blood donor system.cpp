#include <iostream>
#include <string>
using namespace std;

struct Donor {
    int id, age;
    string name, bloodGroup, contact;
    Donor* next;
};

Donor* head = NULL;

// Add donor
void addDonor() {
    Donor* newNode = new Donor;

    cout << "Enter Donor ID: ";
    cin >> newNode->id;
    cin.ignore();

    cout << "Enter Name: ";
    getline(cin, newNode->name);

    cout << "Enter Age: ";
    cin >> newNode->age;

    cout << "Enter Blood Group: ";
    cin >> newNode->bloodGroup;

    cout << "Enter Contact Number: ";
    cin >> newNode->contact;

    newNode->next = head;
    head = newNode;

    cout << "Donor added successfully.\n";
}

// Delete donor
void deleteDonor() {
    int id;
    cout << "Enter Donor ID to delete: ";
    cin >> id;

    Donor *temp = head, *prev = NULL;

    while (temp != NULL && temp->id != id) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Donor not found.\n";
        return;
    }

    if (prev == NULL)
        head = temp->next;
    else
        prev->next = temp->next;

    delete temp;
    cout << "Donor deleted successfully.\n";
}

// Search donor by blood group
void searchDonor() {
    string group;
    bool found = false;

    cout << "Enter Blood Group: ";
    cin >> group;

    Donor* temp = head;

    while (temp != NULL) {
        if (temp->bloodGroup == group) {
            cout << "\nID: " << temp->id;
            cout << "\nName: " << temp->name;
            cout << "\nAge: " << temp->age;
            cout << "\nBlood Group: " << temp->bloodGroup;
            cout << "\nContact: " << temp->contact << "\n";
            found = true;
        }
        temp = temp->next;
    }

    if (!found)
        cout << "No suitable donor found.\n";
}

// Display all donors
void displayDonors() {
    if (head == NULL) {
        cout << "No donor records available.\n";
        return;
    }

    Donor* temp = head;

    cout << "\n--- Available Donors ---\n";

    while (temp != NULL) {
        cout << "\nID: " << temp->id;
        cout << "\nName: " << temp->name;
        cout << "\nAge: " << temp->age;
        cout << "\nBlood Group: " << temp->bloodGroup;
        cout << "\nContact: " << temp->contact << "\n";
        temp = temp->next;
    }
}

// Main function
int main() {
    int choice;

    do {
        cout << "\n===== Blood Donor Management System =====\n";
        cout << "1. Add Donor\n";
        cout << "2. Delete Donor\n";
        cout << "3. Search Donor\n";
        cout << "4. Display All Donors\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addDonor();
                break;

            case 2:
                deleteDonor();
                break;

            case 3:
                searchDonor();
                break;

            case 4:
                displayDonors();
                break;

            case 5:
                cout << "Exiting program...\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while (choice != 5);

    return 0;
}
