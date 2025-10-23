#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0) return false;
    return true;
}

bool isPrimeSum(int sum) {
    return isPrime(sum);
}

bool isPrimeRangeSum(const vector<int>& a, int L, int R) {
    int s = 0;
    for (int i = L; i <= R; ++i) s += a[i];   
    return isPrime(s);
}

void printBestPrimeRunPreferPrimeSum(const vector<int>& a) {
    int n = (int)a.size();

    int bestL = -1, bestR = -1, bestLen = -1;
    bool bestSumIsPrime = false;

    int currL = -1, currLen = 0, currSum = 0;

    auto consider = [&](int L, int R, int len, int sum) {
        bool sumIsPrime = isPrimeSum(sum); 

        if (bestLen == -1) {
            bestL = L; bestR = R; bestLen = len; bestSumIsPrime = sumIsPrime;
            return;
        }
        if (sumIsPrime && !bestSumIsPrime) {
            bestL = L; bestR = R; bestLen = len; bestSumIsPrime = true;
            return;
        }
        if (!sumIsPrime && bestSumIsPrime) return;

        if (len > bestLen) {
            bestL = L; bestR = R; bestLen = len; bestSumIsPrime = sumIsPrime;
            return;
        }
        };

    for (int i = 0; i < n; ++i) {
        if (isPrime(a[i])) {
            if (currLen == 0) { currL = i; currSum = 0; }
            ++currLen;
            currSum += a[i];
        }
        else {
            if (currLen > 0) {
                consider(currL, i - 1, currLen, currSum);
                currLen = 0; currSum = 0;
            }
        }
    }
    if (currLen > 0) consider(currL, n - 1, currLen, currSum);

    if (bestLen <= 0) {
        cout << "Khong co day so nguyen to lien tiep.\n";
        return;
    }

    int s = 0;
    for (int i = bestL; i <= bestR; ++i) s += a[i];
    cout << "Vi tri: [" << bestL << ", " << bestR << "], do dai = " << bestLen
        << ", tong = " << s << (isPrimeSum(s) ? " (prime)\n" : " (not prime)\n");
    cout << "Day so: ";
    for (int i = bestL; i <= bestR; ++i) {
        cout << a[i] << (i < bestR ? ' ' : '\n');
    }
}

int main() {
   
    vector<int> a = { 1,2,3,5,8,7,11,13,17,14,5 };
    printBestPrimeRunPreferPrimeSum(a);
    return 0;
}
