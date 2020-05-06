/**
 * @author  Moe_Sakiya	sakiya@tun.moe
 * @date    2019-08-02 16:13:12
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

typedef long long int LL;

char str[maxN];

struct Node
{
	LL sNum;
	LL hNum;
	LL shNum;
	bool operator < (const Node & n) const {
		return sNum * n.hNum > hNum * n.sNum;
	}
} N[maxN];

int n;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int len;
	scanf("%d", &n);
	getchar();
	for (int i = 0; i < n; i++) {
		N[i].sNum = N[i].hNum = N[i].shNum = 0;
		gets(str);
		len = strlen(str);
		for (int j = len - 1; j >= 0; j--)
			if (str[j] == 'h')
				N[i].hNum++;
			else {
				N[i].sNum++;
				N[i].shNum += N[i].hNum;
			}
	}
	sort(N, N + n);
	Node ansNode = {0, 0, 0};
	for (int i = 0; i < n; i++) {
		ansNode.shNum += N[i].shNum;
		ansNode.shNum += ansNode.sNum * N[i].hNum;
		ansNode.sNum += N[i].sNum;
		ansNode.hNum += N[i].hNum;
	}
	printf("%lld\n", ansNode.shNum );
	return 0;
}