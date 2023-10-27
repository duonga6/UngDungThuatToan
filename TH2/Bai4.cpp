#include <iostream>
using namespace std;

long F(int n) {
	int f1 = 1, f2 = 1, fn;
	for (int i = 3; i <= n; i++) {
		fn = f1 + f2;
		f1 = f2;
		f2 = fn;
	}
	return fn;
}

int main() {
	
	cout << F(6);
	return 0;
}
