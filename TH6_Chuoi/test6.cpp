#include <iostream>
#include <string.h>
using namespace std;

int char_in_string(char s, char *p) {
	for (int i = 0; i < strlen(p); i++)
		if (p[i] == s)
			return i;
	return -1;
}

int boyer(char *P, char *T) {
	int dem = 0, v = strlen(P), i = v - 1;
	while (i < strlen(T)) {
		int x = v - 1;
		while (T[i] == P[x] && x > -1) {
			i--;
			x--;
		}
		if (x < 0) {
			dem++;
			i = i + v + 1;
		} else {
			int k = char_in_string(T[i], P);
			if (k < 0) i = i + v;
			else i = i + v - k - 1;
		}
	}
	return dem;
}

int main() {
	
	return 0;
}
