n,m,q = map(int,input().split())

a = [0] * q
b = [0] * q
c = [0] * q
d = [0] * q

for i in range(q):
    a[i],b[i],c[i],d[i] = map(int,input().split())
    a[i] -= 1
    b[i] -= 1
    
def solve(x):
    res = 0
    
    if len(x) == n:
        for i in range(q):
            if x[b[i]] - x[a[i]] == c[i]:
                res += d[i]
        return res
    
    if len(x) == 0:
        bef = 1
    else:
        bef = x[-1]
        
    for i in range(bef,m+1):
        res = max(res,solve(x + [i]))
        
    return res

print(solve([]))