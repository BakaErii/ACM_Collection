/**
 * @author  Moe_Sakiya	sakiya@tun.moe
 * @date    2018-10-09 13:27:23
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

int n;

unsigned long long int BFS(void) {
	queue<unsigned long long int> que;
	que.push(1);
	while (!que.empty()) {
		unsigned long long tmp = que.front();
		que.pop();
		if (tmp % n == 0)
			return tmp;
		que.push(tmp * 10);
		que.push(tmp * 10 + 1);
	}
	return 0;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	while (~scanf("%d", &n) && n != 0) {
		printf("%llu\n",BFS());
	}
	return 0;
}