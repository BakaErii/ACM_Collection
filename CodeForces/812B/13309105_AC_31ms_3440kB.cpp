/**
 * @author	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2018-04-03 19:03:00
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

int n, m;
char str[15][105];
int dp[15][2];
int leftLight[15], rightLight[15];
bool isExistLightbyFloor[15];
bool isExistLight;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int i, j;
	scanf("%d %d", &n, &m);
	getchar();
	for (i = n - 1; i >= 0; i--)
		gets(str[i]);
	//init
	for (i = 0; i < n; i++)
		for (j = 0; j < m + 2; j++)
			if (str[i][j] == '1') {
				if (leftLight[i] == 0)
					leftLight[i] = j;
				rightLight[i] = j;
				isExistLightbyFloor[i] = true;
				isExistLight = true;
			}
	//Special Judge
	if (isExistLight == false) {
		printf("0\n");
		return 0;
	}
	while (isExistLightbyFloor[n - 1] == false && n > 0)
		n--;
	//DP
	//FisrtFloor
	if (isExistLightbyFloor[0] == false) {
		dp[0][0] = 1;
		dp[0][1] = m + 2;
	} else {
		dp[0][0] = rightLight[0] * 2 + 1;
		dp[0][1] = m + 2;
	}
	//MiddleFloor
	for (i = 1; i < n - 1; i++) {
		if (isExistLightbyFloor[i] == false) {
			dp[i][0] = dp[i - 1][0] + 1;
			dp[i][1] = dp[i - 1][1] + 1;
			continue;
		}
		//goLeft
		dp[i][0] = min(dp[i - 1][0] + rightLight[i] * 2 + 1, dp[i - 1][1] + m + 2);
		//goRight
		dp[i][1] = min(dp[i - 1][0] + m + 2, dp[i - 1][1] + (m - leftLight[i] + 1) * 2 + 1);
	}
	//LastFloor
	if (n != 1)
		printf("%d\n", min(dp[i - 1][0] + rightLight[n - 1], dp[i - 1][1] + (m - leftLight[n - 1] + 1)));
	else
		printf("%d\n", rightLight[0]);
	return 0;
}