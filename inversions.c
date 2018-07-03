#include<stdio.h>

void merger(int a[], int L, int M, int R);
void mergsort(int a[], int L, int R);

long long cnt = 0;

int main()
{
    int a[65538], n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    cnt = 0;
    mergsort(a, 0, n - 1);
    // for(int i = 0; i < n; i++){
    //     printf("%d ", a[i]);
    // }
    printf("%lld", cnt);
    return 0;
}


void mergsort(int a[], int L, int R){
    if(R == L){
        return;
    }else{
        int M = (L + R) / 2;
        mergsort(a, L, M);
        mergsort(a, M + 1, R);
        merger(a, L, M, R);
    }
}

void merger(int a[], int L, int M, int R){
    int temp[65538], i = L, j = M + 1, k = L;
    while(i <= M && j <= R){
        if(a[i] <= a[j]){
            temp[k++] = a[i++];
        }else{
            //printf("%d---%d\n", cnt, i);
            cnt += M - i + 1;
            temp[k++] = a[j++];
        }
    }
    while(i <= M){
        temp[k++] = a[i++]; 
    }
    while(j <= R){
        temp[k++] = a[j++];
    }
    for(i = L; i <= R; i++){
        a[i] = temp[i];
    }
}


// #include <stdio.h>
// int arrTmp[100010];         //定义一个临时数组
// //归并两个分段的结果，两个分段是数组中的[low,mid]以及[mid+1,high]中的元素
// long long num;
// void Merge(int arr[],int low,int mid,int high){
// 	int i=low,j=mid+1,k=low;    //I、J、K分别指向待归并的两段以及临时数组
// 	while(i<=mid&&j<=high){
// 		if(arr[i]<=arr[j]){
// 			arrTmp[k++]=arr[i++];
// 		}else{
// 			arrTmp[k++]=arr[j++];
// 			num+=mid-i+1;  //统计逆序数量
// 		}
// 	}
// 	while(i<=mid){
// 		arrTmp[k++]=arr[i++];
// 	}
// 	while(j<=high){
// 		arrTmp[k++]=arr[j++];
// 	}
// 	for(i=low;i<=high;i++){
// 		arr[i]=arrTmp[i];
// 	}
// }
// void MergeSort(int arr[],int low,int high){
// 	if(low<high){
// 		int mid=(low+high)/2;
// 		MergeSort(arr,low,mid);
// 		MergeSort(arr,mid+1,high);
// 		Merge(arr,low,mid,high);
// 	}
// }
// int main(){
// 	int T;
// 	while(scanf("%d",&T)!=EOF){
// 		for(int i=0;i<T;i++){
// 			int N;
// 			num=0;
// 			scanf("%d",&N);
// 			int arr[N];
// 			for(int j=0;j<N;j++){
// 				scanf("%d",&arr[j]);
// 			}
// 			MergeSort(arr,0,N-1);
// 			printf("%lld\n",num);
// 		}
 
// 	}
// }

