n = 100 * 1000 * 1000
scores <- floor(rnorm(n, mean = 80, sd = 15))

hist(scores)
mean(scores)
sd(scores)
