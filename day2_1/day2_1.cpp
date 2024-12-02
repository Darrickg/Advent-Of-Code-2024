#include <bits/stdc++.h>
#include <vector>
#include <cmath>
using namespace std;

bool comp(int a, int b) {
    return a >= b;
}

vector<int> copy(vector<int>& vec) {

    vector<int> ret(vec.size());
    for (long unsigned int i = 0; i < vec.size(); i++) {
        ret[i] = vec[i];
    }

    return ret;
}

int day2_1() {
    ifstream f("day2.txt");

    if (!f.is_open()) {
        cerr << "Error opening file";
        return 1;
    }

    string s;
    string del = " ";
    vector<int> sorted;
    vector<int> backwards;
    int total = 0;

    while (getline(f, s)) {
        vector<int> numbers;
        istringstream stream(s);
        int num;

        while (stream >> num) {
            numbers.push_back(num);
        }

        sorted = copy(numbers);
        sort(sorted.begin(), sorted.end(), comp);
        backwards = copy(sorted);
        reverse(backwards.begin(), backwards.end());

        bool valid = true;

        for (size_t i = 1; i < numbers.size(); i++) {
            int diff = abs(numbers[i] - numbers[i-1]);

            if (diff < 1 || diff > 3) {
                valid = false;
                break;
            }
        }

        if ((numbers == sorted || numbers == backwards) && valid == true) {
            total++;
        } else {
            continue;
        }
    }

    return total;
}

int main() {
    cout << day2_1() << endl;
    return 0;
}