/**
 * @author  Moe_Sakiya	sakiya@tun.moe
 * @date    2019-08-02 10:12:26
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

typedef long long int LL;

int t;
LL aHP, bHP, aATK, bATK;

LL GetSum(LL x) {
	return x * (x + 1) / 2;
}

LL GetRound(LL x) {
	LL rnd = 1;
	while (GetSum(rnd) < x)
		rnd++;
	return rnd;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	LL aRound, bRound, totRound, ansDam;
	scanf("%d", &t);
	while (t--) {
		// INIT
		scanf("%lld %lld %lld %lld", &aHP, &bHP, &aATK, &bATK);
		// Cal Round
		aRound = GetRound(aHP);
		bRound = GetRound(bHP);
		totRound = GetRound(aHP + bHP);
		ansDam = min(aRound * aATK + totRound * bATK , bRound * bATK + totRound * aATK);
		string ansStr(totRound, 'B');
		if (aRound * aATK + totRound * bATK == ansDam) {
			// A First
			string tmpStr(totRound, 'A');
			for (int i = aRound; i < totRound; i++)
				tmpStr[i] = 'B';
			LL aRemain = GetSum(aRound) - aHP;
			LL totRemain = GetSum(totRound) - aHP - bHP;
			if (aRemain > totRemain)
				tmpStr[aRemain - 1] = 'B';
			ansStr = min(ansStr, tmpStr);
		}
		if (bRound * bATK + totRound * aATK == ansDam) {
			// B First
			string tmpStr(totRound, 'B');
			for (int i = bRound; i < totRound; i++)
				tmpStr[i] = 'A';
			LL bRemain = GetSum(bRound) - bHP;
			LL totRemain = bRemain - (GetSum(totRound) - aHP - bHP);
			int lastChange;
			for (int i = 0; i < aRound; i++)
				if (bRemain >= i + 1) {
					tmpStr[i] = 'A';
					bRemain -= i + 1;
					totRemain -= i + 1;
					lastChange = i;
				}
			if (totRemain > 0) {
				tmpStr[lastChange] = 'B';
				tmpStr[lastChange + totRemain] = 'A';
			}
			ansStr = min(ansStr, tmpStr);
		}
		cout << ansDam << ' ' << ansStr << endl;
	}
	return 0;
}