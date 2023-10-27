#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

// Hàm random
int random(int minN, int maxN){
 return minN + rand() % (maxN + 1 - minN);
}

void loang(int i, int j, bool **flag, int **O, int m, int n, int &so_mien) {
	flag[i][j] = true;
	so_mien++;
	//loang trai
	if (j > 0)
		if (O[i][j - 1] == O[i][j] && !(flag[i][j-1]))
			loang(i, j - 1, flag, O, m, n, so_mien);
	//loang tren
	if (i > 0)
		if (O[i - 1][j] == O[i][j] && !(flag[i-1][j]))
			loang(i - 1, j, flag, O, m, n, so_mien);
	//loang phai
	if (j < n - 1)
		if (O[i][j + 1] == O[i][j] && !(flag[i][j + 1]))
			loang(i, j + 1, flag, O, m, n, so_mien);
	//loang duoi
	if (i < m - 1)
		if (O[i + 1][j] == O[i][j] && !(flag[i + 1][j]))
			loang(i + 1, j, flag, O, m, n, so_mien);
}

int main() {
	int so_mien = 0;
	int m, n;
	cout << "m = ";	cin >> m;
	cout << "n = ";	cin >> n;
	
	int **O = new int*[m];
	// khoi tao mang 0 1
	for (int i = 0; i < m; i++)
		O[i] = new int[n];
	// khoi tao mang true false
	bool **flag = new bool*[m];
	for (int i = 0; i < m; i++)
		flag[i] = new bool[n];
			
	// random 0 1
	srand((int)time(0));	
	for (int i = 0; i < m; i++) 
		for (int j = 0; j < n; j++)
			O[i][j] = random(0,1);
			
	// xuat mang;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << O[i][j] << " ";
		}
		cout << endl;
	}
	
	//loang
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++) {
			if (O[i][j] == 1 && !flag[i][j]) {
				so_mien = 0;
				cout << "diem xuat phat: O["<<i<<"]["<<j<<"]";
				loang(i, j, flag, O, m, n, so_mien);
				cout << "\tso mien: " << so_mien << endl;
			}
		}
	
	return 0;
}
