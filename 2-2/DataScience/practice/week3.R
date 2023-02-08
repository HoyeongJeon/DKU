# week Three R Time

#game 3 : RSP Game (Game project #1)


customer <- c('kim', 'lee', 'park', 'choi', 'seo')
deposit <- c(5000000,4500000,4000000,5500000,6000000)
rate <- c(3.5,3,4,5,4.5)
period <- c(2,2,5,7,4)

names(deposit) <- customer
names(rate) <- customer
names(period) <- customer

who <- 'kim'

for(who in 1:length(customer)){
  sum <- deposit[who]*(1+rate[who]/100)^period[who]
  print(sum)
}

#built-in function

factorial(5) 
abs(-3)
log(16,2)
cowsay::say("function is fun", "random")

scores <- c(80,95,74,83,60,98,81,77,79,94)
mean(scores)
sqrt(var(scores))
sorted_scores <- sort(scores, TRUE)
hist(scores)

#Paste()
y <- 2021
m <- 1:12
yr_mt <- paste(y,m, sep='/')
yr_mt

str <- paste('good','morning',sep = ' / ')
str

scores <- c(80,95,74,83,60,98,81,77,79,94)
sum(scores)
my_sum <- function(data){
  result = 0
  for(i in 1:length(data)){
    result=result+data[i]
  }
  return(result)
}


scores <- c(80,95,74,83,60,98,81,77,79,94)
my_mean <- function(data){
  result = 0
  for(i in 1:length(data)){
    result=result+data[i]
  }

  return(round(result/length(data),precision))
}

print(my_mean(scores))

library(ggplot2)
tdata <- 
  read.csv("/Users/hoyoungjeon/Desktop/한국도로공사_교통사고통계_20201231.csv",, header = T, fileEncoding = "euc-kr")
class(tdata)
View(tdata)

ggplot(data=tdata, aes(Year)) +
  geom_point(aes(x = Year, y=Accidents,colour = "Accidents")) + geom_point(aes(x = Year, y=Deaths,colour = "Deaths"))+ geom_point(aes(x = Year, y=Injuries,colour = "Injuries"))