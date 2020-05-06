/**
 * @author  Moe_Sakiya	sakiya@tun.moe
 * @date    2018-10-09 13:40:23
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

const int maxN = 10005;
int n, m, primeCnt;
bool isPrime[maxN];
int arrPrime[maxN];
bool vis[maxN];

void calPrime() {
	memset(isPrime, 1, sizeof(isPrime));
	for (int i = 2; i < maxN; i++) {
		if (isPrime[i])
			arrPrime[primeCnt++] = i;
		for (int j = 0; j < primeCnt && i * arrPrime[j] < maxN; j++) {
			isPrime[i * arrPrime[j]] = false;
			if (!(i % arrPrime[j]))
				break;
		}
	}
	return;
}

int changeVal(int num, int pos, int val) {
	int ret;
	switch (pos) {
	case 1:
		ret = val * 1000 + (num % 1000) / 100 * 100 + (num % 100) / 10 * 10 + (num % 10);
		break;
	case 2:
		ret = num / 1000 * 1000 + val * 100 + (num % 100) / 10 * 10 + (num % 10);
		break;
	case 3:
		ret = num / 1000 * 1000 + (num % 1000) / 100 * 100 + val * 10 + (num % 10);
		break;
	case 4:
		ret = num / 1000 * 1000 + (num % 1000) / 100 * 100 + (num % 100) / 10 * 10 + val;
		break;
	}
	if (isPrime[ret] == true)
		return ret;
	else
		return -1;
}

struct Node
{
	int val;
	int times;
};

int BFS() {
	memset(vis, 0, sizeof(vis));
	queue<Node> que;
	que.push({n, 0});
	vis[n] = true;
	while (!que.empty()) {
		Node f = que.front();
		que.pop();
		if (f.val == m)
			return f.times;
		for (int i = 1; i <= 4; i++)
			for (int j = (i == 1) ? 1 : 0; j < 10; j++) {
				int tmp = changeVal(f.val, i, j);
				if (tmp != -1 && vis[tmp] == false) {
					vis[tmp] = true;
					que.push({tmp, f.times + 1});
				}
			}
	}
	return -1;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	calPrime();
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &n, &m);
		int ans = BFS();
		if (ans == -1)
			printf("Impossible\n");
		else
			printf("%d\n", ans );
	}
	return 0;
}