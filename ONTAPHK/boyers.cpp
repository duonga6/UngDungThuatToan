#include <iostream>
#include <string.h>
using namespace std;

int char_in_string(char s, char *t) {
	for (int i = strlen(t) - 1; i >= 0; i--)
		if (s == t[i])
			return i;
	return -1;
}

int boyer(char *P, char *Q) {
	int dem = 0, v = strlen(Q), i = v - 1;
	while (i < strlen(P)) {
		int x = v - 1, j = i;
		while (P[j] == Q[x] && x > -1) {
			x--;
			j--;
		}
		if (x < 0) {
			dem++;
			i += v;
		} else {
			int k = char_in_string(P[j], Q);
			if (k < 0) i += v;
			else i = i + v - k - 1;
		}
	}
	return dem;
}

int main() {
	char P[] = "Hello world. Hello world\0";
	char Q[] = "Hello\0";
	
	cout << boyer(P, Q);
	
	return 0;
}
