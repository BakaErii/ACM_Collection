/**
 * @author  Moe_Sakiya	sakiya@tun.moe
 * @date    2019-02-25 15:00:55
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

int n, m;
int arrSet[maxN * 2];
int arrIn[maxN * 2];
int arrAns[maxN * 2];
char G[maxN][maxN];

vector<int> vecPer[maxN * 2];
queue<int> que;

void Init() {
	for (int i = 0; i <= n + m; i++)
		arrSet[i] = i;
	return;
}

int FindSet(int x) {
	if (arrSet[x] == x)
		return x;
	arrSet[x] = FindSet(arrSet[x]);
	return arrSet[x];
}

void MergeSet(int a, int b) {
	int tmpA = FindSet(a);
	int tmpB = FindSet(b + n);
	if (tmpA != tmpB)
		arrSet[tmpA] = tmpB;
	return;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	scanf("%d %d", &n, &m);
	Init();
	getchar();
	for (int i = 0; i < n; i++)
		gets(G[i]);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (G[i][j] == '=')
				MergeSet(i, j);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			if (G[i][j] == '<') {
				vecPer[FindSet(i)].push_back(FindSet(j + n));
				arrIn[FindSet(j + n)]++;
			}
			if (G[i][j] == '>') {
				vecPer[FindSet(j + n)].push_back(FindSet(i));
				arrIn[FindSet(i)]++;
			}
		}
	for (int i = 0; i < n + m; i++)
		if (arrIn[i] == 0) {
			arrAns[i] = 1;
			que.push(i);
		}
	while (!que.empty()) {
		int u = que.front();
		que.pop();
		for (int i = 0; i < (int)vecPer[u].size(); i++) {
			int v = vecPer[u][i];
			arrIn[v]--;
			arrAns[v] = max(arrAns[v], arrAns[u] + 1);
			if (arrIn[v] == 0)
				que.push(v);
		}
	}
	for (int i = 0; i < n + m; i++)
		if (arrIn[FindSet(i)] != 0) {
			printf("No\n");
			return 0;
		}
	printf("Yes\n");
	for (int i = 0; i < n + m; i++) {
		if (i == n)
			putchar('\n');
		printf("%d ", arrAns[FindSet(i)]);
	}
	putchar('\n');
	return 0;
}