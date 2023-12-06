#include <stdio.h>
//η βιβλιοθήκη <math.h> είναι απαραίτητη λόγω της χρήσης συναρτήσεων όπως pow(x,y) και fabs(x)
#include <math.h>
#include <stdlib.h>

//δημιούργησα μία συνάρτηση factorial η οποία υπολογίζει το πολυώνυμο ενός στοιχείου xo με συντελεστές πολυωνύμου α0,α1,α2,α3,α4,α5 σύμφωνα με τον γνωστό τύπο 
double factorial(double a0,double a1,double a2,double a3,double a4,double a5,double xo) {
    return a0+a1*xo+a2*pow(xo,2)+a3*pow(xo,3)+a4*pow(xo,4)+a5*pow(xo,5);
    
}

//επίσης δημιούργησα μία συνάρτηση factorial_p η οποία υπολογίζει την παράγωγο ενός στοιχείου xo του παραπάνω πολυωνύμου 
double factorial_p(double a1,double a2,double a3,double a4,double a5,double xo) {
    return 5*a5*pow(xo,4)+4*a4*pow(xo,3)+3*a3*pow(xo,2)+2*a2*pow(xo,1)+a1;
}



int main(int argc,char**argv) {
    //οριοθέτησα τον αριθμό των ορισμάτων(αριθμών) που ζητάω από τον χρήστη θέλω τα α0,α1,α2,α3,α4,α5 και xo οπότε αν δεν είναι 8 πρέπει να επιστρέψει 1
    if (argc!=8){
        printf("sorry but you have to check it again\n");
        return 1;
    }
    //ένταξα αυτά τα ορίσματα κατάλληλα στον αλγόριθμο μου με την βιβλιοθήκη strtod σε double 
    double a0=strtod(argv[1],NULL),a1=strtod(argv[2],NULL),a2=strtod(argv[3],NULL),a3=strtod(argv[4],NULL),a4=strtod(argv[5],NULL),a5=strtod(argv[6],NULL),xo=strtod(argv[7],NULL);
    double x;//το x ανιπαριστά το xν+1 ενώ το xo xν
    x=xo-(factorial(a0,a1,a2,a3,a4,a5,xo)/factorial_p(a1,a2,a3,a4,a5,xo));//υπολογίζω το x σύμφωνα με τον κατάλληλο τύπο χ=χο-φ(χ)/φ'(χ)
    int i=0;
    double result=0.0;
    do {
      i++;
      result=fabs(x-xo);
      if (i>1000){
          printf("incomplete\n");//αν εκτελέσει 1000 επαναλήψεις βγαινει και εμφανίζει incomplete
          }
       else if (result<pow(10,-6)) {//εξετάζω την προϋπόθεση |xn+1 − xn| < 10−6 για να βγει έξω απο την επανάληψη και εμφανίζει την ρίζα
           printf("%.2f\n",x);
           
       }
       else if (factorial_p(a1,a2,a3,a4,a5,xo)==0){//εξετάζει αν ο αλγόριθμος ολισθαίνει
          printf("nan\n");
          
       }
       else {
        xo=x;
        x=xo-(factorial(a0,a1,a2,a3,a4,a5,xo)/factorial_p(a1,a2,a3,a4,a5,xo));//ξανα υπολογίζω το x σύμφωνα με τον κατάλληλο τύπο χ=χο-φ(χ)/φ'(χ)

       }
    }
    while ( result>=pow(10,-6) && i<=1000 && factorial_p(a1,a2,a3,a4,a5,xo)!=0 );
    return 0;
    
    
    }