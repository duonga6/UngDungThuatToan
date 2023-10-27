#include <iostream>
#include <string.h>
using namespace std;

struct kytu {
	char x[100];
};

int demtu(char *x) {
	int dem = 0;
	for (int i = 0; i < strlen(x); i++) {
		if (x[i] == ' ')
			dem++;
	}
	return dem + 1;
}

void sapxep(kytu *d, int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (demtu(d[i].x) < demtu(d[j].x)) {
				kytu temp = d[i];
				d[i] = d[j];
				d[j] = temp;
			}
		}
	}
}

int layxau(kytu *d, int n, int k, int *s) {
	sapxep(d, n);
	int i = 0;
	while (i < n && k > 0) {
		if (k >= demtu(d[i].x)) {
			k -= demtu(d[i].x);
			s[i] = 1;
		}
		i++;
	}
	return k;
}

int char_in_string(char s, char *t) {
	for (int i = 0; i < strlen(t); i++) 
		if (t[i] == s)
			return i;
	return -1;
}

int tim(char *p, char *t) {
	int dem = 0, v = strlen(p), i = v - 1;
	while (i < strlen(t)) {
		int x = v - 1;
		while(t[i] == p[x] && x > -1){
			i--;
			x--;
		}
		if (x < 0) {
			dem++;
			i = i + v + 1;
		} else {
			int k = char_in_string(t[i], p);
			if (k < 0)
				i = i + v;
			else
				i = i + v - k - 1;
		}
	}
	return dem;
}

int timds(kytu *d, int n, char *s, int *result) {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		if (tim(s, d[i].x) > 0) {
			sum++;
			result[i] = 1;
		}
	}
	return sum;
}

void ttz(char *s, int *z) {
	int n = strlen(s), left = 0, right = 0;
	for (int i = 1; i < n; i++) {
		if (i > right) {
			left = right = i;
			while(right < n && s[right - left] == s[right])
				right++;
			z[i] = right - left;
			right--;
		} else if (z[i - left] < right - i + 1) {
			z[i] = z[i - left];
		} else {
			left = i;
			while(right < n && s[right-left] == s[right])
				right++;
			z[i] = right - left;
			right--;
		}
	}
}

int timkiemz(kytu *d, int n, int *result) {
	int dem = 0;
	char *s;
	for (int i = 1; i < n; i++) {
		char s[strlen(d[0].x) + strlen(d[i].x)];
		strcpy(s, d[0].x);
		strcat(s, "$");
		strcat(s, d[i].x);
		
		int z[strlen(s)] = {-1};
		
		ttz(s, z);
		
		for (int j = strlen(d[0].x); j < strlen(s); j++) {
			if (z[j] == strlen(d[0].x)) {
				dem++;
				result[i] = 1;
				break;
			}
		}
		
	}
	return dem;
}

int main() {
	int n = 5;
	kytu d[n] = {
	{"child"},
	{"i from vn"},
	{"child funny"},
	{"vn is very beautiful"},
	{"i love child"},
	};
	
//	int k = 5;
//	int s[n] = {0};
//	int z = layxau(d, n, k, s);
//	if (z == 0) {
//		for (int i = 0; i < n; i++) {
//			if (s[i] == 1) {
//				int j = 0;
//				while (d[i].x[j] != '\0') {
//					cout << d[i].x[j];
//					j++;
//				}
//				cout << endl;
//			}
//		}
//	}
//	
//	cout << endl;
	
//	int result[n] = {0};
//	char tukhoa[] = "child";
//	int sum = timds(d, n, tukhoa, result);
//	
//	if (sum == 0) {
//		cout << "Khong co ket qua" << endl;
//	} else {
//		for (int i = 0; i < n; i++) {
//			if (result[i] == 1) {
//				int j = 0;
//				while (d[i].x[j] != '\0') {
//					cout << d[i].x[j];
//					j++;
//				}
//				cout << endl;
//			}
//		}
//	}
//	
//	cout << endl;
	
	int result2[n] = {0};
	int dem = timkiemz(d, n, result2);
	
	if (dem == 0) {
		cout << "Khong co ket qua " << endl;
	} else {
		for (int i = 1; i < n; i++) {
			if (result2[i] == 1) {
				int j = 0;
				while (d[i].x[j] != '\0') {
					cout << d[i].x[j];
					j++;
				}
				cout << endl;
			}
		}
	}
	
	
	
	
	return 0;
}
