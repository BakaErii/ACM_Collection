/**
 * @author	Moe_Sakiya    	sakiya@tun.moe
 * @date	2018-12-06 18:27:22
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
int arrIn[100005];
int edgeNum;
set<int> Gst;
set<int> Cntst;

int findSet(int x) {
	if(arrSet[x] == x)
		return x;
	else
		arrSet[x] = findSet(arrSet[x]);
	return arrSet[x];
}

void unionSet(int a, int b) {
	int ap = findSet(a);
	int bp = findSet(b);
	if(ap != bp)
		arrSet[bp] = ap;
	return;
}

void init() {
	edgeNum = 0;
	Gst.clear();
	Cntst.clear();
	for(int i = 0; i < 100005; i++) {
		arrSet[i] = i;
		arrIn[i] = 0;
	}
	return;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int a, b, u, v, kase = 0;
	while(~scanf("%d %d", &a, &b)) {
		if(a < 0 || b < 0)
			break;
		if(a == 0 && b == 0) {
			printf("Case %d is a tree.\n", ++kase);
			continue;
		}
		init();
		unionSet(a, b);
		Gst.insert(a);
		Gst.insert(b);
		arrIn[b]++;
		edgeNum++;
		while(~scanf("%d %d", &u, &v)) {
			if(u == 0 && v == 0) {
				//Solve
				int rootCnt = 0, nodeCnt = 0;
				for(auto it : Gst) {
					Cntst.insert(findSet(it));
					if(arrIn[it] == 0)
						rootCnt++;
					if(arrIn[it] == 1)
						nodeCnt++;
				}
				if(Cntst.size() == 1) {
					if(edgeNum == (int)Gst.size() - 1 && nodeCnt == edgeNum && rootCnt == 1)
						printf("Case %d is a tree.\n", ++kase);
					else
						printf("Case %d is not a tree.\n", ++kase);
					break;
				} else {
					printf("Case %d is not a tree.\n", ++kase);
					break;
				}
			}
			unionSet(u, v);
			Gst.insert(u);
			Gst.insert(v);
			arrIn[v]++;
			edgeNum++;
		}
	}
	return 0;
}