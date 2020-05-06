/**
 * @author	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2018-04-02 17:55:58
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
#include <deque>

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>

using namespace std;

#define INF 233333333

int n, m;
int graph[300][300], layer[300];
bool vis[300];

bool isExistLayer(void) {
	int i, curr;
	deque<int> que;
	//init
	memset(layer, 0xff, sizeof(layer));
	//BFS
	layer[1] = 0;
	que.push_back(1);
	while (!que.empty()) {
		curr = que.front();
		que.pop_front();
		//遍历数组
		for (i = 1; i <= m; i++)
			if (graph[curr][i] > 0 && layer[i] == -1) {
				layer[i] = layer[curr] + 1;
				if (i == m) {
					//搜到汇点
					return true;
				}
				else {
					//加入队列 继续BFS
					que.push_back(i);
				}
			}
	}
	//未找到汇点 算法停止
	return false;
}

int dinic(void) {
	int i, curr, minTransfer, minTransfer_s, u, v;
	int maxFlow = 0;
	deque<int> que;
	//BFS 是否可以探寻到汇点
	while (isExistLayer()) {
		//init
		memset(vis, 0, sizeof(vis));
		vis[1] = true;
		//DFS
		que.push_back(1);
		while (!que.empty()) {
			curr = que.back();
			if (curr != m) {
				//不是汇点 继续DFS下一层
				for (i = 1; i <= m; i++)
					if (graph[curr][i] > 0 && layer[curr] + 1 == layer[i] && vis[i] == false) {
						vis[i] = true;
						que.push_back(i);
						break;
					}
				//寻找不到有效点 出栈回溯
				if (i > m)
					que.pop_back();
			} else {
				//是汇点 计算最大流
				//寻找当前流中的最小边
				minTransfer = INF;
				for (i = 1; i < (int)que.size(); i++) {
					u = que[i - 1];
					v = que[i];
					if (graph[u][v] > 0 && graph[u][v] < minTransfer) {
						//更新最小边
						minTransfer = graph[u][v];
						minTransfer_s = u;
					}
				}
				//将最小值加入流中
				maxFlow += minTransfer;
				//增广扩边
				for (i = 1; i < (int)que.size(); i++) {
					u = que[i - 1];
					v = que[i];
					//减少当前边 增加反向边
					graph[u][v] -= minTransfer;
					graph[v][u] += minTransfer;
				}
				//回溯到最小点 继续DFS
				while(!que.empty()&&que.back()!=minTransfer_s){
					vis[que.back()]=false;
					que.pop_back();
				}
			}
		}
	}
	return maxFlow;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int i;
	int s, e, c;
	while (~scanf("%d %d", &n, &m)) {
		//init
		memset(graph, 0, sizeof(graph));
		//建图
		for (i = 0; i < n; i++) {
			scanf("%d %d %d", &s, &e, &c);
			graph[s][e] += c;
		}
		//solve
		printf("%d\n", dinic());
	}
	return 0;
}