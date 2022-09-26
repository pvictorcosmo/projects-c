#include<stdio.h>

int pp ( int x ) 
{
  int i , div = 0 ;
  for( i = 1 ; i <= x ; i ++ )
  {
   if(x%i==0)
   {
     div=div+1;
   }
  }
  if(div==2)
  {
    return 1;
  } 
  else
  {
    return 0;
  }
}
  //Essa função testa se os valores são primos, ou seja, se o valor for primo ele vai retornar 1, caso contrario retorna 0

int main()
{ 
  int i, nn,aux=0;
  printf ( "Digite seu numero:" ) ;
  scanf ( "%i" , &nn ) ;
  printf( "O intervalo [2,%d] de numeros primos sao:\n", nn ) ;
  for( i = 1 ; i <= nn ; i ++ )
   {
    if( pp (i) == 1 )
    {
     printf ("%d\n" , i);
     aux=aux+i;
    }
   }
  
  printf("A soma eh igual a: %i\n",aux);   
  system("pause");
}     