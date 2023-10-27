#include<iostream>
using namespace std;

void swap(int &x, int &y) {
	int tg = x;
	x = y;
	y = tg;
}

void quick_sort(int *x, int l, int r) {
	int i = l, j = r;
	int pivot = x[(l+r)/2];
	while (i <= j) {
		while (x[i] > pivot)
			i++;
		while (x[j] < pivot)
			j--;
		if (i <= j) {
			swap(x[i], x[j]);
			i++;
			j--;
		}
	}
	if (l < j)
		quick_sort(x, l, j);
	if (r > i)
		quick_sort(x, i, r);
}

void op(int *x, int n) {
	for (int i = 0; i < n; i++)
		cout << x[i] << " ";
}

int main() {
	
	int x[5] = {3, 7, 1, 3, 8};
	quick_sort(x, 0, 4);
	op(x, 5);
	return 0;
}
