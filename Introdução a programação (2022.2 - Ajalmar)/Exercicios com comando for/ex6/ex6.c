#include<stdio.h>
int S;
int main(){
    for(int i=1;i<=100;i++){
        static int s=0;
        if(i%9==0){

        }else{
            s=s+i;

        }
        S=s;
    }
    printf("Soma de [1,100] sem os multiplos de 9:%i",S);
}