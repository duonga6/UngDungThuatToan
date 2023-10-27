#include <iostream>
using namespace std;

struct hang{
	float gt;
	int kl;
	hang() {
		this->gt=0;
		this->kl=0;
	}
	hang(float gt, int kl) {
		this->gt = gt;
		this->kl = kl;
	}
};

void sapxep(hang *x, int n) {
	for (int i = 1; i < n; i++) {
		for (int j = i + 1; j <= n; j++) {
			if (x[i].gt > x[j].gt) {
				hang temp = x[i];
				x[i] = x[j];
				x[j] = temp;
			}
		}
	}
}

float thamlam(hang *a, float C, int n, int &dem) {
	sapxep(a, n);
	int i = 1;
	while (i < n && C > 0) {
		if (C >= a[i].gt) {
			C -= a[i].gt;
			dem++;
		}
		i++;
	}
	return C;
}

void quyhoach(hang *a, int M, float **F, int n) {
	for (int i = 0; i <= M; i++) {
		F[0][i] = 0;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= M; j++) {
			F[i][j] = F[i-1][j];
			float temp = a[i].gt + F[i - 1][j - a[i].kl];
			if (a[i].kl <= j && F[i][j] < temp)
				F[i][j] = temp;
		}
	}
}

void result(hang *a, int M, float **F, int n) {
	int i = n, j = M;
	float P = 0;
	while (i != 0) {
		if (F[i][j] != F[i-1][j]) {
			cout << a[i].kl << " ";
			P += a[i].kl;
			j -= a[i].kl;
		}
		i--;
	}
	cout << "\nP = " << P << endl;
}

int main() {
	int n = 8;
	hang *a = new hang[n + 1];
	a[1] = hang(2.2, 5);
	a[2] = hang(4.5, 8);
	a[3] = hang(3.9, 6);
	a[4] = hang(1.2, 2);
	a[5] = hang(7.8, 11);
	a[6] = hang(4.1, 5);
	a[7] = hang(2.9, 6);
	a[8] = hang(1.5, 3);
	float C = 2.7;
	
	int D = 0;
	float c = thamlam(a, C, n, D);
	if (c == 0 && D != 0) {
		cout << "D = " << D << endl;
		for (int i = 1; i <= D; i++) {
			cout << a[i].gt << " ";
		}
		cout << endl;
	} else {
		cout << "Khong co ket qua" << endl;
	}
	
	int M = 18;
	
	float **F = new float*[n + 1];
	for (int i = 0; i <= n; i++)
		F[i] = new float[M + 1];
		
	quyhoach(a, M, F, n);
	result(a, M, F, n);
	return 0;
}
