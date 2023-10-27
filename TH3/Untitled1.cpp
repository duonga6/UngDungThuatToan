#include <iostream>
#include <string.h>
using namespace std;

	struct HocSinh {
		string fname;
		string lname;
		int born;
		string add;
		
		HocSinh(){}
		
		HocSinh(string fname, string lname, int born, string add) {
			this->fname = fname;
			this->lname = lname;
			this->born = born;
			this->add = add;
		}
		
		void xuat() {
			cout << "Ho dem: " <<this->fname << endl;
			cout << "Ten: " <<this->lname << endl;
			cout << "Nam sinh: " <<this->born << endl;
			cout << "Dia chi: " <<this->add << endl;
		}
	};
	
	
	int n = 6;
	HocSinh *x = new HocSinh[n];
	HocSinh *b = new HocSinh[n];
	string ten;
	
void MergeSort(HocSinh *a, int l, int r) {
	if (r > l) {
		int m = (l + r) / 2;
		MergeSort(a, l, m);
		MergeSort(a, m+1, r);
		
		for (int i = m; i >= l; i--) b[i] = a[i];
		for (int j = m + 1; j <= r; j++) b[r+m+1-j] = a[j];
		
		int i = l, j =r;
		for (int k = l; k <= r; k++)
			if (b[i].fname[0] < b[j].fname[0]) {
				a[k] = b[i];
				i++;
			} else {
				a[k] = b[j];
				j--;
			}
	}
}

HocSinh TimTen(HocSinh *x, int l, int r) {
	if (l == r && x[l].fname == ten)
		return x[l];
	if (l == r && x[l].fname != ten)
		return HocSinh("", "", 0, "");
	int mid = (l + r) / 2;
	
	HocSinh left = TimTen(x, l, mid);
	HocSinh right = TimTen(x, mid + 1, r);
	
	if (left.fname == ten)
		return left;
	else
		return right;
}


int main() {
	x[0] = HocSinh("duong", "pham", 2002, "tn");
	x[1] = HocSinh("khanh", "dang", 2002, "bg");
	x[2] = HocSinh("truong", "pham", 2002, "bn");
	x[3] = HocSinh("long", "nguyen", 2002, "bn");
	x[4] = HocSinh("duc", "pham", 2002, "hn");
	x[5] = HocSinh("tu", "do", 2002, "hy");
	
	MergeSort(x, 0, 5);
	for (int i =0; i < n; i++)
		cout << "Ten: " << x[i].fname << "\t\tHo dem: " << x[i].lname << "\t\tNam sinh: " << x[i].born << "\t\tDia chi: " << x[i].add << endl;

	cout << "Nhap ten: "; cin >> ten;
	HocSinh z = TimTen(x, 0, 5);
	cout << "Ten: " << z.fname << "\t\tHo dem: " << z.lname << "\t\tNam sinh: " << z.born << "\t\tDia chi: " << z.add << endl;
	return 0;
}
