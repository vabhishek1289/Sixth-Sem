def check(s,f,b):
	n = len(s)
	a = []
	a.append(b[0])
	k = 1
	for i in range(2,n):
		if s[i] >= f[k] :
			a.append(b[i])
			k = i

	print a
			

	

print "Enter Number of elements"
n = input()
s = []
f = []
k = []
for i in range(0,n):
	x,y =  [int(x) for x in raw_input().strip().split()]
	s.append(x)
	f.append(y)
	k.append([x,y])

#print s
#print f
print k
f.sort()
check(s,f,k)


	
