/**
 * @author	Moe_Sakiya	sakiya@tun.moe
 * @date	2019-04-27 14:49:31
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

int q, t, n;
double arr[maxN][maxN];

void Floyd() {
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			for(int k = 1; k <= n; k++)
				if(i != k && i != j && j != k)
					if(arr[j][k] < arr[j][i]*arr[i][k])
						arr[j][k] = arr[j][i] * arr[i][k];
	return;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int u, v;
	while(~scanf("%d", &n)) {
	for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
				scanf("%lf", &arr[i][j]);
		Floyd();
		scanf("%d", &q);
		for(int i = 0; i < q; i++) {
			scanf("%d %d", &u, &v);
			if(arr[u][v] != 0)
				printf("%.3f\n", arr[u][v]);
			else
				printf("What a pity!\n");
		}
	}
	return 0;
}