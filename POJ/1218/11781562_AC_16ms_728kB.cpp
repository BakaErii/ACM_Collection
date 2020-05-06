/**
 * @authors	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2017-11-30 17:57:15
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

int cell[101];

int change(int a);

int main(void) {
	int n, m, i, j, tmax;
	cin >> n;
	while (n--) {
		tmax = 0;
		cin >> m;
		memset(cell, 0, sizeof(cell));
		for (i = 1; i <= m; i++) {
			for (j = 1; j <= m; j++)
				if (j % i == 0)
					cell[j] = change(cell[j]);
		}
		for (i = 1; i <= m; i++)
			if (cell[i] == 1)
				tmax++;
		cout << tmax << endl;
	}
	return 0;
}

int change(int a) {
	return a == 0 ? 1 : 0;
}