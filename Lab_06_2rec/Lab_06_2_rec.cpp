#include<iostream>
#include<iomanip>
using namespace std;

void Create(int* a, const int size, const int Low, const int High, int i)
{
	a[i] = Low + rand() % (High - Low + 1);
	if (i < size - 1)
		Create(a, size, Low, High, i + 1);
}

void Print(int* a, const int size, int i)
{
	cout << setw(4) << a[i];
	if (i < size - 1)
		Print(a, size, i + 1);
}

int Find(int* a, const int size, int i, int smallestOdd, int smallestOddIndex)
{
    if (i >= size) {
        return smallestOddIndex;
    }

    if (a[i] % 2 != 0) {
        if (smallestOdd == -1 || a[i] < smallestOdd) {
            smallestOdd = a[i];
            smallestOddIndex = i;
        }
    }

    return Find(a, size, i + 1, smallestOdd, smallestOddIndex);
}


int main()
{
	srand((unsigned)time(NULL));
	const int n = 10;
	int a[n];
	int Low = 1;
	int High = 31;
	Create(a, n, Low, High, 0);
	cout << "mas =      ["; Print(a, n, 0);
	cout << "  ]" << endl;
	cout << "Index of the smallest odd: [" << Find(a, n, 0, -1, -1) << "]" << endl;
	return 0;
}