#ifndef MERGESORT
#define MERGESORT

#include <vector>
#include "SortStrategy.h"

class MergeSort : public SortStrategy
{
	public:	
		// TODO: Implement the missing interface
		// You need to use to implemeted method sort()
		
		/***********************************************************************
		 * Merge the subarrays a[lo] .. a[mid-1] and a[mid] .. a[hi-1] into a[lo] ..
		 * a[hi-1] using the auxilliary array aux[] as scratch space.
		 *
		 * Precondition: the two subarrays are in ascending order Postcondition:
		 * a[lo] .. a[hi-1] is in ascending order
		 *
		 ***********************************************************************/
	private:
		static void merge(std::vector<int>& a, std::vector<int>& aux, int lo, int mid, int hi)
		{
			int i = lo, j = mid;
			for (int k = lo; k < hi; k++)
			{
				if (i == mid)
				{
					aux[k] = a[j++];
				}
				else if (j == hi)
				{
					aux[k] = a[i++];
				}
				else if (a[j] < a[i])
				{
					aux[k] = a[j++];
				}
				else
				{
					aux[k] = a[i++];
				}
			}

			// copy back
			for (int k = lo; k < hi; k++)
			{
				a[k] = aux[k];
			}
		}

		/***********************************************************************
		 * Mergesort the subarray a[lo] .. a[hi-1], using the auxilliary array aux[]
		 * as scratch space.
		 ***********************************************************************/
		static void sort(std::vector<int>& a, std::vector<int>& aux, int lo, int hi)
		{

			// base case
			if (hi - lo <= 1)
			{
				return;
			}

			// sort each half, recursively
			int mid = lo + (hi - lo) / 2;
			sort(a, aux, lo, mid);
			sort(a, aux, mid, hi);

			// merge back together
			merge(a, aux, lo, mid, hi);
		}

};


#endif	//#ifndef MERGESORT
