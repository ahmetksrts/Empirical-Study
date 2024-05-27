//
//  quickSort.cpp
//  Empirical Study
//
//  Created by ahmetkosretas on 21.05.2024.
//

#include <iostream>
#include <vector>
#include <fstream>
#include <chrono> // Add this header for timing

using namespace std;

// Function to read integers from a text file into an array
vector<int> readArrayFromFile(const string& filename) {
    ifstream inputFile(filename);
    vector<int> arr;

    if (inputFile.is_open()) {
        int num;
        while (inputFile >> num) {
            arr.push_back(num);
        }
        inputFile.close();
    } else {
        cerr << "Error opening the file for reading." << endl;
    }

    return arr;
}

// Function to partition the array
int partition(vector<int>&arr, int start, int end) {
    int pivot = arr[end]; // Choose the last element as the pivot
    int i = start - 1;

    for (int j = start; j < end; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[end]);
    return i + 1;
}

// Recursive QuickSort function
void quickSort(vector<int>&arr, int start, int end) {
    if (start < end) {
        int p = partition(arr, start, end);
        quickSort(arr, start, p - 1); // Sort elements before the pivot
        quickSort(arr, p + 1, end);   // Sort elements after the pivot
    }
}

// Function to print the array
void printArray(vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        cout << "Element " << i+1 << ": " << arr[i] << endl;
    }
}

int main() 
{
    string filenameToOutput = "/Users/ahmetberke/Desktop/2024 SPRING/CSE 311/Empirical Study/array size 100/OUTPUT_quickSort.txt";
    string filenameToRead = "/Users/ahmetberke/Desktop/2024 SPRING/CSE 311/Empirical Study/Empirical Study/random_array.txt";
    
    cout << "QUICK SORT" << endl << endl;


    vector<int> readArray = readArrayFromFile(filenameToRead);
    vector<int> randomArray = readArray;

    int N = static_cast<int>(randomArray.size());
    quickSort(randomArray, 0, N-1);
    randomArray = readArray;
    cout<<"random array:\n"<<endl;
    printArray(randomArray);
    
    const int numRuns = 10;
    ofstream outputFile(filenameToOutput);
    double totalDuration_ms = 0.0;
    for (int run = 0; run < numRuns; run++){
        randomArray = readArray;
        auto start = chrono::high_resolution_clock::now();
        quickSort(randomArray, 0, N-1);
        auto end = chrono::high_resolution_clock::now();
        auto duration_ms = chrono::duration_cast<chrono::microseconds>(end - start).count();
        
        cout << run+1 << ". run is: " << duration_ms << " microseconds" << endl;
        outputFile << run+1 << ". run is: " << duration_ms << " microseconds" << endl;
        totalDuration_ms += duration_ms;
    }
    
    double avgDuration_ms = totalDuration_ms / numRuns;
    
    cout << endl << endl << "Sorted array:\n" << endl;
    printArray(randomArray);
    
    cout << "Average execution time over " << numRuns << " runs: " << avgDuration_ms << " microseconds" << endl;
    outputFile << "Average execution time over " << numRuns << " runs: " << avgDuration_ms << " microseconds" << endl;
    return 0;
}

