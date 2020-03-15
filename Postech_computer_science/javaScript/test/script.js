var randomnuber = Math.floor(Math.random()*100) + 1;

var guesses = document.querySelector('.guesses');
var lastResult = document.querySelector('.lastResult');
var lowOrHi = document.querySelector('lowOrHi');

var guessSubmit = document.querySelector('.guessSubmit');
var guessField = document.querySelector('.guessField');

var guessCount = 1;
var resetButton;
guessField.focus();

function checkGuess() {
  var userGuess = Number(guessField.value);
  if (guessCount === 1) {
    guesses.textContent = 'Previous Guesses: ';
  }
  guesses.textContent += userGuess + ' ';

  if (userGuess === randomNumber) {
    lastResult.textContent = 'Congratulation! You got it '
    lastResult.style.backgroundColor = 'green';
    lowOrHi.textContent = '';
    setGameover();
  } else if (guessCount === 10) {
    lastResult.textContent = 'Game Over!!';
    setGameover();
  } else {
    lastResult.textContent = '틀림!';
    lastResult.style.backgroundColor = 'blue';
    if (userGuess < randomnuber){
      lowOrHi.textContent = '이것보다 높아요';
    } else if(userGuess > randomNumber) {
      lowOrHi.textContent = '이것보다 낮아요';
    }
  }

  guessCount++;
  guessField.value = ' ';
  guessField.focus();
  alrert("I am alert");
}

guessSubmit.addEventListener('click', checkGuess);

function setGameover() {
  guessField.disabled = true;
  guessSubmit.disabled = true;
  resetButton = document.createElement('button');
  resetButton.textContent = '새 게임';
  document.body.appendChild(resetButton);
  resetButton.addEventListener('click', resetGame);
}

function resetGame() {
  guessCount = 1;

  var resetParas = document.querySelectorAll('.resultParas p')
  for (var i = 0 ; i < resetParas.length ; i++) {
    resetParas[i].textContent = '';
  }

  resetButton.parentNode.removeChild(resetButton);

  guessField.disabled = false;
  guessSubmit.disabled = false;
  guessField.value = '';
  guessField.focus();

  lastResult.style.backgroundColor = 'white';

  randomNumber = Math.floor(Math.random()* 100) + 1;
}