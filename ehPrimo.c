#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(void)
{
    int k,cont,n,i,x;

    scanf("%d",&n);
    if (n>=1 && n<=100){
        for(cont = 0; cont < n; cont++){
            scanf("%d",&x);
            k=0;
            if (x>=1){
                if (x<4){
                    printf("%d eh primo\n",x);
                }else{
                    for(i = 2 ; i < x; i++){
                        if (x%i==0){
                            k=1;
                            break;
                        }else k=2;
                    }
                }
                    if (k==1){
                        printf("%d nao eh primo\n",x);
                    }else if(k==2){
                        printf("%d eh primo\n",x);
                    }
            }
        }
    }


    return 0;
}
