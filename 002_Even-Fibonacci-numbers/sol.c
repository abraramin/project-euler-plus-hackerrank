#include <stdio.h>

/**
* compile:
* gcc -Wall -Werror -pedantic -std=c99 ./sol.c -o sol
*/

int main(int argc, char** argv) {
	int numTestCases;
	scanf("%d", &numTestCases);

	for(int testCase = 0; testCase < numTestCases; testCase++) {
		unsigned long int fibLimit;
		scanf("%lu", &fibLimit);
		unsigned long int f1 = 1;
		unsigned long int f2 = 1;
		unsigned long int f3 = 0;
		unsigned long int res = 0;
		
		while(f3 < fibLimit) {
			if(f3%2 == 0)
				res+=f3;
			f1 = f2;
			f2 = f3;
			f3 = f1+f2;
		}

		printf("%lu\n", res);
	}

	return 0;
}
