#include <iostream>
using namespace std;

double sum(float *x, int l, int r) {
	if (l == r && x[l] > 0)
		return x[l];
	if (l == r && x[l] <= 0)
		return 0;
	int mid = (l + r) / 2;
	
	return sum(x, l, mid) + sum(x, mid + 1, r);
}

int main() {
	float x[20] = {1.2, 2.3, 4.5, -0.5, -8, -12.7, 20, 24.5, 28.4,
	-10, 22, -19.2, 18.9, -13, -16.3, 23.6, 16.7, -15.2, 16.4, 22.3};
	
	cout << sum(x, 0, 19);
	
	return 0;
}
