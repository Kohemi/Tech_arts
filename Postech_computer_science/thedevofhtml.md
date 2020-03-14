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
           Property: Propertyvalue; #Declaration
}

ex)

p {
	color: red;
	width: 500px;
	border: 1px solid black;
}

p, li, h1{		#여러 셀렉터 동시 사용 가능
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

