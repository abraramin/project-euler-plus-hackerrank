#include <stdio.h>
#include <stdbool.h>
#include <math.h>

/**
* compile:
* gcc -Wall -Werror -pedantic -lm -std=c99 ./sol.c -o sol
*/

bool isPrime(unsigned long n) {
	if(n !=2 && n%2 == 0)
		return false;
	if(n == 2)
		return true;
	unsigned long sqrootN = round(sqrt(n));
	for(unsigned long i = 3; i <= sqrootN; i+=2) {
		if(n%i==0)
			return false;
	}
	return true;
}
	

int main(int argc, char** argv) {
	int numTestCases;
	scanf("%d", &numTestCases);
	
	for(int testCase = 0; testCase < numTestCases; testCase++) {
		unsigned long inputNum;
		scanf("%lu", &inputNum);
		unsigned long inputNumCpy = inputNum;
		
		while(inputNumCpy%2==0) {
			inputNumCpy/=2;
		}
		
		//printf("is prime %lu = %d\n", inputNum, isPrime(inputNum));
		unsigned long sqrootN = round(sqrt(inputNumCpy));
		unsigned long largestPrimeFactor = 1;
		
		for(unsigned long j = 1; j <= sqrootN; j+=2) {
			if((inputNumCpy%j == 0)) {
				unsigned long f1 = j;
				unsigned long f2 = inputNumCpy/j;
				if(isPrime(f2)) {
					largestPrimeFactor = f2;
					break;
				} else if (isPrime(f1)) {
					largestPrimeFactor = (f1>largestPrimeFactor)?f1:largestPrimeFactor;
				}
			}
		}
		largestPrimeFactor = (largestPrimeFactor == 1 && inputNum%2==0)?2:largestPrimeFactor;
		printf("%lu\n", largestPrimeFactor);
	}
	
	return 0;
}
