/**
 * 데이터 타입
 * 숫자, 문자열, 불리언, 배열, 객체, 함수, undefined, null
 */

// 숫자
// 정수, 실수, 지수, NaN(Not a Number), Infinity
let num1 = 10;
console.log("num1: ", num1);
console.log("num1 type: ", typeof num1);

let num2 = 10.5;
console.log("num2: ", num2);
console.log("num2 type: ", typeof num2);

let num3 = 1e3; // 1 * 10^3
console.log("num3: ", num3);
console.log("num3 type: ", typeof num3);

let num4 = 0 / 0;
console.log("num4: ", num4);
console.log("num4 type: ", typeof num4);

let num5 = 10 / 0;
console.log("num5: ", num5);
console.log("num5 type: ", typeof num5);

let num6 = -10 / 0;
console.log("num6: ", num6);
console.log("num6 type: ", typeof num6);

// 문자열
let name = "전호영";
let message = "Hello World!";

console.log("name: ", name);
console.log("name type: ", typeof name);
console.log("message: ", message);
console.log("message type: ", typeof message);
console.log("message length: ", message.length);

// 불리언
let isTrue = true;
let isFalse = false;
console.log("isTrue: ", isTrue);
console.log("isTrue type: ", typeof isTrue);
console.log("isFalse: ", isFalse);
console.log("isFalse type: ", typeof isFalse);

// undefined
// 값이 할당되지 않은 변수를 의미
let x;
console.log("x: ", x);
console.log("x type: ", typeof x);

// null
// 값이 없음을 의미
let y = null;
console.log("y: ", y);
console.log("y type: ", typeof y);

// 객체
// 속성과 메소드를 가지고 있는 데이터 타입
let person = {
  name: "전호영",
  age: 27,
  address: "서울",
};
console.log("person: ", person);
console.log("person name: ", person.name);
console.log("person age: ", person.age);
console.log("person address: ", person.address);
console.log("person type: ", typeof person);

// 배열
let fruits = ["apple", "banana", "cherry"];
console.log("fruits: ", fruits);
console.log("fruits type: ", typeof fruits);
console.log("fruits length: ", fruits.length);
