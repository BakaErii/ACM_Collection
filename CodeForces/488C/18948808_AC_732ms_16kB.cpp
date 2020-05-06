/**
 * @author	Moe_Sakiya	sakiya@tun.moe
 * @date	2019-03-27 15:55:57
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

int myATK, myHP, myDEF;
int eATK, eHP, eDEF;
int cATK, cHP, cDEF;
const int INF = 0x3f3f3f3f;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int minCost = INF;
	scanf("%d %d %d", &myHP, &myATK, &myDEF);
	scanf("%d %d %d", &eHP, &eATK, &eDEF);
	scanf("%d %d %d", &cHP, &cATK, &cDEF);
	// BuyATK
	for(int i = 0; i <= 301; i++) {
		// BuyDEF
		for(int j = 0; j <= 301 ; j++) {
			// BuyHP
			for(int k = 0; k < 3000; k++) {
				// Attack
				if(myATK + i <= eDEF)
					continue;
				// Cost turn
				int eTurn = (eHP - 1) / (myATK + i - eDEF) + 1;
				// Cost HP
				int costHP = eTurn * (eATK - myDEF - j) - myHP;
				if(costHP >= k)
					continue;
				// Update Ans
				minCost = min(minCost, i * cATK + j * cDEF + k * cHP);
			}
		}
	}
	printf("%d\n", minCost == INF ? 0 : minCost );
	return 0;
}