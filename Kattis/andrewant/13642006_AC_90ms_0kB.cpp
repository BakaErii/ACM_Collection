/**
 * @author	Moe_Sakiya    	sakiya@tun.moe
 * @date	2018-04-24 17:31:28
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

struct Ants {
	int dis;
	char toward;
} arrAnts[100001];
int arrMove[100001];

bool cmp(Ants a, Ants b) {
	return a.dis < b.dis;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, l, maxLen, ansAnt1, ansAnt2, ansCount;
	while(cin >> l >> n) {
		//Init
		maxLen = 0;
		ansCount = 0;
		for(int i = 0; i < n; i++) {
			cin >> arrAnts[i].dis >> arrAnts[i].toward;
			if(arrAnts[i].toward == 'L')
				maxLen = max(maxLen, arrAnts[i].dis);
			else
				maxLen = max(maxLen, l - arrAnts[i].dis);
		}
		sort(arrAnts, arrAnts + n, cmp);
		for(int i = 0; i < n; i++)
			if(arrAnts[i].toward == 'L')
				arrMove[i] = arrAnts[i].dis - maxLen;
			else
				arrMove[i] = arrAnts[i].dis + maxLen;
		sort(arrMove, arrMove + n);
		for(int i = 0; i < n; i++)
			if(arrMove[i] == 0 || arrMove[i] == l) {
				if(ansCount == 0)
					ansAnt1 = i;
				else
					ansAnt2 = i;
				ansCount++;
			}
		if(ansCount == 1)
			printf("The last ant will fall down in %d seconds - started at %d.\n", maxLen, arrAnts[ansAnt1].dis);
		else
			printf("The last ant will fall down in %d seconds - started at %d and %d.\n", maxLen, arrAnts[ansAnt1].dis, arrAnts[ansAnt2].dis);
	}
	return 0;
}