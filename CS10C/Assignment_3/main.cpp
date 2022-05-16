#include <iostream>

using namespace std;

bool C(string String1, string String2);
int* Index_Sort_Selection(string A[], int n);
int* Index_Sort_Quick(string A[], int n);
int Index_Partition(string A[], int I[], int left, int right);
void Index_Quicksort(string A[], int I[], int left, int right);

int main() {
    string A[4] = {"MN", "NY", "CA", "OK"};
    int* indexSorted = Index_Sort_Selection(A, 4);
    for(int i = 0; i < 4; i++) {
        cout << indexSorted[i] << " ";
    }
    cout << endl;
    return 0;
}


bool C(string String1, string String2) {
    return String1 < String2;
}

int* Index_Sort_Selection(string A[], int n) {
    if(n > 0) {
        int *I = new int(n);
        for(int x = 0; x < n; x++) {
            I[x] = x;
        }
        for(int i = 0; i < n-1; i++) {
            int min = i;
            for(int j = i + 1; j < n; j++) {
                if(C(A[j], A[min])) {
                    int temp = I[min];
                    I[min] = I[j];
                    I[j] = temp;
                }

            }
        }
        return I;
    }
    return nullptr; //if invalid n
}

int* Index_Sort_Quick(string A[], int n) {
    if(n > 0) {
        int *I = new int(n);
        for(int j = 0; j < n; j++) {
            I[j] = j;
        }
        Index_Quicksort(A, I, 0, n);
        return I;
    }
    return nullptr; //if invalid n
}   

int Index_Partition(string A[], int I[], int left, int right) {
    string p = A[left];
    int i = left + 1;
    for(int j = left + 1; j < right; j++) {
        if(C(A[j], p)) {
            int temp = I[j];
            I[j] = I[i];
            I[i] = temp;
            i++;
        }
    }
    int temp = I[left];
    I[left] = I[i-1];
    I[i-1] = temp;
    return i-1;
}

void Index_Quicksort(string A[], int I[], int left, int right) {
    if(left < right) {
        int q = Index_Partition(A, I, left, right);
        Index_Quicksort(A, I, left, q-1);
        Index_Quicksort(A, I, q+1, right);
    }
}
