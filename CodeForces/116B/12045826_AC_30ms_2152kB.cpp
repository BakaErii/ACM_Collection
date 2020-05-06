/**
 * @authors	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2017-12-22 18:22:12
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

char arr[10][11];

int main(void) {
	int n, m, i, j, ans = 0;
	cin >> n >> m;
	getchar();
	for (i = 0; i < n; i++)
		gets(arr[i]);
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
			if (arr[i][j] == 'P')
				if (i + 1 < n && arr[i + 1][j] == 'W') {
					arr[i + 1][j] = '.';
					arr[i][j] = '.';
					ans++;
				} else if (i - 1 >= 0 && arr[i - 1][j] == 'W') {
					arr[i - 1][j] = '.';
					arr[i][j] = '.';
					ans++;
				} else if (j + 1 < m && arr[i][j + 1] == 'W') {
					arr[i][j + 1] = '.';
					arr[i][j] = '.';
					ans++;
				} else if (j - 1 >= 0 && arr[i][j - 1] == 'W') {
					arr[i][j - 1] = '.';
					arr[i][j] = '.';
					ans++;
				}
	cout << ans << endl;
	return 0;
}