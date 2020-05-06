/**
 * @author	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2018-03-04 16:53:38
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

//二叉树中X节点的高=二叉树中X的父节点的高+X是第几个儿子-1
int kase, maxBefore, maxAfter, curStrPtr;
string str;

void transTree(int curBefore, int curAfter) {
	int tmp = 0;
	while (str[curStrPtr] == 'd') {
		tmp++;
		curStrPtr++;
		transTree(curBefore + 1, curAfter + tmp);
	}
	maxBefore = max(maxBefore, curBefore);
	maxAfter = max(maxAfter, curAfter);
	curStrPtr++;
	return;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	while (cin >> str && str != "#") {
		//init
		curStrPtr = 0;
		maxBefore = 0;
		maxAfter = 0;
		transTree(0, 0);
		printf("Tree %d: %d => %d\n", ++kase, maxBefore, maxAfter );
	}
	return 0;
}