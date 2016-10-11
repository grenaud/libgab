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
    // cout<<("19"<"1")<<endl;
    // return 1;
    
    // cout<<compare2Chrs("chr10","chr1")<<endl;
    // cout<<compare2Chrs("chr20","chr1")<<endl;
    //cout<<compare2Chrs("chrX","chrUn")<<endl;

    //return 1;
    string  horsechr[] = { "chr10","chr11","chr12","chr13","chr14","chr15","chr16","chr17","chr18","chr19","chr1","chr20","chr21","chr22","chr23","chr24","chr25","chr26","chr27","chr28","chr29","chr2","chr30","chr31","chr3","chr4","chr5","chr6","chr7","chr8","chr9","chrX","chrUn"};


     vector<string> horsechrV (horsechr, horsechr + sizeof(horsechr) / sizeof(horsechr[0]) );
     
     // cout<<sizeof(horsechr)<<endl;
     // cout<<sizeof(horsechr[0])<<endl;
     // cout<<horsechrV.size()<<endl;

    string  humanchr[] = { "1","2","3","4","5","6","7","8","9","10","11","12","13","14","15","16","17","18","19","20","21","22","X","Y","MT"};

     vector<string> humanchrV (humanchr, humanchr + sizeof(humanchr) / sizeof(humanchr[0]) );

     for (unsigned int i=0; i< horsechrV.size(); i++){
     	 cout<<i<<"\t"<<horsechrV[i]<<endl;
     }
     //return 1; 
     for (unsigned int i=0; i< humanchrV.size(); i++){
     	 cout<<i<<"\t"<<humanchrV[i]<<endl;
     }



     sort(horsechrV.begin(), horsechrV.end(), cmp2Chrs );
     sort(humanchrV.begin(), humanchrV.end(), cmp2Chrs );
    
     for (unsigned int i=0; i< horsechrV.size(); i++){
	 cout<<i<<"\t"<<horsechrV[i]<<endl;
     }
     for (unsigned int i=0; i< humanchrV.size(); i++){
     	 cout<<i<<"\t"<<humanchrV[i]<<endl;
     }

    // cout<<compare2Chrs("1","2")<<endl;
    // cout<<compare2Chrs("10","MT")<<endl;
    // cout<<compare2Chrs("chr11","chr22")<<endl;

    // cout<<compare2Chrs("12","2")<<endl;
    // cout<<compare2Chrs("X","MT")<<endl;
    // cout<<compare2Chrs("chrX","chrUn")<<endl;


    return 1;
    cout<<getDateString()<<endl;
    cout<<getTimeString()<<endl;

    return 1;
    long double v1=(0.5);
    long double v2=(0.4);
    long double v1l=logl(v1);
    long double v2l=logl(v2);
    cout<<oplusl(v1l,v2l)<<"\t"<<exp(oplusl(v1l,v2l))<<"\t"<<(v1+v2)<<"\t"<<( exp(oplusl(v1l,v2l)) - (v1+v2)) <<endl;
    //cout<<v1<<endl;
    
    return 1;

    double valAll=0.108927;
    ifstream jackFileFP;
    vector<double> valsJ;

    jackFileFP.open("/tmp/t", ios::in);
    if (jackFileFP.good()) {
	string jackLine;
	while(getline(jackFileFP,jackLine)){
	    valsJ.push_back(destringify<double>(jackLine));
	    // vector<string> fields =allTokens(line,'\t');
	    // unsigned int f1 = destringify<unsigned int>(fields[1]);
	    // unsigned int f2 = destringify<unsigned int>(fields[0]);
	}
	jackFileFP.close();
    }
    
    pair<double,double> testDD2= computeJackknifeConfIntervals(valAll,valsJ);
    cout<<(valAll)<<"\t"<<testDD2.first<<"\t"<<testDD2.second<<endl;
    return 0;
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

