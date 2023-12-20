#include <iostream>
#include <vector>

using namespace std;

class PriorityQueue {
private:
    vector<int> heap;

    void heapifyUp(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2;
            if (heap[index] > heap[parent]) {
                swap(heap[index], heap[parent]);
                index = parent;
            } else {
                break;
            }
        }
    }

    void heapifyDown(int index) {
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;
        int largest = index;

        if (leftChild < heap.size() && heap[leftChild] > heap[largest]) {
            largest = leftChild;
        }

        if (rightChild < heap.size() && heap[rightChild] > heap[largest]) {
            largest = rightChild;
        }

        if (largest != index) {
            swap(heap[index], heap[largest]);
            heapifyDown(largest);
        }
    }

public:
    void insert(int value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }

    int top() {
        if (!heap.empty()) {
            return heap[0];
        } else {
            cerr << "Priority queue is empty." << endl;
            return -1;
        }
    }

    void pop() {
        if (!heap.empty()) {
            swap(heap[0], heap.back());
            heap.pop_back();
            heapifyDown(0);
        } else {
            cerr << "Priority queue is empty." << endl;
        }
    }

    bool isEmpty() {
        return heap.empty();
    }
};

int main() {
    PriorityQueue priorityQueue;

    vector<int> elements = {8, 3, 9, 1, 7, 5, 6, 4};
    for (int element : elements) {
        priorityQueue.insert(element);
    }

    while (!priorityQueue.isEmpty()) {
        cout << "Top element: " << priorityQueue.top() << endl;
        priorityQueue.pop();
    }

    return 0;
}
