#include <iostream>
using namespace std;
void printarr(int arr[], int n){
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " "; 
	}
	cout << "\n"; 
}

int binarysearch(int arr[], int l, int r, int num){
	int middle; 
	while (l < r)
	{
		middle = l + (r - l) / 2;
		if (arr[middle] > num)
		{
			return binarysearch(arr, l, middle, num);
		}
		else if (arr[middle] < num)
		{
			return binarysearch(arr, middle + 1, r, num);
		}
		else
		{
			return middle;
		}
	}
	
}
void binaryinsertionsort(int arr[], int n){
	int i, j, ins, temp; 
	for (i = 1; i < n; i++)
	{
		ins = binarysearch(arr, 0, i, arr[i]); 
		temp = arr[i]; 
		for (j = i-1; j >= ins; j--)
		{
			arr[j + 1] = arr[j];
		}
		arr[ins] = temp;
	}
}
int main(){
	int arr[100], i, n; 
	cout << "nhap sz: "; cin >> n; 
	for (i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	binaryinsertionsort(arr, n); 
	printarr(arr, n);
	return 0;
}