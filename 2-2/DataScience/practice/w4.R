numbers  <- floor(runif(10, 0, 100))

my_min <- function(data) {
  min = 101
  for(i in data) {
    if(i < min)
    {
      min <- i
    }
  }
  return (min)
}
print(numbers)
print(my_min(numbers))

rnsum <- function(n) {
  if(n <= 1) return (n)
  else return (n + rnsum(n - 1))
}