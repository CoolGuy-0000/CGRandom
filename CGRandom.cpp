#include "CGRandom.h"

void CCGRandom::Reset(long double seed, int range) {
	m_fSeed = seed;
	m_iListSize = range;
	m_iIndex = time(NULL)%m_iListSize;
	
	if(m_fList)free(m_fList);

	m_fList = (long double*)malloc(m_iListSize*sizeof(long double));
	if (m_fList == NULL) {
		delete this;
		return;
	}

	this->Update(m_fSeed);
}

void CCGRandom::Update() {
	this->Update(m_fList[time(NULL)%m_iListSize]);
}
void CCGRandom::Update(long double seed) {
	m_fSeed = fabs(seed);
	m_iIndex = time(NULL)%m_iListSize;
	
	float x = 0.0;

	for (unsigned long long int i = 0; i < m_iListSize; i++) {
		x = ((-1.0 * fabs(m_fSeed)) + x) / (x + 1);
		m_fList[i] = x;
	}
}
