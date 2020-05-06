/**
 * @author  Moe_Sakiya	sakiya@tun.moe
 * @date    2019-02-23 19:29:03
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

int n, hPtr, lPtr;
int arr[maxN];
int arrAns[maxN];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	sort(arr, arr + n);
	hPtr = 0;
	lPtr = n - 1;
	for (int i = 0; i < n; i++)
		if (i % 2 == 0)
			arrAns[hPtr++] = arr[i];
		else
			arrAns[lPtr--] = arr[i];
	for (int i = 0; i < n; i++)
		printf("%d ", arrAns[i]);
	putchar('\n');
	return 0;
}