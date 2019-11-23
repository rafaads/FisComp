#include <math.h>
#include <stdio.h>

void legendre(double x,int ORDEM, double resposta[2]){ 
  double p0,p1,p,dp;
  int n;
  
  p0=1;
  p1=x;
  for(n=1;n<ORDEM;n++){
    p = ((2.*n+1.)*x*p1-n*p0)/(n+1.);
    p0=p1;
    p1=p;
  }
  dp = (ORDEM+1)*(p0-x*p1)/(1-x*x);

  resposta[0] = p;
  resposta[1] = dp;

  return;
}

main(){
  int N = 3,m;
  double x,dx,P[2];

  for(m=N;m>=1;m--){
    
    x  = (4.*m-1.)/(4.*N+2.)*M_PI;
    x = cos(x + 1/tan(x)/8/N/N);
    //printf("\t%d %f\n",m,x);
    dx = 1;
    
    while(fabs(dx)>1e-15){
      legendre(x,N,P);
      dx = P[0]/P[1];
      x -= dx;
      //printf("%.15e\n",x);
    }
    double w = 2*(N+1)*(N+1)/(N*N*(1-x*x)*P[1]*P[1]);
    printf("%d %f %f\n",N-m,x,w);
    
  }

}
