/**********************************************************************
 * Contém as funções para calcular os pontos de integração e pesos    *
 * para quadratura Gauss-Legendre.                                    *
 *                                                                    *
 * Baseado no código aberto fornecido por Mark Newman.                *
 *                                                                    *
 * O polinômio de Legendre e sua derivada são calculados usando as    *
 * fórmulas recursivas de Bonnet (ver Abramowitz and Stegun 22.7.10)  *
 * e os zeros do polinômio de Legendre de grau N são encontrados via  *
 * método de Newton, tomando como condições iniciais a aproximação    *
 * dada em Abramowitz and Stegun 22.16.6. A funcionalidade dessas     *
 * funções foram verificadas frente a outras fontes para valores até  *
 * N=1000.                                                            *
 *                                                                    *
 **********************************************************************/

void legendre(double x, int ORDEM, double resposta[2]){ 
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

void zerosEpesos(int N, double zeros[], double pesos[]){
  int m;
  double x,dx,P[2];

  for(m=N;m>=1;m--){
    x  = (4.*m-1.)/(4.*N+2.)*M_PI;
    x = cos(x + 1/tan(x)/8/N/N);

    dx = 1;
    
    while(fabs(dx)>1e-15){
      legendre(x,N,P);
      dx = P[0]/P[1];
      x -= dx;
    }
    zeros[N-m] = x;
    pesos[N-m] = 2*(N+1)*(N+1)/(N*N*(1-x*x)*P[1]*P[1]); 
  }
}

void gaussxw(int N, double a, double b,double zeros[],double pesos[]){
  int i;
  
  zerosEpesos(N,zeros,pesos);
  
  for(i=0;i<N;i++){
    zeros[i] = 0.5*(b-a)*zeros[i] + 0.5*(b+a);
    pesos[i] = 0.5*(b-a)*pesos[i];
  }
  
  return;
}

