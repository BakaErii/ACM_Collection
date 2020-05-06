/**
 * @author  Moe_Sakiya	sakiya@tun.moe
 * @date    2019-08-07 14:46:02
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

int x;
string str;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	scanf("%d", &x);
	for (int i = 0; i <= 10; i++) {
		str = "";
		int tmp = x;
		while (tmp > 0) {
			str.push_back((tmp % 10) + '0');
			tmp /= 10;
		}
		for (int j = 0; j < i; j++)
			str.push_back('0');
		string strA = "";
		strA = str;
		reverse(str.begin(),str.end());
		if (str == strA) {
			printf("YES\n");
			return 0;
		}
	}
	printf("NO\n");
	return 0;
}