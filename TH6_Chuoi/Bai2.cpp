#include <iostream>
#include <string.h>
using namespace std;

void tim(char *p, char *t, int &s) {
	int m = strlen(p);
	int n = strlen(t) - m;
	for (int i = 0; i <= n; i++) {
		int j = 0;
		while (j < m && t[i+j] == p[j]) {
			j++;
		}
		if (j == m)
			s++;
	}
}

void thaythe(char *p, char *t, char *x, char *l) {
	int m = strlen(p);
	int k = 0;
	for (int i = 0; i < strlen(t); i++) {
		
		if (i <= strlen(t) - m) {
			int j = 0;
			while(j < m && t[i+j] == p[j]) {
				j++;
			}
		
			if (j == m) {
				int z = 0;
				while (l[z] != '\0') {
					x[k] = l[z];
					k++;
					z++;
				}
				i += strlen(p);
			}
		}
		
		x[k] = t[i];
		k++;
	}
	x[k + 1] = '\0';
}

int main() {
	char s[] = "I love child. child good";
	char p[] = "child";
	char l[] = "children";
	int sum = 0;
	tim(p, s, sum);
	
	if (sum == 0) {
		cout << "Khong co ket qua" << endl;
	} else {
		cout << sum << endl;
		char kq[100];
		thaythe(p, s, kq, l);
		int i = 0;
		while (kq[i] != '\0') {
			cout << kq[i];
			i++;
		}
	}
	
	return 0;
}
