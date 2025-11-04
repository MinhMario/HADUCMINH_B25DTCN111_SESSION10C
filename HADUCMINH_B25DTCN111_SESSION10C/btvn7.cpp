#include<stdio.h>

int main(){
	int arr[]={1,2,3,4,5};
	int size=sizeof(arr)/sizeof(arr[0]);
	int key;
	printf("Enter key:");
	scanf("%d",&key);
	int mid;
	int flag=0;
    int left=0;
     int right=size-1;
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
