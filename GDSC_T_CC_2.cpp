#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// function to sort elements inside the non boundary region of the Matrix
void Sort_to_non_Boundary(int Mat[][10], int n) {
    vector<int> non_Boundary_ele;

    for(int i=1; i<n-1; i++) {
        for(int j=1; j<n-1; j++) {
            non_Boundary_ele.push_back(Mat[i][j]);
        }
    }

    sort(non_Boundary_ele.begin(), non_Boundary_ele.end());

    int k = 0;
    for(int i=1; i<n-1; i++) {
        for(int j=1; j<n-1; j++) {
            Mat[i][j] = non_Boundary_ele[k++];
        }
    }
}

// function to calculate the sum of the main and anti diagonals of the Matrix
int Sum_Doigonal(int Mat[][10], int n) {
    int sum = 0;

    // calculate the sum of the main diagonal
    for(int i=0; i<n; i++) {
        sum += Mat[i][i];
    }

    // calculate the sum of the anti diagonal
    for(int i=0; i<n; i++) {
        sum += Mat[i][n-i-1];
    }

    // adjust the sum if the matrix has an odd order
    if(n%2 == 1) {
        sum -= Mat[n/2][n/2];
    }

    return sum;
}

int main() {
    int n;
    cout << "enter the order of the matrix: ";
    cin >> n;

    int Mat[10][10];

    cout << "enter the matrix elements:\n";
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> Mat[i][j];
        }
    }

    // sort non boundary elements in the Matrix
    Sort_to_non_Boundary(Mat, n);

    cout << "sorted matrix:\n";
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cout << Mat[i][j] << " ";
        }
        cout << endl;
    }

    // calculate and display the sum of diagonals
    int sum = Sum_Doigonal(Mat, n);
    cout << "sum of diagonals: " << sum << endl;

    return 0;
}
