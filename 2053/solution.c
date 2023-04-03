#include <stdio.h>
#include <stdlib.h>

int main(){
    int n,x,y,a,b,i,j,k,p=0;
    scanf("%d",&n);
    scanf(" %d %d",&x,&y);
    scanf(" %d %d",&a,&b);
    int z[2000] = {};
    for (i=0;i<b;i++){
        if (z[i] == 0){
            for (k=i;k<b-2;k+=(i+2)){
                z[k] = 1;
            }
            z[i] = 2;
        }else continue;
    }
    int result[b];
    for (i=0;i<b;i++){
        if (z[i] == 2 && i+2>=a){
            result[p] = i+2;
            p++;
        }else continue;
    }
    for (i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%d ",result[abs((x-1)-i)+abs((y-1)-j)]);
        }
        printf("\n");
    }
    return 0;
}
