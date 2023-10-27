#include <iostream>
#include <string.h>
using namespace std;

void tt_Z(char *S, int *z) {
	int n = strlen(S), left = 0, right = 0;
	for (int i = 1; i < n; i++) {
		if (i > right) {
			left = right = i;
			while(right < n && S[right-left] == S[right]) {
				right++;
			}
			z[i] = right - left;
			right--;
		} else if(z[i - left] < right - i + 1){
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
	char T[] = "i love child";
	char P[] = "child";
	char S[] = "";
	strcpy(S,P);
	strcat(S, "$");
	strcat(S, T);
//	char S[] = "Viet$Ban Viet o Viet Nam";
//	cout << strlen(S) << endl;
	int z[strlen(S)] = {-1};
	
	int i = 0;
	while (S[i] != '\0') {
		cout << S[i];
		i++;
	}
	
	cout << endl;
	
	tt_Z(S, z);
	for (int i = 0; i < strlen(S); i++) {
		cout << z[i];
	}
	
	return 0;
}
