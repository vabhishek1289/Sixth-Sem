res=[]
for i in range(int(raw_input())):    
    A,N,M=map(str,raw_input().split())
    A=str(A)
    N=int(N)
    M=int(M)
    res.append((int(A*N))%M)
for i in res:
    print i
