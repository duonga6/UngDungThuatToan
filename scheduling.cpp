#include <iostream>
using namespace std;

void insertArr(float *s, int m) {
	for (int i = 0; i < m; i++)
		cin >> s[i];
}

void scheduling(float *s, float *f, int *status, int m) {
	int id[m];
	for (int i = 0; i < m; i++) {
		id[i] = i;
		status[i] = 0;
	}
	for (int i = 0; i < m - 1; i++)
		for (int j = m - 1; j > i; j--)
			if (f[j] < f[j-1]) {
				swap(f[j], f[j-1]);
				swap(s[j], s[j-1]);
				swap(id[j], id[j-1]);
			}
	float lastFinish = 0;
	for (int i = 0; i < m; i++) {
		if (s[i] >= lastFinish) {
			status[i] = 1;
			lastFinish = f[i];
		}
	}
	for (int i = 0; i < m - 1; i++)
		for (int j = m - 1; j > i; j--)
			if (id[j] < id[j-1]) {
				swap(id[j], id[j-1]);
				swap(status[j], status[j-1]);
			}
}

int main() {
	int m;
	cin >> m;
	float s[m], f[m];
	int status[m];
	insertArr(s, m);
	insertArr(f, m);
	scheduling(s, f, status, m);
	for (int i = 0; i < m; i++)
		cout << status[i] << " ";
	return 0;
}
