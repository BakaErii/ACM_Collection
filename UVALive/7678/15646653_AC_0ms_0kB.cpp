/**
 * @author  Moe_Sakiya	sakiya@tun.moe
 * @date    2018-08-23 17:58:36
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

long long int tab[84] = {1, 199981, 199982, 199983, 199984, 199985, 199986, 199987, 199988, 199989, 199990, 200000, 200001, 1599981, 1599982, 1599983, 1599984, 1599985, 1599986, 1599987, 1599988, 1599989, 1599990, 2600000, 2600001, 13199998, 35000000, 35000001, 35199981, 35199982, 35199983, 35199984, 35199985, 35199986, 35199987, 35199988, 35199989, 35199990, 35200000, 35200001, 117463825, 500000000, 500000001, 500199981, 500199982, 500199983, 500199984, 500199985, 500199986, 500199987, 500199988, 500199989, 500199990, 500200000, 500200001, 501599981, 501599982, 501599983, 501599984, 501599985, 501599986, 501599987, 501599988, 501599989, 501599990, 502600000, 502600001, 513199998, 535000000, 535000001, 535199981, 535199982, 535199983, 535199984, 535199985, 535199986, 535199987, 535199988, 535199989, 535199990, 535200000, 535200001, 1111111110};
string str;
long long int tmp;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	while (cin >> str) {
		tmp = 0;
		if ((int)str.length() > 10) {
			printf("83 1111111110\n");
			continue;
		}
		for (int i = 0; i < (int)str.length(); i++) {
			tmp = tmp * 10 + (str[i] - '0');
		}
		// cout << tmp << endl;
		int i;
		for (i = 0; i < 83; i++)
			if (tmp < tab[i])
				break;
		printf("%d %lld\n", i, tab[i - 1] );
	}
	return 0;
}