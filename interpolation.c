#include<stdio.h>
int isearch(int arr[],int si,int ei,int k)
{
    int mid;
    while (si<=ei) {
        mid = si + (ei - si)*((k-arr[si])/(arr[ei]-arr[si]));
        if (arr[mid] == k)
        {
            return mid;
        }
        if (arr[mid] > k)
        {
            ei = mid - 1;
        }
        else
        {
            si = mid + 1;
        }    
    }
    return -1;
}

int main()
{
    int n,i;
    int arr[10];
    int k;
    int res;
    printf("Enter array length");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Enter Element to search");
    scanf("%d",&k);
     
    res = isearch(arr,0,n-1,k);
    if(res == -1)
    {
        printf("Element not found");
    }
    else
    {
        printf("Element is found at %d\n",res+1);
    }
    return 0;
}
