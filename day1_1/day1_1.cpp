#include <bits/stdc++.h>
#include <vector>
#include <cmath>
using namespace std;

bool comp(int a, int b) {
    return a >= b;
}

int day1_1() {
    ifstream f("day1.txt");

    if (!f.is_open()) {
        cerr << "Error opening file";
        return 1;
    }

    int total = 0;
    string s;
    vector<int> first;
    vector<int> second;
    string del = "   ";

    while (getline(f, s)) {
        vector<int> numbers;
        istringstream stream(s);
        int num;

        while (stream >> num) {
            numbers.push_back(num);
        }

        first.push_back(numbers[0]);
        second.push_back(numbers[1]);
    }

    sort(first.begin(), first.end(), comp);
    sort(second.begin(), second.end(), comp);

    for (size_t i = 0; i < min(first.size(), second.size()); i++) {
        total += abs(first[i] - second[i]);
    }

    return total;
}

int main () {
    cout << day1_1() << endl;
    return 0;
}