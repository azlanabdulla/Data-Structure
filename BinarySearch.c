#include<stdio.h>
 int Binarysearch(int arr[],int n,int target){
    int left=0 , right=n-1;
    while(left<=right){
        int mid=left+(right-left)/2;

        if(arr[mid]==target){
            return mid;
        }
        if(arr[mid]<target){
            left=mid+1;
        }
        else{
            right=mid-1;
        }
        
    }
    return -1;
 }

 void main(){
    int a[50],n,target,i,result;
    printf("Enter the  no.of elements: ");
    scanf("%d",&n);
    printf("Enter the Elements: ");
    for (i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("Enter the number that need to be Searched: ");
    scanf("%d",&target);
    result=Binarysearch(a,n,target);
    if(result!=-1){
        printf("Element Found On %d ",result);
    }
    else{
        printf("Element Not Found");
    }

 }