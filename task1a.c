//Maximilian Böker ; 16-706-137
#include <stdio.h>
#include <math.h>

int l, r;
int min, max;
int maxlength = 100;


void TwoEndSort(int A[], int n){
	A[maxlength];
	l = 0;
	r = n - 1;
	while(r > l){
		min = l; max = r;
		for(int i=l; i <= r; i++){
			if(A[i] < A[min]){
				min = i;
			}
			if(A[i] > A[max]){
				max = i;
			}
		}
		//swap(A, l, min);
		int temp = A[l];
		A[l] = A[min];
		A[min] = temp;
		
		if(l == max){
			max = min;
		}
		//swap(A,r,max);
		int temp2 = A[r];
		A[r] = A[max];
		A[max] = temp;
	l++;
	r--;
	}
}

int main(){
	
	double c[6] = {1, 2, 5, 4, 10, 9};
	for(int i=0; i < 6; i++){
		printf("%f ", c[i]);
	}
	printf("\n");
	
	TwoEndSort(c, 6);
	
	for(int i=0; i < 6; i++){
		printf("%f ", c[i]);
	}
		
}
