#include <iostream>
#include <string.h>
using namespace std;

bool check(char *s) {
	int i = 0;
	int j = strlen(s) - 1;
	while(i < j) {
		if (s[i] != s[j])
			return false;
		i++;
		j--;
	}
	return true;
}

void chuoicon(char *s, char *kq, int p) {
	int i = p, j = p;
	while (i >= 0 && j <= strlen(s) - 1) {
		if (s[i - 1] != s[j + 1]) {
			break;
		}
		i--;
		j++;
	}
	int k = 0;
	for (int z = i; z <= j; z++) {
		kq[k] = s[z];
		k++;
	}
	kq[j + 1] = '\0';
}

int main() {
	char s[10] = {'m', 'o', 'm', 'o', 'm', 'm', 'o', 'm', '\0'};
	
	if (check(s)) {
		cout << "La chuoi doi xung" << endl;
	} else {
		cout << "Khong phai chuoi doi xung" << endl;
		char kq[100];
		chuoicon(s, kq, 2);
		int i = 0;
		while(kq[i] != '\0') {
			cout << kq[i];
			i++;
		}
	}
	
	return 0;
}
