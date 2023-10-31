#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;
void Create(int* a, const int size, const int Low, const int High)
{
	for (int i = 0; i < size; i++)
		a[i] = Low + rand() % (High - Low + 1);
}
void Print(int* a, const int size)
{
	for (int i = 0; i < size; i++)
		cout << setw(4) << a[i];
	cout << endl;
}
void QuickSort(int* a, int first, int last)
{
	int l = first, r = last, p = a[(first + last) / 2];
	do {
		while (a[l] > p) l++;
		while (a[r] < p) r--;
		if (l <= r) {
			if (a[l] < a[r]) swap(a[l], a[r]);
			l++;
			r--;
		}
	} while (l <= r);
	if (l < last)
		QuickSort(a, l, last);
	if (first < r)
		QuickSort(a, first, r);
}
int main()
{
	srand((unsigned)time(NULL));
	const int n = 25;
	int a[n];
	int Low = -20;
	int High = 30;
	Create(a, n, Low, High);
	Print(a, n);
	QuickSort(a, 0, n - 1);
	Print(a, n);
	return 0;
}
