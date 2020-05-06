/**
 * @authors	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2017-12-22 18:34:24
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

int arr[100][100];

int main(void) {
	int c, n, i, j;
	scanf("%d", &c);
	while (c--) {
		scanf("%d", &n);
		for (i = 0; i < n; i++)
			for (j = 0; j < i + 1; j++)
				scanf("%d", &arr[i][j]);
		for (i = n - 1; i >= 1; i--)
			for (j = 0; j < i; j++)
				arr[i - 1][j] += max(arr[i][j], arr[i][j + 1]);
		printf("%d\n",arr[0][0] );
	}
	return 0;
}