#Basic Operations
2**8
4+2
2**10
2**40
s="hello world!"
print(s)
2**40 # automatic type casting
round(11/3,1) # arguments: input
floor(11/3) #내림
ceiling(11/3)#올림
19%%5

#swapping a, b
a <- 1 #R에선 화살표로 변수 할당
b <- 2
temp <- a
a <- b
b <- temp
print(a)
print

#package
install.packages('ggplot2')
library(ggplot2)
ggplot(data=iris,aes(x=Petal.Length,y=Petal.Width))+geom_point()

# a fun package
install.packages('cowsay')
library(cowsay)
"hello world"
cowsay::say("was geht?", "cat")

#Game1: Odd/Even verifier
num <- floor(runif(1, 1, 100)) #3개 매개변수 (몇개, 최소, 최대) 랜덤숫자 출력
cat("num:",num) #print 역할

if(num%%2==0) {
  print("짝수")
} else {
  print("홀수")
}

for(i in c(1:100)) { # c(1:10) -> 1~10까지
  num <- floor(runif(1, 1, 100)) #3개 매개변수 (몇개, 최소, 최대) 랜덤숫자 출력
  cat("num:",num) #print 역할
  
  if(num%%2==0) {
    print("짝수")
  } else {
    print("홀수")
  }
}

i = 1
while(TRUE) {
  num <- floor(runif(1, 1, 100)) #3개 매개변수 (몇개, 최소, 최대) 랜덤숫자 출력
  cat("num:",num) #print 역할
  
  if(num%%2==0) {
    print("짝수")
  } else {
    print("홀수")
  }
  
  i = i+1
  if(i > 10) break;
}


#game 2 odd/even verifier2
num <- floor(runif(1, 1, 100))
choice=readline(propmt="choose:odd/even:")
cat("num",num, "choice",choice)

mod_num <- floor(num%%2)
if(mod_num==1 && choice=="odd") {
  print("Yeah :) ")
} else if(mod_num==0 && choice=="even") {
  print("Yeah :)")
} else print("sorry :(")

# self-game projects: #1. 가위바위보

# precision in R
.Machine$integer.max
log(.Machine$integer.max,2)
.Machine$integer.max+1L
