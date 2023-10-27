#include <iostream>
using namespace std;

int tong_chu_so(int n) {
	if (n > 0)
		return n%10 + tong_chu_so(n / 10);
	else
		return 0;	
}

int main() {
	int n;
	cout << "n = ";
	cin >> n;	
	
	cout << "Tong cac chu so cua n: " << tong_chu_so(n);
	
	return 0;
}
