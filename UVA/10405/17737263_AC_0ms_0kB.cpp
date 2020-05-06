/**
 * @author  Moe_Sakiya	sakiya@tun.moe
 * @date    2019-01-16 00:33:43
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

const int maxN = 1005;

int dpArr[maxN][maxN];
string strA, strB;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	while (getline(cin, strA)) {
		getline(cin, strB);
		// INIT
		n = strA.length();
		m = strB.length();
		for (int i = 0; i <= n; i++)
			dpArr[0][i] = 0;
		for (int i = 0; i <= m; i++)
			dpArr[i][0] = 0;
		// CalDp
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				if (strA[i - 1] == strB[j - 1])
					dpArr[i][j] = dpArr[i - 1][j - 1] + 1;
				else
					dpArr[i][j] = max(dpArr[i - 1][j], dpArr[i][j - 1]);
		printf("%d\n", dpArr[n][m]);
	}
	return 0;
}