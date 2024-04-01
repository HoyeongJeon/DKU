/**
 * 연산자
 */

// 1. 산술 연산자
console.log(1 + 2);
console.log(1 - 2);
console.log(1 * 2);
console.log(1 / 2);
console.log(5 % 2);
console.log(2 ** 3); // 제곱 2^3

// 2. 할당 연산자
let a = 1;
a += 1; // a = a + 1;
console.log("a: ", a);

a -= 1;
console.log("a: ", a);

a *= 5;
console.log("a: ", a);

a /= 2;
console.log("a: ", a);

a %= 2;
console.log("a: ", a);

// 3. 일치 연산자 (=== , !==) 이거 사용하기!!
console.log(1 == 1); // true
console.log(1 == "1"); // true
console.log(1 === 1); // true
console.log(1 === "1"); // false

// 4. 타입 연산자
// typeof => 데이터 타입을 반환
console.log(typeof 1); // number
console.log(typeof "1"); // string
