#include <iostream>
using namespace std;

struct Hang {
	string mh;
	float gia;
};

const int n = 6;
Hang hang[n+1] = {
	{"", 0},
	{"h1", 1.5},
	{"h2", 1.2},
	{"h3", 2.3},
	{"h4", 0.7},
	{"h5", 4.1},
	{"h6", 5.3}
};

float tongia(Hang x[], int n) {
	if (n == 0)
		return 0;
	return x[n].gia + tongia(x, n-1);
}

void swap(Hang &x, Hang &y) {
	Hang tg;
	tg = x;
	x = y;
	y = tg;
}

void quick_sort(Hang *x, int l, int r) {
	int i = l, j = r;
	float pivot = x[(l+r)/2].gia;
	while (i <= j) {
		while (x[i].gia < pivot)
			i++;
		while (x[j].gia > pivot)
			j--;
		if (i <= j) {
			swap(x[i], x[j]);
			i++;
			j--;
		}
	}
	if (l < j)
		quick_sort(x, l, j);
	if (r > i)
		quick_sort(x, i, r);
}

void xuat(Hang x[], int n) {
	for (int i = 1; i <= n; i++)
		cout << x[i].mh << "\t" << x[i].gia << endl;
}

void banhang(Hang *x, float p, int n, int &s) {
	int i = 1;
	while (i <= n && p - x[i].gia >= 0) {
		p -= x[i].gia;
		i++;
		s++;
	}
}

void show(int *x, int n) {
	for (int i = 1; i <= n; i++)
		cout << hang[x[i]].mh << "\t";
	cout << endl;
}

void swapint(int &x, int &y) {
	int tg = x;
	x = y;
	y = tg;
}

void next(int *x, int i, int n) {
	int k = n;
	while (x[k] < x[i])
		k--;
	swapint(x[k], x[i]);
	i++;
	int j = n;
	while (i < j) {
		swapint(x[i], x[j]);
		i++;
		j--;
	}
}

void hoanvisinh(int n) {
	int x[n+1], i;
	for (i = 1; i <=n; i++)
		x[i] = i;
	do {
		show(x, n);
		i = n - 1;
		while (i > 0 && x[i] > x[i + 1])
			i--;
		if (i > 0)
			next(x, i, n);
	} while (i > 0);
}

int dd[n+1] = {0};
int kq[n+1] = {0};
void Try(int k, int n) {
	for (int i = 1; i <= n; i++) {
		if (dd[i] == 0) {
			kq[k] = i;
			if (k == n)
				show(kq, n);
			else {
				dd[i] = 1;
				Try(k + 1, n);
				dd[i] = 0;
			}
		}
	}
}

int main() {
	
	cout << tongia(hang, n) << endl;
	
	quick_sort(hang, 1, n);
	xuat(hang, n);
	
	int s = 0;
	float p;
	cout << "p = ";
	cin >> p;
	banhang(hang, p, n, s);
	xuat(hang, s);
	
	cout << "1\t2\t3\t4\t5\t6" << endl;
//	hoanvisinh(n);
	Try(1, n);
	
	return 0;
}
