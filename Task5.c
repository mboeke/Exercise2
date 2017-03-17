//Tobias Egger, 16-728-016
#include <stdio.h>
#include <math.h>

int ternarySearch(int A[], int l, int r, int k){
	int mid1,mid2;
	
	while (r>l){
		mid1 = floor(l+(r-l)/3);
		mid2 = floor(r-(r-l)/3);

		if (A[mid1] == k){
			return mid1;
		} else if (A[mid2] == k){
			return mid2;
		}
		
		if (A[mid1]>k){
			return ternarySearch(A, l, mid1, k);
		}
		else if (A[mid2] <= k){
			return ternarySearch(A, mid2, r, k);
		}else{
			return ternarySearch(A, mid1, mid2, k);
		}
	}
	return -1;
}

int main(){
	int A[100], k, i, r, result;
	i = 0;
	
	printf("Enter the array you want to search through (stop by typing end):\n");
	while (scanf("%d", &A[i]) == 1){
		i++;
	}
	scanf("%*s");
	printf("\nEnter the element you want to search for:\n");
	scanf("%d", &k);

	r = i-1;
	result = ternarySearch(A,0,r,k);
	if (result == -1){
		printf("\nYour element wasn't found in the array!");
	}else{
		printf ("\nYour element is at position %d in the array!", result);
	}
	return 0;
}

