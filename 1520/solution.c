#include <stdio.h>

int a[170][170]={};
int b[170][170]={};
int dx[8]={1,1,1,0,0,-1,-1,-1};
int dy[8]={1,0,-1,1,-1,1,0,-1};

int main(){
    int i,j,k,c,m,n,bo,del1,del2,r,kk;
    scanf("%d %d",&m,&n);
    scanf("%d %d %d",&bo,&del1,&del2);
    for (i=0;i<m;i++){
        for (j=0;j<n;j++){
            scanf(" %d",&a[i][j]);
        }
    }
    scanf(" %d",&r);
    for (kk=0;kk<r;kk++){
        for (i=0;i<m;i++){
            for (j=0;j<n;j++){
                c=0;
                for (k=0;k<8;k++){
                    if (i+dx[k]>=0&&i+dx[k]<m&&j+dy[k]>=0&&j+dy[k]<n){
                        if (a[i+dx[k]][j+dy[k]]){
                            c++;
                        }
                    }
                }
                if (a[i][j]){
                    if (c>=del2||c<del1)b[i][j]=0;
                    else b[i][j]=1;
                }else{
                    if (c==bo)b[i][j]=1;
                }
            }
        }
        for (i=0;i<m;i++){
            for (j=0;j<n;j++){
                a[i][j]=b[i][j];
                b[i][j]=0;
            }
        }
    }
    for (i=0;i<m;i++){
        for (j=0;j<n;j++){
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
}
