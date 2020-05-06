/**
 * @authors	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2017-12-03 14:47:29
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

int tenpw(int i) {
	int tmp = 1;
	while (i--)
		tmp *= 10;
	return tmp;
}

int main(void) {
	unsigned long long sum = 0;
	unsigned long long i, a, b, tmp, cnt, rtmp;
	cin >> a >> b;
	for (i = 1; i <= a; i++) {
		//根据打表知第i个数字即为i*位数+i的回文
		tmp = i;
		rtmp = 0;
		cnt = 0;
		while (tmp > 0) {
			rtmp = rtmp * 10 + tmp % 10;
			tmp /= 10;
			cnt++;
		}
		tmp = i * tenpw(cnt) + rtmp;
		sum += tmp;
		sum %= b;
	}
	cout << sum << endl;
	return 0;
}