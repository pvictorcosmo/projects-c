#include<stdio.h>
int ff(){
    static int n1= 1;
    static int n2= 0;
    int aux=n2;
    n2=n1+n2;
    n1=aux;
    return n1;

}

int main(){
    int n;
    for(n=1;n<21;n++){
    printf("%d\n", ff());
    }    
}