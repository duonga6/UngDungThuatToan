#include <iostream>
using namespace std;

int n = 5;
int m[100][100] = {0};
int X[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int Y[8] = {-1, 1, -2, 2, -2, 2, -1, 1};
int dem = 0;

void show() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cout << m[i][j] << "\t";
		cout << endl << endl;
	}
}

void Try(int x, int y) {
	++dem;
	m[x][y] = dem;
	for (int i = 0; i < 8; i++) {
		if (dem == n * n) {
			cout << "cac buoc di la: " << endl;
			show();
			exit(0);
		}
		
		int u = x + X[i];
		int v = y + Y[i];
		
		if (u >= 0 && u < n && v >= 0 && v < n && m[u][v] == 0)
			Try(u, v);
	}
	--dem;
	m[x][y] = 0;
}

int main() {
	Try(0 ,0);
	return 0;
}
