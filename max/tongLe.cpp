#include <iostream>
using namespace std;

int tongLe(int x[], int l, int r, int &sl) {
	if (l == r && x[l] % 2 != 0){
		sl++;
		return x[l];
	}
	else if (l == r && x[l] % 2 == 0)
		return 0;
	else {
		int mid = (l + r) / 2;
		return tongLe(x, l, mid, sl) + tongLe(x, mid + 1, r, sl);
	}
}

int main() {
	int x[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int sl = 0;
	int tong = tongLe(x, 0, 9, sl);
	if (sl == 0)
		cout << "khong co so le";
	else {
		cout << "Tong cac so le: " << tong << endl;
		cout << "TBC cac so le: " << 1.0*tong/sl << endl;
	}
}
