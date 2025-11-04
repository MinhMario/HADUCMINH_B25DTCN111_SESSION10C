#include<stdio.h>

int main(){
	int arr[]={1,2,3,4,2,2};
	int n=sizeof(arr)/sizeof(arr[0]);
	int key;
	int flag=0;
	int count=0;
	printf("Enter key");
	scanf("%d",&key);
	for(int i=0;i<n;i++){
		if(arr[i]==key){
			flag=1;
			count++;
		}
	}
	if(flag==1){
		printf("So %d xuat hien trong mang %d",key,count);
	}else{
		printf("So khong xuat hien trong mang");
	}
	}

