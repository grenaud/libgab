/*
 * testUtils
 * Date: Aug-20-2012 
 * Author : Gabriel Renaud gabriel.reno [at sign here ] gmail.com
 *
 */

#include <iostream>
#include <fstream>
#include <memory>

#include "utils.h"

using namespace std;
int randIn(int n){ 
    return rand()%n; 
}

int main (int argc, char *argv[]) {
    
    vector<double> vals;
    double sumVals=0.0;
    for (unsigned i=0; i<100; i++){
    	vals.push_back((0.5-randomProb()/10));
	sumVals+=vals[i];
    }

    vector<double> jackk;
    for (unsigned i=0; i<100; i++){
	double temp=0;
	for (unsigned j=0; j<100; j++){
	    if( i!=j){
		temp+= vals[j] ;
	    }
	}
	jackk.push_back(temp/99);
    }

    //cout<<&vals<<endl;

    pair<double,double> testDD= computeJackknifeConfIntervals(sumVals/100,jackk);
    cout<<(sumVals/100)<<"\t"<<testDD.first<<"\t"<<testDD.second<<endl;

    
    return 0;

    // cout<<RAND_MAX<<endl;
    for (unsigned i=0; i<1000000; i++){
    	cout<<randomProb()<<endl;
	//cout<<randIn(20)<<endl;
    }

    return 0;
    for(int tsss=0;tsss<2000;tsss++){
	cout<<randomLongDouble(0.1,0.5)<<endl;
    }
    return 0;

    for(int tsss=0;tsss<44;tsss++){
	cout<<tsss<<"\t"<<( (nChoosek(44,tsss)) )<<endl;
    }
    return 0;
    cout<<( (nChoosek(44,33)) )<<endl;
    cout<<( (long double)(nChoosek(44,33)) )<<endl;
    cout<<( (nChoosek(44,11)) )<<endl;
    cout<<( (long double)(nChoosek(44,11)) )<<endl;
    cout<<( (nChoosek(44,2)) )<<endl;
    cout<<( (long double)(nChoosek(44,2)) )<<endl;

    return 0;
    // for (unsigned i=0; i<20; i++){
    // 	cout<<randomInt(20,20)<<endl;
    // }
    // return 0;
    // double  data2[] = { -1747.38   ,     -393.709    ,    -463.553  ,      -742.378 };
    // cout<<firstAndSecondHighestArray(data2,4).first<<"\t"<<firstAndSecondHighestArray(data2,4).second<<endl;

    std::vector<int> myvector (10);   // 10 zero-initialized ints
    srand(939);
    // assign some values:
    for (unsigned i=0; i<myvector.size(); i++){
	myvector.at(i)=int(rand()*100);
	cout<<myvector.at(i)<<endl;
    }
    cout<<firstAndSecondHighestVector(myvector).first<<"\t"<<firstAndSecondHighestVector(myvector).second<<endl;
    return 0;

    cout<<editDistTwoStrings("TEST","TEST")<<endl;    
    cout<<editDistTwoStrings("TEST","TAST")<<endl;    
    cout<<editDistTwoStrings("TEST","FAST")<<endl;    

    return 0;
    cout<<isInt("1")<<endl;
    cout<<isInt("-1")<<endl;
    cout<<isInt("123.3")<<endl;
    cout<<isInt("boo")<<endl;
    cout<<isPositiveInt("1")<<endl;
    cout<<isPositiveInt("-1")<<endl;
    cout<<isPositiveInt("123.3")<<endl;
    cout<<isPositiveInt("boo")<<endl;
    return 0;
    cout<<isDos("/tmp/dos.fa.gz")<<endl;
    cout<<isDos("/tmp/mac.fa.gz")<<endl;
    cout<<isDos("/tmp/mac2.fa.gz")<<endl;
    cout<<isDos("/tmp/unix.fa.gz")<<endl;
    cout<<endl;
    cout<<isDos("/tmp/dos.fa")<<endl;
    cout<<isDos("/tmp/mac.fa")<<endl;
    cout<<isDos("/tmp/mac2.fa")<<endl;
    cout<<isDos("/tmp/unix.fa")<<endl;
    cout<<endl;
    cout<<isMac("/tmp/dos.fa")<<endl;
    cout<<isMac("/tmp/mac.fa")<<endl;
    cout<<isMac("/tmp/mac2.fa")<<endl;
    cout<<isMac("/tmp/unix.fa")<<endl;

    return 0;
    
    int data[] = { 5, 7, 8, 9, 1, 2 };
    cout<<arrayToString(data,6,"-")<<endl;
    return 0;

     while(true)
	 cout<<randomInt(10,12)<<endl;
    // cout<<thousandSeparator(933421)<<endl;
    
    return 0;

    string n1="hello";
    string n2="1239";
    cout<<isStringNatNumber(n1)<<endl;
    cout<<isStringNatNumber(n2)<<endl;

    string toSplit= "f1\tf2   f3  f4\tf5";
    vector<string> returnVEC2 = splitWS(toSplit);  
    cout<<vectorToString(returnVEC2)<<endl;

    return 0;
    string testdna = "TAT";
    cout<<seq2uint64(testdna)<<endl;
    return 0;

    static const int arr[] = {1,4,10,16,20,22,100};
    vector<int> testVector (arr, arr + sizeof(arr) / sizeof(arr[0]) );
    vector<int> returnVEC=vectorDist(testVector);
    cout<<vectorToString(returnVEC)<<endl;
    return 0;
    for(int i=0;i<10000;i++)
	cout<<randomUint()<<endl;
    return 0;
    cout<<getDateString()<<endl;
    cout<<getTimeString()<<endl;

    return 1;
    cout<<destringify<float>("hello")<<endl;
    bool s1=destringify<bool>("0");
    bool s2=destringify<bool>("1");
    cout<<booleanAsString(s1)<<endl;
    cout<<booleanAsString(s2)<<endl;


    for(int i=0;i<1000000;i++){
	vector<string>  s1=allTokens("1:2:3:2:3:2:3:2:3:2:3:2:3",':');
	//delete(s1);
    }
    //cout<<"#"<<iteratorToString(s1," - ")<<"#"<<endl;

    return 0;


    cout<<reverseComplement("ATCG")<<endl;
    return 0;


    string testst="   asdsa ad asd\t\n ";
    cout<<"#"<<testst<<"#"<<endl;
    trimWhiteSpacesBothEnds(&testst);
    cout<<"#"<<testst<<"#"<<endl;
    



    if(0)
	for(int i=0;i<1000;i++){
	    cout<<randomBool()<<endl;
	}


    for(int k=0;k<1;k++){

	vector<string> s1;//=allTokens(":0/0:57:99:0,162,2093:26,30:0,0:0,0:0,0:0:",':');
	// string a=string("0/0:57:99:0,162,2093:26,30:0,0:0,0:0,0:0");
	// string b=string(":");
	// vector<string> s1=allTokens(a,b);
	for(unsigned int i=0;i<s1.size();i++){
	    cout<<"#"<<s1[i]<<"#"<<endl;
	}
    }
    
    return 0;
}

