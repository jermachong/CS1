//Dr. Andrew Steinberg
//COP3502 Computer Science 1
//Merge Sort Algorithm

#include <stdio.h>
#include <stdlib.h>


void merge(int *arr, int p, int q, int r);
void mergeSort(int * arr, int p, int r);

int main(void)
{
	int arr[10];
	
	for(int x = 0; x < 10; ++x)
		arr[x] = rand() % 80;
	
	printf("------------------------------------------------------------------------\n");
	printf("------------------------------------------------------------------------\n");
	printf("Before Merge Sort\n");
	
	for(int x = 0; x < 10; ++x)
		printf("%4d", arr[x]);
	printf("\n");
	printf("------------------------------------------------------------------------\n");
	printf("------------------------------------------------------------------------\n");
	
	mergeSort(arr, 0,  sizeof(arr)/sizeof(arr[0]) - 1); //array, index 0, size of array
	
	printf("After Merge Sort\n");
	
	for(int x = 0; x < 10; ++x)
		printf("%4d", arr[x]);
	printf("\n");
	printf("------------------------------------------------------------------------\n");
	printf("------------------------------------------------------------------------\n");
	
	return 0;
}

void merge(int *arr, int p, int q, int r)
{
	int n1 = q - p + 1;
	int n2 = r - q;
	
	int * leftarr = (int *) malloc(sizeof(int) * n1);
	int * rightarr = (int *) malloc(sizeof(int) * n2);
	
	for(int x = 0; x < n1; ++x)
		leftarr[x] = arr[p + x];
	
	for(int x = 0; x < n2; ++x)
		rightarr[x] = arr[q + x + 1];
	
	int i = 0;
	int j = 0;
	int k = p;
	
	//merge
	while (i < n1 && j < n2) 
	{
		if (leftarr[i] <= rightarr[j]) 
		{
		  arr[k] = leftarr[i];
		  i++;
		} 
		else 
		{
		  arr[k] = rightarr[j];
		  j++;
		}
		
		k++;
	}
	
	//copy the remaining elements once out of bounds

	while (i < n1) 
	{
		arr[k] = leftarr[i];
		i++;
		k++;
	}

	while (j < n2) 
	{
		arr[k] = rightarr[j];
		j++;
		k++;
	}
	
	free(leftarr);
	free(rightarr);
}

void mergeSort(int * arr, int p, int r)
{
	if(p < r)
	{
		int q = (r + p) / 2;
		mergeSort(arr, p, q);
		mergeSort(arr, q + 1, r);
		merge(arr, p, q, r);
	}
}

