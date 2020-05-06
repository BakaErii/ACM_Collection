/**
 * @author  Moe_Sakiya	sakiya@tun.moe
 * @date    2019-08-07 15:09:35
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

const int maxN = 105;
int arr[maxN];
int n, mxans = 0x3f3f3f3f;
int mxIdx, mxVal;
int arrSort[maxN];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	scanf("%d", &n);
	n *= 2;
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++) {
			int ptr = 0;
			int ans = 0;
			for (int k = 0; k < n; k++)
				if (k != i && k != j)
					arrSort[ptr++] = arr[k];
			sort(arrSort, arrSort + ptr);
			for (int k = 0; k < ptr; k += 2)
				ans += arrSort[k + 1] - arrSort[k];
			mxans = min(ans, mxans);
		}
	printf("%d\n", mxans );
	return 0;
}