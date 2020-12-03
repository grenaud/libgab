/*
 * testUtils
 * Date: Aug-20-2012 
 * Author : Gabriel Renaud gabriel.reno [at sign here ] gmail.com
 *
 */

#include <iostream>
#include <fstream>
#include <memory>

#include "libgab.h"

using namespace std;
int randIn(int n){ 
    return rand()%n; 
}

int main (int argc, char *argv[]) {

    for(unsigned int c=1;c<1000;c+=1)
	cout<<thousandSeparator(c)<<endl;

    double e  = 0.2;
    double p1 = 0.01;
    double p2 = 0.55;
    double r  = (1-e)*p1 +  e*p2;
    cout<<r<<"\t"<<log(r)<<endl;
    
    double l1_e  = log(1-e);
    double le    = log(e);
    
    double lp1   = log(p1);
    double lp2   = log(p2);
    
    double lr = oplusnatl( l1_e+lp1 ,  le+lp2 );
    cout<<exp(lr)<<"\t"<<lr<<endl;
    
    cout<<"#"<<printIntAsWhitePaddedString(10,3)<<"#"<<endl;
    cout<<"#"<<printDoubleAsWhitePaddedString(12.34,3,5)<<"#"<<endl;

    cout<<isInteger("19")<<endl;
    cout<<isInteger("-3924")<<endl;
    cout<<isInteger("29349932")<<endl;
    cout<<isInteger("19a")<<endl;
    cout<<isInteger("-39_24")<<endl;
    cout<<isInteger("2934+9932")<<endl;
    
    for (int i=0; i<4; i++)
	for (int j=0; j<4; j++){
	    char b1="ACGT"[i];
	    char b2="ACGT"[j];
	    cout<<b1<<" "<<b2<<"\t"<<dinucleotide2uipac(b1,b2)<<endl;
	}
	
    
    return 0;
}

