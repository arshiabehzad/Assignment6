#include <string>
#include <iostream>
#include <fstream>
#include <time.h>
#include <random>
#include <ctime>
#include <chrono>
#include <sstream>
using namespace std;



void bubbleSort(float array[], int n )
{
    for (int i = 0; i < n; i++)
    {
        double temp = 0;
        for (int j = 0; j < n-1; j++)
        {
            if (array[j] > array[j + 1])
            {
                temp = array[j+1];
                array[j+1] = array[j];
                array[j] = temp;
            }
        }
    }
}

void selectionSort(float arr[], int n)
{
    int i, j, minIndex;
    double temp = 0;
    for (i = 0; i < n -1; i++)
    {
        minIndex = i;
        for (j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        if (minIndex != i)
        {
            temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}

void insertionSort(float arr[], int n)
{
    for (int j = 1; j < n; ++j)
    {
        float temp = arr[j];
        int k = j;
        while (k>0 && arr[k-1] >= temp)
        {
            arr[k] = arr[k-1];
            --k;
        }
        arr[k] = temp;
    }
}

//QUICK SORT CODE TAKEN FROM: https://www.geeksforgeeks.org/quick-sort/

// A utility function to swap two elements
void swap(float *a, float *b)
{
    float t = *a;
    *a = *b;
    *b = t;
}

/* This function takes last element as pivot, places  
the pivot element at its correct position in sorted  
array, and places all smaller (smaller than pivot)  
to left of pivot and all greater elements to right  
of pivot */
float partition(float arr[], int low, int high)
{
    float pivot = arr[high]; // pivot
    int i = (low - 1);     // Index of smaller element

    for (int j = low; j <= high - 1; j++)
    {
        // If current element is smaller than the pivot
        if (arr[j] < pivot)
        {
            i++; // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

/* The main function that implements QuickSort  
arr[] --> Array to be sorted,  
low --> Starting ind   ex,  
high --> Ending index */
void quickSort(float arr[], int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now  
        at right place */
        int pi = partition(arr, low, high);

        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
    
}

void printArray(float array[], int n)
{
    for (int i = 0; i <  n; i++)
    {
        cout << array[i] << ", ";
    }
    cout << endl;
}

void createArrayFile(int size)
{
    ofstream outfile;
    outfile.open("arrayFile.txt");
    float random;
    for (int i = 0; i < size; i++)
    {
        random = (float)rand() / (float)RAND_MAX;
        outfile << random <<endl;
    }
    outfile.close();
}

float * readFile(int size)
{
    ifstream file;
    file.open("arrayFile.txt");
    string line;
    float * array = new float [size];
    int index = 0;
    while(getline(file, line))
    {
        float num = stof(line);
        array[index] = num;
        index++;
    }
    return array;
}
int main(int argc, char **argv)
{
    int sizeOfArray = 700000;

    //code taken for calculating time taken from: https://stackoverflow.com/questions/997946/how-to-get-current-time-and-date-in-c
    cout << "\n\nCreate and Read File: ";
    auto start2 = std::chrono::system_clock::now();
    //createArrayFile(sizeOfArray);
    float * array = readFile(sizeOfArray);
    float * array2= array;
    float * array3 = array;
    float * array4 = array;
    auto end2 = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds2 = end2 - start2;
    std::time_t end_time2 = std::chrono::system_clock::to_time_t(end2);
    std::time_t start_time2 = std::chrono::system_clock::to_time_t(start2);
    cout << "Time Started: " << ctime(&end_time2) << endl;
    cout << "Time Ended: " << ctime(&start_time2) << endl;
    cout << "Elapsed Seconds: " << elapsed_seconds2.count() << "s" << endl;

    auto start3 = std::chrono::system_clock::now();
    cout << "\n\nBubble Sort: \n" << endl;
   // bubbleSort(array, sizeOfArray);
    auto end3 = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds3 = end3 - start3;
    std::time_t end_time3 = std::chrono::system_clock::to_time_t(end3);
    std::time_t start_time3 = std::chrono::system_clock::to_time_t(start3);
    cout << "Time Started: " << ctime(&end_time3) << endl;
    cout << "Time Ended: " << ctime(&start_time3) << endl;
    cout << "Elapsed Seconds: " << elapsed_seconds3.count() << "s" << endl;
    //printArray(array, sizeOfArray);

    auto start4 = std::chrono::system_clock::now();
    cout << "\n\nSelection Sort: \n" << endl;
   // selectionSort(array2, sizeOfArray);
    auto end4 = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds4 = end4 - start4;
    std::time_t end_time4 = std::chrono::system_clock::to_time_t(end4);
    std::time_t start_time4 = std::chrono::system_clock::to_time_t(start4);
    cout << "Time Started: " << ctime(&end_time4) << endl;
    cout << "Time Ended: " << ctime(&start_time4) << endl;
    cout << "Elapsed Seconds: " << elapsed_seconds4.count() << "s" << endl;
    //printArray(array2, sizeOfArray);

    auto start5 = std::chrono::system_clock::now();
    cout << "\n\nInsertion Sort: \n" << endl;
    insertionSort(array3, sizeOfArray);
    auto end5 = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds5 = end5 - start5;
    std::time_t end_time5 = std::chrono::system_clock::to_time_t(end5);
    std::time_t start_time5 = std::chrono::system_clock::to_time_t(start5);
    cout << "Time Started: " << ctime(&end_time5) << endl;
    cout << "Time Ended: " << ctime(&start_time5) << endl;
    cout << "Elapsed Seconds: " << elapsed_seconds5.count() << "s" << endl;
    //printArray(array3, sizeOfArray);

    int n = sizeof(array4) / sizeof(array4[0]);
    cout << "\n\nQuick Sort: \n" << endl;
    auto start = std::chrono::system_clock::now();
    quickSort(array4, 0, n-1);
    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;
    std::time_t end_time = std::chrono::system_clock::to_time_t(end);
    std::time_t start_time = std::chrono::system_clock::to_time_t(start);
    cout << "Time Started: " << ctime(&end_time) << endl;
    cout << "Time Ended: " << ctime(&start_time) << endl;
    cout << "Elapsed Seconds: " << elapsed_seconds.count() << "s" << endl;
    //printArray(array4, sizeOfArray);
}