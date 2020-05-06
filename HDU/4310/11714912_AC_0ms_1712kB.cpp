/**
 * @authors	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2017-11-25 18:12:52
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

struct enemy
{
	int dps;
	int hp;
	double weight;
} e[20];

bool cmp(enemy a, enemy b);

int main(void) {
	int i, n, round, hurt;
	while (cin >> n) {
		hurt = 0;
		round = 0;
		for (i = 0; i < n; i++) {
			cin >> e[i].dps >> e[i].hp;
			e[i].weight = (double)e[i].dps / (double)e[i].hp;
		}
		sort(e, e + n, cmp);
		for (i = 0; i < n; i++)
		{
			round += e[i].hp;
			hurt += e[i].dps * round;
		}
		cout << hurt << endl;
	}
	return 0;
}

bool cmp(enemy a, enemy b) {
	return a.weight > b.weight;
}