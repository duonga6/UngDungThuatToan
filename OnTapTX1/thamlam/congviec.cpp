#include <iostream>
using namespace std;

struct CV {
	string mcv;
	float bd;
	float kt;
};

CV ds[7] = {
	{"", 0, 0},
	{"cv1", 7, 8.5},
	{"cv2", 8.7, 10.2},
	{"cv3", 9.3, 10.8},
	{"cv4", 10.1, 11.5},
	{"cv5", 11.6, 12.4},
	{"cv6", 12.5, 13.6}
};

float tongtg(CV *x, int n) {
	if (n == 0)
		return 0;
	return (x[n].kt-x[n].bd) + tongtg(x, n - 1);
}

void swap(CV &x, CV &y) {
	CV z = x;
	x = y;
	y = z;
}

void sapxep(CV *x, int l, int r) {
	int i = l, j = r;
	float pivot = x[(l+r)/2].kt;
	while (i <= j) {
		while(x[i].kt < pivot)
			i++;
		while(x[j].kt > pivot)
			j--;
		if (i <= j) {
			swap(x[i], x[j]);
			i++;
			j--;
		}
	}
	if (l < j)
		sapxep(x, l, j);
	if (r > i)
		sapxep(x, i, r);
}

void xuat() {
	for (int i = 1; i <= 6; i++)
		cout << ds[i].mcv << " " << ds[i].bd << " " << ds[i].kt << endl;
}

void lastF(CV *x, int *result, int n) {
	float lastFinish = 0;
	for (int i = 1; i <= n; i++) {
		if (x[i].bd > lastFinish) {
			lastFinish = x[i].kt;
			result[i] = 1;
		}
	}
}

void xuatKQ(CV *x, int n, int *result) {
	for (int i = 1; i <= n; i++)
		if (result[i] == 1)
			cout << ds[i].mcv << " " << ds[i].bd << " " << ds[i].kt << endl;
}

void show(int *x, int k) {
	for (int i = 1; i <= k; i++)
		cout << ds[x[i]].mcv << " ";
	cout << endl;
}

void next(int *x, int i, int k) {
	x[i] += 1;
	i++;
	while (i <= k) {
		x[i] = x[i - 1] + 1;
		i++;
	}
}

void layCV(int n, int k) {
	int x[k+1], i;
	for (i = 1; i <= k; i++)
		x[i] = i;
	do {
		show(x, k);
		i = n - 1;
		while (i > 0 && x[i] == n - k + i)
			i--;
		if (i > 0)
			next(x, i, k);
	} while (i > 0);
}

int x[7] = {0};

void layCV2(int i, int k, int n) {
	for (int j = x[i - 1] + 1; j <= n - k + i; j++) {
		x[i] = j;
		if (i == k)
			show(x, k);
		else
			layCV2(i + 1, k, n);
	}
}

int main() {
	// tong thoi gian thuc hien
	cout << tongtg(ds, 6) << endl;
	// so cong viec thuc hien nhieu nhat
	sapxep(ds, 1, 6);
	int result[7] = {0};
	lastF(ds, result, 6);
	xuatKQ(ds, 6, result);
	
	// lay 5 cong viec tu cac cong viec tren
	layCV(6, 5);
	layCV2(1, 5, 6);
	return 0;
}
