#include <math.h>
#include <stdio.h>

#define dt 0.01
#define w2 3.0

main(){

  double  x=2,vnew,xnew,E,E0;
  double  v=1;
  int i;

  E0 = v*v/w2 + x*x;
  
  for(i=0;i<10000;i++){
    vnew = v - w2*x*dt;
    xnew = x + v*dt;

    v=vnew;
    x=xnew;

    E = v*v/w2 + x*x;
    
    printf("%f %f %f %f\n",i*dt,x,v,E/E0 - 1.0);
  }


}
