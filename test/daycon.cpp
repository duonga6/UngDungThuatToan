#include <iostream>
using namespace std;

// 3 vong lap
long algo1(long a[], int n) {
	long max = a[0];
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			long s = 0;
			for (int k = i; k <= j; k++)
				s = s + a[k];
			max = max < s ? s : max;
		}
	}
	return max;
}

//2 vong lap
long algo2(long a[], int n) {
	long max = a[0];
	for (int i = 0; i < n; i++) {
		long s = 0;
		for (int j = i; j < n; j++) {
			s = s + a[j];
			max = max < s ? s : max;
		}
	}
	return max;
}

int main() {
	long a[6] = {-2, 11, -4, 13,-5, 2};
	cout << algo1(a, 6) << endl;
	cout << algo2(a, 6) << endl;
	return 0;
}
