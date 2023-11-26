#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

class CCGRandom {
public:
	CCGRandom() {
		m_fList = NULL;
		m_iDimension = 0;
		Reset(2.0, 100);
	};
	CCGRandom(long double seed, int range) {
		m_fList = NULL;
		m_iDimension = 0;
		Reset(seed, range);
	};
	CCGRandom(long double seed, int range, int dimension) {
		m_fList = NULL;
		m_iDimension = dimension;
		Reset(seed, range);
	};
	~CCGRandom(){
		free(m_fList);
	};

	virtual void Reset(long double seed, int range);
	virtual void Update(long double seed);
	virtual unsigned long long int MaxIndex() { return m_iListSize; };
	virtual long double Index(unsigned long long int i) { return m_fList[i % m_iListSize]; };
	virtual long double CurrentSeed() { return m_fSeed; };
	virtual void SetDimension(unsigned long long int d) { m_iDimension = d; };
	virtual unsigned long long int GetDimension() { return m_iDimension; };

private:

	unsigned long long int m_iListSize;
	unsigned long long int m_iDimension;
	long double* m_fList;
	long double m_fSeed;

};