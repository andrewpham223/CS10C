#include "Heap.h"

#include <iostream>
using namespace std;

Heap::Heap() {
    numItems = 0;
}

void Heap::enqueue(PrintJob *newPJ) {
    if(numItems != MAX_HEAP_SIZE)
    {
        if(numItems == 0) {
            arr[numItems] = newPJ;
            numItems++;
        }
        else {
            int newPos = numItems;
            while(newPos > 0 && newPJ->getPriority() > arr[(newPos-1)/2]->getPriority()) {
                int parentPos = (newPos - 1) / 2;
                arr[newPos] = arr[parentPos];
                newPos = parentPos;
            }
            arr[newPos] = newPJ;
            numItems++;
        }
    }
}

void Heap::dequeue() {
    if(numItems > 0) {
        arr[0] = arr[numItems-1];
        numItems--;
        trickleDown(0);
    }
}

PrintJob* Heap::highest() {
    if(numItems > 0) {
        return arr[0];
    }
    else {
        return nullptr;
    }
}

void Heap::print() {
    cout << "Priority: " << highest()->getPriority() << ", ";
    cout << "Job Number: " << highest()->getJobNumber() << ", ";
    cout << "Number of Pages: " << highest()->getPages() << endl;
}

void Heap::pjSwap(int indexA, int indexB) {
    PrintJob *temp = arr[indexA];
    arr[indexA] = arr[indexB];
    arr[indexB] = temp;
}

void Heap::trickleDown(int index) {
    int childIndex = 2 * index + 1;
    int pjPriority = arr[index]->getPriority();
    while(childIndex < numItems) {
        int maxPriority = pjPriority;
        int maxIndex = -1;
        for(int i = 0; i < 2 && i + childIndex < numItems; i++) {
            if(arr[i + childIndex]->getPriority() > maxPriority) {
                maxPriority = arr[i + childIndex]->getPriority();
                maxIndex = i + childIndex;
            }
        }
        if(maxPriority == pjPriority) {
            return;
        }
        else {
            pjSwap(index, maxIndex);
            index = maxIndex;
            childIndex = 2 * index + 1;
        }
    }
}

