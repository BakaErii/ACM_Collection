/**
 * @author  Moe_Sakiya	sakiya@tun.moe
 * @date    2018-10-09 14:35:38
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

int len;
string strAns, strTmp;
string strA, strB, str;
set<string> st;

int solve() {
	int ret = 1;
	st.clear();
	str.clear();
	for (int i = 0; i < len; i++) {
		str.push_back(strB[i]);
		str.push_back(strA[i]);
	}
	st.insert(str);
	while (str != strAns) {
		strTmp = str;
		str.clear();
		for (int i = 0; i < len; i++) {
			str.push_back(strTmp[i + len]);
			str.push_back(strTmp[i]);
		}
		if (st.count(str) == 1)
			return -1;
		else
			st.insert(str);
		ret++;
	}
	return ret;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		cin >> len >> strA >> strB >> strAns;
		cout << i << " " << solve() << endl;
	}
	return 0;
}
