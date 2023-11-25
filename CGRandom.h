#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

class CCGRandom {
public:
	CCGRandom() {
		m_fList = NULL;
		Reset(2.0, 100);
	};
	CCGRandom(long double seed) {
		m_fList = NULL;
		Reset(seed, 100);
	};
	CCGRandom(long double seed, int range) {
		m_fList = NULL;
		Reset(seed, range);
	};
	~CCGRandom(){
		free(m_fList);
	};

	virtual void Reset(long double seed, int range);
	virtual void Update();
	virtual void Update(long double seed);
	virtual long double Index(unsigned long long int i) { return m_fList[i % m_iListSize]; };
	virtual unsigned long long int CurrentIndex() { return m_iIndex; };
	virtual long double Get() { return this->Index(m_iIndex); };

private:
	unsigned long long int m_iListSize;
	long double* m_fList;
	unsigned long long int m_iIndex;
	long double m_fSeed;
};