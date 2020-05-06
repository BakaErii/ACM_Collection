/**
 * @author  Moe_Sakiya	sakiya@tun.moe
 * @date    2018-11-24 14:03:49
 *
 */

#include <bits/stdc++.h>

using namespace std;

int arr[105];
string str;

int main(void) {
	int n, ptr, maxGCD;
	cin >> n;
	getchar();
	while (n--) {
		ptr = 0;
		maxGCD = 1;
		getline(cin, str);
		istringstream in(str);
		while (in >> arr[ptr++]);
		for (int i = 0; i < ptr - 1; i++)
			for (int j = i + 1; j < ptr - 1; j++)
				maxGCD = max(maxGCD, __gcd(arr[i], arr[j]));
		cout << maxGCD << endl;
	}
	return 0;
}