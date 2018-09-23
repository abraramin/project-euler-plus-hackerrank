#include <stdio.h>
#include <stdbool.h>

#define MIN(x,y) ((x)<(y) ? (x):(y))
/**
* compile:
* gcc -Wall -Werror -pedantic -std=c99 ./sol.c -o sol
*/

bool isPalindrome(int n) {
	int digits[6];
	for(int i =0; i < 6; i++) {
		digits[i] = n%10;
		n/=10;
	}
	if(digits[0] == digits[5] && digits[1] == digits[4] && digits[2] == digits[3])
		return true;
	return false;
}

bool isProductOfTwoThreeDigitNum(int n) {
	for(int i = 100; i <= 999; i++) {
		if(n%i == 0) {
			int i2 = n/i;
			if((i2/100 > 0 && i2/100 < 10) && (i/100 > 0 && i/100 < 10)) {
				return true;
			}
		}
	}
	return false;
}

int main(int argc, char** argv) {
	int t; 
	scanf("%d",&t); 
	for(int a0 = 0; a0 < t; a0++) {
		int n;
		scanf("%d",&n);
		// palindrome has to be lesser than n
		while(!isPalindrome(n-1) || !isProductOfTwoThreeDigitNum(n-1)) {
			n--;
		}
		printf("%d\n", n-1);
	}
	return 0;
}
