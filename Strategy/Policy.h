#ifndef POLICY
#define POLICY

#include "MergeSort.h"
#include "QuickSort.h"
#include "Context.h"

class Policy
{
	private:
	    // TODO: Declare the missing attribute (hint: check the constructor).


	public:
		// TODO: Instantiate the missing attribute.
		Policy(Context* context) {}

		virtual void configure(bool timeIsImportant, bool spaceIsImportant)
		{
		// TODO: Add implementation for choosing the appropriate sorting algorithm.
		// If time is important and space is not, use MergeSort else Quicksort
		}
};

#endif	//#ifndef POLICY
