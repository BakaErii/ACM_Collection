/**
 * @author  Moe_Sakiya	sakiya@tun.moe
 * @date    2018-10-17 20:35:08
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
	int a, b, op, pre;
};

queue<Node> que;
vector<Node> vec;
stack<Node> sta;
bool vis[105][105];

//Status
//0 FillA, 1 FillB, 2 AtoB, 3 BtoA, 4 DropA,5 DropB

void OutputAns(int index) {
	while (index != -1) {
		sta.push(vec[index]);
		index = vec[index].pre;
	}
	printf("%d\n", (int)sta.size());
	while (!sta.empty()) {
		Node tmp = sta.top();
		sta.pop();
		switch (tmp.op) {
		case 0:
			printf("FILL(1)\n");
			break;
		case 1:
			printf("FILL(2)\n");
			break;
		case 2:
			printf("POUR(1,2)\n");
			break;
		case 3:
			printf("POUR(2,1)\n");
			break;
		case 4:
			printf("DROP(1)\n");
			break;
		case 5:
			printf("DROP(2)\n");
			break;
		}
	}
	return;
}

bool BFS(int a, int b, int c) {
	int curr = 0;
	//INIT
	que.push({a, 0, 0, -1});
	vec.push_back({a, 0, 0, -1});
	vis[a][0] = true;
	que.push({0, b, 1, -1});
	vec.push_back({0, b, 1, -1});
	vis[0][b] = true;
	//BFS
	while (!que.empty()) {
		int tmp;
		Node q = que.front();
		que.pop();
		if (q.a == c || q.b == c) {
			OutputAns(curr);
			return true;
		}
		//FillA
		if (vis[a][q.b] != true) {
			que.push({a, q.b, 0, curr});
			vec.push_back({a, q.b, 0, curr});
			vis[a][q.b] = true;
		}
		//FillB
		if (vis[q.a][b] != true) {
			que.push({q.a, b, 1, curr});
			vec.push_back({q.a, b, 1, curr});
			vis[q.a][b] = true;
		}
		//AtoB
		tmp = min(b - q.b, q.a);
		if (vis[q.a - tmp][q.b + tmp] != true) {
			que.push({q.a - tmp, q.b + tmp, 2, curr});
			vec.push_back({q.a - tmp, q.b + tmp, 2, curr});
			vis[q.a - tmp][q.b + tmp] = true;
		}
		//BtoA
		tmp = min(a - q.a, q.b);
		if (vis[q.a + tmp][q.b - tmp] != true) {
			que.push({q.a + tmp, q.b - tmp, 3, curr});
			vec.push_back({q.a + tmp, q.b - tmp, 3, curr});
			vis[q.a + tmp][q.b - tmp] = true;
		}
		//DropA
		if (vis[0][q.b] != true) {
			que.push({0, q.b, 4, curr});
			vec.push_back({0, q.b, 4, curr});
			vis[0][q.b] = true;
		}
		//DropB
		if (vis[q.a][0] != true) {
			que.push({q.a, 0, 5, curr});
			vec.push_back({q.a, 0, 5, curr});
			vis[q.a][0] = true;
		}
		//Iterator++
		curr++;
	}
	return false;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	memset(vis,0,sizeof(vis));
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	if (BFS(a, b, c) == false)
		printf("impossible\n");
	return 0;
}