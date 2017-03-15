// Tobias Egger, 16-728-016

#include <stdio.h>

int isReverse(char A[], char B[]){
	int i, alen, blen, j;
	
	i = 0;
	while (A[i] != '\0'){
		i++;
	}
	alen = i;
	
	i = 0;
	while (B[i] != '\0'){
		i++;
	}
	blen = i;
	
	if (alen == blen){
		for (j = 0; j < alen; j++){
			if (A[j] != B[blen-j-1]){
				return 0;
			}
		}
		return 1;
	}
	return 0;
}

int main(){
	char A[100], B[100];
	int the_truth;
	
	printf("Please enter string A:\n");
	scanf("%s", &A);
	printf("\nPlease enter string B:\n");
	scanf("%s", &B);
	
	the_truth = isReverse(A,B);
	if (the_truth){
		printf("\nString B is the reverse of string A.");
	}else{
		printf("\nString B is not the reverse of string A.");
	}
	
	return 0;
}
