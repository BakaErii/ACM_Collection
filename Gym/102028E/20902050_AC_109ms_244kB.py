#
# @author	Moe_Sakiya	sakiya@tun.moe
# @date		2019-07-30 11:35:44
#
#!/usr/bin/python
# -*- coding: UTF-8 -*-

import math

maxN = 5005

def GCD(a,b):
	if b>0:
		return GCD(b,a%b)
	return a

def Prime():
	isPrime = [True]*maxN
	prime = []
	for i in range(2,maxN):
		if isPrime[i]:
			prime.append(i)
			for j in range(i*i,maxN,i):
				isPrime[j] = False
	return prime

# Main

arrPrime = Prime()
t = int(input())

while t:
	n = int(input())
	tot = 1
	mom = 1
	mem = 1
	for prime in arrPrime:
		 tot*=prime
		 if tot>n:
		 	break
		 mom*=prime+1
		 mem*=prime
	gcdNum = GCD(mem,mom)
	mem//=gcdNum
	mom//=gcdNum
	print(str(mem)+'/'+str(mom))
	t-=1