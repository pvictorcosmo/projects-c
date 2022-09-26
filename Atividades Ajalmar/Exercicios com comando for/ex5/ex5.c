#include<stdio.h>
#include<stdlib.h>
float P,I,Medp,Medi;
int pimp(int x){
    if(x%2==0){
        return 1;

    }else{
        return 0;
    }
}
int main(int argc,char *argv[]){
    float medf;
    for(int i=1;i<=10;i++){
        static float p,im,medp=0.0,medi=0.0;
        if(pimp(atoi(argv[i]))==1){
            p++;
            medp=atof(argv[i])+medp;
        }
        else if(pimp(atoi(argv[i]))==0){
            im++;
            medi=atof(argv[i])+medi;
        }
        Medp=medp;
        Medi=medi;
        P=p;
        I=im;
    }
    medf=(Medp+Medi)/10;
    Medp=Medp/P;
    Medi=Medi/I;

    printf("Numero de pares:%.1f\n",P);
    printf("Numero de impares:%.1f\n",I);
    printf("Media dos pares:%.1f\n",Medp);
    printf("Media dos impares:%.1f\n",Medi);
    printf("Media total:%.1f\n",medf);


}