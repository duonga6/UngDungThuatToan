#include <iostream>
using namespace std;

int tong(int *a, int left, int right) {
	if (left == right) {
		if (a[left] % 2 == 0)
			return 0;
		else return a[left];
	}
	
	int mid = (left + right) / 2;
	int sumL = tong(a, left, mid);
	int sumR = tong(a, mid+1, right);
	return sumL + sumR;
}

int main() {
	int n = 10;
	int a[n] = {1,5,2,6,11,49,34,12,98,34};
	
	cout << tong(a, 0, n - 1);
	
	return 0;
}
