/**
 * @author	Moe_Sakiya    	sakiya@tun.moe
 * @date	2018-06-06 13:00:49
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

map<string, string> mp;
string str;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    mp.insert(make_pair("purple", "Power"));
    mp.insert(make_pair("green", "Time"));
    mp.insert(make_pair("blue", "Space"));
    mp.insert(make_pair("orange", "Soul"));
    mp.insert(make_pair("red", "Reality"));
    mp.insert(make_pair("yellow", "Mind"));
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> str;
        mp.erase(str);
    }
    cout << mp.size() << endl;
    for(auto i : mp)
        cout << i.second << endl;
    return 0;
}