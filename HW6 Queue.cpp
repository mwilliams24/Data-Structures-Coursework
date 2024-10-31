#include <iostream>
using namespace std;

// Node structure for the doubly linked list
struct Node {
    int data;
    Node* next;
    Node* prev;
};

// Class to manage the doubly linked list
class IntegerDoublyLinkedList {
private:
    Node* head;
    Node* tail;
    int counter;

public:
    IntegerDoublyLinkedList() {
        head = NULL;
        tail = NULL;
        counter = 0;
    }
    // Creates a new node and adds it to the end of the list
    void createnewNode(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = NULL;
        newNode->prev = NULL;

        if (head == NULL) {
            head = newNode;
            tail = newNode;
        }
        else{ // List is not empty
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        
        counter++;
    }

    // Returns the first item in the list
    int getFirst() {
        if (head == NULL) {
            cout << "List is empty." << endl;
        }
        else{
            return head->data;
        }
    }

    // Deletes the first node in the list
    void deleteFirstNode() {
        if (head == NULL) {
            cout << "List is empty." << endl;
        }
        else{
            Node* temp = head;
            head = head->next;
            head->prev = nullptr;
            delete temp;
        }
        counter--;
    }

    // Checks if the list is empty
    bool isEmpty() {
        return counter == 0;
    }

    // Returns the current size of the list
    int getSize() {
        return counter;
    }

    // Displays all the elements in the list in forward order
    void display() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

// Class to manage the queue using a doubly linked list
class IntegerQueue {
private:
    IntegerDoublyLinkedList list;

public:
    // Inserts an element at the end of the queue
    void enqueue(int value) {
        list.createnewNode(value);
    }

    // Removes and returns the element at the front of the queue
    int dequeue() {
        if (list.isEmpty()) {
            throw runtime_error("Queue is empty");
        }
        int frontValue = list.getFirst();
        list.deleteFirstNode();
        return frontValue;
    }

    // Returns the element at the front without removing it
    int front() {
        return list.getFirst();
    }

    // Checks if the queue is empty
    bool isEmpty() {
        return list.isEmpty();
    }

    // Returns the current size of the queue
    int getSize() {
        return list.getSize();
    }

    // Displays all the elements in the queue
    void displayQueue() {
        list.display();
    }
};

int main() {
    IntegerQueue queue;
    int value;

    cout << "Enter 5 integer values:" << endl;
    for (int i = 0; i < 5; i++) {
        cin >> value;
        queue.enqueue(value);
    }

    cout << "Elements in the queue: ";
    queue.displayQueue();

    cout << "Size of the queue: " << queue.getSize() << endl;

    if (!queue.isEmpty()) {
        cout << "First item in the queue: " << queue.front() << endl;
    }

    // Remove the first two elements
    cout << "Dequeueing two elements:" << endl;
    for (int i = 0; i < 2; i++) {
        if (!queue.isEmpty()) {
            cout << "Dequeued: " << queue.dequeue() << endl;
        }
    }

    cout << "Elements in the queue after dequeueing: ";
    queue.displayQueue();

    return 0;
}
