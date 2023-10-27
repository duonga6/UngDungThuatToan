#include <iostream>
using namespace std;

long F(int n) {
	if (n == 1 || n == 2)
		return 1;
	else
		return F(n - 1) + F(n - 2);
}

int main() {
	cout << F(6);
	return 0;
}
