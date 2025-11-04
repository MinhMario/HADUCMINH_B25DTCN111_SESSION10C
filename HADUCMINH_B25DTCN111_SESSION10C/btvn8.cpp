#include<stdio.h>

int main(){
	int arr[]={5,1,8,3,2,7};
	int n=sizeof(arr)/sizeof(arr[0]);
	for(int i=0;i<n;i++){
		for(int j=0;j<n-1-i;j++){
			if(arr[j]>arr[j+1]){
				int tmp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=tmp;
			}
		}
	}
	printf("Mang sau khi sap xep la :");
	for(int i=0;i<n;i++){
		printf("%d",arr[i]);
	}
		int key;
	printf("Enter key:");
	scanf("%d",&key);
	int mid;
	int flag=0;
    int left=0;
     int right=n-1;
     while(left<=right) {
        mid=(left+right)/2;
        if(arr[mid]==key) {
            printf("Tim thay phan tu key ");
            flag=1;
            break;
         }
         else if(arr[mid]<key) {
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
