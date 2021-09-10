num <- floor(runif(1, 1, 100))
choice=readline(prompt="choose:odd/even:")
cat("num",num, "choice",choice)

mod_num <- floor(num%%2)
if(mod_num==1 && choice=="odd") {
  print("Yeah :) ")
} else if(mod_num==0 && choice=="even") {
  print("Yeah :)")
} else print("sorry :(")

