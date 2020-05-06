/**
 * @author  Moe_Sakiya	sakiya@tun.moe
 * @date    2018-10-17 19:08:28
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

struct Done
{
	int a, b, op;
	const bool operator < (Done t) const {
		if (this->a == t.a) {
			if (this->b == t.b) {
				return this->op < t.op;
			}
			return this->b < t.b;
		}
		return this->a < t.a;
	}
	const bool operator == (Done t) const {
		return this->a == t.a && this->b == t.b && this->op == t.op;
	}
};

queue<Node> que;
vector<Node> vec;
stack<Node> sta;
set<Done> st;

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

//Status
//0 FillA, 1 FillB, 2 AtoB, 3 BtoA, 4 DropA,5 DropB

bool BFS(int a, int b, int c) {
	int curr = 0;
	//INIT
	que.push({a, 0, 0, -1});
	vec.push_back({a, 0, 0, -1});
	st.insert({a, 0, 0});
	que.push({0, b, 1, -1});
	vec.push_back({0, b, 1, -1});
	st.insert({0, b, 1});
	//Query
	while (!que.empty()) {
		int tmp;
		Node q = que.front();
		que.pop();
		if (q.a == c || q.b == c) {
			OutputAns(curr);
			return true;
		}
		//FillA
		if (st.count({a, q.b, 0}) != 1) {
			que.push({a, q.b, 0, curr});
			vec.push_back({a, q.b, 0, curr});
			st.insert({a, q.b, 0});
		}
		//FillB
		if (st.count({q.a, b, 1}) != 1) {
			que.push({q.a, b, 1, curr});
			vec.push_back({q.a, b, 1, curr});
			st.insert({q.a, b, 1});
		}
		//AtoB
		tmp = min(b - q.b, q.a);
		if (st.count({q.a - tmp, q.b + tmp, 2}) != 1) {
			que.push({q.a - tmp, q.b + tmp, 2, curr});
			vec.push_back({q.a - tmp, q.b + tmp, 2, curr});
			st.insert({q.a - tmp, q.b + tmp, 2});
		}
		//BtoA
		tmp = min(a - q.a, q.b);
		if (st.count({q.a + tmp, q.b - tmp, 3}) != 1) {
			que.push({q.a + tmp, q.b - tmp, 3, curr});
			vec.push_back({q.a + tmp, q.b - tmp, 3, curr});
			st.insert({q.a + tmp, q.b - tmp, 3});
		}
		//DropA
		if (st.count({0, q.b, 4}) != 1) {
			que.push({0, q.b, 4, curr});
			vec.push_back({0, q.b, 4, curr});
			st.insert({0, q.b, 4});
		}
		//DropB
		if (st.count({q.a, 0, 5}) != 1) {
			que.push({q.a, 0, 5, curr});
			vec.push_back({q.a, 0, 5, curr});
			st.insert({q.a, 0, 5});
		}
		//Iterator++
		curr++;
	}
	return false;
}


int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	if (BFS(a, b, c) == false)
		printf("impossible\n");
	return 0;
}