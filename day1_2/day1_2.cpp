#include <bits/stdc++.h>
#include <vector>
#include <cmath>
#include <unordered_map>
using namespace std;

bool comp(int a, int b) {
    return a >= b;
}

int day1_2() {
    ifstream f("day1.txt");

    if (!f.is_open()) {
        cerr << "Error opening file";
        return 1;
    }

    int total = 0;
    string s;
    vector<int> first;
    unordered_map<int, int> count;
    string del = "   ";

    while (getline(f, s)) {
        vector<int> numbers;
        istringstream stream(s);
        int num;

        while (stream >> num) {
            numbers.push_back(num);
        }

        first.push_back(numbers[0]);
        count[numbers[1]]++;
    }

    for (int i : first) {
        if (count.find(i) != count.end()) {
            total += i * count[i];
        }
    }

    return total;
}

int main() {
    cout << day1_2() << endl;
    return 0;
}