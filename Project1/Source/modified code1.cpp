#include <iostream>
#include <string>
using namespace std;

struct Donor {
    int id, age;
    string name, blood;
    Donor *prev, *next;
};

Donor *top = NULL;
Donor *front = NULL, *rear = NULL;

// Create New Donor
Donor* create() {
    Donor* n = new Donor;

    cout << "Enter ID, Name, Age, Blood Group: ";
    cin >> n->id >> n->name >> n->age >> n->blood;

    n->prev = n->next = NULL;
    return n;
}

// Stack Operations
void push() {
    Donor* n = create();

    n->next = top;

    if (top != NULL)
        top->prev = n;

    top = n;
    cout << "Donor Added to Stack!\n";
}

void pop() {
    if (top == NULL) {
        cout << "Stack Empty!\n";
        return;
    }

    Donor* t = top;
    top = top->next;

    if (top != NULL)
        top->prev = NULL;

    delete t;
    cout << "Donor Removed from Stack!\n";
}

// Queue Operations
void enqueue() {
    Donor* n = create();

    if (rear == NULL)
        front = rear = n;
    else {
        rear->next = n;
        n->prev = rear;
        rear = n;
    }

    cout << "Donor Added to Queue!\n";
}

void dequeue() {
    if (front == NULL) {
        cout << "Queue Empty!\n";
        return;
    }

    Donor* t = front;
    front = front->next;

    if (front != NULL)
        front->prev = NULL;
    else
        rear = NULL;

    delete t;
    cout << "Donor Removed from Queue!\n";
}

// Display Donors
void display(Donor* t) {
    if (t == NULL) {
        cout << "No Donors Available!\n";
        return;
    }

    while (t != NULL) {
        cout << t->id << " " << t->name << " "
             << t->age << " " << t->blood << endl;

        t = t->next;
    }
}

// Search Donor
void search(Donor* t) {
    string bg;
    bool found = false;

    cout << "Enter Blood Group: ";
    cin >> bg;

    while (t != NULL) {
        if (t->blood == bg) {
            cout << t->id << " " << t->name << " "
                 << t->age << " " << t->blood << endl;
            found = true;
        }
        t = t->next;
    }

    if (!found)
        cout << "Donor Not Found!\n";
}

// Main Function
int main() {
    int ch;

    do {
        cout << "\n--- BLOOD DONOR MANAGEMENT ---\n";
        cout << "1. Push (Stack)\n";
        cout << "2. Pop (Stack)\n";
        cout << "3. Enqueue (Queue)\n";
        cout << "4. Dequeue (Queue)\n";
        cout << "5. Display Stack\n";
        cout << "6. Display Queue\n";
        cout << "7. Search Stack\n";
        cout << "8. Search Queue\n";
        cout << "9. Exit\n";

        cout << "Enter Choice: ";
        cin >> ch;

        switch (ch) {
            case 1: push(); break;
            case 2: pop(); break;
            case 3: enqueue(); break;
            case 4: dequeue(); break;
            case 5: display(top); break;
            case 6: display(front); break;
            case 7: search(top); break;
            case 8: search(front); break;
            case 9: cout << "Exit!\n"; break;
            default: cout << "Invalid Choice!\n";
        }

    } while (ch != 9);

    return 0;
}
