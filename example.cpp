#include <stdio.h>
#include <math.h>
#include "CGRandom.h"

int main() {

	CCGRandom* random = new CCGRandom();

	int count1 = 0;
	int count2 = 0;

	for (int i = 0; i < 1000; i++) {
		if ((int)fabs(random->Get() * 100.0) % 2)count1++;
		else count2++;

		random->Update();
	}

	printf("%d : %d\n", count1, count2);

	delete random;

	getchar();

	return 0;
}
