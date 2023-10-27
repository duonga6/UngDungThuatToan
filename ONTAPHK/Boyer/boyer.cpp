#include <iostream>
#include <string.h>
using namespace std;

int char_in_string(char s, string t) {
	for (int i = 0; i < t.length(); i++)
		if (t[i] == s)
			return i;
	return -1;
}

int boyer(string P, string Q) {
	int dem = 0, v = Q.length(), i = v - 1;
	while (i < P.length()) {
		int x = v - 1, j = i;
		while (P[j] == Q[x] && x > -1) {
			x--;
			j--;
		}
		if (x < 0) {
			dem++;
			i = i + v;
		} else {
			int k = char_in_string(P[j], Q);
			if (k < 0) i = i + v;
			else i = i + v - k - 1;
		}
	}
	return dem;
}

int main() {
	string P = "Hello world Hello world";
	string Q = "Hello";
	
	cout << boyer(P, Q);
	
	return 0;
}
