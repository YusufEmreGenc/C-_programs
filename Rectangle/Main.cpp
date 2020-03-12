#include <iostream>
#include "Rectangle.h"
using namespace std;

//******************************************
// Created by Hacer Yalim Keles, 18/04/2018, related to PA3 of COM102B
// Ankara University, Dept. of Computer Engineering
//******************************************

// You can comment and uncomment the following MACRO lines during your development
// I strongly suggest an incremental development approach:
// Hence, you can start by enabling only TEST1 first, then only TEST1 and TEST2, and so on..
#define TEST1
#define TEST2
#define TEST3
#define TEST4

int ComputeIntersectionAreasInPairs(Rectangle RA[], int size)
{
	int sum_area = 0;
	for (int i = 0; i < size - 1; i++)
		for (int j = i + 1; j < size; j++)
		{	
			int area = (RA[i] & RA[j]);
			sum_area += area;
			// check pair intersections
			cout << RA[i] << "\t&\t" << RA[j] << "\t: ";
			cout << area << endl;
		}
	return sum_area;
}

int ComputeUnionAreasInPairs(Rectangle RA[], int size)
{
	int sum_area = 0;
	for (int i = 0; i < size - 1; i++)
		for (int j = i + 1; j < size; j++)
		{
			int area = (RA[i] | RA[j]);
			sum_area += area;
			// check pair unions
			cout << RA[i] << "\t|\t" << RA[j] << "\t: ";
			cout << area << endl;
		}
	return sum_area;

}

int CounputeBoundingBoxAreaInPairs(Rectangle RA[], int size)
{
	int sum_area = 0;
	for (int i = 0; i < size - 1; i++)
		for (int j = i + 1; j < size; j++)
		{
			int area = (RA[i] ^ RA[j]);
			sum_area += area;
			// check pair BBXs
			cout << RA[i] << "\t^\t" << RA[j] << "\t: ";
			cout << area << endl;
		}
	return sum_area;

}
int main()
{
	int count = 0;
	Rectangle* RectList;

	cin >> count;
	RectList = new Rectangle[count];

	for (int i = 0; i < count; i++)
	{
		cin >> RectList[i];
#ifdef TEST1		
		// check if we read correctly
		cout << RectList[i]<<endl; 
#endif
	}

#ifdef TEST2
	cout << "TEST2----------\n";
	int total_int_area = ComputeIntersectionAreasInPairs(RectList, count);
	cout << "Total Intersection Area:\t" << total_int_area << endl;
#endif

#ifdef TEST3
	cout << "TEST3----------\n";
	int total_union_area = ComputeUnionAreasInPairs(RectList, count);
	cout << "Total Union Area:\t" << total_union_area << endl;
#endif

#ifdef TEST4
	cout << "TEST4----------\n";
	int total_bbx_area = CounputeBoundingBoxAreaInPairs(RectList, count);
	cout << "Total BBX Area:\t" << total_bbx_area << endl;
#endif

	delete[] RectList;
}

