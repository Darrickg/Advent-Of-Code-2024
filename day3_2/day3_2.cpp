#include <bits/stdc++.h>
#include <vector>
#include <cmath>
#include <iostream>
#include <regex>
#include <string>
using namespace std;

int day3_2() {
    ifstream f("day3.txt");

    if (!f.is_open()) {
        cerr << "Error opening file" << endl;
        return 1;
    }

    string s;
    int total = 0;
    regex mulPattern(R"(mul\((\d+),(\d+)\))");
    regex doPattern(R"(do\(\))");
    regex dontPattern(R"(don't\(\))");

    bool mulEnabled = true;

    while (getline(f, s)) {
        smatch match;
        string::const_iterator searchStart(s.cbegin());

        while (regex_search(searchStart, s.cend(), match, regex(R"((mul\((\d+),(\d+)\))|do\(\)|don't\(\))"))) {
            string matched = match.str();

            if (regex_match(matched, doPattern)) {
                mulEnabled = true;
            } else if (regex_match(matched, dontPattern)) {
                mulEnabled = false;
            } else if (regex_match(matched, mulPattern)) {
                if (mulEnabled) {
                    int num1 = stoi(match[2].str());
                    int num2 = stoi(match[3].str());
                    total += num1 * num2;
                }
            }

            searchStart = match.suffix().first;
        }
    }

    return total;
}

int main() {
    cout << day3_2() << endl;
    return 0;
}
