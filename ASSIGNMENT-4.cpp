#include <iostream>
using namespace std;

#define MAX 100

int queue[MAX];
int front = -1, rear = -1;

void enqueue(int value);
void dequeue();
bool isEmpty();
bool isFull();
void display();
void peek();

int main() {
    int choice, value;

    cout << "\nCircular Queue Menu\n";
    cout << "1. Enqueue\n";
    cout << "2. Dequeue\n";
    cout << "3. Peek\n";
    cout << "4. Display\n";
    cout << "5. Check if Empty\n";
    cout << "6. Check if Full\n";
    cout << "7. Exit\n";

    while (true) {
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the value to insert: ";
                cin >> value;
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                if (isEmpty())
                    cout << "Queue is empty\n";
                else
                    cout << "Queue is not empty\n";
                break;
            case 6:
                if (isFull())
                    cout << "Queue is full\n";
                else
                    cout << "Queue is not full\n";
                break;
            case 7:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid choice\n";
        }
    }
    return 0;
}

void enqueue(int value) {
    if (isFull()) {
        cout << "Queue Overflow! Cannot insert " << value << ".\n";
        return;
    }
    if (isEmpty()) { // first element
        front = rear = 0;
    } else {
        rear = (rear + 1) % MAX;
    }
    queue[rear] = value;
    cout << value << " inserted into the queue.\n";
}

void dequeue() {
    if (isEmpty()) {
        cout << "Queue Underflow!\n";
        return;
    }
    cout << queue[front] << " removed from the queue.\n";

    if (front == rear) { // only one element
        front = rear = -1;
    } else {
        front = (front + 1) % MAX;
    }
}

bool isEmpty() {
    return (front == -1);
}

bool isFull() {
    return ((rear + 1) % MAX == front);
}

void display() {
    if (isEmpty()) {
        cout << "Queue is empty.\n";
        return;
    }

    cout << "Queue elements: ";

    int i = front;
    while (true) {
        cout << queue[i] << " ";
        if (i == rear)
            break;
        i = (i + 1) % MAX;
    }
    cout << "\n";
}

void peek() {
    if (isEmpty()) {
        cout << "Queue is empty\n";
    } else {
        cout << "Front element is: " << queue[front] << "\n";
    }
}
