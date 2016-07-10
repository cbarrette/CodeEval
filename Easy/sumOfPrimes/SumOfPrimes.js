var sum = 0;
var nb_prime = 0;
var x = 2;

while (nb_prime < 1000) {
  var sqrRootOfX = parseInt(Math.sqrt(x));
  var isPrime = true;
  for (var i = 2; i <= sqrRootOfX; i++) {
    if (x % i == 0) {
      isPrime = false;
      break;
    }
  }
  if (isPrime) {
    sum += x;
    nb_prime++;
  }
  x++;
}
console.log(sum);
