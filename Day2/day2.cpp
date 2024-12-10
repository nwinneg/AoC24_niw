#include "day2.h"
#include <sstream>
#include <numeric>

using namespace std;

int main()
{
    string dataFile = "input.txt";
    ifstream file(dataFile);
    string line;
    vector<int> report;
    int safeCounter = 0;

    // Check that the file opened appropriately
    if (!file.is_open()) {
        cout << "Unable to open file..." << endl;
    }

    // Loop through the file and read each line
    while (getline(file,line)) {
        // Convert the line into a vector of numbers
        report = convertStringToVector(line);
        
        // Instantiate
        int idx = 0;
        bool safe = isSafe2(report,idx);

        // Check if the report on it's own is safe
        if (safe) {
            // cout << "Safe" << endl;
            safeCounter++;
        }

        // If not, loop through removing a single element and check again
        else {
            bool safeAfter = false;
            for (int jj=0; jj < report.size(); jj++) {
                if(isSafe3(report,jj)) {
                    safeAfter = true;
                }
            }
            if (safeAfter) {
                safeCounter++;
            }
        }
    }

    // Report the results:
    cout << "\nNumber of safe reports: " << safeCounter << endl;
}

vector<int> convertStringToVector(string line)
{
    vector<int> levels;
    int level;
    istringstream ss(line);

    while (ss >> level) {
        levels.push_back(level);
    }

    return levels;
}

bool isSafe1(vector<int> report)
{   
    // Initialize
    bool isAscending;
    int prev;
    int cur;

    // Loop through the report
    for(int ii=0; ii < report.size(); ii++) {
        if (ii == 0) {
            prev = report[ii];
            continue;
        }
        cur = report[ii];
        prev = report[ii-1];
        if (ii == 1) {
            // Check increase decrease condition
            if ((abs(cur - prev) < 1 ) || (abs(cur - prev) > 3)) {
                return false;
            }
            // Check ascending or descending condition
            isAscending = cur > prev;
        }
        else {
            // Check increase decrease condition
            if ((abs(cur - prev) < 1 ) || (abs(cur - prev) > 3)) {
                return false;
            }
            // Check ascending/descending
            if (isAscending && (cur < prev)) {
                return false;
            }
            else if (!isAscending && (cur > prev)) {
                return false;
            }
        }

    }
    return true;
}

bool isSafe2(vector<int> report, int &idx) 
{   
   // Initialize
    bool isAscending;
    int prev;
    int cur;

    // Loop through the report
    for(int ii=0; ii < report.size(); ii++) {
        if (ii == 0) {
            prev = report[ii];
            continue;
        }
        cur = report[ii];
        prev = report[ii-1];
        if (ii == 1) {
            // Check increase decrease condition
            if ((abs(cur - prev) < 1 ) || (abs(cur - prev) > 3)) {
                idx = ii;
                return false;
            }
            // Check ascending or descending condition
            isAscending = cur > prev;
        }
        else {
            // Check increase decrease condition
            if ((abs(cur - prev) < 1 ) || (abs(cur - prev) > 3)) {
                idx = ii;
                return false;
            }
            // Check ascending/descending
            if (isAscending && (cur < prev)) {
                idx = ii;
                return false;
            }
            else if (!isAscending && (cur > prev)) {
                idx = ii;
                return false;
            }
        }

    }
    return true;
}

bool isSafe3(vector<int> report, int removeIdx)
{   
    // Modify the vector
    report.erase(report.begin() + removeIdx);
    // Initialize
    bool isAscending;
    int prev;
    int cur;

    // Loop through the report
    for(int ii=0; ii < report.size(); ii++) {
        if (ii == 0) {
            prev = report[ii];
            continue;
        }
        cur = report[ii];
        prev = report[ii-1];
        if (ii == 1) {
            // Check increase decrease condition
            if ((abs(cur - prev) < 1 ) || (abs(cur - prev) > 3)) {
                return false;
            }
            // Check ascending or descending condition
            isAscending = cur > prev;
        }
        else {
            // Check increase decrease condition
            if ((abs(cur - prev) < 1 ) || (abs(cur - prev) > 3)) {
                return false;
            }
            // Check ascending/descending
            if (isAscending && (cur < prev)) {
                return false;
            }
            else if (!isAscending && (cur > prev)) {
                return false;
            }
        }

    }
    return true;
}