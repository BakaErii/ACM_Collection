/**
 * @author	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2018-03-04 16:05:59
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

vector<int> ivec;

int findSet(int id) {
	if (ivec[id] == -1)
		return id;
	else {
		ivec[id] = findSet(ivec[id]);
		return ivec[id];
	}
}

void mergeSet(int idA, int idB) {
	int tmp1, tmp2;
	tmp1 = findSet(idA);
	tmp2 = findSet(idB);
	if (tmp1 != tmp2)
		ivec[tmp2] = tmp1;
	return;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int i, t, n, m, argv0, argv1;
	char command;
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &n, &m);
		getchar();
		//init
		ivec.clear();
		for (i = 0; i <= 2 * n + 1; i++)
			ivec.push_back(-1);
		for (i = 0; i < m; i++) {
			scanf("%c %d %d", &command, &argv0, &argv1);
			getchar();
			switch (command) {
			case 'A':
				if (findSet(argv0) != findSet(argv1) && findSet(argv0) != findSet(argv1 + n))
					printf("Not sure yet.\n");
				else if (findSet(argv0) == findSet(argv1))
					printf("In the same gang.\n");
				else {
					printf("In different gangs.\n");
				}
				break;
			case 'D':
				if (findSet(argv0) != findSet(argv1 + n)) {
					ivec[findSet(argv0)] = findSet(argv1 + n);
					ivec[findSet(argv1)] = findSet(argv0 + n);
				}
				break;
			}
		}
	}
	return 0;
}