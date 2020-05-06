/**
 * @author  Moe_Sakiya	sakiya@tun.moe
 * @date    2019-08-02 15:48:02
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
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, ans = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		for (int j = i; j <= n; j++)
			if ((i ^ j) <= n && (i ^ j) >= j && (i + j) > (i ^ j))
				ans++;
	printf("%d\n", ans );
	return 0;
}