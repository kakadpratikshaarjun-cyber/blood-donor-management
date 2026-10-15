#include <iostream>
using namespace std;

struct Donor {
    int id;
    string name, blood;
    Donor* next;
};

Donor *s = NULL, *q = NULL;

// Create Donor
Donor* create() {
    Donor* n = new Donor;
    cout << "Enter ID, Name, Blood Group: ";
    cin >> n->id >> n->name >> n->blood;
    n->next = n;
    return n;
}

// Stack Push
void push() {
    Donor* n = create();

    if (s == NULL)
        s = n;
    else {
        n->next = s->next;
        s->next = n;
    }
    cout << "Pushed Successfully!\n";
}

// Stack Pop
void pop() {
    if (s == NULL) {
        cout << "Stack Empty!\n";
        return;
    }

    Donor* t = s->next;

    if (s == t)
        s = NULL;
    else
        s->next = t->next;

    delete t;
    cout << "Popped Successfully!\n";
}

// Queue Enqueue
void enqueue() {
    Donor* n = create();

    if (q == NULL)
        q = n;
    else {
        n->next = q->next;
        q->next = n;
        q = n;
    }
    cout << "Enqueued Successfully!\n";
}

// Queue Dequeue
void dequeue() {
    if (q == NULL) {
        cout << "Queue Empty!\n";
        return;
    }

    Donor* t = q->next;

    if (q == t)
        q = NULL;
    else
        q->next = t->next;

    delete t;
    cout << "Dequeued Successfully!\n";
}

// Display Donors
void display(Donor* last) {
    if (last == NULL) {
        cout << "List Empty!\n";
        return;
    }

    Donor* t = last->next;

    do {
        cout << t->id << " "
             << t->name << " "
             << t->blood << endl;

        t = t->next;
    } while (t != last->next);
}

// Search Donor
void search(Donor* last) {
    if (last == NULL) {
        cout << "List Empty!\n";
        return;
    }

    string bg;
    bool found = false;

    cout << "Enter Blood Group: ";
    cin >> bg;

    Donor* t = last->next;

    do {
        if (t->blood == bg) {
            cout << t->id << " "
                 << t->name << " "
                 << t->blood << endl;
            found = true;
        }
        t = t->next;
    } while (t != last->next);

    if (!found)
        cout << "Donor Not Found!\n";
}

// Main Function
int main() {
    int ch;

    do {
        cout << "\n--- BLOOD DONOR MANAGEMENT ---\n";
        cout << "1. Push Stack\n";
        cout << "2. Pop Stack\n";
        cout << "3. Enqueue Queue\n";
        cout << "4. Dequeue Queue\n";
        cout << "5. Display Stack\n";
        cout << "6. Display Queue\n";
        cout << "7. Search Stack\n";
        cout << "8. Search Queue\n";
        cout << "9. Exit\n";

        cout << "Enter Choice: ";
        cin >> ch;

        switch(ch) {
            case 1: push(); break;
            case 2: pop(); break;
            case 3: enqueue(); break;
            case 4: dequeue(); break;
            case 5: display(s); break;
            case 6: display(q); break;
            case 7: search(s); break;
            case 8: search(q); break;
            case 9: cout << "Exit!\n"; break;
            default: cout << "Invalid Choice!\n";
        }

    } while(ch != 9);

    return 0;
}
