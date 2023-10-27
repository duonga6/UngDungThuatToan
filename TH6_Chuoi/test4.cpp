#include <iostream>
#include <string.h>
using namespace std;

void tt_z(char *s, int *z) {
	int n = strlen(s), left = 0, right = 0;
	for (int i = 1; i < n; i++) {
		if (i > right) {
			left = right = i;
			while (right < n && s[right - left] == s[right])
				right++;
			z[i] = right - left;
			right--;
		} else if (z[i - left] < right - i + 1) {
			z[i] = z[i - left];
		} else {
			left = i;
			while (right < n && s[right - left] == s[right])
				right++;
			z[i] = right - left;
			right--;
		}
	}
}

int main() {
	
	char s[] = "child$I love child. child very stupid";
	int z[strlen(s)] = {-1};
	
	tt_z(s, z);
	
	for (int i = 0; i < strlen(s); i++) {
		cout << z[i];
	}
	
	return 0;
}
