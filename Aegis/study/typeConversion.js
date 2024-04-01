// 형변환
// 문자열과 더하면 무조건 문자열이 됨
console.log("1" + 10);
console.log("1" + true);
console.log("1" + undefined);
console.log("1" + null);
console.log("1" + {});

// "" 로 감싸져있는 숫자에 연산자(+ , -)를 붙이면 숫자가 됨
console.log(+"1");
console.log(-"1");
console.log("1" + 10);
console.log(+"1" + 10);

// 불리언 변환 (아래 5가지는 다 false)
console.log(Boolean(0));
console.log(Boolean(""));
console.log(Boolean(null));
console.log(Boolean(undefined));
console.log(Boolean(NaN));
