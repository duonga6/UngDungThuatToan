#include <iostream>
#include <string.h>
using namespace std;

int thamlam(float *a, float C, int n, float &M) {
	int dem = 0, i = 0;
	while (i < n && C > 0) {
		if (C > a[i]) {
			dem++;
			C -= a[i];
			M += a[i];
		}
		i++;
	}
	return dem;
}

int char_in_string(char s, char *t) {
	for (int i = 0; i < strlen(t); i++)
		if (s == t[i])
			return i;
	return -1;
}

int boyer(char *P, char *Q) {
	int dem = 0, v = strlen(Q), i = v - 1;
	while (i < strlen(P)) {
		int x = v - 1, j = i;
		while (P[j] == Q[x] && x > -1) {
			x--;
			j--;
		}
		if (x < 0) {
			dem++;
			i = i + v;
		} else {
			int k = char_in_string(P[j], Q);
			if (k < 0) i = i + v;
			else i = i + v - k - 1;
		}
	}
	return dem;
}

int main() {
	int n = 8;
	float a[n] = {1.2, 2.4, 6.1, 12.2, 22.5, 29.7, 31.1, 39.2};
	float C = 22.4;
	char P[] = "Hello world - Hello world\0";
	char Q[] = "Hello\0";
	
	float M = 0;
	int D = thamlam(a, C, n, M);
	if (D == 0) {
		cout << "Khong co ket qua" << endl;
	} else {
		cout << "D = " << D << endl;
		cout << "M = " << M << endl;
		for (int i = 0; i < D; i++)
			cout << a[i] << " ";
		cout << endl;
	}
	
	int dem = boyer(P, Q);
	if (dem > 0) {
		cout << dem << endl;
		cout << "Q la chuoi con cua P" << endl;
	} else {
		cout << "Q khong la chuoi con cua P" << endl;
	}
	
	return 0;
}
