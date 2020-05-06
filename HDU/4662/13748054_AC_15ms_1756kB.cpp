/**
 * @author	Moe_Sakiya    	sakiya@tun.moe
 * @date	2018-05-01 17:35:02
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
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t, len, cntM, cntI, cntU;
	string str;
	cin >> t;
	while(t--) {
		cin >> str;
		//init
		cntM = cntI = cntU = 0;
		len = str.length();
		for(int i = 0; i < len; i++)
			switch(str[i]) {
			case 'M':
				cntM++;
				break;
			case 'I':
				cntI++;
				break;
			case 'U':
				cntU++;
				break;
			}
		//check
		if(cntM != 1 || (cntI == 0 && cntU == 0) || str[0] != 'M') {
			printf("No\n");
			continue;
		}
		//solve
		if(((cntU * 3 + cntI) % 2 == 0 && (cntU * 3 + cntI) % 3 != 0)  || cntU * 3 + cntI == 1)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}