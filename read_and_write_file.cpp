#include "iostream"
#include "fstream"
using namespace std;
//
void ReadFile(const char* filename, int *&a, int& n);
void WriteFile(const char* filename, int* a, int n);
int LinearSearchEx(int* a, int n, int x); 
int BinarySearch(int* a, int left, int right, int x); 
int TernarySearch(int* a, int left, int right, int x);
int main()
{
	int n;
	int* a = NULL;
	const char* input = "text.txt";
	//const char* output = "output.txt";
	ReadFile(input, a, n);
	//
	cout << TernarySearch(a, 0, n - 1, 6) << endl;
	cout << TernarySearch(a, 0, n - 1, 8) << endl;
	// 
	//cout << BinarySearch(a, 0, n - 1, 7) << endl;
	//cout << BinarySearch(a, 0, n - 1, 11) << endl;

	//cout << LinearSearchEx(a, n, 9) << endl;
	//cout << LinearSearchEx(a, n, 11);
	//WriteFile(output, a, n);
	return 0;
}
void ReadFile(const char* filename, int*& a, int& n)
{
	ifstream file;
	//1
	file.open(filename);
	//2
	if (file)
	{
		file >> n;
		a = new int[n];
		for (int i = 0; i < n; i++)
			file >> a[i];
	}
	//3
	file.close();
}
void WriteFile(const char* filename, int* a, int n)
{
	ofstream file;
	//1
	file.open(filename);
	//2
	if (file)
	{
		file << n << endl;
		for (int i = 0; i < n; i++)
			file << a[i] << " ";
	}
	//3
	file.close();
}
int LinearSearchEx(int* a, int n, int x)
{
	int i = 0;
	a[n] = x;
	while (a[i] != x)
		i++;
	if (i == n)
		return -1;
	else
		return i;
}
int BinarySearch(int* a, int left, int right, int x)
{
	int mid;
	if (left > right)
		return -1;
	mid = (left + right) / 2;
	if (a[mid] == x)
		return mid;
	if (a[mid] > x)
		return BinarySearch(a, left, mid - 1, x);
	else
		return BinarySearch(a, mid + 1, right, x);
	
}
int TernarySearch(int* a, int left, int right, int x)
{
	int mid1, mid2;
	if (left > right)
		return -1;
	mid1 = (left + right) / 3;
	if (a[mid1] == x)
		return mid1;  
	mid2 = (mid1 + (left + right)) / 3;
	if (a[mid2] == x)
		return mid2;
	// a[left] -> a[mid1]-> a[mid2]-> a[right]
	if (a[mid1] > x)
		return TernarySearch(a, left, mid1 - 1, x);
	else if (a[mid2] < x)
		return TernarySearch(a, mid2 + 1, right, x);
	else
		return TernarySearch(a, mid1 + 1, mid2 - 1, x);


}
