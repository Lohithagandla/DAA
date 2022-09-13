#include<stdio.h>

void heapify(int heap[],int n,int i){
         int smallest=i;
         int left=2*i+1;
         int right=2*i+2;
         if(left<n && heap[left]<heap[smallest])
                       smallest=left;
         if(right<n && heap[right]<heap[smallest])
                       smallest=right;
         if(smallest!=i){
                  int temp=heap[i];
                  heap[i]=heap[smallest];
                  heap[smallest]=temp;
                  heapify(heap,n,smallest);
         }
}
void print(int heap[],int n){
	int i;
        for( i=0;i<n;i++){
                printf("%d\t",heap[i]);
        }
}

void heapsort(int heap[],int n){
         int i;
         for( i=n/2-1;i>=0;i--){
                   heapify(heap,n,i);
         }
         printf("\nElements in min heap are: \n");
         print(heap,n);
    
         for(i=n-1;i>0;i--){
                 int temp=heap[i];
                 heap[i]=heap[0];
                 heap[0]=temp;
                 heapify(heap,i,0);
         }
         
}


int main(){
           int n,i;
           printf("Enter size of array: ");
           scanf("%d",&n);
           int heap[n];
          for( i=0;i<n;i++){
                   printf("Enter %d index element: ",i);
                   scanf("%d",&heap[i]);
          }
          heapsort(heap,n);
          printf("\nSorted elements are: \n");
          print(heap,n);
}
