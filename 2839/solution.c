#include <stdio.h>
#include <stdlib.h>

int stack[1000000][2];
int top = -1;

void push(int x,int y){
    top++;
    stack[top][0] = x;
    stack[top][1] = y;
}

void initStack(){
    top = -1;
}

int* pop(){
    return stack[top--];
}

int main(){
    int h,w,i,j,k,x=0,y=0,c=0,cc=0,o,p,l;
    scanf("%d %d",&h,&w);
    int m[h][w];
    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,1,0,-1};
    int* forc;
    for (i=0;i<h;i++){
        for(j=0;j<w;j++){
            scanf("%01d",&m[i][j]);
        }
    }
    for (i=0;i<h;i++){
        for(j=0;j<w;j++){
            if (m[i][j] == 1){
                c++;
                m[i][j] = -1;
                x = 0;
                y = 0;
                cc = 0;
                l=0;
                initStack();
                while (cc==0 || x!=0 || y!=0 || l==0){
                    cc=1;
                    for (k=0;k<4;k++){
                        if (i+x+dx[k]>=0&&i+x+dx[k]<h&&j+y+dy[k]>=0&&j+y+dy[k]<w){
                            if (m[i+x+dx[k]][j+y+dy[k]] == 1){
                                push(x,y);
                                cc=0;
                                x+=dx[k];
                                y+=dy[k];
                                m[i+x][j+y] = -1;
                                break;
                            }
                        }
                    }
                    if (cc==1){
                        if (top >= 0){
                            forc = pop();
                            x=forc[0];
                            y=forc[1];
                        }else{
                            l=1;
                        }
                    }
                }
            }
        }
    }
    printf("%d",c);
    return 0;
}
