// Name: Nitu
// UID: 22BCS10707
// Section: 631-B


// Queue operations:


#include <iostream>
using namespace std;

class Queue {
private:
    int front, rear, size;
    int* queue;

public:
    Queue(int capacity) {
        size = capacity;
        queue = new int[size];
        front = rear = -1;
    }

    ~Queue() {
        delete[] queue;
    }

    void enqueue(int item) {
        if ((rear + 1) % size == front) {
            cout << "Queue is full!" << endl;
            return;
        }
        if (front == -1) front = 0;
        rear = (rear + 1) % size;
        queue[rear] = item;
    }

    void dequeue() {
        if (front == -1) {
            cout << "Queue is empty!" << endl;
            return;
        }
        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % size;
        }
    }

    void display() {
        if (front == -1) {
            cout << "Queue is empty!" << endl;
            return;
        }
        int i = front;
        while (true) {
            cout << queue[i] << " ";
            if (i == rear) break;
            i = (i + 1) % size;
        }
        cout << endl;
    }
};

int main() {
    int size, choice, value;
    cout << "Enter the size of the queue: ";
    cin >> size;
    Queue q(size);

    do {
        cout << "\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to enqueue: ";
            cin >> value;
            q.enqueue(value);
            break;
        case 2:
            q.dequeue();
            break;
        case 3:
            q.display();
            break;
        case 4:
            break;
        default:
            cout << "Invalid choice!" << endl;
        }
    } while (choice != 4);

    return 0;
}



// Stack operations:

#include <iostream>
using namespace std;

class Stack {
private:
    int* stack;
    int top;
    int size;

public:
    Stack(int capacity) {
        size = capacity;
        stack = new int[size];
        top = -1;
    }

    ~Stack() {
        delete[] stack;
    }

    void push(int item) {
        if (top == size - 1) {
            cout << "Stack is full!" << endl;
            return;
        }
        stack[++top] = item;
    }

    void pop() {
        if (top == -1) {
            cout << "Stack is empty!" << endl;
            return;
        }
        top--;
    }

    void display() {
        if (top == -1) {
            cout << "Stack is empty!" << endl;
            return;
        }
        for (int i = top; i >= 0; i--) {
            cout << stack[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    int size, choice, value;
    cout << "Enter the size of the stack: ";
    cin >> size;
    Stack s(size);

    do {
        cout << "\n1. Push\n2. Pop\n3. Display\n4. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to push: ";
            cin >> value;
            s.push(value);
            break;
        case 2:
            s.pop();
            break;
        case 3:
            s.display();
            break;
        case 4:
            break;
        default:
            cout << "Invalid choice!" << endl;
        }
    } while (choice != 4);

    return 0;
}
