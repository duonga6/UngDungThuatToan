#include <iostream>
using namespace std;

struct SP{
	string msp;
	float gia;
};

SP dsSP[7] = {
	{"", 0},
	{"sp1", 5.5},
	{"sp2", 4.3},
	{"sp3", 6.2},
	{"sp4", 12.4},
	{"sp5", 2.6},
	{"sp6", 3.6},
};

float tonggia(SP *x, int n) {
	if (n == 0)
		return 0;
	return x[n].gia + tonggia(x, n - 1);
}

// sinh tap con pp sinh

void showtapcon_sinh(int *x, int k) {
	for (int i = 1; i <= k; i++)
		cout << dsSP[x[i]].msp << " ";
	cout << endl;
}

void tapcon_next(int *x, int i, int k) {
	x[i] += 1;
	i++;
	while (i <= k) {
		x[i] = x[i - 1] + 1;
		i++;
	}
}

void tapcon_sinh(int k, int n) {
	int x[k + 1], i;
	for (i = 1; i <= k; i++)
		x[i] = i;
	do {
		showtapcon_sinh(x, k);
		i = k;
		while (i > 0 && x[i] == n - k + i)
			i--;
		if (i > 0)
			tapcon_next(x, i, k);
	} while (i > 0);
}

// sinhtap con quay lui

int z[7] = {0};

void tapcon_quaylui(int i, int n, int k) {
	for (int j = z[i -1] + 1; j <= n - k + i; j++) {
		z[i] = j;
		if (i == k)
			showtapcon_sinh(z, k);
		else
			tapcon_quaylui(i + 1, n, k);
	}
}

// hoan vi pp sinh

void swap(int &a, int &b) {
	int tg = a;
	a = b;
	b = tg;
}

void hoanvi_next(int *x, int i, int n) {
	int k = n;
	while (x[k] < x[i])
		k--;
	swap(x[i], x[k]);
	i++;
	int j = n;
	while (i <= j) {
		swap(x[i], x[j]);
		i++;
		j--;
	}
}

void hoanvi_sinh(int n) {
	int x[n + 1], i;
	for (i = 1; i <= n; i++)
		x[i] = i;
	do {
		showtapcon_sinh(x, n);
		i = n - 1;
		while (i > 0 && x[i] > x[i+1])
			i--;
		if (i > 0)
			hoanvi_next(x, i, n);
	} while (i > 0);
}

// hoan vi quay lui
int dd[7] = {0};
int kq[7] = {0};

void hoanvi_quaylui(int k, int n) {
	for (int i = 1; i <= n; i++) {
		if (dd[i] == 0) {
			kq[k] = i;
			if (k == n)
				showtapcon_sinh(kq, n);
			else {
				dd[i] = 1;
				hoanvi_quaylui(k + 1, n);
				dd[i] = 0;
			}
		}
	}
}

void quick_sort(SP *x, int l, int r) {
	int i = l, j = r;
	float pivot = x[(l+r)/2].gia;
	while(i <= j) {
		while (x[i].gia < pivot)
			i++;
		while (x[j].gia > pivot)
			j--;
		if (i <= j) {
			SP z = x[i];
			x[i] = x[j];
			x[j] = z;
			i++;
			j--;
		}
	}
	if (l < j)
		quick_sort(x, l, j);
	if (r > i)
		quick_sort(x, i, r);
}

void thamlam(SP *x, float t, int n, int &s) {
	int i = 1;
	while (i <= n && x[i].gia <= t) {
		t -= x[i].gia;
		i++;
		s++;
	}
}

int main() {
	cout << tonggia(dsSP, 6) << endl;
//	tapcon_sinh(4, 6);
//	tapcon_quaylui(1, 6, 4);
//	hoanvi_sinh(6);
//	hoanvi_quaylui(1, 6);
	float t;
	int s = 0;
	cout << "t = ";
	cin >> t;
	quick_sort(dsSP, 1, 6);
	thamlam(dsSP, t, 6, s);
	for (int i = 1; i <= s; i++)
		cout << dsSP[i].gia << " ";
}
