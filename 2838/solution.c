#include <stdio.h>
#include <math.h>

int main(){
    int n,i,r=0,c=0,k,j,l,m,o,oc=0;
    int a[3] = {};
    scanf("%d",&n);
    if (n<12){
        printf("%d",0);
    }else{
        for (i=12;i<=n;i++){
            for (k=1;k<i;k++){
                for (j=k+1;j<i;j++){
                    l = i-j;
                    m = j-k;
                    if((pow(k,2)+pow(m,2)==pow(l,2))||(pow(l,2)+pow(m,2)==pow(k,2))||(pow(k,2)+pow(l,2)==pow(m,2))){
                        for (o=0;o<3;o++){
                            if (a[o]==k||a[o]==m||a[o]==l){
                                oc+=1;
                            }
                        }
                        if (oc!=3){
                            c++;
                            a[0] = k;
                            a[1] = m;
                            a[2] = l;
                        }
                        //printf("(%d %d %d, %d)\n",k,m,l,oc);
                        oc=0;
                    }
                }
            }
            if (c==1){
                r++;
            }
            c=0;
        }
        printf("%d",r);
    }
    return 0;
}
