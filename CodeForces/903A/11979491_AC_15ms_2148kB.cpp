/**
 * @authors	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2017-12-15 18:21:52
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
	int n, i, j, x;
	cin >> n;
	while (n--) {
		cin >> x;
		for (i = 0; i < 15; i++)
			for (j = 0; j < 34; j++) {
				if (i * 7 + j * 3 == x) {
					cout << "YES" << endl;
					goto END;
				}
				if (i * j > x)
					break;
			}
		cout << "NO" << endl;
END:;
	}
	return 0;
}