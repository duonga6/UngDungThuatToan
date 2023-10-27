#include<iostream>
using namespace std;

int min(int *x, int l, int r) {
	if (l == r && x[l] % 2 == 0)
		return x[l];
	if (l == r && x[l] % 2 != 0)
		return -1;
	int mid = (l + r) / 2;
	int minL = min(x, l, mid);
	int minR = min(x, mid + 1, r);
	
	if (minL > minR)
		return minR;
	else
		return minL;
}

int main() {
	int a[20] = {0, 2, -4, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16,
	17, 18, 19, 20};
	
	cout << min(a, 0, 19);
	
	return 0;
}
