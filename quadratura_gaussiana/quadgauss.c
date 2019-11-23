#include <math.h>
#include <stdio.h>

#include "gaussxw.h"

double f(double x){
  return pow(x,4) - 2*x + 1;
}

int main(){
  int i, N = 3;
  double xk[N],wk[N]; //posições e pesos
  double soma,a,b;

  //define limites de integração (a,b)
  a=0.0;
  b=2.0;

  //calcula posições e pesos
  gaussxw(N,a,b,xk,wk);


  //calcula integral e imprime resultado:
  soma=0.0;
  for(i=0;i<N;i++)
    soma += wk[i]*f(xk[i]);

  printf("%.15e\n",soma);

  return 0;
}
