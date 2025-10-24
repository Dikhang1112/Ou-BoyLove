#include <iostream>
#include <climits>
using namespace std;


int sumArr(int a[10][10], int row, int col, int k) {
    int sum = 0;
    for (int i = row; i < row + k; i++) {
        for (int j = col; j < col + k; j++) {
            sum += a[i][j];
        }
    }
    return sum;
}

int bestWindow(int a[10][10], int m, int n, int k) {
    if (k > m || k > n || k <= 0) {
        return -1; 
    }
    int maxSum = INT_MIN;
    for (int i = 0; i <= m - k; i++) {
        for (int j = 0; j <= n - k; j++) {
            int curSum = sumArr(a, i, j, k);
            if (curSum > maxSum) {
                maxSum = curSum;
            }
        }
    }
    return maxSum;
}

int main() {
    int m = 4, n = 5;
    int k = 2;

    int a[10][10] = {
        {1, 2, 4, 7},
        {4, 3, 10, 8},
        {1, 1, 2, 5}
    };

    cout << "Max sum = " << bestWindow(a,   , n, k) << endl;
    return 0;
}
