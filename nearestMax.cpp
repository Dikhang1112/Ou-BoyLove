#include <iostream>
#include <vector>
using namespace std;
//Cú pháp hàm exchange
// max1 = v;
// max2 = old; (Giá tr? tr??c khi gán)
// C++ 11: if (v > max1) { max2 = max1; max1 = v; }
int main() {
    vector<int> a = { 2,4,3,1,2,2,5,6,6,7};
    int max1 = 0, max2 = 0;
    for (int v : a) {
        if (v > max1) max2 = exchange(max1, v);
        else if (v < max1 && v > max2) max2 = v;
    }
    cout << (max2 == 0 ? max1 : max2);
}
