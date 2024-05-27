//
//  randomArray.cpp
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

// Function to generate a random array
vector<int> generateRandomArray(int size) {
    vector<int> randArray(size);

    srand(static_cast<unsigned>(time(nullptr)));


    // Generate random numbers between 0 and 99
    for (int i = 0; i < size; i++) {
        randArray[i] = rand() % 100;
    }

    return randArray;
}

// Function to print the array
void printArray(const vector<int>& arr) {
    for (int i = 0; i < arr.size(); ++i) {
        cout << "Element " << i + 1 << ": " << arr[i] << endl;
    }
}

// Function to save the array to a text file
void saveArrayToFile(const vector<int>& arr, const string& filename) {
    ofstream outputFile(filename); // Open the file for writing

    if (outputFile.is_open()) {
        for (int i = 0; i < arr.size(); i++) {
            outputFile << arr[i] << " "; // Write each element to the file
        }
        outputFile.close(); // Close the file
        cout << "Array saved to " << filename << endl;
    }
    else {
        cerr << "Error opening the file for writing." << endl;
    }
}



int main()
{
    string filenameToOutput = "/Users/ahmetberke/Desktop/2024 SPRING/CSE 311/Empirical Study/array size 100000/random_array.txt";
    string filenameToWrite = "/Users/ahmetberke/Desktop/2024 SPRING/CSE 311/Empirical Study/Empirical Study/random_array.txt";

    //string outputFilename = "/Users/ahmetberke/Desktop/2024 SPRING/CSE 311/Empirical Study/Empirical Study/OUTPUT.txt";
    //freopen(outputFilename.c_str(), "w", stdout);

    int arraySize = 100000;
    vector<int> randomArray = generateRandomArray(arraySize);


    saveArrayToFile(randomArray, filenameToWrite);
    saveArrayToFile(randomArray, filenameToOutput);

    // Print the generated array
    printArray(randomArray);
    //fclose(stdout);

    // Indicate that the terminal output has been copied to the specified file
    //std::cout << "Terminal output copied to " << outputFilename << std::endl;
}
