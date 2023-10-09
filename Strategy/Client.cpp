#include "Policy.h"
#include "Context.h"

#include <string>
#include <vector>
#include <iostream>
#include <cmath>
#include <optional>
#include <random>
#include <algorithm>

std::vector<int> createIntegerArray();
std::vector<int> scrambleArray(std::vector<int>);
void printIntegerArray(std::vector<int>&);
void simulateRuntimeConfigurationChange(Policy*);

int main()
{
	// TODO: Instantiate the policy and the context.
	



	std::vector<int> array = createIntegerArray();

	for (int i = 0; i < 10; i++)
	{
		array = scrambleArray(array);
		sortingContext->setArray(array);
		simulateRuntimeConfigurationChange(policy);
		std::cout << "Unsorted Array a = ";
		printIntegerArray(array);
		sortingContext->sort();
		std::cout << "Sorted Array a = ";
		printIntegerArray(array);
	}
	
	
}

std::vector<int> createIntegerArray()
{
	int output = 0;
	std::vector<int> a(30);
	for (int i = 0; i < a.size(); i++)
	{
		output = 1 + (rand() % static_cast<int>(100 - 1));
		a[i] = std::abs(output % 100);
	}

	return a;
}

std::vector<int> scrambleArray(std::vector<int> array)
{
	auto rng = std::default_random_engine {};
	std::shuffle(std::begin(array), std::end(array), rng);

	return array;
}

void printIntegerArray(std::vector<int>& a)
{
	std::cout << "{";
	for (int i = 0; i < a.size(); i++)
	{
		std::cout << a[i];
		if (i < a.size() - 1)
		{
			std::cout << ",";
		}
	}
	std::cout << "}" << std::endl;
}

void simulateRuntimeConfigurationChange(Policy* sortPolicy)
{
	int output = 1 + (rand() % static_cast<int>(100 - 1));

	bool timeIsImportant = false;
	bool spaceIsImportant = false;
	if ((output % 2) == 0)
	{
		std::cout << "Time is important!" << std::endl;
		timeIsImportant = true;
		spaceIsImportant = false;
		sortPolicy->configure(timeIsImportant, spaceIsImportant);
	}
	else
	{
		timeIsImportant = true;
		spaceIsImportant = true;
		std::cout << "Time and space are important!" << std::endl;
		sortPolicy->configure(timeIsImportant, spaceIsImportant);
	}

}

