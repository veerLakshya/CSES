n,q = map(int,input().split())
arr = list(map(int,input().split()))

pref = [0]*(n+1)
for i in range(n):
    pref[i+1] = pref[i]+arr[i]
for i in range(q):
    l,r = [int(e) for e in input().split()]
    print(pref[r]-pref[l-1])