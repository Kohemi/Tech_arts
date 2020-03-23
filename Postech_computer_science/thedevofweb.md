# The Dev of Web

## HTML

```html
<!DOCTYPE html>
```

* 문서 형식이 html 임을 알림

```
<html> 
</html>
```

* 문서 전체를 감싸며, root element라고도 함

```
<head>
</head>
```

* 키워드, 검색 결과, 문서 집합 선언 등을 표현 

```
<body>
```

* 브라우저에 포함될 모든 요소를 가지고 있음

### 이미지

* alt 속성은 이미지를 볼 수 없는 사람을 위한 이름 지정 가능

### 텍스트 

```
<p>
</p>
```

* 문단을 표현하기 위한 요소

```
<ul>
</ul>
```

* Unorderd list

```
<ol>
</ol>
```

* Orederd list

```
<li>
</li>
```

* List item

## CSS

* Cascade Style Sheets

### 선택자

```
Selector {
           Property: Propertyvalue; //Declaration
}

ex)

p {
	color: red;
	width: 500px;
	border: 1px solid black;
}

p, li, h1{		//여러 셀렉터 동시 사용 가능
	color: red;
}

```

| 선택자 종류        | 설명                                                         | 예시                                                         |
| ------------------ | ------------------------------------------------------------ | ------------------------------------------------------------ |
| 요소 선택자        | 특정 타입의 HTML 요소                                        | p <br><p>를 선택                                             |
| 아이디 선택자      | 특정 아이디를 가진 요소<br>아이디당 하나의 요소만 선택       | #eid<br><p id ="eid"> 또는<br><a id="eid"> 를 선택           |
| 클래스 선택자      | 특정 클래스를 가진 요소<br>해당 클래스 속성을 가진 모든 요소가 선택. | .my-class<br><p class="my-class">와<br><a class="my-class">를 선택 |
| 속성 선택자        | 특정 속성을 갖는 요소                                        | img[src]<br><img src="image.png"> 선택                       |
| 가상 클래스 선택자 | 특정 상태에 있는 요소<br>:link, :visited, :hover, :active    | a:hover<br>마우스 포인터가 <a>요소 위에 있을 때 선택         |

### 박스 모델

* padding
* border
* margin

```html
body {
	margin: 0 auto;
	bacground-color : #ff9500;
	padding 0 20px 20px 20px;
	border: 5px solid black;
}
```

* auto는 왼쪽과 오른쪽의 수평을 균등 분할하는 특별한 값 

### 참고사이트

* 실습 소스 : https://github.com/then0524/theun0525.github.io/tree/chapter-2
* HTML : https://developer.mozila.org/ko/docs/Learn/HTML
* CSS : https://developer.moizila.org/ko/docs/Learn/CSS
* Selector :https://developer.moizila.org/ko/docs/Learn/CSS/Introduction_to_CSS/Selectors
* Flexbox : https://developer.mozila.org/ko/docs/Learn/CSS/CSS_layout/Flexbox

## JAVASCRIPT

### 어떤 일을 할 수 있나?

* 변수에 값 저장, 문자열 결합

```javascript
let name = prompt('enter a new name');
para.textContent ='player 1:' + name;
```

* 웹 페이지 상의 이벤트에 따라 응답하는 기능

```javascript
para.addEventListener('click', updateName);
function updateName(){
	let name = prompt('Enter a new name');
	para.textContent = 'Player 1:' + name;
}
```

* 자바스크립트 기반 API를 통한 기능 확장 

* 써드파티 API
  * 브라우저에 내장된 것이 아닌 인터넷에서 개인적으로 정보와 코드를 얻어 이용하는 것
  * Twitter API
  * Google Maps API

### 웹페이지와 자바스크립트

* 브라우저 보안성 : 브라우저 탭
* 실행 순서 : 위에서 아래로
* 인터프리터(Interpreter)와 컴파일러(Compiler) : 인터프리터(Interpreter)
  * 코드가 위에서 아래로 수행되고 그 즉시 실행
* 서버측 코드와 클라이언트측 코드, 동적이라는 것은 서버측과 클라이언트측 동시에 이용가능.

### 예문

자바스크립트 호출

```javascript
<!DOCTYPE html>
<html lang="en-US">
  <head>
    <meta charset="utf-8">
    <title>Apply JavaScript example</title>
  </head>
  <body>
    <button>Click me</button>
    <script src = "script.js"></script>
  </body>
</html>
```

script.js 내부

```
function createParagraph(){
  var par = document.createElement('p');
  para.textContent = 'You clicked the button';
  document.body.appendChild(para);
  }

  var buttons = document.querySelectorAll('button');
  for (var i = 0; i < buttons.length; i++) {
    buttons[i].addEventListener('click', createParagraph);
  }
```



### 주석

```javascript
//I am a comment a paragraph

/*
I am also 
a comment paragraphs
*/
```

### 문제해결

#### 에러의 종류

1. 문법 에러
   * 자바스크립트 문법이 잘못된 경우 => 개발자 도구 콘솔 탭에서 확인

2. 논리 에러
   * 코드의 논리가 잘못된 경우 => 코드 분석을 통해 확인

### 변수

#### 동적 자료형

변수에 포함된 데이터 유형을 지정할 필요가 없음. 

#### 숫자와 연산자

##### 숫자의 종류 

* 십진수(decimal) : 0~9까지만 사용하여 숫자를 표현
  * 정수(integer) : 10, 400, -5
  * 부동소수점(float) : 소수점 이하 6자리 까지 정밀도
  * 배정도 부동소수점(double) : 소수점 이하 15자리까지 정밀도
* 이진수(binary) : 0과 1만 사용하여 숫자를 표현
* 8진수(octal) : 0~7까지만 사용하여 숫자를 표현
* 16진수(hexadecimal) : 0 ~9, a~f까지 사용하여 숫자를 표현. CSS 색상 표현시 사용

#### 연산자 우선순위

* 학교 수학 시간에 배운 것과 같음

#### 증감연산자

* 반복문에서 주로 사용
* 오직 변수에만 사용 가능

#### 대입연산자

#### 비교연산자

* 값의 동일성 테스트
  * == / != : 값만 비교
  * === / !== : 값과 자료형도 비교.(오류를 줄이기 위해 주로 사용)
* 논리값 참 또는 거짓을 반환
* false, undefined, null, 0, NaN, 빈문자열 : 거짓
* 그 외의 값 : 참

#### 문자열 

* 이스케이프(escape) 문자 : (back slash)
  * 문자를 코드가 아닌 문자로 인식되도록 함.

```javascript
var bigmouth = 'I\'ve got no right to take my place...';
bigmouth
```

* 자바스크립트의 모든 것은 객체(object)
* string 변수가 문자열 객체의 인스턴스(instance)
* 문자열 객체의 속성(property) 및 메서드(method) 사용 가능
* length :  문자열 길이

```
var x = 'browsertype'
x.length;
```

* indexOf() : 부분 문자열 검색

  * 찾을 부분 문자열을 매개변수(parameter)로 전달
  * 찾은 부분 문자열 시작 위치를 반환하거나 -1값 반환.

  * 문자열을 필터링하는데 사용

  * 문자열이 하위 문자열을 포함하고 있지 않은 경우 -1값 반환.

* Slice() : 부분 문자열 추출

  * 추출할 시작 위치와 끝 위치를 매개변수로 전달.
  * 추출한 부분 문자열을 반환.
  * 끝위치가 생략되면 문자열 끝까지 추출함. 

* toUpperCase() : 문자열을 대문자로 변환

* toLowerCase() : 문자열을 소문자로 변환

* replace() : 부분 문자열 교체

  * 교체할 문자열과 새로운 문자열을 매개변수로 전달

#### 배열(Array)

* 목록과 유사한 객체
* 목록에 저장된 여러 값들을 포함할 수 있는 단일 객체
* 목록 내부 값에 개별적으로 접근 가능
* 반복문을 통해 효율적인 작업이 가능
* 대괄호 내에 쉼표로 구분된 항목을 나열하여 표현
* 대괄호 표기법 : 대괄호 내 개별 항목 접근 가능
* length : 배열 길이
* <string>.split() : 문자열을 배열로 변환
  * 구분 문자를 매개변수로 전달
* <array>.join() : 배열을 문자열로 변환
  * 구분문자를 매개변수로 전달
* <array>.toString() : 배열을 쉼표로 구분된 문자열로 변환
* push() : 배열 끝에 항목 추가
  * 배열 길이를 반환
* pop() : 배열 끝의 항목 제거
  * 제거된 항목을 반환

* unshift() : 배열 시작에 항목 추가
  * 배열 길이를 반환
* shift() : 배열 시작에 항목 제거
  * 제거된 항목을 반환

### 조건문

```javascript
//기본 형태의 조건문 
if(condition) {
	code to run if condition is true
} else {
	run some other code instead
}

//else가 없는 형태
if(condition) {
	code to run if condition is true
}

run some other code instead

//{}가 없는 형태, 추천하지 않음
if(condition) code to run if condition is true
else run some other code instead
```

#### If … else 문

#### else if 문 

* 더 많은 선택을 정할 수 있음 
* 중첩 가능

```javascript
// nesting if ... else
if (choice === 'sunny') {
    if (temperature < 86) {
        para.textContent = '날씨가 화창합니다.';
    } else if (temperature >= 86) {
        para.textContent = '외출하실 때 썬크림을 바르세요.'
    }
}
```

#### 논리연산자

```javascript
// logical operator : AND - AND 연산자. 좌항과 우항이 모두 참인 경우만 참
if (choice === 'sunny' && temperature < 86) {
        para.textContent = '날씨가 화창합니다.';
    } else if (choice === 'sunny' && temperature >= 86) {
        para.textContent = '외출하실 때 썬크림을 바르세요.'
    }

//|| - OR 연산자. 좌항 또는 우항이 참이면 참
if(iceCreamVanOutside || houseStatus === 'on fire') {
    console.log('집에서 빨리 나오세요.');
} else {
    console.log('그냥 집에 계세요.')
}

//! - NOT 연산자. 논리값을 역전시킴
if(!(iceCreamVanOutside || houseStatus === 'on fire')){
    console.log('그냥 집에 계세요.')
} else {
    console.log('집에서 빨리 나오세요.')
}

// combine logical operator
if ((x === 5 || y > 3 || z <= 10) && (loggedIN || userName ==='Steve')) {
    //run the code
}

// incorrect logical operator
if (x ===5 || 7 || 10 || 20) {
    // run the code
}

// correct logical operator
if (x === 5 || x === 7 || x === 10 || x === 20) {
    // run the code
}
```

#### swith 문

* 많은 선택 구문이 있을 경우 유용

```javascript
switch(expression){
	case choice1:
	// run this code
	break;
	case choice2:
	// run this code instead
	break;
	
	//include as many cases as you like
	
	default:
	//actually, just run this code
}

// Previous weather message can be written like below
 function setWeather(){
     var choice = select.value;
     
     switch (choice){
         case 'sunny':
             para.textContent = 'It is nice and sunny outside today.';
             break;
         case 'rainy':
             para.textContent = 'Rain is falling outside.';
             break;
         case 'snowing':
             para.textContent = 'The snow is coming down = it is freezing!';
             break;
         case 'overcast':
             para.textContent = 'It isn\'t raining.';
             break;
         default:
             para.textContent = '';
            
     }
 }
```

#### 삼항연산자

```javascript
//
(condition) ? run this code : run this code instead

//
var greeting =(isBirthday) ? '.생일 축하합니다. 행복한 하루되세요!' : '좋은 아침입니다.'

//

```

### 반복문

![image-20200315224438879](\Images\image-20200315224438879.png)

#### loop

```javascript
loop(food = 0; foodNeeded = 10) {
if (food = foodNeeded) {
exit loop;//We have enough food; let's go home
} else {
food += 2; //Spend an hour collecting 2 more food 
// loop will then run again
}
}
```

* 동일한 작업을 빠르게 수행해 완료하는 것

```javascript
for(let i = 0; i < 100; i++){
    ctx.beginPath();
    ctx.fillStyle = 'rgba(255, 0, 0, 0.5)';
    ctx.arc(random(WIDTH), random(HEIGHT), random(50), 0, 2 * Math.PI);
    ctx.fill();
}
```

* ???

#### for 반복문

#### break로 반복문 종료하기

* break : 반복문을 종료하고 반복문 다음으로 이동 

#### continue로 반복문 건너뛰기

* continue : 반복문을 건너뛴다.

#### while 반복문

```javascript
// while loop
initializer
while (exist-condition) {
    //code to run
    
    final-expression
}
```

#### do...while반복문

```javascript
// do...while loop
initializer
do {
    // code to run
    
    final - expression
} while(exist-condition);
```

### 함수

#### 함수(function)의 개념

* 한가지 일을 수행하는 코드가 블록으로 묶여있는 것
* 함수 호출을 통해 반복 실행이 가능
* JavaScript를 위한 다양한 브라우저 내장 함수 제공
* method는 객체 내부에 정의된 함수

#### 사용자 정의 함수

* 사용자 코드 내에 정의되어 있는 함수 

#### 함수 호출

* 함수 이름 뒤에 괄호를 붙여서 호출

#### 익명 함수

* 함수 이름이 없는 함수 

#### 매개변수(parameters)

* 함수 괄호 안에 넣어서 전달하는 값들 

#### 유효범위(scope)

* 함수 유효범위
  * 함수를 정의하는 코드 블록 내부. 함수 유효범위 내에 정의된 변수는 해당 함수 내에서만 접근 가능
* 전역 유효범위
  * 모든 함수의 외부인 최상위 레벨. 전역 유효범위 내에 정의된 변수는 코드 어디서든 접근 가능.

#### 함수 쪼개기

```javascript
function myBigFunction() {
    var myValue = 1;
    
    subFunction1(myValue);
    subFunction2(myValue);
    subFucction3(myValue);
}

function subFunction1(value) {
    console.log(value);
}

function subFunction2(value){
    console.log(value);
}
function subFunction3(value){
    console.log(value);
}
```

#### 함수 만들기

* 함수 뒤에 괄호는 함수호출연산자라고 하며, 함수를 즉시 실행시킴.

#### 반환값

* 함수가 완료될 때 반환하는 값 
* return 키워드 사용하여 값을 반환함 

### 비동기 자바스크립트

#### 비동기 프로그래밍

* 동기 모델
  * 순차적으로 실행되며 어떤 작업이 수행 중이면 다음 작업은 대기함
* 비동기 모델
  * 작업이 종료되지 않은 상태라도 대기하지 않고 다음 작업을 실행함 

블로킹코드

* 제어권을 반환하지 않고 계속 실행하는 코드
* 사용자 입력 처리와 다른 수행이 차단됨 

스레드

* 프로그램이 작업을 완료하는데 사용할 수 있는 하나의 프로세스 
* 자바스크립트는 단일 스레드 : main thread

```
Task A --> Task B --> Task C

Thread 1 : Task A --> Task B
Thread 2 : Task C --> Task D

Main Thread : Render circles to canvas --> Display alert()

Main Thread : Task A --> Task C
Worker thread : Expensive task B
```

비동기 코드

* 웹 워커(web worker)
  * DOM 접근이 불가능하며 숫자 계산만 가능함.
  * 순차 실행만 가능

```
Main thread : Task A --> Task B
Main Thread : Task A --> Task B --> |Task D|
Worker thread : Task C -----------> |      |

Main thread : Task A                 Task B
	promis  : 	   |_async operation_|
```

동기식 자바스크립트

#### 비동기 자바스크립트 

* 비동기 콜백(callback)
* 프로미스(promise)

비동기 콜백

* 비동기 함수의 매개변수로 넘겨주는 함수
* 비동기 함수 실행 중이나 완료 후 호출되어 작업 진행 상황이나 완료 여부를 알려줌 

프라미스

* 비동기 작업의 완료 또는 실패를 나타내는 객체 

이벤트 큐

* 비동기 작업이 저장되는 공간
* 메인 스레드 처리 후 실행되는 큐 

프라미스의 장점

* 여러 개의 비동기 연산을 여러 개의 .then()메서드로 연결하여 순차 처리 가능
* 항상 이벤트 대기열에 배치된 순서대로 호출됨
* .catch() 블록을 이용하여 오류 처리가 쉬움.

비동기 코드의 특성

### Timeout과 Interval

#### 소개

* setTimeout()

  * 지정된 시간이 경과한 후 코드 블록을 한 번 실행

* setInterval()

  * 지정된 시간 간격마다 코드 블록을 실행

* requestAnimationFrame()

  * 브라우저가 다음 화면을 다시 그리기 전에 코드 블록을 실행

    적절한 프레임 속도록 애니메이션 구현이 가능함 

#### setTimeout()

* 지정된 시간이 경과한 후 콜백 함수를 실행
* 매개변수
  * 실행할 콜백함수 
  * 밀리 초 단위의 대기 시간. 0이나 생략하면 즉시 콜백함수를 실행함.
  * 0개 이상의 콜백 함수에 전달할 매개 변수들...

#### setInterval()

* 지정된 시간 간격으로 반복적으로 콜백 함수를 실행
* 매개변수
  * 실행할 콜백 함수
  * 밀리 초 단위의 대기 시간. 10보다 작은 값이면 10을 사용.
  * 0개 이상의 콜백 함수에 전달할 매개 변수들...

#### setInterval()

* 반복 작업 멈추기
  * clearInterval()

#### 고려사항

* 재귀적 타임아웃
* 0 타임아웃
* clearTimeout()과 clearInterval()

#### requestAnimationFrame()

* 브라우저 애니메이션을 효율적으로 실행하기 위해 만들어진 특수한 함수
* 브라우저가 다음 화면을 그리기 전에 콜백 함수를 실행
* setInterval() 관련 문제를 해결하기 위해 작성됨 
* 매개변수로 콜백함수를 전달 받음 
* 부드러운 애니메이션은 프레임 속도에 좌우됨
* 최대 프레임 속도는 스크린의 재생 빈도인 초당 60프레임 
* 60프레임 속도를 위해 각 프레임 당 16.7ms(1000/60)가 필요
* 부드러운 애니메이션을 위해 콜백 함수의 코드 양을 고려해야 함
* setInterval()과의 차이
* 타임스탬프 추가

### 프라미스

* 작업의 중간 상태를 나타내는 객체
  * 어떤 종류의 결과가 미래에 어떤 시점에 반환될 것이라는 약속
* 반환할때마다 응답할 수 있는지가 관건 
* 가장 일반적인 예는 프라미스를 반환하는 Web API를 사용하는 것 

#### 프라미스를 사용하는 이유 

* 비동기 콜백 함수의 문제점 
* 프라미스로 개선 

```
() => x == () => { return x; }
```

* 성공이나 실패를 한 번만 할 수 있음
* 성공이나 실패 이후 프라미스 콜백을 추가해도 올바른 콜백이 호출됨 

#### 프라미스 용어

* 보류(pending) : 프라미스가 만들어지고 성공 또는 실패하기 전 상태
* 완료(resolved) : 프라미스가 완료된 상태
  * 해결(fulfilled) : 성공적으로 완료된 프라미스 상태. 프라미스 체인의 다음 .then() 콜백으로 해결된 값을 전달
  * 거부(rejected) : 완료된 프라미스가 실패를 반환한 상태. catch() 콜백으로 거부된 이유를 나타내는 오류 메시지를 전달 

#### Promise.all()

* 매개변수인 프라미스 배열이 모두 완료된 후 수행할 새로운 프라미스 객체를 반환
* 모든 프라미스가 해결된 결과 배열이 .then() 콜백 함수로 전달
* 프라미스 중 하나라도 거부되면 전체가 거부됨 

#### .finally() 코드 블록

* 해결 도는 거부 여부에 관계없이 프라미스 완료 후 실행되는 코드 블록
* 최근 브라우저에서 사용 가능
* 프라미스 체인 끝에 연결 

#### Promise() 생성자

* 사용자 정의 프라미스를 생성
* 구식의 비동기 코드를 변환하는 경우 주로 사용됨 
* 매개변수인 resolve, reject는 생성된 프라미스를 해결 또는 거부하는 함수 

### async와 await

#### async 키워드

* 함수 선언 앞에 붙여서 함수를 비동기 함수로 만드는 역할
* 비동기 코드를 호출하기 위해 await 키워드를 사용

```javascript
async function hello() { return 'Hello';}
hello()

let hello = async function() { return 'Hello'; }

let hello = async () => { return 'Hello';}

hello().then(value => console.log(value))
```

#### await 키워드

* async 비동기 함수 내에서 비동기 코드를 실행
* 비동기 코드 앞에 위치하며 프라미스가 해결된 후 결과를 반환 

#### 동작 설명

* function 키워드 앞에 asynce 키워드 추가
* .then() 블록 대신 await 키워드 추가 후 결과를 변수에 할당
* await는 비동기 코드가 결과를 반환할 때까지 일시 중지하고 다른 코드를 실행
* 비동기 코드가 완료되면 다음 줄로 이동하여 계속 실행 

#### 오류처리

* async 함수 내에서 try...catch 구조 사용
* 프라미스 체인의 마지막에 .catch() 코드 블록 추가 

#### async/await의 단점

* await는 프라미스가 해결될 때까지 자신의 코드 실행을 차단함 
* 순차적인 많은 수의 프라미스를 사용할 경우 실행 속도가 느려짐 
* 해결 패턴 : 모든 프라미스를 변수에 저장한 후 해당 변수들을 await로 기다림 

#### async/await class 메서드

#### 브라우저 지원

* 인터넷 익스플로어와 오페라 미니에서는 지원되지 않음
* 최신 브라우저는 대부분 지원
* BabelJS 라이브러리를 사용하면 이전 브라우저에서도 사용 가능 

### API란?

* 복잡한 코드를 추상화하여 사용하기 쉬운 구문을 제공



#### 자바스크립트, API 및 기타 자바스크립트 도구 간의 관계

* 자바스크립트
  * 브라우저에 내장된 고급 스크립트 언어. Node와 같은 다른 프로그래밍 환경에서도 사용가능
* Browser APIs
  * Browser에 내장된 JavaScript 기반의 API
* Third party APIs
  * 타사 플랫폼으로 구축된 API
* JavaScript 라이브러리
  * 사용자정의 함수들이 포함된 하나 이상의 JavaScript 파일. 예) jQuery, Mootools, React, ...
* JavaScript 프레임워크
  * HTML, CSS, JavaScript 및 기타 기술들을 모아놓은 패키지. 예) Angular, Ember, ...

#### 일반적인 브라우저 API

* DOM API
  * 브라우저에 로드된 문서를 조작
* Fetch API
  * 웹페이지의 부분 업데이트를 위해 서버에서 데이터를 가져옴
* Canvas/WebGL API
  * 그래픽 그리기 및 조작
* Audio/Video API
  * 오디오 및 비디오 재생
* Device API
  * 장치 하드웨어에서 데이터를 조작하고 검색 
* 클라이언트 저장소 API
  * 클라이언트 측에 데이터를 저장 

#### 일반적인 써드파티 API

* Twitter API : 웹 사이트에 최신 트윗을 표시
* maprequest/Google Maps API : 웹페이지에 지도로 모든 종류의 작업을 수행
* Facebook suite API : 웹 어플리케이션에 페이스북 생태계를 사용할 수 있음
* Telegram API : 봇지원 및 웹 사이트에 텔레그램 채널의 내용을 삽입 
* etc.

#### API의 동작 방식 

* 객체 기반

  * 하나 이상의 JavaScript 객체를 사용하여 API와 상호작용함

* 진입점 

  * 진입점을 통해 API 기능에 쉽게 접근

* 이벤트를 사용한 상태 변경

  * 이벤트를 사용하여 클라이언트에게 상태를 알림

* 보안 메커니즘

  * JavaScript 및 기타 웹 기술이 제공하지 않는 추가적인 보안 메커니즘 제공

### 클라이언트 저장소

#### 클라이언트 측 저장소

* 클라이언트에 데이터를 저장 및 검색 API
* 사이트 환경 설정 개인화
  * 사용자 정의 위젯, 색 구성 또는 글꼴 크기 설정
* 이전 사이트 활동 기억
  * 이전 세션의 장바구니 내용저장, 이전 로그인 사용자 기억
* 사이트 데이터 및 리소스를 로컬에 저장.
  * 오프라인 상태에서 사용할 수 있거나 보다 빠른 사이트 로딩 속도 지원

* 웹에서 생성한 문서를 오프라인에서 사용할 수 있도록 로컬에 저장

#### 고전 방식 : 쿠키

* 웹에서 가장 일반적으로 사용되는 클라이언트 측 저장소의 초기 형태 
* 다양한 보안 문제와 복잡한 데이터를 저장할 수 없는 문제
* 오래된 브라우저를 지원이 유일한 장점

#### Web Storage와 IndexedDB

* Web Storage API
  * 이름과 값으로 이루어진 작은 데이터 항목을 저장하고 검색하는 기능 제공
* IndexedDB API
  * 브라우저에 복잡한 데이터를 저장하기 위한 데이터베이스 시스템
  * 고객 레코드 등등

#### Cache API

* 특정 요청에 대한 HTTP 응답을 저장하기 위해 설계
* 웹 사이트 리소스를 오프라인에 저장하는 데 유용
* 네트워크 연결 없이도 사이트를 사용할 수 있도록 함
* 일반적으로 Service Worker API와 함께 사용함

#### Web Storage API

* sessionStorage
  * 브라우저가 열려있는 동안만 유지되고 브라우저가 닫히면 손실됨
* localStorage
  * 브라우저가 닫혀도 손실되지 않음. 
* 데이터 유지
  * 페이지 로드 중에도 데이터가 지속
* 도메인 별 스토리지
  * 도메인마다 별도의 데이터 저장소 제공
  * 보안 문제로 웹 사이트가 다른 사이트 데이터를 보지 못하게 막음

#### 오프라인 asset 저장소

* Service worker
  * 네트워크 요청을 가로채어 로드된 페이지와 네트워크 사이에서 원하는 작업 수행
* Cache API
  * HTTP 응답을 저장하도록 설계 