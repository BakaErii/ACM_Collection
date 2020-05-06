/**
 * @author	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2018-03-11 16:37:43
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
	string str;
	stack<char> st;
	bool isFirst;
	int t, n, i, cnt, tmp;
	cin >> t;
	while (t--) {
		//init
		cnt = 0;
		str.clear();
		isFirst = true;
		cin >> n;
		for (i = 0; i < n; i++) {
			cin >> tmp;
			while (tmp > cnt) {
				str.push_back('(');
				cnt++;
			}
			str.push_back(')');
		}
		//cout << str << endl;
		for (i = 0; i < (int)str.length(); i++) {
			cnt = 0;
			if (str[i] == ')') {
				while (!st.empty())
					st.pop();
				st.push(')');
				tmp = i - 1;
				while (!st.empty() && tmp >= 0) {
					if (st.top() == ')' && str[tmp] == '(') {
						st.pop();
						cnt++;
					}
					else
						st.push(str[tmp]);
					tmp--;
				}
			}
			if (cnt != 0 && isFirst == false)
				printf(" ");
			if (cnt != 0) {
				printf("%d", cnt );
				isFirst = false;
			}
		}
		putchar('\n');
	}
	return 0;
}