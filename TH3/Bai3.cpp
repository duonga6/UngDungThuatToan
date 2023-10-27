#include <iostream>
using namespace std;

float Max(float *x, int l, int r) {
	if (l == r)
		return x[l];
	int mid = (l + r) / 2;
	float maxLeft = Max(x, l, mid);
	float maxRight = Max(x, mid + 1, r);
	return maxLeft <= maxRight ? maxRight : maxLeft;
}

int main() {
	float x[15] = {1.2, 2.3, 4.5, -0.5, -8, -12.7, 20, 24.5, 28.4, -10, 22, -19.2, 18.9, -13, -16.3};
	
	cout << Max(x, 0, 14);
	return 0;
}
