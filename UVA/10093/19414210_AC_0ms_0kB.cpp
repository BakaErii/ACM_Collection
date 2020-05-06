/**
 * @author	Moe_Sakiya	sakiya@tun.moe
 * @date	2019-04-23 19:52:11
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

const int maxN = 10005;

const char tab[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
map<char, int> mp;

char arr[maxN];

void Init() {
	for(int i = 0; i < 63; i++)
		mp[tab[i]] = i;
	return;
}

int getInt() {
	int len = strlen(arr);
	int maxCnt = 2;
	for(int i = 0; i < len; i++)
		if(maxCnt <= mp[arr[i]])
			maxCnt = mp[arr[i]] + 1;
	for(int i = maxCnt; i < 63; i++) {
		int last = 0;
		for(int j = 0; j < len; j++)
			last = (last * i + mp[arr[j]]) % (i - 1);
		if(last == 0)
			return i;
	}
	return -1;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	Init();
	while(~scanf("%s", arr)) {
		int ans = getInt();
		if(ans == -1)
			printf("such number is impossible!\n");
		else
			printf("%d\n", ans );
	}
	return 0;
}