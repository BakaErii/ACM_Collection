/**
 * @author  Moe_Sakiya	sakiya@tun.moe
 * @date    2019-07-31 15:07:59
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

const int maxN = 200005;

typedef unsigned long long int LL;

int arr[maxN];
int n, leftNum, rightNum;
LL sum, dis;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	arr[0] = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
		dis += arr[i];
	}
	sort(arr, arr + n + 1);
	leftNum = 0;
	rightNum = n;
	sum += dis;
	for (int i = 1; i <= n; i++) {
		dis += (LL)leftNum * (LL)(arr[i] - arr[i - 1]);
		dis -= (LL)rightNum * (LL)(arr[i] - arr[i - 1]);
		sum += dis;
		leftNum++;
		rightNum--;
	}
	printf("%llu %llu\n", sum / __gcd(sum, (LL)n), n / __gcd(sum, (LL)n) );
	return 0;
}