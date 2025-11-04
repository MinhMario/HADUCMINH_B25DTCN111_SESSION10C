#include<stdio.h>

int main(){
	int arr[]={5,1,4,2,8};
	int n= sizeof(arr)/sizeof(arr[0]);
	bool swapped;
	printf("Mang truoc khi sap xep la: ");
	for(int i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
	for(int i=0;i<n-1;i++){
		swapped =false;
		for(int j=0;j<n-i-1;j++){
			if(arr[j]>arr[j+1]){
				int tmp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=tmp;
				swapped =true;
			}
		}
	if(swapped==false){
	printf("Chuong trinh ket thuc.Dung thuat toan \n");
	break;
}

}
	printf("Mang sau khi sap xep la :");
	for(int i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
}
