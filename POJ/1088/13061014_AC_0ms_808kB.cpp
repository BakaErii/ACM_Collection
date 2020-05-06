/**
 * @author	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2018-03-16 18:55:53
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

int dparr[101][101];
int arr[101][101];
int r, c;

int dp(int x, int y) {
	int currAns = 0;
	if (dparr[x][y] > 0)
		return dparr[x][y];
	if (x + 1 < r && arr[x + 1][y] < arr[x][y])
		currAns = max(currAns, dp(x + 1, y));
	if (y + 1 < c && arr[x][y + 1] < arr[x][y])
		currAns = max(currAns, dp(x, y + 1));
	if (x - 1 >= 0 && arr[x - 1][y] < arr[x][y])
		currAns = max(currAns, dp(x - 1, y));
	if (y - 1 >= 0 && arr[x][y - 1] < arr[x][y])
		currAns = max(currAns, dp(x, y - 1));
	dparr[x][y] = currAns + 1;
	return dparr[x][y];
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int i, j, ans = 1;
	scanf("%d %d", &r, &c);
	for (i = 0; i < r; i++)
		for (j = 0; j < c; j++)
			scanf("%d", &arr[i][j]);
	for (i = 0; i < r; i++)
		for (j = 0; j < c; j++) {
			dparr[i][j] = dp(i, j);
			ans = max(ans, dparr[i][j]);
		}
	printf("%d\n",ans );
	return 0;
}