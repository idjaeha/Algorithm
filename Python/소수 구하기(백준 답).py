def eratos(m:int, n:int) -> [int]: 
  seive = [False, False] + [True] * (n - 1)
  for k in range(2, int(n ** 0.5 + 1.5)):
    if seive[k]:
      seive[k*2::k] = [False] * ((n - k) // k)
  return [x for x in range(m, n+1) if seive[x]]
M, N = map(int, input().split())

l = eratos(M, N)

for i in l:
  print(i)