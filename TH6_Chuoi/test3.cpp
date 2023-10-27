#include <iostream>
using namespace std;

struct hang{
	int w;
	float v;
};

void quyhoach(hang *d, float **F, int n, int m) {
	for (int i = 0; i <= m; i++)
		F[0][i] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			F[i][j] = F[i - 1][j];
			float temp = d[i].v + F[i - 1][j - d[i].w];
			if (d[i].w <= j && F[i][j] < temp)
				F[i][j] = temp;
		}
	}
}

void result(hang *d, float **F, int n, int m) {
	int i = n, j = m;
	while (i != 0) {
		if (F[i][j] != F[i-1][j]) {
			cout << d[i].w << " " << d[i].v << endl;
			j -= d[i].w;
		}
		i--;
	}
}

int main() {
	int n = 6, m = 42;
	
	hang d[n] = {
	{4, 6.5},
	{7, 8.9},
	{3, 2.1},
	{12, 6.2},
	{21, 28.1},
	{9, 10.2},
	};
	
	float **F = new float*[n + 1];
	for (int i = 0; i <= n; i++)
		F[i] = new float[m + 1];
	
	quyhoach(d, F, n, m);
	result(d, F, n, m);
	
	
	return 0;
}
