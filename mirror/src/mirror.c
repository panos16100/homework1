#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX pow(10,15)
#define MIN 1



unsigned long long  mirror(unsigned long long n){
   unsigned long long result=0;
   unsigned  int temp;
    while (n>0){
        temp=n%10;
        result=result*10+temp;
        n/=10;
    }
    return result;
}

  unsigned int check(unsigned long long n){
    
    if (!(n%2)){
        return 0;
    }
    unsigned long long h,final=sqrt(n);

    for(h=3;h<=final;h+=2){
        if (!(n%h)){
            return 0;
        }
    }
    return 1;
 }


int main(int argc,char**argv){
    if (argc!=3){
        printf("sorry but you have to check it again\n");
        return 1;
    }
    unsigned long long low=atoll(argv[1]);
    unsigned long long high=atoll(argv[2]);
    if(low>high)
       return 1;
    else if ((low<MIN)||(high>MAX))
       return 1;
    else{
        unsigned long long low_sqrt=ceil(sqrt(low)); //αριθμό προς τα πανω(ακεραιο)
        unsigned long long i,j,sum=0;
        for(i=low_sqrt;i*i<=high;i++){
            j=i*i;
            if (check(i)){
                unsigned long long mirror_number=mirror(j);
                if (mirror_number!=j){
                    unsigned long long x=sqrt(mirror_number);
                    if ((mirror_number==x*x)&&(check(x)))
                       sum+=j;
                        
                    
                    
                        
                                   
                   
                }
            }
        }
        printf(" %llu\n",sum);
        return 0;
        
    }
}



