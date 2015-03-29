for(var n=999;n>0;n--){
	if(isPrime(n)&&isPalindrome(n)){
		console.log(n);
		break;
	}
}

function isPrime(n){
	var prime=true;
	if(n%2==0){	
		prime=false;
	}else{
		var sqrtOfN=parseInt(Math.sqrt(n));
		for(var i=3;i<=sqrtOfN;i+=2){
			if(n%i==0){
				prime=false;
				break;
			}
		}
	}
	return prime;
}
function isPalindrome(n){
	var i=0;
	var working=n;
	while(working!=0){
		i*=10;
		i+=working%10;
		working=parseInt(working/10);
	}
	return i==n;
}
