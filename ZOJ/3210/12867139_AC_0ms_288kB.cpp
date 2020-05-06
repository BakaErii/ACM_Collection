/**
 * @author	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2018-02-07 01:47:20
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

stack<int> s;
queue<int> q;

int main(void) {
	int t, n, i, tmp;
	bool isStack, isQueue;
	scanf("%d", &t);
	while (t--) {
		isQueue = true;
		isStack = true;
		scanf("%d", &n);
		for (i = 0; i < n; i++) {
			scanf("%d", &tmp);
			s.push(tmp);
			q.push(tmp);
		}
		for (i = 0; i < n; i++) {
			scanf("%d", &tmp);
			if (s.top() != tmp)
				isStack = false;
			if (q.front() != tmp)
				isQueue = false;
			s.pop();
			q.pop();
		}
		if (isStack && isQueue)
			cout << "both" << endl;
		else if (isStack)
			cout << "stack" << endl;
		else if (isQueue)
			cout << "queue" << endl;
		else
			cout << "neither" << endl;
	}
	return 0;
}