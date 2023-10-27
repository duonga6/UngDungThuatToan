#include <iostream>
using namespace std;

float tong(float *a, int left, int right) {
	if (left == right) {
		if (a[left] > 0)
		 return a[left];
		else return 0;
	}
	
	int mid = (left + right) / 2;
	
	float sumL = tong(a, left, mid);
	float sumR = tong(a, mid + 1, right);
	return sumL + sumR;
}

int main() {
	int n = 10;
	float a[n] = {2.5, -2.1, -6.7, 22.1, 67.5, -51.6, 22.6, -21.5, 11.2, -99.9};
	
	cout << tong(a, 0, n - 1);
		
	return 0;
}
