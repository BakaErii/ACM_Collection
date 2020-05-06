/**
 * @author	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2018-02-02 00:43:29
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

char arr[100][101];

int main(void) {
	int i, j, n, m;
	cin >> n >> m;
	getchar();
	for (i = 0; i < n; i++)
		gets(arr[i]);
	for (i = 0; i < n; i++) {
		for (j = 1; j < m; j++)
			if (arr[i][j] != arr[i][0])
				break;
		if (j != m)
			break;
		else {
			if (i > 0 && arr[i][0] == arr[i - 1][0])
				break;
		}
	}
	if (i == n && j == m)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	return 0;
}