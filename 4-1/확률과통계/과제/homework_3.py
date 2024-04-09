from math import comb
from scipy.stats import binom


n = 5 # 시도 횟수
p = 0.1 # 불량품 확률

# 1.1

P1 = comb(n, 2) * (p**2) * ((1-p)**(n-2))
print("불량품이 2개 들어 있을 확률 : ", P1)

# 1.2

P2 = 1 - binom.pmf(0,n,p)
print("적어도 1개 이상의 불량품이 들어 있을 확률 : ", P2)

# 2.1

P2_1 = (39/52) * (38/51) * (37/50) * (36/49) 
print("4장 모두 다른 무늬일 확률 : ", P2_1)

# 2.2

P_red_3 = comb(26, 3) * comb(26, 0) / comb(52, 3)
P_red_2_black_1 = comb(26, 2) * comb(26, 1) / comb(52, 3)
print(P_red_3 + P_red_2_black_1)