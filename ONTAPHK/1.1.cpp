#include <iostream>
using namespace std;

float tong(float *a, int left, int right) {
	if (left == right)
		return a[left];
	int mid = (left + right) / 2;
	
	float sumL = tong(a, left, mid);
	float sumR = tong(a, mid+1, right);
	
	return sumL + sumR;
}

int main() {
	int n = 10;
	float a[n] = {0.1, 2.3, 2.4, 6.1, 4.7, 8.2,9.1, 14.5,15.9,22.7};
	
	cout << tong(a, 0, n - 1);
	
	return 0;
}
