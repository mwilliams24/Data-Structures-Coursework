#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class IntegerSinglyLinkedList {

private:
    int counter;
    Node* head;

public:

    IntegerSinglyLinkedList() {
        head = NULL;
        counter = 0;
    }

    void createNode(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
        }
        else {

            newNode->next = head;
            head = newNode;
        }
        counter++;
    }

    int getFirst() {
        if (head == NULL) {
            cout << "List is empty" << endl;
        }
        else {
            return head->data;
        }
    }

    void deleteFirstNode() {
        if (head == NULL) {
            cout << "List is empty" << endl;
        }
        else {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        counter--;
    }

    bool isEmpty() {
        if (head == NULL) {
            return true;
        }
        else {
            return false;
        }
    }

    int getSize() {
        return counter;
    }

    void displayList() {
        if (head == NULL) {
            cout << "List is empty" << endl;
        }
        else {
            Node* temp = head;
            while (temp != NULL) {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
    }

};

class IntegerStack {

private: IntegerSinglyLinkedList stack;

public:

    void push(int value) {
         stack.createNode(value);
    }

    int pop() {
         return stack.getFirst();
         stack.deleteFirstNode();
    }

    int top() {
        return stack.getFirst();
    }

    bool isEmpty() {
        return stack.isEmpty();
    }

    int getSize() {
        return stack.getSize();
    }

    void displayStack() {
        stack.displayList();
    }

};

int main() {

    IntegerStack s;
    int value;

    cout << "Please enter 5 integers: " << endl;
    for (int i = 0; i < 5; i++) {
        cin >> value;
        s.push(value);
    }

    s.displayStack();
    s.getSize();
    s.top();
    s.isEmpty();

    s.pop();
    s.pop();
    s.displayStack();



    return 0;
}