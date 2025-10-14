#include <stdio.h>
int step;

int InsertionSort(int arr[],int n){
    step=0;
    for(int i=1;i<n;i++){
        int key=arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j--;
            step++;
        }
        arr[j+1]=key;
        step++;
    }
}
void SelectionSort(int arr[],int n){
    step=0;
    for(int i=0;i<n-1;i++){
        int min =i,j;
        for(int j=i+1;j<n;j++){
            step++;
            if(arr[j]<arr[min]){
                min=j;
            }
        }
        int temp=arr[i];
        arr[i]= arr[min];
        arr[min]=temp;
    }
}
void Merge(int arr[],int l,int m,int r){
    int n1=m+1;
    int n2=r-m;
    int L[n1],R[n2];
    for(int i=0;i<n1;i++){
        L[i]=arr[l+i];
    }
    for(int j=0 ;j<n2;j++){
        R[j]=arr[m+1+j];
    }
    int i=0,j=0,k=l;
    while(i<n1 && j<n2){
        step++;
        if(L[i]<=R[j]){
            arr[k++]=L[i++];
        }
        else{
            arr[k++]=R[j++];
        }
    }
    while(i<n1){
       arr[k++]=L[i++];
    }
    while(j<n2){
        arr[k++]=R[j++];
    }
    
}
void MergeSort(int arr[],int l,int r){
    step=0;
    if(l<r){
        int m=(l+r)/2;
        MergeSort(arr,l,m);
        MergeSort(arr,m+1,r);
        Merge(arr,l,m,r);
    }
}

int Partition(int arr[],int low, int high){
    int p=arr[high];
    int i=low-1;
    for(int j=low;j<high;j++){
        if(arr[j]<p){
            i++;
            int temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
            step++;
        }
    }
    int temp=arr[i+1];
    arr[i+1]=arr[high];
    arr[high]=temp;
    step++;
    return i+1;

    
}
void QuickSort(int arr[],int low,int high){
    if(low<high){
        int p1=Partition(arr,low,high);
        QuickSort(arr,low,p1-1);
        QuickSort(arr,p1+1,high);
    }
}

void CountSort(int arr[],int n,int exp){
    int output[n];
    int count[10]={0};
    for(int i=0;i<n;i++){
        int id=(arr[i]/exp)%10;
        count[id]++;
        step++;
    }
    for(int i=1;i<10;i++){
        count[i]+=count[i-1];
    }
    for(int i=n-1;i>=0;i--){
        int id=(arr[i]/exp)%10;
        output[count[id]-1]=arr[i];
        count[id]--;
        step++;
    }
    for(int i=0;i<n;i++){
        arr[i]=output[i];
        step++;
    }
}
void RadixSort(int arr[],int n){
    step=0;
    int m=arr[0];
    for(int i=1;i<n;i++){
        if(arr[i]>m){
            m=arr[i];
        }
    }
    for(int exp=1;m/exp>0;exp*=10){
        CountSort(arr,n,exp);
    }
}
void main(){
    int i ,n,arr[10],l,r,op,low,high;
    printf("enter the no.of elements in an array: ");
    scanf("%d",&n);
    printf("Enter the Elements: ");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("Your array is:[ ");
    for(i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("]");
    
    printf("\n1.InsertionSort\t2.SelectionSort\t3.MergeSort\t4.QuickSort\t5.RadixSort");
    printf("\nEnter the Option: ");
    scanf("%d",&op);
    if(op==1){
        //Insertion Sort
        InsertionSort(arr,n);
        printf("\nInsertion Sort:[ ");
        for(i=0;i<n;i++){
            printf("%d ",arr[i]);
        }
        printf("]");
        printf("\nSteps: %d",step);
    }
    else if(op==2){
        //Selection Sort
        SelectionSort(arr,n);
        printf("\nSelection Sort:[ ");
        for(i=0;i<n;i++){
            printf("%d ",arr[i]);
        }
        printf("]");
        printf("\nSteps: %d",step);


    }
    else if(op==3){
        //Merge Sort
        l=0;
        r=n-1;
        MergeSort(arr,l,r);
        printf("\nMerge Sort:[ ");
        for(i=0;i<n;i++){
            printf("%d ",arr[i]);
        }
        printf("]");
        printf("\nSteps: %d",step);

    }
    else if(op==4){
        //Quick Sort
        low=0;
        high=n-1;
        QuickSort(arr,low,high);
        printf("\nQuick Sort:[ ");
        for(i=0;i<n;i++){
            printf("%d ",arr[i]);
        }
        printf("]");
        printf("\nSteps: %d",step);

    }
    else if(op==5){
        //Radix Sort
        RadixSort(arr,n);
        printf("\nRadix Sort:[ ");
        for(i=0;i<n;i++){
            printf("%d ",arr[i]);
        }
        printf("]");
        printf("\nSteps: %d",step);


    }
    else{
        printf("invalid");
    }
}