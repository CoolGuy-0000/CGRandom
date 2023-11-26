#include "CGRandom.h"

void CCGRandom::Reset(long double seed, int range) {
	m_fSeed = seed;
	m_iListSize = range;
	
	if(m_fList)free(m_fList);

	m_fList = (long double*)malloc(m_iListSize*sizeof(long double));
	if (m_fList == NULL) {
		delete this;
		return;
	}

	this->Update(m_fSeed);
}
void CCGRandom::Update(long double seed) {
	m_fSeed = fabs(seed);

	long double x = 0.0;

	for (unsigned long long int i = 0; i < m_iListSize; i++) {
		x = ((-1.0 * m_fSeed) + x) / (x + 1.0);
		m_fList[i] = fmod(x, 10.0);
	}


	int c;

	for (unsigned long long int i = 0; i < m_iDimension; i++) {
		
		for (unsigned long long int k = 0; k < m_iListSize; k++) {
			c = abs((int)(m_fList[k] * 100.0))%m_iListSize;
			x = 0.0;

			for (int m = 0; m < c; m++)
				x = ((-1.0 * fabs(m_fList[k])) + x) / (x + 1.0);

			m_fList[k] = fmod(x, 10.0);
		}

	}

}