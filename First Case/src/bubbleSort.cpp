//
//  bubbleSort.cpp
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

// perform bubble sort
void bubbleSort(vector<int>&array, int size) {
    // loop to access each array element
    for (int i = 0; i < size-1; i++) {
        // loop to compare array elements
        for (int j = 0; j < size-1-i; j++) {
            // compare two adjacent elements
            // change > to < to sort in descending order
            if (array[j+1]<array[j]){
                // swapping elements if elements
                // are not in the intended order
                swap(array[j], array[j+1]);
            }
        }
    }
}

// Function to print the array
void printArray(const vector<int>& arr) {
    for (int i = 0; i < arr.size(); ++i) {
        cout << "Element " << i + 1 << ": " << arr[i] << endl;
    }
}

int main(void)
{
    cout << "BUBBLE SORT" << endl;
    string filenameToOutput = "/Users/ahmetberke/Desktop/2024 SPRING/CSE 311/Empirical Study/array size 100/OUTPUT_bubbleSort.txt";
    string filenameToRead = "/Users/ahmetberke/Desktop/2024 SPRING/CSE 311/Empirical Study/Empirical Study/random_array.txt";
    vector<int> readArray = readArrayFromFile(filenameToRead);
    vector<int> randomArray = readArray;
    
    int N = (int)readArray.size(); // Corrected size calculation
    bubbleSort(randomArray, N); // ignore first run
    randomArray = readArray;
    cout << "Read random array:" << endl;
    printArray(randomArray);
    cout<<endl<<endl;
    const int numRuns = 10;

    double totalDuration_ms = 0.0;
    
    ofstream outputFile(filenameToOutput);
    
    for (int run = 0; run < numRuns; run++) {
        
        randomArray = readArray;
        auto start = chrono::high_resolution_clock::now();
        bubbleSort(randomArray, N);
        auto end = chrono::high_resolution_clock::now();
        auto duration_ms = chrono::duration_cast<chrono::microseconds>(end - start).count();
        cout << run+1 << ". run is: " << duration_ms << " microseconds" << endl;
        outputFile << run+1 << ". run is: " << duration_ms << " microseconds" << endl;


        totalDuration_ms += duration_ms;
        
    }

    double avgDuration_ms = totalDuration_ms / numRuns;

    cout <<endl<<endl<< "Sorted array:" << endl;
    printArray(randomArray);

    cout << "Average execution time over " << numRuns << " runs: " << avgDuration_ms << " microseconds" << endl;
    outputFile << "Average execution time over " << numRuns << " runs: " << avgDuration_ms << " microseconds" << endl;

    return 0;
    
    

}
