#include <iostream>
#include <time.h>
using namespace std;

const int NUMBERS_SIZE = 50000;
const int CLOCKS_PER_MS = CLOCKS_PER_SEC / 1000;

void InsertionSort(int numbers[], int numbersSize) {
    for(int i = 1; i < numbersSize; i++) {
        int j = i;
        while(j > 0 && numbers[j] < numbers[j-1]) {
            int temp = numbers[j-1];
            numbers[j-1] = numbers[j];
            numbers[j] = temp;
            j -= 1;
        }
    }
}

int Partition_midpoint(int *numbers, int i, int k)
{
    int l = 0;
    int h = 0;
    int midpoint = 0;
    int pivot = 0;
    int temp = 0;
    bool done = false;

    midpoint = i + (k - i) / 2;
    pivot = numbers[midpoint];

    l = i;
    h = k;

    while (!done)
    {
        while (numbers[l] < pivot)
        {
            ++l;
        }

        while (pivot < numbers[h])
        {
            --h;
        }


        if (l >= h)
        {
            done = true;
        }
        else
        {

            temp = numbers[l];
            numbers[l] = numbers[h];
            numbers[h] = temp;

            ++l;
            --h;
        }
    }

    return h;
}

int Partition_medianOfThree(int numbers[], int i, int k) {
    int l = 0;
    int h = 0;
    int midpoint = 0;
    int pivot = 0;
    int temp = 0;
    bool done = false;


    midpoint = i + (k - i) / 2;

    if (numbers[midpoint] > numbers[i])
    {
        if (numbers[midpoint] > numbers[k]) 
        {
            pivot = numbers[k];
        }
        else 
        {
            pivot = numbers[midpoint];
        }
    }
    else
    {
        if (numbers[i] > numbers[k]) 
        {
            pivot = numbers[k];
        }
        else 
        {
            pivot = numbers[i];
        }
    }

    l = i;
    h = k;

    while (!done)
    {

        while (numbers[l] < pivot)
        {
            ++l;
        }

        while (pivot < numbers[h])
        {
            --h;
        }


        if (l >= h)
        {
            done = true;
        }
        else
        {

            temp = numbers[l];
            numbers[l] = numbers[h];
            numbers[h] = temp;

            ++l;
            --h;
        }
    }

    return h;
}

void Quicksort_midpoint(int numbers[], int i, int k)
{
    int j = 0;


    if (i >= k)
    {
        return;
    }


    j = Partition_midpoint(numbers, i, k);


    Quicksort_midpoint(numbers, i, j);
    Quicksort_midpoint(numbers, j + 1, k);
}

void Quicksort_medianOfThree(int numbers[], int i, int k)
{
    int j = 0;

    if (i >= k)
    {
        return;
    }


    j = Partition_medianOfThree(numbers, i, k);


    Quicksort_medianOfThree(numbers, i, j);
    Quicksort_medianOfThree(numbers, j + 1, k);
}

int genRandInt(int low, int high) {
   return low + rand() % (high - low + 1);
}

void fillArrays(int arr1[], int arr2[],int arr3[]){
    for(int i = 0; i < NUMBERS_SIZE; ++i){
        arr1[i] = genRandInt(0,NUMBERS_SIZE);
        arr2[i] = arr1[i];
        arr3[i] = arr1[i];
    }
}

int main() {
    srand(time(nullptr));
	
	int arr1[NUMBERS_SIZE];
	int arr2[NUMBERS_SIZE];
	int arr3[NUMBERS_SIZE];
	
	fillArrays(arr1, arr2, arr3);
	
	cout << "Sorting runtime for an array of " << NUMBERS_SIZE << " integers: " << endl;
	
	clock_t start = clock();
	Quicksort_midpoint(arr1, 0, NUMBERS_SIZE);
	clock_t end = clock();
	int runtime = (end - start) / CLOCKS_PER_MS;
	cout << "Quicksort (midpoint) runtime: " << runtime << " ms" << endl;
	
	start = clock();
	Quicksort_medianOfThree(arr2, 0, NUMBERS_SIZE);
	end = clock();
	runtime = (end - start) / CLOCKS_PER_MS;
	cout << "Quicksort (median of three) runtime: " << runtime << " ms" << endl;
	
	start = clock();
	InsertionSort(arr3, NUMBERS_SIZE);
	end = clock();
	runtime = (end - start) / CLOCKS_PER_MS;
	cout << "Insertion sort runtime: " << runtime << " ms" << endl;
}