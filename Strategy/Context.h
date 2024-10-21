#ifndef _CONTEXT_H_
#define _CONTEXT_H_

#include "SortStrategy.h"
#include <vector>

class Context 
{
	private:
		SortStrategy* sortAlgorithm;
		std::vector<int> array;

	public:
		void setSortAlgorithm(SortStrategy* sortStrategy) 
		{
			sortAlgorithm = sortStrategy;
		}
		
		void setArray(std::vector<int>& arr)
		{
			array = arr;
		}
		
		void sort() 
		{
			sortAlgorithm->performSort(array);
		}

		std::vector<int>& getArray()
		{
			return array;
		}

};

#endif // _CONTEXT_H_
