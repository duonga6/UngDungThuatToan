#include <iostream>
using namespace std;

int max(int x[], int l, int r) {
	if (l == r)
		return x[l];
	else {
		int mid = (l + r) / 2;
		int maxLeft = max(x, l, mid);
		int maxRight = max(x, mid + 1, r);
		if (maxLeft > maxRight)
			return maxLeft;
		else
			return maxRight;	
	}
}

int max2(int x[], int l, int r) {
	if (l == r) return x[l];
	return max(x, l, (l + r) / 2) > max(x, (l + r) / 2 + 1, r) ? max(x, l, (l + r) / 2) : max(x, (l + r) / 2 + 1, r);
}

int main() {
	int x[8] = {1,3,4,9,6,7,5,4};
	cout << max(x, 0, 7) << endl;
	cout << max2(x, 0, 7) << endl;
	return 0;
}
