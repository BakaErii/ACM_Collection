/**
 * @author	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2018-03-24 14:46:13
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

struct Node
{
	int next;
	int val;
};

vector<Node> tree[40001];
int ans[40001];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t, n, m, x, y, z, cmd;
	int i, j, k;
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &n, &m);
		//init
		memset(ans, 0, sizeof(ans));
		for (i = 0; i <= n; i++)
			tree[i].clear();
		//creatTree
		for (i = 0; i < n - 1; i++) {
			scanf("%d %d %d", &x, &y, &z);
			tree[x].push_back({y, z});
			tree[y].push_back({x, z});
		}
		//calAns
		for (i = 1; i <= n; i++) {
			for (j = 0; j < (int)tree[i].size(); j++) {
				ans[i] += tree[i][j].val;
			}
		}
		//queryAns
		for (i = 0; i < m; i++) {
			scanf( "%d", &cmd);
			if (cmd == 0) {
				scanf("%d", &x);
				if (ans[x] % 2 == 0)
					printf("Boys win!\n");
				else
					printf("Girls win!\n");
			} else {
				scanf("%d %d %d", &x, &y, &z);
				//findNode
				for (j = 0; j < (int)tree[x].size(); j++) {
					if (tree[x][j].next == y) {
						//checkEqual?
						if (tree[x][j].val != z) {
							tree[x][j].val = z;
							if (z == 0) {
								ans[x]--;
								ans[y]--;
							} else {
								ans[x]++;
								ans[y]++;
							}
							for (k = 0; k < (int)tree[y].size(); k++)
								if (tree[y][k].next == x) {
									tree[y][k].val = z;
									break;
								}
							break;
						} else
							break;
					}
				}
			}
		}
	}
	return 0;
}