n = 100
dp = [0 for i in range(n+1)]
dp[0] = 1
dp[1] = 1
for i in range(2,n):
	dp[i]= dp[i-1] + dp[i-2]
	print(dp[i])