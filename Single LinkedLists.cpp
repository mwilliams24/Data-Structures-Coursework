// HW3 LinkedLists.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

struct Node {
    int data; //holds integer value
    Node* next; //points to the next node in the list
};

class IntegerLinkedList {

private:
    Node* head; //points to the first node in the list
    int counter;

public:

    IntegerLinkedList() { //default constructor
        head = NULL;
        counter = 0;
    }


    void createNewNode(int value) { //function will create a new node
        Node* newNode = new Node; //creates a new node
        newNode->data = value; //new node holds the value
        newNode->next = NULL; //new node points to NULLe points to NULL
        if (head == NULL) { //if list is empty, the head will be the new node //if 
            head = newNode;
        }
        else { //if list is not empty, the new node will be added to the end of the list
            Node* temp = head;
            while (head != NULL) { //while the next node is not NULL
                temp = temp -> next; //temp will point to the next NULL until it reaches a NULL node
            }
            temp->next = newNode; //when temp reaches the NULL node, the new node will be added to the end of the list
        }
        counter++;
    }



    void display() {
        if (head == NULL) {
            cout << "The list is empty" << endl;
        }
        // temp node will point to the head and then traverse through list and print the value that each node holds until it reaches NULL
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->next << ", ";
            temp = temp->next;
        }
        cout << endl;
    }


    bool search(int target) { //function will search for a target value in the list
        Node* temp = head;
        while (head != NULL) {
            if (temp->data == target)
            {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    ~IntegerLinkedList() { //deconstructor; deletes temp node and then deletes the next node until the list is empty
        Node* temp;
        while (head != NULL) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }

};

int main() {

    IntegerLinkedList list;
    int value;

    cout << "Enter 5 values..." << endl;
    for (int i = 0; i < 5; i++) {
        cin >> value;
        list.createNewNode(value); //creates new node with vlaue input
    }

    list.display(); //displays list

    cout << "Enter a number to search the list..." << endl;
    cin >> value;

    if (list.search(value)) {//searches for value in list
        cout << value << " is found in the list" << endl;
    }
    else {
        cout << value << " is not found in the list" << endl;
    }


}