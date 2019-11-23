#include <stdio.h>
#include <math.h>

void splint(double xa[], double ya[], double y2a[], int n, double x, double *y)
{
  int klo,khi,k;
  double h,b,a;
  klo=0;
  khi=n-1;
  while (khi-klo > 1) {
    k=(khi+klo) >> 1;
    if (xa[k] > x) khi=k;
    else klo=k;
  }
  h=xa[khi]-xa[klo];
  a=(xa[khi]-x)/h; 
  b=(x-xa[klo])/h;
  *y=a*ya[klo]+b*ya[khi]+((a*a*a-a)*y2a[klo]+(b*b*b-b)*y2a[khi])*(h*h)/6.0;
}

void spline(double x[], double y[], int n, double yp1, double ypn, double y2[])
/*Given arrays x[0..n-1] and y[0..n-1] containing a tabulated function, i.e., yi=f(xi), with x0 < x1 < . . . < xn-1 , and given values yp1 and ypn for the first derivative of the interpolating function at points 0 and n-1, respectively, this routine returns an array y2[1..n] that contains the second derivatives of the interpolating function at the tabulated points xi. If yp1 and/or ypn are equal to 1 × 10^30 or larger, the routine is signaled to set the corresponding boundary condition for a natural spline, with zero second derivative on that boundary.*/
{
  int i,k;
  double p,qn,sig,un,u[n-2];
  if (yp1 > 0.99e30)
    y2[0]=u[0]=0.0; 
  else { 
    y2[0] = -0.5;
    u[0]=(3.0/(x[1]-x[0]))*((y[1]-y[0])/(x[1]-x[0])-yp1);
  }

  for(i=1;i<=n-2;i++) {
    sig=(x[i]-x[i-1])/(x[i+1]-x[i-1]);
    p=sig*y2[i-1]+2.0;
    y2[i]=(sig-1.0)/p;
    u[i]=(y[i+1]-y[i])/(x[i+1]-x[i]) - (y[i]-y[i-1])/(x[i]-x[i-1]);
    u[i]=(6.0*u[i]/(x[i+1]-x[i-1])-sig*u[i-1])/p;
  }
  if (ypn > 0.99e30)
    qn=un=0.0;
  else {
    qn=0.5;
    un=(3.0/(x[n-1]-x[n-2]))*(ypn-(y[n-1]-y[n-2])/(x[n-1]-x[n-2]));
  }
  y2[n-1]=(un-qn*u[n-2])/(qn*y2[n-2]+1.0);
  for (k=n-2;k>=0;k--)
    y2[k]=y2[k]*y2[k+1]+u[k];
}


int main(){

  int i,N = 7;
  double x[] =  { 0,1,2,3,4,5,6};
  double y[] = {0,0.842,0.909,0.141,-0.757, -0.959, -0.279};
  double yy,xx,y2[N],yp1,ypn;

  /* opções de inicialização (derivadas nas extremidades): */
  /* spline natural: */
  yp1=ypn=1.0e31;

  /* estima derivadas iniciais e finais da função (spline fixado/clamped) */
  //   yp1 = (y[1]-y[0])/(x[1]-x[0]);
  //   ypn = (y[N-1]-y[N-2])/(x[N-1]-x[N-2]);

  /* outra opção de spline fixado: */
  //   yp1=ypn=0.0;

  /* calcula derivada segunda em cada segmento */
  spline(x , y , N, yp1, ypn, y2 );


  /* utiliza y2 calulado em spline para interpolar (SPLine INTerpolation) */
  xx = 0.5;
  splint(x , y , y2 , N, xx, &yy);
  printf("%.5f %.5f\n", xx, yy);

  return 0;
}
