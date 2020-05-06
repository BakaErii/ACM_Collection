/**
 * @author	Moe_Sakiya	sakiya@tun.moe
 * @date	2019-03-18 07:54:59
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

const int maxN = 505;
const int maxM = 2005;

struct Query {
	// op==0 '='; op==1 '<'; op==2 '>'
	int a, b, op;
} Q[maxM];

int n, m;
int arrSet[maxN], arrRank[maxN], arrError[maxN];

void Init() {
	for(int i = 0; i <= n; i++) {
		arrSet[i] = i;
		arrRank[i] = 0;
	}
	return;
}

int FindSet(int x) {
	if(arrSet[x] == x)
		return x;
	int now = arrSet[x];
	arrSet[x] = FindSet(arrSet[x]);
	arrRank[x] = (arrRank[x] + arrRank[now]) % 3;
	return arrSet[x];
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int u, v, op, fu, fv;
	char cmd;
	while(~scanf("%d %d", &n, &m)) {
		for(int i = 0; i < m; i++) {
			scanf("%d %c %d", &Q[i].a, &cmd, &Q[i].b);
			switch(cmd) {
			case '=':
				Q[i].op = 0;
				break;
			case '<':
				Q[i].op = 1;
				break;
			case '>':
				Q[i].op = 2;
				break;
			}
		}
		memset(arrError, -1, sizeof(arrError));
		for(int i = 0; i < n; i++) {
			Init();
			for(int j = 0; j < m; j++) {
				if(Q[j].a == i || Q[j].b == i)
					continue;
				u = Q[j].a;
				v = Q[j].b;
				op = Q[j].op;
				fu = FindSet(u);
				fv = FindSet(v);
				if(fu != fv) {
					arrSet[fv] = fu;
					arrRank[fv] = (arrRank[u] + 3 + op - arrRank[v]) % 3;
				} else {
					if((arrRank[v] + 3 - arrRank[u]) % 3 != op) {
						arrError[i] = j;
						break;
					}
				}
			}
		}
		int ans = 0, cnt = 0;
		for(int i = 0; i < n; i++) {
			if(arrError[i] == -1) {
				cnt++;
				v = i;
			}
			ans = max(ans, arrError[i] + 1);
		}
		if(cnt == 0)
			printf("Impossible\n");
		else if(cnt > 1)
			printf("Can not determine\n");
		else
			printf("Player %d can be determined to be the judge after %d lines\n", v, ans);
	}
	return 0;
}