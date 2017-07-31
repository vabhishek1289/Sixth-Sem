T=int(raw_input())
for j in xrange (T):
    s = raw_input()
    count = 0
    for i in xrange (1, len(s)-1):
        if (s[i-1] == "<" and s[i] == ">"):
            count += 1
            i += 1
    print count
