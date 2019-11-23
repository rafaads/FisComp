#include <stdio.h>
#include <math.h>

#define N 6              // número de intervalos

#define a 0.0            // limite inferior de integração
#define b 1.0            // limite superior

double func(double x){    
  return 2*x;            // integrando (função a ser integrada)
}

int main(void){
  int i;
  double h,x,soma;


  h=(b-a)/N;
  soma=0.0;
    
  for(i=0;i<N;i++){
    x = a + h*i;
    soma += h*func(x);
  }
    
  printf("%.15e\n",soma);

  return 0;
}
