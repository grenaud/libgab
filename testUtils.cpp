/*
 * testUtils
 * Date: Aug-20-2012 
 * Author : Gabriel Renaud gabriel.reno [at sign here ] gmail.com
 *
 */

#include <iostream>
#include <fstream>

#include "utils.h"

using namespace std;

int main (int argc, char *argv[]) {
    if(0)
	for(int i=0;i<1000;i++){
	    cout<<randomBool()<<endl;
	}


    for(int k=0;k<1;k++){

	vector<string> s1=allTokens(":0/0:57:99:0,162,2093:26,30:0,0:0,0:0,0:0:",':');
	// string a=string("0/0:57:99:0,162,2093:26,30:0,0:0,0:0,0:0");
	// string b=string(":");
	// vector<string> s1=allTokens(a,b);
	for(unsigned int i=0;i<s1.size();i++){
	    cout<<"#"<<s1[i]<<"#"<<endl;
	}
    }
    
    return 0;
}

