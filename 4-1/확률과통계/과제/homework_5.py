from scipy.stats import binom

n = 150
p = 0.6
k = 78

prob = binom.cdf(k, n, p)
print(prob)