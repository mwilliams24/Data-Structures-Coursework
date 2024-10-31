#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

class IntegerDoublyLinkedList {

private:
    int counter;
    Node* head;
    Node* tail;

public:

    IntegerDoublyLinkedList() {
        head = NULL;
        tail = NULL;
        counter = 0;
    }

    void createnewNode(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = NULL;
        newNode->prev = NULL;

        if (head == NULL) {
            head = newNode;
            tail = newNode;
        }
        else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
        counter++;
    }

    void displayInReverseOrder() {
        if (tail == NULL) {
            cout << "The list is empty" << endl;
        }
        else {
            Node* temp = tail;

            while (temp != NULL) {
                cout << temp->data << " ";
                temp = temp->prev;
            }
            cout << endl;
        }
    }

    void deleteLastNode() {
        if (tail == NULL) {
            cout << "The list is empty" << endl;
        }
        else if (head == tail) {
            delete tail;
            head = NULL;
            tail = NULL;
        }
        else {
            Node* temp = tail;
            tail = tail->prev;
            tail->next = NULL;
            delete temp;
        }
        counter--;
    }

    bool search(int target) {
        Node* temp = head;
        while (temp != NULL) {
            if (temp->data == target) {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    ~IntegerDoublyLinkedList() {
        Node* temp = head;
        while (temp != NULL) {
            Node* next = temp->next;
            delete temp;
            temp = next;
        }
    }
};

int main() {

    IntegerDoublyLinkedList list;
    int value;
    int target;

    cout << "Enter 5 integers: " << endl;
    for (int i = 0; i < 5; i++) {
        cin >> value;
        list.createnewNode(value);
    }

    cout << "List in reverse order: ";
    list.displayInReverseOrder();

    list.deleteLastNode();

    cout << "List after deleting the last node: ";
    list.displayInReverseOrder();

    // Search for an integer in the list
    cout << "Enter an integer to search in the list: ";
    cin >> target;
    if (list.search(target)) {
        cout << "Value " << target << " found in the list." << endl;
    }
    else {
        cout << "Value " << target << " not found in the list." << endl;
    }

    return 0;
}