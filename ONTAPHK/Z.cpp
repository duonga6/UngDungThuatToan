#include <iostream>
#include <string.h>
using namespace std;

void Z(char *S, int *z) {
	int n = strlen(S), left = 0, right = 0;
	for (int i = 1; i < n; i++) {
		if (i > right) {
			left = right = i;
			while (right < n && S[right - left] == S[right])
				right++;
			z[i] = right - left;
			right--;
		} else if (z[i - left] < right - i + 1) {
			z[i] = z[i - left];
		} else {
			left = i;
			while (right < n && S[right - left] == S[right])
				right++;
			z[i] = right - left;
			right--;
		}
	}
}

int main() {
	
	char T[] = "child@I love child, child good\0";
	int z[strlen(T)] = {-1};
	
	Z(T, z);
	for (int i = 0; i < strlen(T); i++)
		cout << z[i];	
	return 0;
}
