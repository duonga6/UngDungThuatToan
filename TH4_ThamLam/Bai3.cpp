#include<iostream>
using namespace std;

void swap(float &a, float &b) {
	float temp = a;
	a = b;
	b = temp;
}

void quicksort(float *x, int l, int r) {
	int i = l, j = r;
	float pivot = x[(l+r) / 2];
	while(i <= j) {
		while(x[i] > pivot)
			i++;
		while(x[j] < pivot)
			j--;
		if (i <= j) {
			swap(x[i], x[j]);
			i++;
			j--;
		}
	}
	if (l < j)
		quicksort(x, l, j);
	if (r > i)
		quicksort(x, i, r);
}

void demxe(float *x, int n, float p, int &s) {
	quicksort(x, 0, n - 1);
	int i = 0;
	while (i < n && p > 0) {
		p -= x[i];
		s++;
		i++;
	}
}

int main() {
	float x[6] = {4.2,2.5,3.5,4.2,6.1, 7.2};
	float p = 13.3;
	int sum = 0;
	demxe(x, 6, p, sum);
	
	if (sum == 0) {
		cout << "Khong co xe nao thoa man" << endl;
	} else {
		for (int i = 0; i < sum; i++)
			cout << x[i] << endl;
	}
	

	return 0;
}
