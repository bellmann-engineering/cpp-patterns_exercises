#ifndef QUICKSORT
#define QUICKSORT

#include <vector>
#include "SortStrategy.h"


class QuickSort : public SortStrategy
{

	// TODO 2: implement the missing interface


	public:
		

	private:
		int partition(std::vector<int>& v, int start, int end)
		{
			int pivot = end;
			int j = start;
			for(int i=start;i<end;++i)
			{
				if(v[i]<v[pivot])
				{
					std::swap(v[i],v[j]);
					++j;
				}
			}
			std::swap(v[j],v[pivot]);
			return j;		
		}
		
		void quicksort(std::vector<int>& v, int start, int end)
		{
			if(start<end)
			{
				int p = partition(v,start,end);
				quicksort(v,start,p-1);
				quicksort(v,p+1,end);
			}	
		}

	

};


#endif	//#ifndef QUICKSORT
