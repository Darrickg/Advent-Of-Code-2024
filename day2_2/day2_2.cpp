#include <bits/stdc++.h>
#include <vector>
#include <cmath>
using namespace std;

bool isSortedAscending(const vector<int>& numbers) {
    for (size_t i = 1; i < numbers.size(); i++) {
        if (numbers[i] <= numbers[i - 1]) {
            return false;
        }
    }
    return true;
}

bool isSortedDescending(const vector<int>& numbers) {
    for (size_t i = 1; i < numbers.size(); i++) {
        if (numbers[i] >= numbers[i - 1]) {
            return false;
        }
    }
    return true;
}

bool hasValidDifferences(const vector<int>& numbers) {
    for (size_t i = 1; i < numbers.size(); i++) {
        int diff = abs(numbers[i] - numbers[i - 1]);
        if (diff < 1 || diff > 3) {
            return false;
        }
    }
    return true;
}

bool isSafe(const vector<int>& numbers) {
    return (isSortedAscending(numbers) || isSortedDescending(numbers)) && hasValidDifferences(numbers);
}

int day2_2() {
    ifstream f("day2.txt");

    if (!f.is_open()) {
        cerr << "Error opening file" << endl;
        return 1;
    }

    string s;
    int total = 0;

    while (getline(f, s)) {
        vector<int> numbers;
        istringstream stream(s);
        int num;

        while (stream >> num) {
            numbers.push_back(num);
        }

        if (isSafe(numbers)) {
            total++;
            continue;
        }

        bool foundSafeAfterRemoval = false;
        for (size_t i = 0; i < numbers.size(); i++) {
            vector<int> modified = numbers;
            modified.erase(modified.begin() + i);

            if (isSafe(modified)) {
                foundSafeAfterRemoval = true;
                break;
            }
        }

        if (foundSafeAfterRemoval) {
            total++;
        }
    }

    return total;
}

int main() {
    cout << day2_2() << endl;
    return 0;
}
