/**
 * @authors	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2017-12-25 15:43:14
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
set<char> s;

int main(void) {
	int i, j, n, m;
	char ch;
	cin >> n >> m >> ch;
	getchar();
	for (i = 0; i < n; i++)
		gets(arr[i]);
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
			if (arr[i][j] == ch) {
				if (i - 1 >= 0 && arr[i - 1][j] != ch && arr[i - 1][j] != '.')
					s.insert(arr[i - 1][j]);
				if (i + 1 < n && arr[i + 1][j] != ch && arr[i + 1][j] != '.')
					s.insert(arr[i + 1][j]);
				if ( j - 1 >= 0 && arr[i][j - 1] != ch && arr[i][ j - 1] != '.')
					s.insert(arr[i][j - 1]);
				if (j + 1 < m && arr[i][j + 1] != ch && arr[i][ j + 1] != '.')
					s.insert(arr[i][j + 1]);
			}
	cout << s.size() << endl;
	return 0;
}