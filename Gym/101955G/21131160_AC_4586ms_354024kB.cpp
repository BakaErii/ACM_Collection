/**
 * @author  Moe_Sakiya	sakiya@tun.moe
 * @date    2019-08-07 11:41:09
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

const int maxDis = 10000005;
const int maxN = 6005;
const int dx[] = {1, 1, -1, -1};
const int dy[] = {1, -1, 1, -1};

struct Point
{
	int x, y;
};

vector<Point> V[maxDis], nowV;
set<pair<int, int>> querySet;
int mp[maxN][maxN];
int n, m, t, kase;
long long int lstans;

void Init() {
	for (int i = 0; i < maxN; i++)
		for (int j = 0; j < maxN; j++)
			if (i * i + j * j < maxDis)
				V[i * i + j * j].push_back({i, j});
	return;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	Init();
	int x, y, w, k, op;
	scanf("%d", &t);
	while (t--) {
		// INIT
		nowV.clear();
		lstans = 0;
		printf("Case #%d:\n", ++kase);
		scanf("%d %d", &n, &m);
		// INPUT
		for (int i = 0; i < n; i++) {
			scanf("%d %d %d", &x, &y, &w);
			mp[x][y] = w;
			nowV.push_back({x, y});
		}
		// QUERY
		for (int i = 0; i < m; i++) {
			scanf("%d", &op);
			switch (op) {
			case 1:
				scanf("%d %d %d", &x, &y, &w);
				x = (x + lstans) % 6000 + 1;
				y = (y + lstans) % 6000 + 1;
				mp[x][y] = w;
				nowV.push_back({x, y});
				break;
			case 2:
				scanf("%d %d", &x, &y);
				x = (x + lstans) % 6000 + 1;
				y = (y + lstans) % 6000 + 1;
				mp[x][y] = 0;
				break;
			case 3:
				querySet.clear();
				scanf("%d %d %d %d", &x, &y, &k, &w);
				x = (x + lstans) % 6000 + 1;
				y = (y + lstans) % 6000 + 1;
				for (int j = 0; j < (int)V[k].size(); j++)
					for (int d = 0; d < 4; d++) {
						int X = V[k][j].x * dx[d] + x;
						int Y = V[k][j].y * dy[d] + y;
						if (X > 0 && Y > 0 && X <= 6000 && Y <= 6000 && mp[X][Y] != 0)
							querySet.insert({X, Y});
					}
				for (auto it : querySet)
					mp[it.first][it.second] += w;
				break;
			case 4:
				querySet.clear();
				scanf("%d %d %d", &x, &y, &k);
				x = (x + lstans) % 6000 + 1;
				y = (y + lstans) % 6000 + 1;
				for (int j = 0; j < (int)V[k].size(); j++)
					for (int d = 0; d < 4; d++) {
						int X = V[k][j].x * dx[d] + x;
						int Y = V[k][j].y * dy[d] + y;
						if (X > 0 && Y > 0 && X <= 6000 && Y <= 6000 && mp[X][Y] != 0)
							querySet.insert({X, Y});
					}
				lstans = 0;
				for (auto it : querySet)
					lstans += mp[it.first][it.second];
				printf("%lld\n", lstans );
				break;
			}
		}
		for (int i = 0; i < (int)nowV.size(); i++)
			mp[nowV[i].x][nowV[i].y] = 0;
	}
	return 0;
}