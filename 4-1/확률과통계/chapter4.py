from scipy.stats import binom

# 예제 7
# 매개변수 
n = 4 # 나무의 수
p = 0.3 # 병충해에 걸릴 확률

# 확률 계산
probabilities = binom.pmf(range(n+1), n, p)


# 예제 8
prob_1_or_less = probabilities[0] + probabilities[1]
prob_2_or_more = probabilities[2] + probabilities[3] + probabilities[4]
prob_1_to_2 = probabilities[1] + probabilities[2]

# 결과 출력
print('P(X <= 1) = {:.4f}'.format(prob_1_or_less))
print('P(X >= 2) = {:.4f}'.format(prob_2_or_more))
print('P(1 <= X <= 2) = {:.4f}'.format(prob_1_to_2))