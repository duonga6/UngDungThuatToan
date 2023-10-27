#include <iostream>
using namespace std;

int ucln(int a, int b) {
	int tg;
	while (a % b != 0) {
		tg = a;
		a = b;
		b = tg % a;
	}
	return b;
}

int main() {
	cout << ucln(9, 15);
	return 0;	
}
