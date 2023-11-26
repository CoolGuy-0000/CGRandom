#include <stdio.h>
#include <math.h>
#include "CGRandom.h"

int main() {

	CCGRandom* random = new CCGRandom(2.0, 3000, 10);
	FILE* fresult = fopen("result.txt", "w+");
	if (fresult == NULL) {
		for (int i = 0; i < random->MaxIndex(); i++)
			printf("%f\n", random->Index(i));
		
		delete random;
		return 0;
	}

	for (int i = 0; i < random->MaxIndex(); i++)
		fprintf(fresult, "%f\n", random->Index(i));
	
	fclose(fresult);

	delete random;

	return 0;
}
