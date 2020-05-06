/**
 * @author	Moe_Sakiya    	sakiya@tun.moe
 * @date	2018-05-06 15:44:59
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

const int maxN = 50005;
const int maxK = 100005;

int N, K;
int st[maxN * 3];

void initSet(int n) {
	for(int i = 0; i < n; i++)
		st[i] = i;
	return;
}

int findSet(int x) {
	if(st[x] == x)
		return x;
	st[x] = findSet(st[x]);
	return st[x];
}

void mergeSet(int xA, int xB) {
	int tmpA = findSet(xA);
	int tmpB = findSet(xB);
	if(tmpA != tmpB)
		st[tmpB] = tmpA;
	return;
}

bool isSame(int xA, int xB) {
	if(findSet(xA) == findSet(xB))
		return true;
	else
		return false;
}


int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int cmdD, cmdX, cmdY, ans = 0;
	scanf("%d %d", &N, &K);
	initSet(N * 3 + 3);
	for(int i = 0; i < K; i++) {
		scanf("%d %d %d", &cmdD, &cmdX, &cmdY);
		if(cmdX > N || cmdY > N) {
			ans++;
			continue;
		}
		if(cmdD == 1) {
			if(isSame(cmdX, cmdY + N) || isSame(cmdX, cmdY + 2 * N)) {
				ans++;
				continue;
			} else {
				mergeSet(cmdX, cmdY);
				mergeSet(cmdX + N, cmdY + N);
				mergeSet(cmdX + 2 * N, cmdY + 2 * N);
				continue;
			}
		}
		if(cmdD == 2) {
			if(isSame(cmdX, cmdY) || isSame(cmdX, cmdY + 2 * N)) {
				ans++;
				continue;
			} else {
				mergeSet(cmdX, cmdY + N);
				mergeSet(cmdX + N, cmdY + 2 * N);
				mergeSet(cmdX + 2 * N, cmdY);
				continue;
			}
		}
	}
	printf("%d\n",ans );
	return 0;
}