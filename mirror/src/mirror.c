#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX pow(10,15) //άνω επιτρεπτό όριο
#define MIN 1 //κάτω επιτρεπτό όριο



unsigned long long  mirror(unsigned long long n){
   unsigned long long result=0;
   unsigned  int temp;
    while (n>0){
        temp=n%10;
        result=result*10+temp;
        n/=10;
    }
    return result; //η συνάρτηση mirror γυρνάει ως έξοδο το κάτοπτρο του φυσικού αριθμού που παίρνει ως είσοδο
}

  unsigned int check(unsigned long long n){ //η συνάρτηση check ελέγχει αν ο φυσικός αριθμός που παίρνει ως είσοδο είναι πρώτος ή όχι
    
    if (!(n%2)){ //αν ο φυσικός αριθμός είναι άρτιος(υπόλοιπο της διαίρεσης αυτού με το 2 είναι 0)
        return 0; 
    }
    unsigned long long h,final=sqrt(n); /*χρησιμοποιώ την μεταβλητή final και τρέχω την for παρακάτω μέχρι την συγκεκριμένη μεταβλητή
    καθώς ως γνωστών ένας αριθμός δεν έχει διαιρέτες μεγαλύτερους απο την ρίζα του*/

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
    //μετατροπή των αλφαριθμητικών που δίνει ο χρήστης σε ακέραιες μεταβλητές μέσω της συνάρτησης atoll που ορίζεται στο stdlib.h
    unsigned long long low=atoll(argv[1]); 
    unsigned long long high=atoll(argv[2]);
    if(low>high)
       return 1;
    else if ((low<MIN)||(high>MAX))
       return 1;
    else{
        unsigned long long low_sqrt=ceil(sqrt(low));  /*χρησιμοποιώ την συνάρτηση ceil η οποία ορίζεται στην βιβλιοθήκη math.h σε 
        περίπτωση που η ρίζα του low δεν είναι ακέραιος αριθμός.Με αυτόν τον τρόπο ελέγχω κατευθείαν αν οι αριθμοί είναι πρώτοι κλπ καθώς
        όλοι οι αριθμοί που ανήκουν στην for αν υψωθούν στο τετράγωνο είναι τέλεια τετράγωνα*/
        unsigned long long i,j,sum=0;
        for(i=low_sqrt;i*i<=high;i++){
            j=i*i; //η ακέραια μεταβλητή j είναι τέλειο τετράγωνο του αριθμού i
            if (check(i)){ //έλεγχος αν ο αριθμός i είναι πρώτος μέσω της συνάρτησης check
                           //εννοείται check(i)==1 καθώς τιμές διάφορες του 0 συμβολίζουν την αλήθεια μιας συνθήκης
                unsigned long long mirror_number=mirror(j);/*αναθέτω στην ακέραια μεταβλητή mirror_number το κάτοπτρο του αριθμού 
                j μέσω της συνάρτησης mirror*/
                if (mirror_number!=j){ //ο αριθμός j δεν είναι παλινδρομικός
                    unsigned long long x=sqrt(mirror_number);
                    if ((mirror_number==x*x)&&(check(x))) /*έλεγχος αν το κάτοπτρο του αριθμού j,δηλαδή η μεταβλητή
                    mirror_number είναι τέλειο τετράγωνο του αριθμου/μεταβλητής x που ορίσαμε ακριβώς παραπάνω και έλεγχος για το
                    αν ο αριθμός x είναι πρώτος*/
                       sum+=j;
                        
                    
                    
                        
                                   
                   
                }
            }
        }
        printf(" %llu\n",sum);
        return 0;
        
    }
}



