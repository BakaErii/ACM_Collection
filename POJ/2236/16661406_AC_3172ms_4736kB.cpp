/**
 * @author  Moe_Sakiya	sakiya@tun.moe
 * @date    2018-10-26 16:10:19
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

const int maxN = 1005;
bool isRepair[maxN];
int uSet[maxN];
vector<int> uVec[maxN];

int n, d;
char op[10];

struct Point
{
	int x, y;
} pos[maxN];

int find(int x) {
	if (uSet[x] == x)
		return x;
	uSet[x] = find(uSet[x]);
	return uSet[x];
}

void unionElement(int a, int b) {
	int tmpa = find(a);
	int tmpb = find(b);
	if (tmpa != tmpb)
		uSet[tmpa] = tmpb;
	return;
}

double calDistance(Point a, Point b) {
	double ret;
	ret = (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
	return ret;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int arg0, arg1;
	scanf("%d %d", &n, &d);
	//Init
	for (int i = 1; i <= n; i++) {
		isRepair[i] = false;
		uSet[i] = i;
	}
	//Input
	for (int i = 1; i <= n; i++)
		scanf("%d %d", &pos[i].x, &pos[i].y);
	//Preproccess
	for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n; j++)
			if (calDistance(pos[i], pos[j]) <= d * d) {
				uVec[i].push_back(j);
				uVec[j].push_back(i);
			}
	//Solve
	getchar();
	while (~scanf("%s", op)) {
		switch (op[0]) {
		case 'O':
			scanf("%d", &arg0);
			isRepair[arg0] = true;
			for (int i = 0; i < (int)uVec[arg0].size(); i++)
				if (isRepair[uVec[arg0][i]] == true)
					unionElement(arg0, uVec[arg0][i]);
			break;
		case 'S':
			scanf("%d %d", &arg0, &arg1);
			if (isRepair[arg0] == true && isRepair[arg1] == true && find(arg0) == find(arg1))
				printf("SUCCESS\n");
			else
				printf("FAIL\n");
			break;
		}
	}
	return 0;
}