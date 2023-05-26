#include <iostream>
using namespace std;
#include <chrono>
using namespace std::chrono;

// Define the structure for the node of the LinkedList
struct Node {
    int data;
    Node* next;
};

// Define the Stack class
class Stack {
private:
    Node* top;

public:
    Stack() {
        top = nullptr;
    }

    // Function to push an element onto the top of the stack
    void Push(int data) {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = top;
        top = newNode;
    }

    // Function to pop the top element from the stack
    int Pop() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return -1;
        }
        int data = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        return data;
    }

    // Function to check if the stack is empty
    bool isEmpty() {
        return top == nullptr;
    }

    // Function to get the top element of the stack without removing it
    int Stacktop() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return -1;
        }
        return top->data;
    }

    // Function to print the elements of the stack
    void Display() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return;
        }
        Node* temp = top;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
auto start = high_resolution_clock::now(); // Start time
Stack s;
s.Push(8);
s.Push(10);
s.Push(5);
s.Push(11);
s.Push(15);
s.Push(23);
s.Push(6);
s.Push(18);
s.Push(20);
s.Push(17);
s.Display();
s.Pop() * 5 ;
s.Display();
s.Push(4);
s.Push(30);
s.Push(3);
s.Push(1);
s.Display();


auto stop = high_resolution_clock::now(); // Stop time
auto duration = duration_cast<nanoseconds>(stop - start); // Duration
cout << "\nTime taken by function : "<< duration.count() << " nanoseconds";
   

    return 0;
}
