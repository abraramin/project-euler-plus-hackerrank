#include <stdio.h>

unsigned long int getGaussianSum(int n, int limit) {
	unsigned long int lastVal = limit-1;
	unsigned long int nCount = (lastVal)/n;
	unsigned long int lastNInLimit = lastVal - (lastVal%n);
	unsigned long int res;

	if(nCount%2 == 0) 
		res = (n+lastNInLimit)*(nCount/2);
	else 
		res = (n+lastNInLimit)*(nCount/2) + (n+lastNInLimit)/2;
	return res;	
}

int main(int argc, char** argv) {
	int numTestCases; 
	scanf("%d", &numTestCases);

	for(int testCase = 0; testCase < numTestCases; ++testCase) {
		int inLimit;
		scanf("%d", &inLimit);
		unsigned long int sum = 0; 
		sum+= getGaussianSum(3, inLimit); 
		sum-= getGaussianSum(15, inLimit);
		sum+= getGaussianSum(5, inLimit);

		printf("%lu\n", sum);
	}

	return 0;
}

