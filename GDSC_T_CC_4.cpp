#include<iostream>
#include<vector>
using namespace std;

// function to find the maximum sum of a contiguous subarray
pair<int, vector<int>> Finding_Max_subarray_Sum(vector<int>& Numbs) {
    int max_current = Numbs[0];
    int maximum_Last = Numbs[0];
    int first = 0, last = 0, s = 0;

    for (int i = 1; i < Numbs.size(); i++) {
        if (maximum_Last < 0) {
            maximum_Last = Numbs[i];
            s = i;
        } else {
            maximum_Last += Numbs[i];
        }

        if (max_current < maximum_Last) {
            max_current = maximum_Last;
            first = s;
            last = i;
        }
    }

    return {max_current, {Numbs.begin() + first, Numbs.begin() + last + 1}};
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> Numbs(n);
    cout << "Enter the array elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> Numbs[i];
    }

    auto Result = Finding_Max_subarray_Sum(Numbs);
    cout << "Maximum sum of contiguous subarray is: " << endl << Result.first << " -> [";
    for (auto X = Result.second.begin(); X != Result.second.end(); X++) {
        if (X != Result.second.begin()) {
            cout << ", ";
        }
        cout << *X;
    }
    cout << "]" << endl;

    return 0;
}
