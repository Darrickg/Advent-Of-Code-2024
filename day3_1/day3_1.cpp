#include <bits/stdc++.h>
#include <vector>
#include <cmath>
#include <iostream>
#include <regex>
#include <string>
using namespace std;

int day3_1() {
    ifstream f("day3.txt");

    if (!f.is_open()) {
        cerr << "Error opening file" << endl;
        return 1;
    }

    string s;
    int total = 0;
    regex pattern(R"(mul\((\d+),(\d+)\))");

    while (getline(f, s)) {

        smatch match;
        string::const_iterator searchStart(s.cbegin());
        while (regex_search(searchStart, s.cend(), match, pattern)) {
            int num1 = stoi(match[1].str());
            int num2 = stoi(match[2].str());

            total += num1 * num2;

            searchStart = match.suffix().first;
        }
    }

    return total;
}

int main() {
    cout << day3_1() << endl;
    return 0;
}