//
//  improved_quickSort.cpp
//  Empirical Study
//
//  Created by ahmetkosretas on 21.05.2024.
//

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <fstream>
using namespace std;

// Function to read integers from a text file into an array
vector<int> readArrayFromFile(const string& filename) {
    ifstream inputFile(filename); // Open the file for reading
    vector<int> arr;

    if (inputFile.is_open()) {
        int num;
        while (inputFile >> num) {
            arr.push_back(num); // Read each integer from the file
        }
        inputFile.close(); // Close the file
    } else {
        cerr << "Error opening the file for reading." << endl;
    }

    return arr;
}

// Selection Sort for small arrays
void selectionSort(vector<int>& arr, int low, int high) {
    for (int i = low; i <= high; ++i) {
        int minIndex = i;
        for (int j = i + 1; j <= high; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

// Partition function for QuickSort
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; ++j) {
        if (arr[j] <= pivot) {
            ++i;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Hybrid QuickSort
void hybridQuickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        if (high - low + 1 < 20) {
            // Use SelectionSort for small arrays
            selectionSort(arr, low, high);
        } else {
            // Use QuickSort for larger arrays
            int pivot = partition(arr, low, high);
            hybridQuickSort(arr, low, pivot - 1);
            hybridQuickSort(arr, pivot + 1, high);
        }
    }
}

// Function to print the array
void printArray(const vector<int>& arr) {
    for (int i = 0; i < arr.size(); ++i) {
        cout << "Element " << i + 1 << ": " << arr[i] << endl;
    }
}

int main() 
{
    string filenameToRead = "/Users/ahmetberke/Desktop/2024 SPRING/CSE 311/Empirical Study/Empirical Study/random_array.txt";
    string filenameToOutput = "/Users/ahmetberke/Desktop/2024 SPRING/CSE 311/Empirical Study/array size 100/OUTPUT_improved_quickSort.txt";

    cout << "IMPROVED QUICK SORT" << endl << endl;

    
    vector<int> readArray = readArrayFromFile(filenameToRead);
    vector<int> randomArr = readArray;
    
    cout << "Read random array:" << endl;
    printArray(randomArr);

    int N = static_cast<int>(randomArr.size());
    hybridQuickSort(randomArr, 0, N-1);
    randomArr = readArray;
    cout << "random array:" << endl;
    printArray(randomArr);

    const int numRuns = 10;
    ofstream outputFile(filenameToOutput);
    double totalDuration_ms = 0.0;
    
    for (int run = 0; run < numRuns; run++) {
        randomArr = readArray;
        auto start = chrono::high_resolution_clock::now();
        hybridQuickSort(randomArr, 0, N-1);
        auto end = chrono::high_resolution_clock::now();
        auto duration_ms = chrono::duration_cast<chrono::microseconds>(end - start).count();
        
        cout << run+1 << ". run is: " << duration_ms << " microseconds" << endl;
        outputFile << run+1 << ". run is: " << duration_ms << " microseconds" << endl;
        totalDuration_ms += duration_ms;
    }

    double avgDuration_ms = totalDuration_ms / numRuns;

    cout << endl << endl << "Sorted array:" << endl;
    printArray(randomArr);

    cout << "Average execution time over " << numRuns << " runs: " << avgDuration_ms << " microseconds" << endl;
    outputFile << "Average execution time over " << numRuns << " runs: " << avgDuration_ms << " microseconds" << endl;

    return 0;
}
