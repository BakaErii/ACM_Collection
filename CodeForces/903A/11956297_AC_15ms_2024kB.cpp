/**
 * @authors	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2017-12-12 22:52:00
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

int main(void) {
	int i, j, n, t;
	cin >> t;
	while (t--) {
		cin >> n;
		for (i = 0; i < 15; i++)
			for (j = 0; j < 35; j++) {
				if (i * 7 + j * 3 > n)
					break;
				if (i * 7 + j * 3 == n) {
					cout << "YES" << endl;
					goto END;
				}
			}
		cout << "NO" << endl;
END:;
	}
	return 0;
}