/**
 * @author	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2018-01-31 22:32:28
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
	string ansstr, constr, tmpstr, tmpansstr;
	int n, m;
	int i, j, k, l;
	bool isSolve, isChanged;
	cin >> n;
	while (n--) {
		cin >> m;
		ansstr.clear();
		isSolve = true;
		for (i = 0; i < m; i++) {
			if (i == 0) {
				cin >> ansstr;
				continue;
			}
			cin >> constr;
			isChanged = false;
			for (j = 60; j >= 3; j--)
				for (k = 0; k <= 60 - j; k++) {
					tmpstr = constr.substr(k, j);
					if (ansstr.find(tmpstr) != ansstr.npos && isChanged == false) {
						isChanged = true;
						tmpansstr = tmpstr;
					}
					if (ansstr.find(tmpstr) != ansstr.npos && isChanged == true) {
						if (tmpansstr.length() == tmpstr.length()) {
							for (l = 0; l < (int)tmpstr.length(); l++)
								if (tmpansstr[l] > tmpstr[l]) {
									tmpansstr = tmpstr;
									break;
								} else if (tmpansstr[l] < tmpstr[l])
									break;
						}
					}
				}
			if (isChanged == false) {
				isSolve = false;
			} else {
				ansstr = tmpansstr;
			}
		}
		if (isSolve == true)
			cout << ansstr << endl;
		else
			cout << "no significant commonalities" << endl;
	}
	return 0;
}