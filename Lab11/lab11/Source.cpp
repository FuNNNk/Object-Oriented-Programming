#include "exception.h"

int main()
{
	Array<int> myArray(5);
	myArray += 5;
	myArray += 10;
	myArray += 20;
	myArray += 15;
	printf("%d",myArray.Find(5));
	/*myArray.PrintMyArray();
	myArray.Sort();
	myArray.PrintMyArray();
	TComparator<int> myComparator;
	printf("%d\n", myArray.BinarySearch(25, &myComparator));
	printf("%d\n", myArray.BinarySearch(15, &myComparator));

	Array<float> myArray2(5);
	myArray2 += 5.0;
	myArray2 += 5.2;
	myArray2 += 20.5;
	myArray2 += 15.6;
	myArray2.PrintMyArray();
	myArray2.Sort();
	myArray2.PrintMyArray();
	TComparator<float> myComparator2;
	printf("%d\n", myArray2.BinarySearch(25, &myComparator));
	printf("%d\n", myArray2.BinarySearch(20.5, &myComparator));

	ArrayIterator<int> myIterator = myArray.GetBeginIterator();
	ArrayIterator<int> endInterator = myArray.GetEndIterator();
	printf("Iterating...\n");
	while (myIterator != endInterator)
	{
		printf("%d ", *myIterator.GetElement());
		++myIterator;
	}
	printf("\n");*/

	return 0;
}