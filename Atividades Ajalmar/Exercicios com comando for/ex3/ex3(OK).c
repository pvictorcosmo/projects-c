#include<stdio.h>
#include<stdlib.h>
float B;
float neg,pos;
int main (int argc, char * argv []){
  for(int i=1;i<=10;i++){
    static int med= 0;
    static float p= 0.0, n=0.0;
    med = atoi ( argv[i] ) + ( med );
    printf("%i\n",med);
    B=med;
    if (atoi (argv[i]) > 0) {
        p=p+1.0;
    }
    else if (atoi (argv[i]) < 0) {
        n = n+1.0;
    }
    pos = p;
    neg = n;



    }  
B=B/10;    
printf ("media igual a = %.2f\n", B );
printf ("Tem %.1f numeros positivos\n", pos );
printf ("tem %.1f numeros negativos\n", neg );
pos= ( pos/10 ) *100;
neg= ( neg/10 ) *100;
printf ("Tem %.1f%% numeros positivos\n", pos );
printf ("tem %.1f%% numeros negativos", neg );
 
}