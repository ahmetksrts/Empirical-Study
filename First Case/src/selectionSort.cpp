//
//  selectionSort.cpp
//  Empirical Study
//
//  Created by ahmetkosretas on 21.05.2024.
//

#include <iostream>
#include <chrono>
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

// Selection Sort function
void selectionSort(vector<int>& arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        swap(arr[i], arr[min_idx]);
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
    string filenameToOutput = "/Users/ahmetberke/Desktop/2024 SPRING/CSE 311/Empirical Study/array size 100/OUTPUT_selectionSort.txt";
    
    cout<<"SELECTION SORT"<<endl<<endl;
    
    
    vector<int> readArray = readArrayFromFile(filenameToRead);
    vector<int> randomArr = readArray;
    

    int N = (int)readArray.size();
    selectionSort(randomArr, N); // ignore first run
    randomArr = readArray;
    cout << "Read random array:" << endl;
    printArray(randomArr);
    
    const int numRuns = 10;
    ofstream outputFile(filenameToOutput);
    double totalDuration_ms = 0.0;
    
    for (int run = 0; run < numRuns; run++) {
        randomArr = readArray;
        auto start = chrono::high_resolution_clock::now();
        selectionSort(readArray, N);
        auto end = chrono::high_resolution_clock::now();
        auto duration_ms = chrono::duration_cast<chrono::microseconds>(end - start).count();
        
        cout << run+1 << ". run is: " << duration_ms << " microseconds" << endl;
        outputFile << run+1 << ". run is: " << duration_ms << " microseconds" << endl;
        
        
        totalDuration_ms += duration_ms;
    }

    double avgDuration_ms = totalDuration_ms / numRuns;

    cout <<endl<< "Sorted array:" << endl;
    printArray(randomArr);

    cout << "Average execution time over " << numRuns << " runs: " << avgDuration_ms << " microseconds" << endl;
    outputFile << "Average execution time over " << numRuns << " runs: " << avgDuration_ms << " microseconds" << endl;

    return 0;
}
