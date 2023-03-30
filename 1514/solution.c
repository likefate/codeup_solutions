#include <stdio.h>
int a[7][7]={};
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
void spliter(int splx,int sply,int nx,int ny){
    int i,x,y;
    for (i=0;i<4;i++){
        x=0;
        y=0;
        if (dx[i]==-nx&&dy[i]==-ny)continue;
        else{
            while (splx+x+dx[i]>=0&&sply+y+dy[i]>=0&&splx+x+dx[i]<=6&&sply+y+dy[i]<=6){
                x+=dx[i];
                y+=dy[i];
                if (a[splx+x][sply+y]==2){
                    spliter(splx+x,sply+y,dx[i],dy[i]);
                    break;
                }else{
                    a[splx+x][sply+y]=1;
                }
            }
        }
    }
}

int main(){
    int i,j,x,y;
    for (i=0;i<3;i++){
        scanf(" %d %d",&x,&y);
        a[x-1][y-1]=2;
    }
    x=3;
    y=-1;
    while (y<=5){
        y++;
        if (a[x][y]==2){
            spliter(x,y,0,1);
            break;
        }else{
            a[x][y]=1;
        }
    }
    for (i=0;i<7;i++){
        for (j=0;j<7;j++){
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
}
