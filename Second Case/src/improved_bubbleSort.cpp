//
//  improved_bubbleSort.cpp
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

void improvedBubbleSort(vector<int>&array, int n){
    bool swapped = true;
    while(swapped){
        swapped = false;
        for(int i=0; i<n; i++){
            if(array[i] > array[i+1]){
                swap(array[i], array[i+1]);
                swapped = true;
            }
        }
        n--;
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
    cout << "IMPROVED BUBBLE SORT" << endl;
    string filenameToOutput = "/Users/ahmetberke/Desktop/2024 SPRING/CSE 311/Empirical Study/array size 100000/OUTPUT_improved_bubbleSort.txt";
    string filenameToRead = "/Users/ahmetberke/Desktop/2024 SPRING/CSE 311/Empirical Study/Empirical Study/random_array.txt";
    vector<int> readArray = readArrayFromFile(filenameToRead);
    vector<int> randomArray = readArray;
    
    int N = static_cast<int>(randomArray.size());
    improvedBubbleSort(randomArray, N); // ignore first run
    randomArray = readArray;
    cout << "Read random array:" << endl;
    printArray(randomArray);
    cout<<endl<<endl;
    const int numRuns = 10;

    double totalDuration_ms = 0.0;
    ofstream outputFile(filenameToOutput);
    for (int run = 0; run < numRuns; run++) {
        
        //randomArray = readArray; SECOND CASE
        auto start = chrono::high_resolution_clock::now();
        improvedBubbleSort(randomArray, N);
        auto end = chrono::high_resolution_clock::now();
        auto duration_ms = chrono::duration_cast<chrono::microseconds>(end - start).count();
        cout << run+1 << ". run is: " << duration_ms << " microseconds" << endl;
        outputFile << run+1 << ". run is: " << duration_ms << " microseconds" << endl;


        totalDuration_ms += duration_ms;
        
    }

    double avgDuration_ms = totalDuration_ms / numRuns;

    cout << endl << endl << "Sorted array:" << endl;
    printArray(randomArray);

    cout << "Average execution time over " << numRuns << " runs: " << avgDuration_ms << " microseconds" << endl;
    outputFile << "Average execution time over " << numRuns << " runs: " << avgDuration_ms << " microseconds" << endl;

    return 0;
    
    

}
