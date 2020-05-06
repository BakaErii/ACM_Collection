/**
 * @author	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2017-12-26 19:49:41
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

int t, m, pv;

set<int> flag;

//mp[0]为0空闲 为1使用 mp[1]存放标识 0为空闲
int mp[100][2];

/*
	申请内存
		int byte:欲分配的内存空间
	成功返回对应的标识 失败返回-1
*/
int m_alloc(int byte) {
	int i, j,  ptr;
	ptr = 0;
	for (i = 0; i < m; i++) {
		if (mp[i][0] == 0)
			ptr++;
		else
			ptr = 0;
		if (ptr == byte) {
			//分配成功 获取标识
			flag.insert(pv);
			j = pv++;
			while (ptr--) {
				mp[i - ptr][0] = 1;
				mp[i - ptr][1] = j;
			}
			return j;
		}
	}
	return -1;
}

/*
	释放内存
		int var:欲释放内存空间的标识
	成功返回true 否则false
*/
bool m_erase(int var) {
	if (flag.count(var) == 0)
		return false;
	flag.erase(var);
	for (int i = 0; i < m; i++)
		if (mp[i][1] == var) {
			mp[i][0] = 0;
			mp[i][1] = 0;
		}
	return true;
}

/*
	整理内存
*/
void m_defragment(void) {
	int sptr, i, tmps1, tmps2;
	sptr = 0;
	for (i = 0; i < m; i++ ) {
		if (mp[i][0] == 1) {
			tmps1 = mp[i][0];
			tmps2 = mp[i][1];
			mp[i][0] = 0;
			mp[i][1] = 0;
			mp[sptr][0] = tmps1;
			mp[sptr++][1] = tmps2;
		}
	}
	return;
}

int main(void) {
	string command;
	int var, reget;
	pv = 1;
	cin >> t >> m;
	//对m进行初始化
	for (int i = 0; i < m; i++) {
		mp[i][0] = 0;
		mp[i][1] = 0;
	}
	while (t--) {
		cin >> command;
		if (command == "alloc") {
			cin >> var;
			reget = m_alloc(var);
			if ( reget == -1)
				cout << "NULL" << endl;
			else
				cout << reget << endl;
		} else if (command == "erase") {
			cin >> var;
			if (m_erase(var) == false)
				cout << "ILLEGAL_ERASE_ARGUMENT" << endl;
		} else {
			m_defragment();
		}
	}
	return 0;
}