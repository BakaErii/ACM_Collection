/**
 * @author	Moe_Sakiya    	sakiya@tun.moe
 * @date	2018-05-29 17:59:21
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

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int i, n, cnt0, cnt1;
    string str;
    cin >> n;
    cin >> str;
    cnt0 = cnt1 = 0;
    if(str == "0")
    {
        printf("No\n");
        return 0;
    }
    for(i = 0; i < n; i++)
    {
        if(str[i] == '1')
        {
            cnt1++;
            cnt0 = 0;
        }
        else
        {
            cnt0++;
            cnt1 = 0;
        }
        if(cnt1 == 2)
        {
            printf("No\n");
            return 0;
        }
        if(cnt0 == 3)
        {
            printf("No\n");
            return 0;
        }
    }
    if(n >= 2 && str[0] == '0' && str[1] == '0')
    {
        printf("No\n");
        return 0;
    }
    if(n >= 2 && str[n - 1] == '0' && str[n - 2] == '0')
    {
        printf("No\n");
        return 0;
    }
    printf("Yes\n");
    return 0;
}