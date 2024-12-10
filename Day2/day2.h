/*
Notes: 
- Each row is a report, each entry in a row is a level
- We are checking for safe reports
- A safe report means: 
    - levels only increase or decrease across the report
    - adjacent levels within a report differ by at least one and at most 3 [>1 & <= 3]
- Return the number of safe reports in the list
*/

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

vector<int> convertStringToVector(string line);

bool isSafe1(vector<int>);

bool isSafe2(vector<int>, int &idx);

bool isSafe3(vector<int>, int idx);

bool isSafe4(vector<int>); // Shorter