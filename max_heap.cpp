//===================== Insertion =======================

// C++ program to insert new element to Heap
#include <iostream>
using namespace std;

#define MAX 1000 // Max size of Heap

// Function to heapify ith node in a Heap
// of size n following a Bottom-up approach
void heapify(int arr[], int n, int i)
{
    // Find parent
    int parent = (i - 1) / 2;

    if (parent >= 0) {
        // For Max-Heap
        // If current node is greater than its parent
        // Swap both of them and call heapify again
        // for the parent
        if (arr[i] > arr[parent]) {
            swap(arr[i], arr[parent]);

            // Recursively heapify the parent node
            heapify(arr, n, parent);
        }
    }
}

// Function to insert a new node to the Heap
void insertNode(int arr[], int& n, int Key)
{
    // Increase the size of Heap by 1
    n = n + 1;

    // Insert the element at end of Heap
    arr[n - 1] = Key;

    // Heapify the new node following a
    // Bottom-up approach
    heapify(arr, n, n - 1);
}

// A utility function to print array of size n
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";

    cout << "\n";
}

// Driver Code
int main()
{
    // Array representation of Max-Heap
    // 10
    // / \
    // 5 3
    // / \
    // 2 4
    int arr[MAX] = { 10, 5, 3, 2, 4 };

    int n = 5;

    int key = 15;

    insertNode(arr, n, key);

    printArray(arr, n);
    // Final Heap will be:
    // 15
    // / \
    // 5     10
    // / \ /
    // 2 4 3
    return 0;
}


//===================== Delete =======================


// C++ program for implement deletion in Heaps

#include <iostream>

using namespace std;

// To heapify a subtree rooted with node i which is
// an index of arr[] and n is the size of heap
void heapify(int arr[], int n, int i)
{
    int largest = i; // Initialize largest as root
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2

    // If left child is larger than root
    if (l < n && arr[l] > arr[largest])
        largest = l;

    // If right child is larger than largest so far
    if (r < n && arr[r] > arr[largest])
        largest = r;

    // If largest is not root
    if (largest != i) {
        swap(arr[i], arr[largest]);

        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}

// Function to delete the root from Heap
void deleteRoot(int arr[], int& n)
{
    // Get the last element
    int lastElement = arr[n - 1];

    // Replace root with last element
    arr[0] = lastElement;

    // Decrease size of heap by 1
    n = n - 1;

    // heapify the root node
    heapify(arr, n, 0);
}

/* A utility function to print array of size n */
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}

// Driver Code
int main()
{
    // Array representation of Max-Heap
    //     10
    // / \
    // 5 3
    // / \
    // 2 4
    int arr[] = { 10, 5, 3, 2, 4 };

    int n = sizeof(arr) / sizeof(arr[0]);

    deleteRoot(arr, n);

    printArray(arr, n);

    return 0;
}


//===================== peak =======================
#include <iostream>
#include <queue>

int main() {
    // Create a max heap with some elements using a priority_queue
    std::priority_queue<int> maxHeap;
    maxHeap.push(9);
    maxHeap.push(8);
    maxHeap.push(7);
    maxHeap.push(6);
    maxHeap.push(5);
    maxHeap.push(4);
    maxHeap.push(3);
    maxHeap.push(2);
    maxHeap.push(1);

    // Get the peak element (i.e., the largest element)
    int peakElement = maxHeap.top();

    // Print the peak element
    std::cout << "Peak element: " << peakElement << std::endl;

    return 0;
}