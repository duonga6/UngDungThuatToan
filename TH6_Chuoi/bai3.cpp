#include <iostream>
#include <string.h>
using namespace std;

int char_in_string(char x, char *y) {
	for (int i = 0; i < strlen(y); i++)
		if (y[i] == x)
			return i;
	return -1;
}

int boyer(char *T, char *P) {
	int dem = 0, v = strlen(P), i = v - 1;
	while(i < strlen(T)) {
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
			if (k < 0) {
				i = i + v;
			} else {
				i = i + v - k - 1;
			}
		}
	}
	return dem;
}

int main() {
	char T[] = "child";
	char P[] = "child";
	
	int dem = boyer(T, P);
	
	cout << dem << endl;
	return 0;
}
