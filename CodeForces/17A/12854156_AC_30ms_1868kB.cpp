/**
 * @author	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2018-02-05 14:49:36
 *
 */

#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <stack>
#include <queue>

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>

using namespace std;

int table[1001];
int prime[1001];

int main(void) {
	int i, j, n, k, ptr, ans;
	bool flag;
	//init
	ans = 0;
	ptr = 0;
	for (i = 1; i < 1000; i += 2) {
		flag = true;
		for (j = 2; j < i; j++)
			if (i % j == 0) {
				flag = false;
				break;
			}
		if (flag == true) {
			table[i] = 1;
			prime[ptr++] = i;
		}
	}
	cin >> n >> k;
	for (i = 2; i <= n; i++)
		if (table[i] == 1) {
			for (j = 0; j < ptr - 1; j++)
				if (prime[j] + prime[j + 1] + 1 == i)
					ans++;
		}
	if (ans >= k)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	return 0;
}