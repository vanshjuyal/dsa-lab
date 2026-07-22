#include <stdio.h>
int main() {
    int arr[100] ,n;
    printf("enter the sizeof array\n");
    scanf("%d",&n);
    printf("now enter elements:\n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("enter the pos to be deleted\n");
    int pos;
    scanf("%d",&pos);
    for(int i=pos-1;i<n-1;i++){
        arr[i]=arr[i+1];
    }
    printf("elements of array are: \n");
    for(int i=0;i<n-1;i++){
        printf("%d\n",arr[i]);
    }
    return 0;
}
