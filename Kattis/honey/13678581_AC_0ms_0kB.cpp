/**
 * @author	Moe_Sakiya    	sakiya@tun.moe
 * @date	2018-04-25 14:34:47
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

int t, n;

//对于点x,y来说在第n步的最大路径数
int dparr[30][30][15];

void calDP(void) {
	int i, j, k;
	//init
	dparr[15][15][0] = 1;
	for(k = 1; k <= 14; k++)
		for(i = 1; i <= 29; i++)
			for(j = 1; j <= 29; j++)
				dparr[i][j][k] = dparr[i][j - 1][k - 1] + dparr[i - 1][j - 1][k - 1] + dparr[i-1][j][k - 1] + dparr[i][j + 1][k - 1] + dparr[i + 1][j + 1][k - 1] + dparr[i + 1][j][k - 1];
	return;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	calDP();
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &n);
		printf("%d\n", dparr[15][15][n]);
	}
	return 0;
}