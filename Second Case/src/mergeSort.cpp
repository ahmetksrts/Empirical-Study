//
//  mergeSort.cpp
//  Empirical Study
//
//  Created by ahmetkosretas on 21.05.2024.
//

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <algorithm>
#include <iterator>
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

// merge function for Mergesort
void merge(vector<int>& arr, int low, int mid, int high) {
    int n1 = mid - low + 1;
    int n2 = high - mid;

    vector<int> left(n1);
    vector<int> right(n2);

    for (int i = 0; i < n1; i++)
        left[i] = arr[low + i];
    for (int j = 0; j < n2; j++)
        right[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = low;
    while (i < n1 && j < n2) {
        if(left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        }
        else{
            arr[k] = right[j];
            j++;
        }
        k++;
    }
    
    while(i < n1) {
        arr[k] = left[i];
        i += 1;
        k += 1;
    }

    while(j < n2) {
        arr[k] = right[j];
        j += 1;
        k += 1;
    }
}

// Merge sort function
void mergeSort(vector<int>& arr, int low, int high) {
    if (low < high){
        int mid = low + (high - low) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
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
    string filenameToOutput = "/Users/ahmetberke/Desktop/2024 SPRING/CSE 311/Empirical Study/array size 100000/OUTPUT_mergeSort.txt";
    
    cout << "MERGE SORT" << endl << endl;

    
    
    vector<int> readArray = readArrayFromFile(filenameToRead);
    vector<int> randomArr = readArray;
    
    int N = static_cast<int>(randomArr.size());

    // Run merge sort once to ignore the first run (memory operations)
    mergeSort(randomArr, 0, N - 1);
    randomArr = readArray;
    cout<<"random array is:\n"<<endl;
    printArray(randomArr);

    const int numRuns = 10; // Run merge sort for multiple times
    ofstream outputFile(filenameToOutput);
    double totalDuration_ms = 0.0;
    
    for (int run = 0; run < numRuns; run++) {
        //randomArr = readArray; SECOND CASE
        auto start = chrono::high_resolution_clock::now();
        mergeSort(randomArr, 0, N - 1);
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
