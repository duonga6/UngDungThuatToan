#include <iostream>
using namespace std;

struct hang{
	int w; float v;
};

void quyhoach(hang *d, float **F, int n, int m) {
	for (int i = 0; i <= m; i++)
		F[0][i] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			F[i][j] = F[i-1][j];
			float temp = d[i].v + F[i-1][j-d[i].w];
			if (d[i].w <= j && F[i][j] < temp)
				F[i][j] = temp;
		}
	}
}

void result(hang *d, float **F, int n, int m) {
	int i = n, j = m;
	while (i != 0) {
		if (F[i][j] != F[i - 1][j])
			i -= d[i].w
		i--;
	}
}

int main() {
	
	return 0;
}
