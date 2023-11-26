#include <stdio.h>
#include <math.h>
#include "CGRandom.h"

int main() {

	CCGRandom* random = new CCGRandom();
	delete random;



	float x = 0.0;
	float y = 0.0;
	float z = 0.0;
	float a = 0.0;

	for (int i = 0; i < 100; i++) {
		x = (-2.0 + x) / (x + 1.0);
		y = (-4.0 + y) / (y + 1.0);
		z = (-5.0 + z) / (z + 1.0);
		printf("%f	%f	%f\n", x, 1.0/x, z);
	}

	getchar();

	return 0;
}
