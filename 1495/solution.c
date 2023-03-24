#include <stdio.h>
int arr[1001][1001]={};
int sum[1001][1001]={};
int main(){
    int n,i,k,j,x1,y1,x2,y2,u,m;
    scanf("%d %d %d",&n,&m,&k);
    for (i=0;i<k;i++){
        scanf("%d %d %d %d %d",&x1,&y1,&x2,&y2,&u);
        arr[x1][y1] = arr[x1][y1]+u;
        arr[x2+1][y2+1] = arr[x2+1][y2+1]+u;

        arr[x1][y2+1] = arr[x1][y2+1]-u;
        arr[x2+1][y1] = arr[x2+1][y1]-u;
    }
    sum[0][0]=arr[0][0];
    printf("%d ",arr[0][0]);
    for (i=1;i<m;i++){
        printf("%d ",arr[0][i]);
        sum[0][i]=sum[0][i-1]+arr[0][i];
    }
    printf("\n");
    for (i=1;i<n;i++){
        printf("%d ",arr[i][0]);
        sum[i][0]=arr[i][0]+sum[i-1][0];
        for (j=1;j<m;j++){
            printf("%d ",arr[i][j]);
            sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+arr[i][j];
        }
        printf("\n");
    }
    printf("\n");
    for (i=0;i<n;i++){
        for (j=0;j<m;j++){
            printf("%d ",sum[i][j]);
        }
        printf("\n");
    }
}
