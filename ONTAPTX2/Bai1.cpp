#include <iostream>
using namespace std;

struct quat{
	string hsx;
	string mau;
	float gia;
};

void sapxep(quat *d, int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (d[i].gia > d[j].gia) {
				quat temp = d[i];
				d[i] = d[j];
				d[j] = temp;
			}
		}
	}
}

void muaquat(quat *x, int n, float p, int &s) {
	sapxep(x, n);
	int i = 0;
	while(i < n && p >= x[i].gia) {
		p -= x[i].gia;
		i++;
		s++;
	}
}

int main() {
	int n = 6;
	quat d[n] = {
	{"USA", "den", 320000},
	{"VN", "xanh", 245000},
	{"DC91", "tim", 199000},
	{"CR7", "vang", 420000},
	{"Q10", "hong", 399000},
	{"HNVV", "do", 299000},
	};
	
	int s = 0;
	float p = 1100000;
	
	muaquat(d, n, p, s);
	
	if (s == 0) {
		cout << "Khong mua duoc quat nao" << endl;
	} else {
		for (int i = 0; i < s; i++) {
			cout << d[i].hsx << " " << d[i].gia << endl;
		}
	}
	
	return 0;
}
