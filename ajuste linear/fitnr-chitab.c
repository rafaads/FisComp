#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <unistd.h>


#define chi2table "./chi2.tab"

#define N 12

#define filedata  "fitparabola.dat"

void pass_comments(FILE *f1)
{
  char c;
  
  while(1){ 
    c=getc(f1);
    if(c==' '||c=='\n') continue;
    if(c=='#') {
      while((c=getc(f1))!='\n') continue;
    }
    else break;
  }
  ungetc(c,f1);
  return;
}

void fit(double x[], double y[], int ndata, double sig[], double par[5])
/*Given a set of data points x[1..ndata],y[1..ndata] with individual standard deviations sig[1..ndata], ﬁt them to a straight line y = a + bx by minimizing χ2 Returned are a,b and their respective probable uncertainties siga and sigb, the chi-square chi2*/
{
  int i;
  double wt,t,sxoss,sx=0.0,sy=0.0,st2=0.0,ss;
  double a,b,siga,sigb,chi2;

  b=0.0;
  ss=0.0;
  for (i=0;i<ndata;i++) { //...with weights
    wt=1.0/pow(sig[i],2);
    ss += wt;
    sx += x[i]*wt;
    sy += y[i]*wt;
  }

  sxoss=sx/ss;
  for (i=0;i<ndata;i++) {
    t=(x[i]-sxoss)/sig[i];
    st2 += t*t;
    b += t*y[i]/sig[i];
  }

  b /= st2; //Solve for a, b, σa, and σb.
  a=(sy-sx*(b))/ss;
  siga=sqrt((1.0+sx*sx/(ss*st2))/ss);
  sigb=sqrt(1.0/st2);

  chi2=0.0; //Calculate χ^2

  for (i=0;i<ndata;i++)
    chi2 += ((y[i]-a-b*x[i])/sig[i])*((y[i]-a-b*x[i])/sig[i]);

  par[0]=a; par[1]=b; par[2]=siga; par[3]=sigb; par[4]=chi2;
  
  return;
}

int main(void)
{
  int j,ok;
  double x[N],y[N],sig[N];
  double ytemp[N],c;
  double par[5];
  double chi2P[5][100]; //[0]=0.999 [1]=0.95 [2]=0.90 [3]=0.10 [4]=0.05
  char nome[5000];
  FILE *fa;
  

  /* ----------- open files ----------- */
  fa=fopen(filedata,"r");
  j=0;
  while (!feof(fa)) {
    ok=fscanf(fa,"%lf %lf %lf",&x[j],&y[j],&sig[j]);
    j++;
  }
  fclose(fa);

  //[0]=0.999 [1]=0.95 [2]=0.90 [3]=0.10 [4]=0.05
  fa=fopen(chi2table,"r");
  pass_comments(fa);
  j=0;  while (!feof(fa)) {
    ok=fscanf(fa,"%*d %f %f %*f",&chi2P[3][j],&chi2P[4][j]);
    ok=fscanf(fa,"%*f %*f %f %f",&chi2P[2][j],&chi2P[1][j]);
    ok=fscanf(fa,"%*f %*f %f",&chi2P[0][j]);
    j++;
  }
  fclose(fa);

  /* -----------  ----------- */
  /* -----------  ----------- */
  /* -----------  ----------- */
  /* -----------  ----------- */

  for(c=-0.2;c<0.0;c+=0.001){

    for(j=0;j<N;j++)
      ytemp[j] = y[j] - c*pow(x[j],2);
    
    
    fit(x,ytemp,N,sig,par);

    printf("%f \t", c);
    for(j=0;j<5;j++)
      printf("%f ", par[j]);
    printf("\n");
  }
  
  return 0;
}
