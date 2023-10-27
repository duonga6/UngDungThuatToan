#include <iostream>
#include <string.h>
using namespace std;

int thamlam(float *a, float C, int n, float &M) {
	int dem = 0, i = n - 1;
	while (i >= 0 && C > 0) {
		C -= a[i];
		M += a[i];
		i--;
		dem++;
	}
	return dem;
}

int char_in_string(char s, char *t) {
	for (int i = 0; i < strlen(t); i++)
		if (t[i] == s)
			return i;
	return -1;
}

int boyer(char *P, char *Q, int *vt) {
	int dem = 0, v = strlen(Q), i = v - 1;
	while (i < strlen(P)) {
		int x = v - 1;
		while (P[i] == Q[x] && x > -1) {
			x--;
			i--;
		}
		if (x < 0) {
			vt[dem] = i + 1;
			dem++;
			i = i + v + 1;
		} else {
			int k = char_in_string(P[i], Q);
			if (k < 0) i = i + v;
			else i = i + v - k - 1;
		}
	}
	return dem;
}

int main() {
	int n = 8; 
	float a[n] = {0.1, 2.3, 2.4, 6.1, 4.7, 8.2,9.1, 14.5};
	float C = 25.6;
	char P[] = "so 22 lon hon so 12 va bang so 22";
	char Q[] = "22";
	
	float M = 0;
	int D = thamlam(a, C, n, M);
	if (D == 0) {
		cout << "Khong co ket qua " << endl;
	} else {
		cout << "D = " << D << endl;
		cout << "M = " << M << endl;
		for (int i = n - 1; i >= n - D; i--) {
			cout << a[i] << " ";
		}
		cout << endl;
	}
	
	int vitri[n];
	for (int i = 0; i < n; i++)
		vitri[i] = -1;
	int dem = boyer(P, Q, vitri);
	if (dem > 0) {
		cout << "Vi tri xuat hien cua Q trong P: ";
		int i = 0;
		while (vitri[i] != -1) {
			cout << vitri[i] << " ";
			i++;
		}
	} else {
		cout << "Q khong phai chuoi con cua P";
	}
	return 0;
}
