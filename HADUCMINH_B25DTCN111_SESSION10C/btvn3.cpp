#include<stdio.h>

int main(){
	int arr[]={2,4,6,8,10};
	int n=sizeof(arr)/sizeof(arr[0]);
	int key;
	int flag=0;
	printf("Enter key:");
	scanf("%d",&key);
	for(int i=0;i<n;i++){
		if(arr[i]==key){
			flag=1;
			break;
		}
	}
	if(flag==1){
		printf("Tim thay %d trong mang ",key);
}else{
	printf("Khong tim thay phan tu trong mang");
}
	}

