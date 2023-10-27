#include<iostream>
using namespace std;

const int MAX = 8;
int d[MAX+1][MAX+1] = {0};
int dc1[2*MAX - 1];
int dc2[2*MAX - 1];
int cot[MAX + 1] = {0};

void show() {
	for (int i = 1; i <= MAX; i++) {
		for (int j = 1; j <= MAX; j++)
			cout << d[i][j] << " ";
		cout << endl;
	}
}

void Try(int k) {
	for (int i = 1; i <= MAX; i++) {
		if (cot[i] == 0 && dc1[k + i] == 0 && dc2[k - i] == 0){
			cot[i] = 1; dc1[k + i] = 1; dc2[k - i] = 1;
			d[k][i] = 1;
			if (i == MAX)
				show();
			Try(k+1);
		}
	}
}

int main() {
	for (int i = 2; i <= 2*MAX; i++)
		dc1[i] = 0;
	for (int i = 1 - MAX; i <= MAX - 1; i++)
		dc2[i] = 0;
		
	Try(1);
	return 0;
}
