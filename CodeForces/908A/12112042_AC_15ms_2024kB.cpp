#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    string str;
    int ans=0;
    cin>>str;
    for(int i=0; i<(int)str.length(); i++)
        switch(str[i])
        {
        case '1':
        case '3':
        case '5':
        case '7':
        case '9':
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
            ans++;
            break;
        }
        cout<<ans<<endl;
    return 0;
}