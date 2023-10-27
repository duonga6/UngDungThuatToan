#include <iostream>
using namespace std;

struct VE {
	string sohieu;
	float giave;
	int ghengoi;
	VE(){
	}
	VE(string sohieu, float giave, int ghengoi) {
		this->sohieu = sohieu;
		this->giave = giave;
		this->ghengoi = ghengoi;
	}
};

int *a;
VE *b;

void dequy(VE *x, int n) {
	if (n < 0) {
		return;
	}
	if (x[n].giave > 700000) {
		cout << x[n].sohieu << " " << x[n].giave << " " << x[n].ghengoi << endl;
	}
	return dequy(x, n - 1);
}

VE tim(VE *x, int left, int right) {
	if (left == right) {
		return x[left];
	}
	int mid = (left + right) / 2;
	VE minL = tim(x, left, mid);
	VE minR = tim(x, mid + 1, right);
	if (minL.giave <= minR.giave)
		return minL;
	else
		return minR;
}


void xuat(int n) {
	for (int i = 1; i <= n; i++)
		cout << b[a[i]].sohieu << " ";
	cout << endl;
}

void Try(int i, int n, int k) {
	for (int j = a[i - 1] + 1; j <= n - k + i; j++) {
		a[i] = j;
		if (i == k) {
			xuat(k);
		} else {
			Try(i + 1, n, k);
		}
	}
}

int main() {
	int n = 6;
	b = new VE[n + 1];
	b[1] = VE("v1", 700000, 12);
	b[2] = VE("v2", 200000, 4);
	b[3] = VE("v3", 800000, 16);
	b[4] = VE("v4", 1500000, 22);
	b[5] = VE("v5", 100000, 2);
	b[6] = VE("v6", 2200000, 30);
	
	dequy(b, n);
	
	VE min = tim(b, 1, n);
	cout << min.sohieu << " " << min.giave << " " << min.ghengoi << endl;
	
	a = new int[n + 1];
	for (int i = 0; i <= n; i++)
		a[i] = 0;
	Try(1, n, 4);
}
