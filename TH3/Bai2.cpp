#include <iostream>
using namespace std;

float *b = new float[15];

void MergeSort(float *a, int l, int r) {
	if (r > l) {
		int m = (r + l) / 2;
		MergeSort(a, l, m);
		MergeSort(a, m + 1, r);
		
		for (int i = m; i >= l; i--) b[i] = a[i];
		for (int j = m + 1; j <= r; j++) b[r+m+1-j] = a[j];
		
		int i = l, j = r;
		for (int k = l; k <= r; k++)
			if (b[i] < b[j]) {
				a[k] = b[i];
				i++;
			} else {
				a[k] = b[j];
				j--;
			}
				
	}
}

int main() {
	float x[15] = {1.2, 2.3, 4.5, -0.5, -8, -12.7, 20, 24.5, 28.4, -10, 22, -19.2, 18.9, -13, -16.3};
	MergeSort(x, 0, 14);
	for (int i = 0; i < 15; i++) {
		cout << x[i] << " ";
	}
	return 0;
}
