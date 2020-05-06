/**
 * @author  Moe_Sakiya	sakiya@tun.moe
 * @date    2019-08-04 15:04:16
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

const int maxN = 100005;

int arr[maxN];
int arrIdx[maxN];
int sum, limit;

struct Node
{
	int val;
	int idx;
	bool operator < (const Node & n) const {
		return val < n.val;
	}
} N[maxN];

int LowBit(int x) {
	return x & -x;
}

bool Check(int val) {
	int ptr = 0;
	for (int i = 1; i <= limit; i++)
		N[i] = {arr[i], i};
	sort(N + 1, N + limit + 1);
	for (int i = limit; i >= 1; i--)
		if (sum > 0) {
			if (N[i].val <= sum) {
				sum -= N[i].val;
				arrIdx[ptr++] = N[i].idx;
			}
		}
	if (sum == 0) {
		printf("%d\n", ptr );
		for (int i = 0; i < ptr; i++)
			printf("%d ", arrIdx[i]);
		putchar('\n');
		return true;
	}
	return false;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	for (int i = 1; i <= maxN; i++)
		arr[i] = LowBit(i);
	scanf("%d %d", &sum, &limit);
	if (Check(sum) == false)
		printf("-1\n");
	return 0;
}