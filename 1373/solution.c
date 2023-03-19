#include <stdio.h>
#include <math.h>

//m은 항상 n보다 큼
long long int mn(int m, int n, long long int p){
    if (m<n){
        m=m+n;
        n=m-n;
        m=m-n;
    }
    int remains[2400]={};
    long long int c = 1;
    int i,j,k;
    for (i=m+n;i>m;i--){
        k=i;
        for (j=2;j<=k;j++){
            while (k%j == 0){
                k/=j;
                remains[j]++;
            }
        }
        if (i-m>0){
            k=i-m;
            for (j=2;j<=k;j++){
                while (k%j == 0){
                    k/=j;
                    remains[j]--;
                }
            }
        }
    }
    if (p != 0){
        for (i=0;i<2400;i++){
            if (remains[i] != 0){
                j=remains[i];
                for (;j>0;j--){
                    c*=i;
                    c%=p;
                }
            }
        }
    }else{
        for (i=0;i<2400;i++){
            if (remains[i] != 0){
                j=remains[i];
                for (;j>0;j--){
                    c*=i;
                }
            }
        }
    }
    return c;
}

int main(){
    int n,m,k;
    long long int p;
    scanf("%d %d %d %lld",&n,&m,&k,&p);
    m = abs(m);
    n = abs(n);
    if (m<n){
        m=m+n;
        n=m-n;
        m=m-n;
    }
    if (p){
        if (m==1&&n==1){
            printf("%d %d",4,4%p);
            return 0;
        }
        if (m==2&&n==1){
            if (!k)printf("%d %d",3,1%p);
            else printf("%d %d",5,8%p);
            return 0;
        }
        if (n==0){
            if (m==0){
                if (!k)
                printf("%d %d",4,8%p);
                else printf("%d %d",6,24%p);
                return 0;
            }else{
                if (k){
                    if (m==3){
                        printf("%d %d",5,10%p);
                    }else if (m==2){
                        printf("%d %d",4,2%p);
                    }else if (m==1){
                        printf("%d %d",5,10%p);
                    }else
                    printf("%d %d",m+2,(((m*(m-1)/2)+m)*2)%p);
                }else{
                    printf("%d %d",m+2,(((m*(m-1)/2)+m)*2)%p);
                }
                return 0;
            }
        }
        if (k){
            if (m==n){
                printf("%d %lld",m+n,(mn(m,n,p)-4+p)%p);
            }else if (abs(m-n)==1){
                printf("%d %lld",m+n,(mn(m,n,p)-3+p)%p);
            }else{
                printf("%d %lld",m+n,(mn(m,n,p)-2+p)%p);
            }
        }else{
            printf("%d %lld",m+n,(mn(m,n,p)-2+p)%p);
        }
    }else{
        if (m==1&&n==1){
            printf("%d %d",4,4);
            return 0;
        }
        if (m==2&&n==1){
            if (!k)printf("%d %d",3,1);
            else printf("%d %d",5,8);
            return 0;
        }
        if (n==0){
            if (m==0){
                if (!k)
                printf("%d %d",4,8);
                else printf("%d %d",6,24);
                return 0;
            }else{
                if (k){
                    if (m==3){
                        printf("%d %d",5,10);
                    }else if (m==2){
                        printf("%d %d",4,2);
                    }else if (m==1){
                        printf("%d %d",5,10);
                    }else
                    printf("%d %d",m+2,(((m*(m-1)/2)+m)*2));
                }else{
                    printf("%d %d",m+2,(((m*(m-1)/2)+m)*2));
                }
                return 0;
            }
        }
        if (k){
            if (m==n){
                printf("%d %lld",m+n,(mn(m,n,p)-4));
            }else if (abs(m-n)==1){
                printf("%d %lld",m+n,(mn(m,n,p)-3));
            }else{
                printf("%d %lld",m+n,(mn(m,n,p)-2));
            }
        }else{
            printf("%d %lld",m+n,(mn(m,n,p)-2));
        }
    }
}

