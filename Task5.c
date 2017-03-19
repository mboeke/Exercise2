//Tobias Egger, 16-728-016
#include <stdio.h>
#include <math.h>

int ternarySearch(int A[], int l, int r, int k){
	int mid1,mid2;
	
	while (r>=l){
		// mid1 und mid2 festlegen, interval wird gleichmässig gedrittelt,falls möglich
		mid1 = ceil(l+(r-l)/3);
		mid2 = ceil(r-(r-l)/3);
		
		// prüfen ob mid1 oder mid2 unser element ist
		if (A[mid1] == k){
			return mid1;
		}else if (A[mid2] == k){
			return mid2;
		}
		
		// mid1 und mid2 schon geprüft -> mid1/mid2+-1
		if (A[mid1]>k){
			return ternarySearch(A, l, mid1-1, k);
		}
		else if (A[mid2] <= k){
			return ternarySearch(A, mid2+1, r, k);
		}else{
			return ternarySearch(A, mid1+1, mid2-1, k);
		}
	}
	// falls element nicht gefunden
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
	printf("\nGieb das Element an, welches du suchst:\n");
	scanf("%d", &k);
	// i == n -> array hat ellemente 0-n-1
	r = i-1;
	result = ternarySearch(A,0,r,k);
	
	// je nach return von funktion verschiedene Meldungen anzeigen
	if (result == -1){
		printf("\nIhr Element wurde im Array nicht gefunden!");
	}else{
		printf ("\nIhr Element is an Stelle %d im Array!", result);
	}
	return 0;
}

