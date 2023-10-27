#include <iostream>
using namespace std;

struct dt {
	string hsx;
	int kt, gia;
};

void quyhoach(dt *d, int **F, int n, int m){
	for (int i = 0; i <= m; i++)
		F[0][i] = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 0; j <= m; j++) {
			F[i][j] = F[i - 1][j];
			int temp = d[i].gia + F[i - 1][j - d[i].kt];
			if (d[i].kt <= j && F[i][j] < temp)
				F[i][j] = temp;
		}
}

void result(dt *d, int **F, int n, int m) {
	int i = n, j = m;
	while (i != 0) {
		if (F[i][j] != F[i-1][j]) {
			cout << d[i].hsx << " " << d[i].gia << endl;
			j -= d[i].kt;
		}
		i--;
	}
}

int main() {
	int n = 6; 
	int m = 22;
	dt d[n] = {
	{"sony", 4, 600000},
	{"samsung", 7, 1000000},
	{"aple", 5, 700000},
	{"xiaomi", 6, 810000},
	{"lenovo", 11, 1650000},
	{"lg", 15, 2130000}
	};
	
	int **F = new int*[n + 1];
	for (int i = 0; i <= n; i++)
		F[i] = new int[m + 1];
	
	quyhoach(d, F, n, m);
	result(d, F, n, m);
	
	return 0;
}
