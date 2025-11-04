#include<stdio.h>

int main(){
	int arr[]={64,25,15,22,11};
	int mid;
	int left=0;
	
	int n=sizeof(arr)/sizeof(arr[0]);
		for(int i = 0 ; i < n ; i++){
		printf("%d " , arr[i]);
	}

	printf("\n");
	for(int i=0;i<n-1;i++){
		for(int j=0;j<n-i-1;j++){
			if(arr[j]>arr[j+1]){
				int tmp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=tmp;
			}
		}
	}
	printf("Mang sau khi sap xep la \n");
	for(int i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
}
