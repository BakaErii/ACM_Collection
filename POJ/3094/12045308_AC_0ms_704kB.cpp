/**
 * @authors	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2017-12-22 17:42:58
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

int main(void) {
	int i, len, sum;
	char ch[256];
	while (gets(ch)) {
		sum = 0;
		len = strlen(ch);
		if (len == 1 && ch[0] == '#')
			return 0;
		for (i = 0; i < len; i++)
			if (ch[i] != ' ')
				sum += (i + 1) * (ch[i] - 'A' + 1);
		cout << sum << endl;
	}
	return 0;
}