/*
    Luna Capsule / vijos-1334

    Problem: https://vijos.org/p/1334
    Record: https://vijos.org/records/544bce0517f3cafc2d14006f
*/

#include <iostream>

using namespace std;

unsigned trace[401][401] = {0}, itemcount, packsize1, packsize2;

unsigned select(unsigned v1, unsigned v2)
{
	return (v1 > v2) ? v1 : v2;
}

void search(unsigned cost1, unsigned cost2, unsigned value)
{
	unsigned size1, size2;

	for (size1 = packsize1; size1 >= cost1; size1--)
		for (size2 = packsize2; size2 >= cost2; size2--)
			trace[size1][size2] = select(trace[size1][size2], trace[size1 - cost1][size2 - cost2] + value);
}

int main()
{
	unsigned i, cost1, cost2, value;

	cin >> packsize1 >> packsize2 >> itemcount;
	for (i = 1; i <= itemcount; i++)
	{
		cin >> cost1 >> cost2 >> value;
		search(cost1, cost2, value);
	}

	cout << trace[packsize1][packsize2];
}
