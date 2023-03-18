#include <stdio.h>
#include <math.h>

//최대공약수
long long int gcd(long long int a, long long int b){
    return b?gcd(b,a%b):a;
}

//유클리드 호제법 확장
void printGcd(long long int a, long long int b, long long int c){
    long long int r1=a,r2=b,t1=0,t2=1,s1=1,s2=0,r,s,t,q;
    while (r2){
        q=r1/r2;
        r=r1%r2;
        r1=r2;
        r2=r;

        s=s1-q*s2;
        s1=s2;
        s2=s;

        t=t1-q*t2;
        t1=t2;
        t2=t;
    }
    printf("%lld %lld",s1*c/r1,t1*c/r1);
}

int main(){
    long long int a,b,c;
    scanf("%lld %lld %lld",&a,&b,&c);
    if (a==0){
        if (b==0){
            if (c==0){
                printf("0 0");
            }else{
                printf("Not Exist");
            }
        }else{
            if (c==0){
                printf("0 0");
            }else{
                if (abs(c)>=abs(b) && c%b==0){
                    printf("0 %lld",c/b);
                }else{
                    printf("Not Exist");
                }
            }
        }
    }else if (b==0){
        if (c==0){
                printf("0 0");
        }else{
            if (abs(c)>=abs(a) && c%a==0){
                printf("%lld 0",c/a);
            }else{
                printf("Not Exist");
            }
        }
    }else if (c==0){
        printf("0 0");
    }else if (c%gcd(a,b)!=0){
        printf("Not Exist");
    }else{
        printGcd(a,b,c);
    }
}
