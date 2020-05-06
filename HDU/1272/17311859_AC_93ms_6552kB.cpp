/**
 * @author	Moe_Sakiya    	sakiya@tun.moe
 * @date	2018-12-04 19:42:50
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

int arrSet[100005];
set<int> st;
set<int> cntSet;
int edgeNum;

int find(int x) {
	if(arrSet[x] == x)
		return x;
	else
		arrSet[x] = find(arrSet[x]);
	return arrSet[x];
}

void unionSet(int a, int b) {
	int ap = find(a);
	int bp = find(b);
	if(bp != ap)
		arrSet[bp] = ap;
	return;
}

void Init(void) {
	for(int i = 1; i <= 100000; i++)
		arrSet[i] = i;
	st.clear();
	cntSet.clear();
	edgeNum = 0;
	return;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int a, b, u, v;
	while(~scanf("%d %d", &u, &v)) {
		if(u == -1 && v == -1)
			break;
		if(u == 0 && v == 0) {
			printf("Yes\n");
			continue;
		}
		Init();
		st.insert(u);
		st.insert(v);
		unionSet(u, v);
		edgeNum++;
		while(~scanf("%d %d", &a, &b)) {
			if(a == 0 && b == 0) {
				// Solve case
				for(auto it : st)
					cntSet.insert(find(it));
				if(cntSet.size() != 1 || edgeNum != (int)st.size() - 1)
					printf("No\n");
				else
					printf("Yes\n");
				break;
			}
			unionSet(a, b);
			st.insert(a);
			st.insert(b);
			edgeNum++;
		}
	}
	return 0;
}