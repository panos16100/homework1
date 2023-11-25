#include <stdio.h>
#include <math.h>
#include <stdlib.h>


double factorial(double a0,double a1,double a2,double a3,double a4,double a5,double xo) {
    return a0+a1*xo+a2*pow(xo,2)+a3*pow(xo,3)+a4*pow(xo,4)+a5*pow(xo,5);
    
}


double factorial_p(double a1,double a2,double a3,double a4,double a5,double xo) {
    return 5*a5*pow(xo,4)+4*a4*pow(xo,3)+3*a3*pow(xo,2)+2*a2*pow(xo,1)+a1;
}



int main(int argc,char**argv) {
    if (argc!=8){
        printf("sorry but you have to check it again\n");
        return 1;
    }
    double a0=strtod(argv[1],NULL),a1=strtod(argv[2],NULL),a2=strtod(argv[3],NULL),a3=strtod(argv[4],NULL),a4=strtod(argv[5],NULL),a5=strtod(argv[6],NULL),xo=strtod(argv[7],NULL);
    double x;
    x=xo-(factorial(a0,a1,a2,a3,a4,a5,xo)/factorial_p(a1,a2,a3,a4,a5,xo));
    int i=0;
    double result=0.0;
    do {
      i++;
      result=fabs(x-xo);
      if (i>1000){
          printf("incomplete\n");
          }
       else if (result<pow(10,-6)) {
           printf("%.2f\n",x);
           
       }
       else if (factorial_p(a1,a2,a3,a4,a5,xo)==0){
          printf("nan\n");
          
       }
       else {
        xo=x;
        x=xo-(factorial(a0,a1,a2,a3,a4,a5,xo)/factorial_p(a1,a2,a3,a4,a5,xo));

       }
    }
    while ( result>=pow(10,-6) && i<=1000 && factorial_p(a1,a2,a3,a4,a5,xo)!=0 );
    return 0;
    
    
    }