#include <iostream>
using namespace std;

void insertArr(int *s, int m) {
	for (int i = 0; i < m; i++) {
		cout << "S[" << i << "] = ";	cin >> s[i];
	}
}

void sortArr(int *s, int m) {
	for (int i = 0; i < m-1; i++)
		for (int j = i + 1; j < m; j++)
			if (s[i] > s[j]) {
				int tg = s[i];
				s[i] = s[j];
				s[j] = tg;
			}
}

bool pouring(int *C, int n, int m, int &s) {
	int i = 0;
	while (n >= C[i]) {
		s++;
		n -= C[i];
		i++;
	}
	if (s == 0)
		return false;
	else
		return true;
}

int main() {
	int n, m, s = 0;
	cout << "Dung tich be nuoc: ";	cin >> n;
	cout << "So luong chai: ";	cin >> m;
	cout << "Dung tich cac chai: " << endl;
	int C[m];
	insertArr(C, m);
	sortArr(C, m);
	if (pouring(C, n, m, s))
		cout << "So binh toi da duoc do day la: " << s;
	else
		cout << "Khong do duoc binh nao";
	return 0;
}
