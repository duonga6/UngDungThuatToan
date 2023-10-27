#include <iostream>
using namespace std;


struct XeTai {
	string bienSo;
	float taiTrong;
};

XeTai timMax(XeTai x[], int l, int r) {
	if (l == r)
		return x[l];
	else {
		int mid = (l + r) / 2;
		XeTai maxLeft = timMax(x, l, mid);
		XeTai maxRight = timMax(x, mid + 1, r);
		if (maxLeft.taiTrong > maxRight.taiTrong)
			return maxLeft;
		else
			return maxRight;
	}
}

XeTai *Tron(XeTai *left, XeTai *right, int nLeft, int nRight) {
	XeTai *kq = new XeTai[nLeft + nRight];
	int i = 0, j = 0, k = 0;
	while (i < nLeft && j < nRight) {
		if (left[i].taiTrong <= right[j].taiTrong)
			kq[k++] = left[i++];
		else
			kq[k++] = right[j++];
	}
	while(i < nLeft)
		kq[k++] = left[i++];
	while (j < nRight)
		kq[k++] = right[j++];
	return kq;
}

XeTai *Sort(XeTai *a, int n) {
	if (n == 1)
		return a;
	int mid = n / 2;
	XeTai *left = Sort(a, mid);
	XeTai *right = Sort(a + mid, n - mid);
	
	XeTai *kq = Tron(left, right,mid, n -mid);
	return kq;
}

void Chen(XeTai *x, XeTai a, int &n) {
	int i = n - 1;
	while (i >= 0 && x[i].taiTrong > a.taiTrong) {
		x[i + 1] = x[i];
		i--;
	}
	
	x[i + 1] = a;
	n++;
}

void display(XeTai *x, int n) {
	for (int i = 0; i < n; i++)
		cout << "Bien so: " << x[i].bienSo << " Trong luong: " << x[i].taiTrong << endl;
}

int main() {
	int n = 7;
	XeTai *x = new XeTai[n];
	x[0].bienSo = "BS01"; x[0].taiTrong = 1.8;
	x[1].bienSo = "BS02"; x[1].taiTrong = 6.1;
	x[2].bienSo = "BS03"; x[2].taiTrong = 4.9;
	x[3].bienSo = "BS04"; x[3].taiTrong = 9.2;
	x[4].bienSo = "BS05"; x[4].taiTrong = 1.4;
	x[5].bienSo = "BS06"; x[5].taiTrong = 3.7;
	x[6].bienSo = "BS07"; x[6].taiTrong = 2.1;
	
	XeTai max = timMax(x, 0, 6);
	cout << "Xe co trong tai lon nhat: " << max.bienSo << " trong tai: " << max.taiTrong << endl;
	
		
	XeTai *z;
	z = Sort(x, 7);
	display(z, n);
	
	XeTai c;
	c.bienSo = "BS08";
	c.taiTrong = 1.2;
	
	Chen(z, c, n);
	display(z, n);
	cout << sizeof(z);
	return 0;
}
