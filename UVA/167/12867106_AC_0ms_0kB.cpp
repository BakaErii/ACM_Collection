/**
 * @author	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2018-01-19 19:52:15
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

int sol[92][8];
int arr[8];
int board[8][8];
int ptr = 0;

bool check (int arr[ ], int n) {
	int i;
	for (i = 0; i < n; i++)
	{
		if ((abs(arr[i] - arr[n]) == n - i) || (arr[i] == arr[n]))
			return false;
	}
	return true;
}

void dfs(int arr[], int n) {
	int i, j;
	for (i = 0; i < 8; i++) {
		arr[n] = i;
		if (check(arr, n) == 1) {
			if (n == 7) {
				for (j = 0; j < 8; j++)
					sol[ptr][j] = arr[j];
				ptr++;
			} else
				dfs(arr, n + 1);
		}
	}
	return;
}

int main(void) {
	int i, j, n, maxans, tmp;
	//初始化
	for (i = 0; i < 8; i++)
		arr[i] = 0;
	dfs(arr, 0);
	cin >> n;
	while (n--) {
		maxans = 0;
		for (i = 0; i < 8; i++)
			for (j = 0; j < 8; j++)
				scanf("%d", &board[i][j]);
		//计算
		for (i = 0; i < 92; i++) {
			tmp = 0;
			for (j = 0; j < 8; j++)
				tmp += board[j][sol[i][j]];
			maxans = max(tmp, maxans);
		}
		printf("%5d\n",maxans );
	}
	return 0;
}