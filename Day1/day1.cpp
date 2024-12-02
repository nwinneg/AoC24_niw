#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>

using namespace std;

string fname = "input.txt";
// string fname = "testInput.txt";

bool readFile(string filename, vector<int>& col1, vector<int>& col2) { // Pass vectors by reference so they are accessible from calling scope
    // Open and verify it worked
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Unable to open file." << endl;
        return false;
    }

    // Read the file (>> is the shift operator)
    int num1, num2;
    while (file >> num1 >> num2) {
        col1.push_back(num1);
        col2.push_back(num2);
    }

    // Close the file
    file.close();
    return true;
}

void Q1(string filename)
{
    // Initialize Vectors and read File
    vector<int> col1, col2;
    bool val = readFile(fname, col1, col2);
    sort(col1.begin(),col1.end());
    sort(col2.begin(),col2.end());

    int difSum = 0;
    for (int ii=0; ii<col1.size(); ii++) {
        difSum += abs(col1[ii] - col2[ii]);
    }
    cout << "Q1: Total distance: " << difSum << endl;
}

void Q2(string filename)
{
    // Initialize Vectors and read File
    vector<int> col1, col2;
    bool val = readFile(fname, col1, col2);

    // Loop through each and compute similarity score
    int similarityScore = 0;
    for (int ii=0; ii<col1.size(); ii++) {
        // Get the value in column 1
        int val = col1[ii];
        // Start a counter for occurances in column 2
        int col2_counter =  0;
        for (int jj=0; jj<col2.size(); jj++) {
            if (col2[jj] - val == 0) {
                col2_counter += 1;
            }
        }
        similarityScore += (val * col2_counter);
    }

    cout << "Q2: Similarity Score: " << similarityScore << endl;
}

int main()
{
    Q1(fname);
    Q2(fname);
    
}