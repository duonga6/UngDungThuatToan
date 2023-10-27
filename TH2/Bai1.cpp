#include <iostream>
using namespace std;

int ucln(int a, int b) {
	if (a % b == 0)
		return b;
	else
		return ucln(b, a % b);
}

int main() {
	cout << ucln(9, 15);
	return 0;
}
