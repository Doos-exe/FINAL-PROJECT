#define MAX_SIZE 100

class Customer {
private:
    int front, rear, size;
    int arr[MAX_SIZE];

public:
    Queue() {
		front = rear = -1;
		size = 0;
	}
    bool isEmpty();
    bool isFull();
    void enqueue(int x);
    int dequeue();
    int getSize();
    void displayQueue();
    int getFront();
    
    void AddCustomer();
    void CustomerDetails();
    void CustomerList();
};

