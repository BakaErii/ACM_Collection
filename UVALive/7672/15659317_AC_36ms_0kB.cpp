/**
 * @author  Moe_Sakiya	sakiya@tun.moe
 * @date    2018-08-24 13:41:04
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

const int INF = 0x3f3f3f3f;

int vis[100005][5][5];

struct Status
{
	int num[5];
	int op2;
	int op3;
	int step;
};

int toInt(int num[5]) {
	int tmp = 0;
	for (int i = 0; i < 5; i++)
		tmp = tmp * 10 + num[i];
	return tmp;
}

void init(void) {
	memset(vis, INF, sizeof(vis));
	vis[12345][3][2] = 0;
	Status fp = {{1, 2, 3, 4, 5}, 3, 2, 0}, tmp;
	queue<Status> que;
	que.push(fp);
	while (!que.empty()) {
		fp = que.front();
		que.pop();
		//Op1
		for (int i = 0; i < 4; i++) {
			tmp = fp;
			tmp.step++;
			swap(tmp.num[i], tmp.num[i + 1]);
			if (vis[toInt(tmp.num)][tmp.op2][tmp.op3] > tmp.step ) {
				vis[toInt(tmp.num)][tmp.op2][tmp.op3] = tmp.step;
				que.push(tmp);
			}
		}
		//Op2
		if (fp.op2 > 0) {
			for (int i = 0; i < 5; i++) {
				tmp = fp;
				tmp.step++;
				tmp.op2--;
				tmp.num[i] = (tmp.num[i] + 1) % 10;
				if (vis[toInt(tmp.num)][tmp.op2][tmp.op3] > tmp.step ) {
					vis[toInt(tmp.num)][tmp.op2][tmp.op3] = tmp.step;
					que.push(tmp);
				}
			}
		}
		//Op3
		if (fp.op3 > 0) {
			for (int i = 0; i < 5; i++) {
				tmp = fp;
				tmp.step++;
				tmp.op3--;
				tmp.num[i] = (tmp.num[i] * 2) % 10;
				if (vis[toInt(tmp.num)][tmp.op2][tmp.op3] > tmp.step ) {
					vis[toInt(tmp.num)][tmp.op2][tmp.op3] = tmp.step;
					que.push(tmp);
				}
			}
		}
	}
	return;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	init();
	int n, ans;
	while (~scanf("%d", &n)) {
		ans = INF;
		for (int i = 0; i <= 3; i++)
			for (int j = 0; j <= 2; j++)
				ans = min(ans, vis[n][i][j]);
		if (ans == INF)
			printf("-1\n");
		else
			printf("%d\n", ans);
	}
	return 0;
}