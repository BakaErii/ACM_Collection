/**
 * @author	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2018-02-06 23:34:52
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

stack<bool> val;
stack<char> op;

string str;

bool calBoolean(void) {
	bool tmp, tmpper, check;
	char ope;
	op.pop();
	check = true;
	while (op.top() == '!') {
		op.pop();
		check = !check;
	}
	if (op.top() == '(')
		tmp = calBoolean();
	else {
		tmp = val.top();
		val.pop();
	}
	if (check == false)
		tmp = !tmp;
	while (op.top() != ')') {
		ope = op.top();
		op.pop();
		check = true;
		while (op.top() == '!') {
			op.pop();
			check = !check;
		}
		if (op.top() == '(')
			tmpper = calBoolean();
		else {
			tmpper = val.top();
			val.pop();
		}
		if (check == false)
			tmpper = !tmpper;
		if (ope == '&')
			tmp = tmp && tmpper;
		else
			tmp = tmp || tmpper;
	}
	op.pop();
	return tmp;
}

int main(void) {
	int i, len, kase;
	bool ans;
	ans = true;
	//init
	kase = 0;
	while (getline(cin, str)) {
		//case init
		len = str.length();
		op.push(')');
		for (i = len - 1; i >= 0; i--)
			if (str[i] != ' ') {
				if (str[i] == 'V')
					val.push(true);
				else if (str[i] == 'F')
					val.push(false);
				else
					op.push(str[i]);
			}
		op.push('(');
		ans = calBoolean();
		printf("Expression %d: %c\n", ++kase, ans ? 'V' : 'F' );
	}
	return 0;
}