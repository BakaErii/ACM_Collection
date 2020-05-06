/**
 * @author  Moe_Sakiya	sakiya@tun.moe
 * @date    2019-05-19 09:44:05
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

int arrA[26];
int arrB[26];
int arrCnt[26];
int ans;

int Fnc(int x) {
	int ret = 0;
	for (int i = 1; i <= x; i++)
		ret += i;
	return ret;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	char str[25];
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s", str);
		arrCnt[str[0] - 'a']++;
	}
	for (int i = 0; i < 26; i++) {
		if (arrCnt[i] % 2 == 0) {
			arrA[i] = arrCnt[i] / 2;
			arrB[i] = arrCnt[i] / 2;
		} else {
			arrA[i] = arrCnt[i] / 2 + 1;
			arrB[i] = arrCnt[i] / 2;
		}
		arrA[i]--;
		arrB[i]--;
		if (arrA[i] >= 0)
			ans += Fnc(arrA[i]);
		if (arrB[i] >= 0)
			ans += Fnc(arrB[i]);
	}
	printf("%d\n", ans );
	return 0;
}