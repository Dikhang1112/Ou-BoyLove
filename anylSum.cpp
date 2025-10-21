#include <iostream>
#include <math.h>
using namespace std;
//int countSum(int n) {
//	int sum = 0;
//	int count = -1;
//	int i = 1, j = 1;
//	while (i < n) {
//		for (; j <= n; j++) {
//			sum += j;
//			if (sum == n)
//			{
//				count++;
//				i++;
//				j = i;
//				sum = 0;
//			}
//			else if (sum > n) {
//				i++;
//				j = i;
//				sum = 0;
//			}
//		}
//	}
//	return count;
//}
// So cach bieu dien = tong cac uoc le
int countSumNumber(int n) {
	if (n <= 0) return 0;
	int cntOddDiv = - 1;
	for (int i = 1; i * i <= n; i++) {
		if (n % i == 0) {
			int j = n / i;
			if (i % 2 == 1) cntOddDiv++;        
			if (j != i && i % 2 == 1) cntOddDiv++; 
		}
	}
	return  cntOddDiv;
}

int main()
{	
	int count = countSumNumber(15);
	if (count == 0)
	{
		cout << count << endl;
	}
	else {
		cout << "So luong tong cua so tu nhien la:" << count << endl;
	}
	return 0;
}