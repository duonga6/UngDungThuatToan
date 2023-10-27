#include <iostream>
using namespace std;

struct HANG {
	int gt;
	float kl;
	HANG(){
		this->gt = 0;
		this->kl = 0;
	}
	HANG(int gt, float kl) {
		this->gt = gt;
		this->kl = kl;
	}
};

HANG *d;
int n = 6;
int M = 16;
float **F;

void quyhoach() {
	for (int i = 0; i <= M; i++)
		F[0][i] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= M; j++) {
			F[i][j] = F[i - 1][j];
			float temp = d[i].kl + F[i - 1][j - d[i].gt];
			if (d[i].gt <= j && F[i][j] < temp)
				F[i][j] = temp;
		}
	}
}

void result() {
	int i = n, j = M;
	while (i != 0) {
		if (F[i][j] != F[i-1][j]) {
			cout << d[i].gt << " " << d[i].kl << endl;
			j -= d[i].gt;
		}
		i--;
	}
}

int main() {
	d = new HANG[n + 1];
	d[1] = HANG(5, 3.2);
	d[2] = HANG(11, 8.7);
	d[3] = HANG(2, 1.1);
	d[4] = HANG(8, 4.9);
	d[5] = HANG(3, 1.9);
	d[6] = HANG(1, 0.5);
	
	F = new float*[n + 1];
	for (int i = 0; i <= n; i++)
		F[i] = new float[M + 1];
		
	quyhoach();
	
	result();
	return 0;
}
