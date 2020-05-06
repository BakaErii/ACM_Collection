/**
 * @author	Moe_Sakiya    	sakiya@tun.moe
 * @date	2018-04-20 12:54:31
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

int r, c, ans;
int dparr[101][101], arr[101][101];

int calDP(int x, int y) {
	int currStatus = 0;
	if(dparr[x][y] > 0)
		return dparr[x][y];
	//update
	if(x + 1 < r && arr[x][y] > arr[x + 1][y])
		currStatus = max(currStatus, calDP(x + 1, y));
	if(y + 1 < c && arr[x][y] > arr[x][y + 1])
		currStatus = max(currStatus, calDP(x, y + 1));
	if(x - 1 >= 0 && arr[x][y] > arr[x - 1][y])
		currStatus = max(currStatus, calDP(x - 1, y));
	if(y - 1 >= 0 && arr[x][y] > arr[x][y - 1])
		currStatus = max(currStatus, calDP(x, y - 1));
	dparr[x][y] = currStatus + 1;
	ans = max(ans, dparr[x][y]);
	return dparr[x][y];
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	scanf("%d %d", &r, &c);
	for(int i = 0; i < r; i++)
		for(int j = 0; j < c; j++) {
			scanf("%d", &arr[i][j]);
			dparr[i][j] = 0;
		}
	for(int i = 0; i < r; i++)
		for(int j = 0; j < c; j++)
			calDP(i, j);
	printf("%d\n", ans );
	return 0;
}