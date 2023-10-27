#include <iostream>
using namespace std;

struct hang{
	float kl;
	float kt;
};

void swap(hang &a, hang &b) {
	hang temp = a;
	a = b;
	b = temp;
}

void sapxep(hang *x, int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (x[i].kl/x[i].kt < x[j].kl/x[j].kt) {
				swap(x[i], x[j]);
			}
		}
	}
}

void demxe(hang *x, int n, float p, int &s) {
	int i = 0;
	sapxep(x, n);
	while (i < n && p > 0) {
		if (p >= x[i].kt) {
			p -= x[i].kt;
			s++;
		}
		i++;
	}
}

int main() {
	
	hang x[5] = {
	{6.2,4.6},
	{3.1,5.3},
	{4.7,2.9},
	{5.9,6.7},
	{4.3,2.1}
	};
	
	
	float p = 10.2;
	int sum = 0;
	demxe(x, 5, p, sum);
	
	for (int i = 0; i < 5; i++) {
		cout << x[i].kt << " " << x[i].kl << " " << x[i].kl / x[i].kt <<endl;
	}
	
	cout << endl;
	
	if (sum == 0) {
		cout << "Khong co xe nao";
	} else {
		for (int i = 0; i < sum; i++) {
			cout << x[i].kt << " " << x[i].kl << endl;
		}
	}
	
	
	return 0;
}
