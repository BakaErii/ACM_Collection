/**
 * @author	Moe_Sakiya	sakiya@tun.moe
 * @date	2019-05-11 09:34:41
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

int n, m, k, maxAns;
int arr[105];
int brr[105];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int tmp;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < m; i++) {
		scanf("%d", &tmp);
		arr[tmp]++;
	}
	k = m / n;
	int lft;
	for(int i = 1; i <= k; i++) {
		// Init
		lft = n;
		for(int j = 1; j <= 100; j++)
			brr[j] = arr[j];
		for(int x = 1; x <= 100; x++)
			while(brr[x] >= i) {
				brr[x] -= i;
				lft--;
			}
		if(lft <= 0)
			maxAns = max(maxAns, i);
	}
	printf("%d\n",maxAns );
	return 0;
}