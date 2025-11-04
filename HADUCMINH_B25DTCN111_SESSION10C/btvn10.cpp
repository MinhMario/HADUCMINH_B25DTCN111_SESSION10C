#include<stdio.h>

int main(){
	int arr[]={5,4,6,2,7,8};
	int size=sizeof(arr)/sizeof(arr[0]);
	int flag=0;
	int key;
	printf("Enter key:");
	scanf("%d",&key);
	printf("Mang truoc khi sap xep la \n");
	for(int i=0;i<size;i++){
		printf("%d ",arr[i]);
	}
	for(int i=0;i<size;i++){
		if(arr[i]=key){
			flag=1;
			break;
		}
	}
	if(flag==1){
		printf("Tim thay phan tu %d trong mang \n",key);
	}else{
		printf("Khong tim thay phan tu trong mang");
	}
	for(int i=0;i<size;i++){
		for(int j=i+1;j<size;j++){
			if(arr[j]<arr[i]){
				int tmp=arr[i];
				arr[j]=arr[i];
				tmp=arr[j];
			}
		}
	}
	printf("Mang sau khi sap xep la: ");
	for(int i=0;i<size;i++){
		printf("%d ",arr[i]);
	}
	int left=0;
	int mid;
	int right=size-1;
	while(left<=right){
		mid=(left+right)/2;
		if(arr[mid]=key){
			printf("Tim thay phan tu key");
			flag=1;
			break;
		}else if(arr[mid]<key){
			left=mid+1;
         }
        else if(arr[mid]>key) {
             right=mid-1;
        }
		}
		if(flag==1) {
         printf(" found\n");
     }else {
        printf(" not found\n");
     }
	
}
