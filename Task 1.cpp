#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int d) : data(d), next(nullptr) {}
};

class LinkedList {
public:
    Node* head;
    LinkedList() : head(nullptr) {}

    void insertAtHead(int data) {
        Node* newnode = new Node(data);
        newnode->next = head;
        head = newnode;
    }

    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL";
    }

    void reverse() {
        Node* prev = nullptr;
        Node* current = head;
        Node* next = nullptr;
        while (current != nullptr) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev; 
    }

    bool search(int value) {
        Node* current = head;
        while (current != nullptr) {
            if (current->data == value) {
                return true; // Value found
            }
            current = current->next;
        }
        return false; // Value not found
    }
};

int main() {
    LinkedList list;
    list.insertAtHead(1);
    list.insertAtHead(2);
    list.insertAtHead(3);

    cout << "\nOriginal list: ";
    list.display();
    cout << endl;

    list.reverse();

    cout << "\nReversed list: ";
    list.display();

    int target = 2;
    cout<<endl<<"\nSearch: Finding "<<target<<" from the list.\n";
    if (list.search(target)) {
        cout << "Value " << target << " found in the list." << endl;
    } else {
        cout << "Value " << target << " not found in the list." << endl;
    }
  cout<<endl;
    return 0;
}
