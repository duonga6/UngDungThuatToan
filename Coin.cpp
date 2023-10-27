#include <iostream>
using namespace std;

void insertArr(int *s, int m) {
	for (int i = 0; i < m; i++) {
		cout << "S[" << i << "] = "; cin >> s[i];
	}
}

void outputArr(int *s, int m) {
	for (int i = 0; i < m; i++)
		cout << "S[" << i << "] = " << s[i] << endl;
}

void sortArr(int *s, int m) {
	for (int i = 0; i < m - 1; i++)
		for (int j = i + 1; j < m; j++)
			if (s[i] < s[j]) {
				int tg = s[i];
				s[i] = s[j];
				s[j] = tg;
			}
}

bool coin(int *C, int n, int m, int *S) {
	for (int i = 0; i < m; i++)
		S[i] = 0;
	int j = 0;
	while (n > 0 && j < m) {
		S[j] = n / C[j];
		n = n % C[j];
		j++;
	}
	if (n > 0)
		return false;
	else
		return true;
}

int main() {
	int n, m;
	cout << "So tien = ";	cin >> n;
	cout << "So menh gia to tien = ";	cin >> m;
	int C[m], S[m];
	insertArr(C, m);
	sortArr(C, m);
	if (coin(C, n, m, S)) {
		cout << "Doi " << n << " can: " << endl;
		for (int i = 0; i < m; i++)
			cout << S[i] << " to " << C[i] << endl;
	} else 
		cout << "Khong doi duoc!" << endl;
	return 0;
}
