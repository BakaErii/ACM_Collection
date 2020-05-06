#
# @author	Moe_Sakiya    	sakiya@tun.moe
# @date    	2018-02-21 00:16:32
#

a, b = map(int, input().split())

if b == 0:
        print("No")
        exit(0)

if b == 1:
        if a == 0:
                print("Yes")
        else:
                print("No")
        exit(0)

if a >= b-1 and (a-b+1) % 2 == 0:
        print("Yes")
else:
        print("No")