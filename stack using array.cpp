#include <iostream>
using namespace std;
#include <chrono>
using namespace std::chrono;

class Stack {
private:
    int arr_size;
    int top;
    int* arr;

public:
    Stack(int size) {
        arr_size = size;
        top = -1;
        arr = new int[arr_size];
    }

    ~Stack() {
        delete[] arr;
    }

    bool isEmpty() {
        return (top == -1);
    }

    bool isFull() {
        return (top == arr_size - 1);
    }

    void Push(int value) {
        top++;
        if (top> arr_size) {
            cout << "Stack Overflow" << endl;
        }
        else {
    
            arr[top] = value;
        }
    }

    int Pop() {
        if (isEmpty()) {
            cout << "Stack Underflow" << endl;
            return 0;
        }
        else {
            int popped_element = arr[top];
            top--;
            return popped_element;
        }
    }

    int Stacktop() {
        if (isEmpty()) {
            cout << "Stack is Empty" << endl;
            return -1;
        }
        else {
            return arr[top];
        }
    }

    void Display() {
        if (isEmpty()) {
            cout << "Stack is Empty" << endl;
        }
        else {
            cout << "Stack elements are: ";
            for (int i = top; i >= 0; i--) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    auto start = high_resolution_clock::now(); // Start time
    int size;
    cout << "Enter the size of the stack: ";
    cin >> size;

    Stack s(size);
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
    //cout << "Top element is: " << s.Stacktop() << endl;
return 0;
}
