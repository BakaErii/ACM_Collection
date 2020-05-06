/**
 * @author  Moe_Sakiya	sakiya@tun.moe
 * @date    2019-07-25 12:30:37
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

const int maxN = 700005;
const int maxLen = 115;

int totNum;
int arrDp[maxN];
int arrRes[maxN];
char strA[maxLen];
char strB[maxLen];
int per10[6];

void BFS() {
	queue<int> Que;
	memset(arrDp, -1, sizeof(arrDp));
	per10[0] = 1;
	for (int i = 1; i < 6; i++)
		per10[i] = per10[i - 1] * 10;
	arrDp[totNum] = 0;
	arrRes[totNum++] = 123456;
	Que.push(123456);
	while (!Que.empty()) {
		int f = Que.front();
		Que.pop();
		for (int i = 1; i <= 6; i++)
			for (int j = 1; j <= 6; j++) {
				if (i == j)
					continue;
				int nxt = 0;
				for (int k = 5; k >= 0; k--) {
					int cur = f / per10[k] % 10;
					if (cur == i)
						nxt = nxt * 10 + j;
					else
						nxt = nxt * 10 + cur;
				}
				if (arrDp[nxt] != -1)
					continue;
				arrDp[nxt] = arrDp[f] + 1;
				arrRes[totNum++] = nxt;
				Que.push(nxt);
			}
	}
	return;
}


int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int len, ans, cur, step, ptr;
	int change[7];
	BFS();
	while (~scanf("%s %s", strA, strB)) {
		len = strlen(strA);
		ans = len;
		for (int i = 0; i < totNum; i++) {
			cur = arrRes[i];
			step = 0;
			ptr = 1;
			for (int j = 5; j >= 0; j--)
				change[ptr++] = cur / per10[j] % 10;
			for (int j = 0; j < len; j++)
				if (strA[j] - '0' != change[strB[j] - '0'])
					step++;
			ans = min(ans, step + arrDp[cur]);
		}
		printf("%d\n", ans + 1 );
	}
	return 0;
}