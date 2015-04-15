#ifndef utils_h
#define utils_h


#include <stdint.h>
#include <bitset>
#include <cmath> 
#include <limits> 
#include <string> 
#include <vector> 
#include <stdio.h>
#include <stdlib.h>
#include <sstream> 
#include <iostream>
#include <fstream>
#include <ctime>
#include <map> 
#include <iomanip>
#include <memory>
#include <algorithm> 
#include <functional> 
#include <sys/time.h> //for srand
#include <iterator>


//For directory/file operations
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h> 
#include <dirent.h>
#include <gzstream.h>
#include <errno.h>
#include <sys/resource.h>


using namespace std;
static bool srand48Called=false;

inline char upper(const char c){
    return char(toupper(c));
}


//Check if it is either A,C,G,T,N
inline bool isValidDNA(const char c){
    char _c= upper(c);

    if(_c ==    'A')
	return true;
    if(_c ==    'C')
	return true;
    if(_c ==    'G')
	return true;
    if(_c ==    'T')
	return true;
    if(_c ==    'N')
	return true;
    return false;
}



//Check if it is either on of the ambiguous UIPAC code
inline bool isAmbiguousUIPAC(const char c){
    char _c= upper(c);

    if(_c ==    'R')
	return true;
    if(_c ==    'Y')
	return true;
    if(_c ==    'S')
	return true;
    if(_c ==    'W')
	return true;
    if(_c ==    'K')
	return true;
    if(_c ==    'M')
	return true;
    if(_c ==    'B')
	return true;
    if(_c ==    'D')
	return true;
    if(_c ==    'H')
	return true;
    if(_c ==    'V')
	return true;

    return false;
}




//Check if it is either A,C,G,T
inline bool isResolvedDNA(const char c){
    char _c= upper(c);

    if(_c ==    'A')
	return true;
    if(_c ==    'C')
	return true;
    if(_c ==    'G')
	return true;
    if(_c ==    'T')
	return true;
    return false;
}

inline int base2int(const char c){
    char _c= upper(c);

    if(_c ==    'N')
	return 0;
    if(_c ==    'A')
	return 1;
    if(_c ==    'C')
	return 2;
    if(_c ==    'G')
	return 3;
    if(_c ==    'T')
	return 4;
    cerr<<"utils.h base2int() Invalid base "<<c<<endl;
    exit(1);
}

inline int baseResolved2int(const char c){
    char _c= upper(c);
    if(_c == 'A')
	return 0;
    if(_c == 'C')
	return 1;
    if(_c == 'G')
	return 2;
    if(_c == 'T')
	return 3;
    cerr<<"utils.h baseResolved2int() Invalid base "<<c<<endl;
    exit(1);
}

//Returns an index for every 2mer of different base A,C,G,T
inline int dimer2index(const char c1,const char c2){
    char _c1= upper(c1);
    char _c2= upper(c2);


    if(_c1     ==    'A'){

	if(_c2 ==    'C')
	    return 0;
	if(_c2 ==    'G')
	    return 1;
	if(_c2 ==    'T')
	    return 2;

	cerr<<"Utils.h:1 dimer2index invalid dimer "<<c1<<" "<<c2<<endl;
	exit(1);
    }


    if(_c1     ==    'C'){

	if(_c2 ==    'A')
	    return 3;
	if(_c2 ==    'G')
	    return 4;
	if(_c2 ==    'T')
	    return 5;

	cerr<<"Utils.h:2 dimer2index invalid dimer "<<c1<<" "<<c2<<endl;
	exit(1);
    }


    if(_c1     ==    'G'){

	if(_c2 ==    'A')
	    return 6;
	if(_c2 ==    'C')
	    return 7;
	if(_c2 ==    'T')
	    return 8;

	cerr<<"Utils.h:3 dimer2index invalid dimer "<<c1<<" "<<c2<<endl;
	exit(1);
    }



    if(_c1     ==    'T'){

	if(_c2 ==    'A')
	    return 9;
	if(_c2 ==    'C')
	    return 10;
	if(_c2 ==    'G')
	    return 11;

	cerr<<"Utils.h:4 dimer2index invalid dimer "<<c1<<" "<<c2<<endl;
	exit(1);
    }



    cerr<<"Utils.h:5 dimer2index invalid dimer "<<c1<<" "<<c2<<endl;
    exit(1);
}




//Returns an index for every 2mer of different
inline int twoBases2index(const char c1,const char c2){
    char _c1= upper(c1);
    char _c2= upper(c2);

    if(_c1     ==    'A'){

	if(_c2 ==    'A')
	    return 0;
	if(_c2 ==    'C')
	    return 1;
	if(_c2 ==    'G')
	    return 2;
	if(_c2 ==    'T')
	    return 3;

	cerr<<"Utils.h:1 twoBases2index invalid dimer "<<c1<<" "<<c2<<endl;
	exit(1);
    }


    if(_c1     ==    'C'){


	if(_c2 ==    'A')
	    return 4;
	if(_c2 ==    'C')
	    return 5;
	if(_c2 ==    'G')
	    return 6;
	if(_c2 ==    'T')
	    return 7;

	cerr<<"Utils.h:2 twoBases2index invalid dimer "<<c1<<" "<<c2<<endl;
	exit(1);
    }


    if(_c1     ==    'G'){

	if(_c2 ==    'A')
	    return 8;
	if(_c2 ==    'C')
	    return 9;
	if(_c2 ==    'G')
	    return 10;
	if(_c2 ==    'T')
	    return 11;


	cerr<<"Utils.h:3 twoBases2index invalid dimer "<<c1<<" "<<c2<<endl;
	exit(1);
    }



    if(_c1     ==    'T'){

	if(_c2 ==    'A')
	    return 12;
	if(_c2 ==    'C')
	    return 13;
	if(_c2 ==    'G')
	    return 14;
	if(_c2 ==    'T')
	    return 15;

	cerr<<"Utils.h:4 twoBases2index invalid dimer "<<c1<<" "<<c2<<endl;
	exit(1);
    }



    cerr<<"Utils.h:5 twoBases2index invalid dimer "<<c1<<" "<<c2<<endl;
    exit(1);
}




inline char complement(const char c){
    if(c ==    'A')
	return 'T';

    if(c ==    'C')
	return 'G';

    if(c ==    'G')
	return 'C';

    if(c ==    'T')
	return 'A';



    if(c ==    'a')
	return 't';

    if(c ==    'c')
	return 'g';

    if(c ==    'g')
	return 'c';

    if(c ==    't')
	return 'a';



    if(c ==    'N')
	return 'N';

    cerr<<"Utils.h: complement: Invalid base pair="<<c<<endl;
    exit(1);
}



inline string reverseComplement(const string & inputString){
    string toReturn="";
    if(inputString.size() >0 )	
	for(int i=(inputString.size()-1);i>=0;i--){
	    toReturn+=complement( inputString[i] );
	}

    return toReturn;
}

inline bool starsWith(const string & header,const string & tocheck){
    return (header.substr(0, min(header.length(),tocheck.length()) ) == tocheck);
}



	
inline string boolStringify(const bool b){
    return b ? "true" : "false";
}


inline string booleanAsString(bool toprint){
    if(toprint)
	return string("currently turned on/used");
    else
	return string("not on/not used");
}


inline bool validOneBP(string & toCheck){
    if(toCheck.length() != 1)
	return false;
    char mychar=toupper(toCheck[0]);

    if(mychar == 'A')
	return true;
    if(mychar == 'C')
	return true;
    if(mychar == 'G')
	return true;
    if(mychar == 'T')
	return true;

    return false;
}

inline bool validAltBP(const string & toCheck){
    if(toCheck.length() != 1)
	return false;
    char mychar=toupper(toCheck[0]);

    if(mychar == '.')
	return true;
    if(mychar == 'A')
	return true;
    if(mychar == 'C')
	return true;
    if(mychar == 'G')
	return true;
    if(mychar == 'T')
	return true;

    return false;
}



/* inline string returnFirstToken(string & toparse,string & delim){ */
/*     size_t found; */
/*     string toreturn; */
/*     found=toparse.find(delim); */
/*     if (found!=string::npos){ */
/* 	toreturn=toparse.substr(0,found); */
/* 	toparse.erase(0,found+delim.length()); */
/* 	return toreturn; */
/*     } */
/*     toreturn=toparse; */
/*     toparse.erase(0,toparse.length()); */
/*     return toreturn; */
/* } */


/* inline vector<string> allTokens(string  & toparse,string & delim){ */
/*     vector<string> toReturn; */
   
/*     string token=returnFirstToken(toparse,delim); */
/*     while(token.length()!=0){ */
/* 	toReturn.push_back(token); */
/* 	token=returnFirstToken(toparse,delim); */
/*     } */
		
/*     return toReturn; */
/* } */



inline vector<string> allTokens(const string  & toparse,const char  delim){
    vector<string> toReturn;
    size_t lastfound=-1;
    while(true){
	size_t found = toparse.find(delim,lastfound+1);
	if (found!=string::npos){
	    toReturn.push_back(toparse.substr(lastfound+1,found-lastfound-1));
	    lastfound=found;
	}else{
	    toReturn.push_back(toparse.substr(lastfound+1));
	    break;
	}
    }
	       
    return toReturn;
}



/* inline vector<string> allTokens(const string  & toparse,const string & delim){ */
/*     if(delim.size() == 0){ */
/* 	cerr<<"Utils.h: allTokens: delim must have at least one char"<<endl; */
/* 	exit(1); */
/*     } */
/*     /\* if(delim.size() == 1) *\/ */
/*     /\* 	return allTokens(toparse,delim[0]); *\/ */

/*     cerr<<"Utils.h: allTokens: to implement"<<endl; */
/*     exit(1); */

/*     /\* vector<string> toReturn; *\/ */

 
		
/*     /\* return toReturn; *\/ */
/* } */


inline bool isInsert(const string & toCheck){
    vector<string> allt =allTokens(toCheck,',');
    for(unsigned int i=0;i<allt.size();i++){
	if(allt[i].length() > 1)
	    return true;
    }
    return false;
}




inline map<string, string> * info2map(const string & info){
    //auto_ptr< map<string, string> > toReturn  (new map<string, string>() );
    map<string, string> * toReturn = new map<string, string>() ;
    vector<string> fields=allTokens(info,';');
    for(unsigned int i=0;i<fields.size();i++){
	size_t found = fields[i].find("=");
	if (found!=string::npos){
	    (*toReturn)[fields[i].substr(0,found)]=fields[i].substr(found+1);
	}else{
	    (*toReturn)[fields[i]]="";
	}
    }
    return toReturn;
}




inline unsigned int string2uint(const string & s){
    return (unsigned int)strtoul(s.c_str(),NULL,0);
}


template <typename T>
string thousandSeparator(const T i){
    stringstream s;
    s.imbue(std::locale("en_US.UTF-8"));
    s << i;
    return s.str();
}


template <typename T>
string stringify(const T i){
    stringstream s;
    s << i;
    return s.str();
}
	
template <typename T>
T destringify( const string& s ){
    istringstream i(s);
    T x;
    if (!(i >> x)){
	cerr<<"Utils.cpp: destringify() Unable to convert string=\""<<s<<"\""<<endl;
	exit(1);
    }
    return x;
} 
	



inline bool isInt( const string& s ){
    istringstream i(s);
    int    x;
    double y;

    if( !(i >> x) ){
	return false;
    }
    
    //check if double
    if( i >> y ){
	if(x!=int(y))
	    return false;	
    }

    return true;
} 

inline bool isPositiveInt( const string& s ){
    istringstream i(s);
    int    x;
    double y;

    if( !(i >> x) ){
	return false;
    }
    
    //check if double
    if( i >> y ){
	if(x!=int(y))
	    return false;	
    }

    if(x<0)
	return false;

    return true;
} 
	

template <typename T>
string var2binary(const T i){
    stringstream s;
    std::bitset<8*sizeof(i)> x(i);
    s << x;
    return s.str();
}
	

inline bool isDirectory(const string & dir){
    struct stat st;
    if(stat(dir.c_str(),&st) == 0)
	if( st.st_mode & S_IFDIR )
	    return true;
    
    return false;
}


inline bool isFile(const string & dir){
    struct stat st;
    if(stat(dir.c_str(),&st) == 0)
	if( st.st_mode & S_IFREG )
	    return true;
    
    return false;
}


inline vector<string>  getdir (const string & dir){
    vector<string> toReturn;
    DIR *dp;
    struct dirent *dirp;
    if(  !( dp  = opendir(dir.c_str())  ) ){
	cerr <<"Cannot open directory = "<<dir<<endl;
	exit(1);   
    }

    while(  (dirp = readdir(dp)) ){
        toReturn.push_back(string(dirp->d_name));
    }
    closedir(dp);


    return toReturn;
}


inline int editDistTwoStrings (string const & str1, string const & str2){
    if (str1.length() != str2.length()){
	cerr <<"editDistTwoStrings(): Cannot count edit distance for two sequences that have different lengths"<<endl;
	exit(1);   	
    }

    int editDist=0;

    for(unsigned int i=0;i<str1.length();i++){
	if ( str1[i] != str2[i] ){
	    editDist++;
	}
    }
    
    return editDist;
}

inline bool strEndsWith (string const &stringToLookIn, string const &suffix){
    if (stringToLookIn.length() >= suffix.length()) 
        return (stringToLookIn.compare (stringToLookIn.length() - suffix.length(), suffix.length(), suffix) == 0 );
    return false;
}


inline bool strBeginsWith (string const &stringToLookIn, string const &prefix){
    if (stringToLookIn.length() >= prefix.length()) 
        return (stringToLookIn.compare (0, prefix.length(), prefix) == 0 );
    return false;
}

template <typename T>
inline string arrayToString(const T toPrint[] ,const int size,const string separator=","){
    if(size == 0){
    	return "";
    }
    string toReturn="";
    for(int i=0;i<(size-1);i++){
    	toReturn+=(stringify(toPrint[i])+separator);
    }
    toReturn+=(stringify(toPrint[ size -1 ]));
    return toReturn;
}

template <typename T>
inline string vectorToString(const vector<T> & toPrint,const string separator=","){
    if(toPrint.size() == 0){
	return "";
    }
    string toReturn="";
    for(int i=0;i<(int(toPrint.size())-1);i++){
	toReturn+=(stringify(toPrint[i])+separator);
    }
    toReturn+=(stringify(toPrint[ toPrint.size() -1 ]));
    return toReturn;
}


template <typename T>
inline string iteratorToString(const T & toPrint,const char * separator=","){
    typename T::const_iterator it;
    stringstream s;
    if(!toPrint.empty()){
	typename T::const_iterator itEnd= toPrint.end();
	--itEnd;
	for(it=toPrint.begin();it!=itEnd;it++){
	    s<<*it<<separator;
	}
	s<<*itEnd;
    }else{
	s<<"";
    }    
    return s.str();
}


/* template <typename T> */
/* inline string iteratorToString(const T & toPrint,const char * separator=","){ */
/*     stringstream s; */
/*     ostream_iterator<typename T::value_type> out_it (s,separator); */

/*     if(toPrint.size() > 1){ */
/* 	copy ( toPrint.begin(), toPrint.end()-1, out_it ); */
/* 	s<<toPrint.back(); */
/*     }else{ */
/* 	if(toPrint.size() == 1){ */
/* 	    s<<toPrint.back(); */
/* 	}else{ */
/* 	    s<<""; */
/* 	} */
/*     } */
/*     return  s.str(); */
/* } */


inline string zeroPad(const int numberToOutput,const int amountOfZeros){
    stringstream s;
    s  << setfill('0') << setw(amountOfZeros) <<numberToOutput;
    return s.str();
}

static bool srandCalled=false;
inline bool randomBool(){
    if(!srandCalled){
	timeval time;
	gettimeofday(&time, NULL);
	srand(  long((time.tv_sec * 1000) + (time.tv_usec / 1000)) );
	srandCalled=true;
    }


    if(rand() % 2 == 0)
    	return true;
    else
    	return false;
}


//returns an int betwen minV and maxV inclusive
inline int randomInt(int minV,int maxV){


    if(!srand48Called){
	timeval time;
	gettimeofday(&time, NULL);
	srand48(  long((time.tv_sec * 1000) + (time.tv_usec / 1000)) );
	srand48Called=true;
    }

    /* if(!srandCalled){ */
    /* 	timeval time; */
    /* 	gettimeofday(&time, NULL); */
    /* 	srand(  long((time.tv_sec * 1000) + (time.tv_usec / 1000)) ); */
    /* 	srandCalled=true; */
    /* } */
    
    
    if( (maxV) < (minV) ){
	cerr<<"Utils.h randomInt cannot generate an int between "<<minV<<" and "<<maxV<<endl;
	exit(1);
    }

    int temp = drand48()*(maxV-minV+1);
    return temp + minV;

    /* int temp  = rand() % (maxV-minV+1); */
    /* return temp + minV; */
}


//returns an int betwen minV and maxV inclusive
inline long double randomLongDouble(long double minV,long double maxV){
    if(!srandCalled){
	timeval time;
	gettimeofday(&time, NULL);
	srand(  long((time.tv_sec * 1000) + (time.tv_usec / 1000)) );
	srandCalled=true;
    }
    
    
    if( (maxV) < (minV) ){
	cerr<<"Utils.h randomInt cannot generate an int between "<<minV<<" and "<<maxV<<endl;
	exit(1);
    }

    long double temp  = ( (long double)( rand() ) ) / ( (long double)(RAND_MAX) ) ;
    temp = temp * (maxV-minV);
    return temp + minV;
}



inline double randomProb(){ //returns between 0 and 1
    if(!srandCalled){
	timeval time;
	gettimeofday(&time, NULL);
	srand(  long((time.tv_sec * 1000) + (time.tv_usec / 1000)) );
	srandCalled=true;
    }


    return double(rand())/double(RAND_MAX);
}

inline int callRand(){
    if(!srandCalled){
	timeval time;
	gettimeofday(&time, NULL);
	srand(  long((time.tv_sec * 1000) + (time.tv_usec / 1000)) );
	srandCalled=true;
    }
    return rand();
}



inline unsigned int randomUint(){
    if(!srand48Called){
	timeval time;
	gettimeofday(&time, NULL);
	srand48(  long((time.tv_sec * 1000) + (time.tv_usec / 1000)) );
	srand48Called=true;
    }
    unsigned int toReturn = (unsigned int)(mrand48());
    return toReturn;
}


inline char randomBPExcept(const char c){
    if(c ==    'A')
	return "CGT"[ rand()%3 ];
    if(c ==    'C')
	return "AGT"[ rand()%3 ];
    if(c ==    'G')
	return "ACT"[ rand()%3 ];
    if(c ==    'T')
	return "ACG"[ rand()%3 ];

    return "ACGT"[ rand()%4 ];
}

inline string randomDNASeq(int desiredLength){
  string toreturn="";
  if(!srandCalled){
    timeval time;
    gettimeofday(&time, NULL);
    srand(  long((time.tv_sec * 1000) + (time.tv_usec / 1000)) );
    srandCalled=true;
  }

  for(int i=0;i<desiredLength;i++){
    toreturn+= "ACGT"[ rand()%4 ];
  }
  return toreturn;
}

//! To trim white spaces
/*!
 *
 * Trims white spaces at the beginning and end of a string

  \param str : Address of string to trim
*/
static inline void trimWhiteSpacesBothEnds(string * str) { 
    str->erase(str->begin(), find_if(str->begin(), str->end(), not1(ptr_fun<int, int>(isspace))));
    str->erase(find_if(str->rbegin(), str->rend(), not1(std::ptr_fun<int, int>(isspace))).base(), str->end());// 


}


//! Returns an integer between 0 and 15  for base {A,C,G,T}x{A,C,G,T}
/*!
 * This function returns an integer according to the following table:
 * 
 * AA  0 
 * AC  1
 * AG  2
 * AT  3
 * CA  4
 * CC  5
 * CG  6
 * CT  7
 * GA  8
 * GC  9
 * GG 10
 * GT 11
 * TA 12
 * TC 13
 * TG 14
 * TT 15
*/
inline int allelePair2Int(char bp1,char bp2){
    char _bp1= upper(bp1);
    char _bp2= upper(bp2);

    if(_bp1 == 'A'){
	if(_bp2 == 'A'){
	    return 0;
	}
	if(_bp2 == 'C'){
	    return 1;
	}
	if(_bp2 == 'G'){
	    return 2;
	}
	if(_bp2 == 'T'){
	    return 3;
	}
    }

    if(_bp1 == 'C'){
	if(_bp2 == 'C'){
	    return 5;
	}
	if(_bp2 == 'T'){
	    return 7;
	}
	if(_bp2 == 'A'){
	    return 4;
	}
	if(_bp2 == 'G'){
	    return 6;
	}
    }


    if(_bp1 == 'G'){
	if(_bp2 == 'G'){
	    return 10;
	}
	if(_bp2 == 'A'){
	    return 8;
	}
	if(_bp2 == 'C'){
	    return 9;
	}
	if(_bp2 == 'T'){
	    return 11;
	}
    }


    if(_bp1 == 'T'){
	if(_bp2 == 'T'){
	    return 15;
	}
	if(_bp2 == 'G'){
	    return 14;
	}
	if(_bp2 == 'A'){
	    return 12;
	}
	if(_bp2 == 'C'){
	    return 13;
	}
    }


    cerr<<"Utils.h allelePair2Int invalid 2 bp: "<<bp1<<" and "<<bp2<<endl;
    exit(1);

}



inline int isPotentialTransition(const char bp1,const char bp2){
    char _bp1= upper(bp1);
    char _bp2= upper(bp2);

    if(_bp1 == 'A'){
	if(_bp2 == 'G'){
	    return true;
	}
	return false;
    }

    if(_bp1 == 'C'){
	if(_bp2 == 'T'){
	    return true;
	}
	return false;
    }


    if(_bp1 == 'G'){
	if(_bp2 == 'A'){
	    return true;
	}
	return false;
    }


    if(_bp1 == 'T'){
	if(_bp2 == 'C'){
	    return true;
	}
	return false;
    }


    cerr<<"Utils.h isPotentialTransition invalid 2 bp: "<<bp1<<" and "<<bp2<<endl;
    exit(1);

}


inline string getDateString(){
    time_t t = time(0);   // get time now
    struct tm * now = localtime( & t );
    return  
	""+
	stringify(now->tm_year + 1900)+"-"+
	zeroPad(  (now->tm_mon + 1) ,2)+"-"+
	zeroPad(  (now->tm_mday + 1) ,2);

}

inline string getTimeString(){
    time_t t = time(0);   // get time now
    struct tm * now = localtime( & t );
    return  
	""+
	zeroPad(now->tm_hour,2)+":"+
	zeroPad(now->tm_min ,2)+":"+
	zeroPad(now->tm_sec ,2);
}





/* static inline void trimWhiteSpacesBothEnds(string * str) { */
/*     stringstream trimVar; */
/*     trimVar << *str; */
/*     str->clear(); */
/*     trimVar >> *str;    */
/* } */



inline double correlation(const vector<double>& x, const vector<double>& y){
    if(x.size() == 0){
	cerr<<"Utils.h correlation() ERROR: the size of x is zero"<<endl;
	exit(1);

    }

    if(x.size() != y.size()){
	cerr<<"Utils.h correlation() ERROR: the size of x is not the same as the size of y"<<endl;
	exit(1);
    }

    double n  = double(x.size());
    double ex(0), ey(0),xt(0), yt(0),sxx(0),syy(0),sxy(0) ;

    for (unsigned int i = 0; i < n; i++) { 
	ex += x[i];
	ey += y[i];
    }
    /* cout<<n<<endl; */
    ex = ex/n;
    ey = ey/n;
    /* cout<<"ex " <<ex<<endl; */
    /* cout<<"ey " <<ey<<endl; */

    for (unsigned int i = 0; i < n; i++) { 
	xt = x[i] - ex;
	yt = y[i] - ey;
	/* cout<<"xt "<<xt<<endl; */
	/* cout<<"yt "<<yt<<endl; */

	sxx += xt * xt;
	syy += yt * yt;
	sxy += xt * yt;
    }

    /* cout<<"1 "<<sxx<<endl; */
    /* cout<<"2 "<<sxy<<endl; */
    /* cout<<"3 "<<syy<<endl; */

    return (sxy/(sqrt(sxx*syy)+ numeric_limits< double >::min() ));
}


inline string returnGitHubVersion(const string  programName,const string  suffixToAdd){
    //getting github version
    string directoryProgram;
    string commandPath=string(programName);
    unsigned posSlash=commandPath.find_last_of("/");
    if(posSlash == string::npos){
        directoryProgram="";
    }else{
        directoryProgram=commandPath.substr(0,posSlash);
    }
    string gitFileLog=directoryProgram+"/"+suffixToAdd+"/.git/logs/HEAD";
    string gitVersion="NA";
    if(isFile(gitFileLog)){
        ifstream myFile;
        string line;
        myFile.open(gitFileLog.c_str(), ios::in);

        if (myFile.is_open()){
            while ( getline (myFile,line)){
                vector<string> vs=allTokens(line,' ');
                gitVersion=vs[1];
            }
            myFile.close();

        }else{
            cerr << "Unable to open github file "<<gitFileLog<<endl;
            return "NA";
        }
    }
    return gitVersion;
}


template <typename T>
inline vector<T>  vectorDist(const vector<T> & toEvaluate){
    vector<T> toReturn;
    T m2;
    T m1;
    T m;
    if(toEvaluate.size() <=1){
	return toReturn;
    }
    //have at least 2
    m2=toEvaluate[0];
    m1=toEvaluate[1];
    if(m2>m1){
	cerr<<"utils.h vectorDist() vector is unsorted"<<endl;
	exit(1);
    }
    toReturn.push_back( (m1-m2)  );
         
    for(unsigned int i=2;i<toEvaluate.size();i++){
	m=toEvaluate[i];
	if(m1>m){
	    cerr<<"utils.h vectorDist() vector is unsorted"<<endl;
	    exit(1);
	}

	if( (m1-m2) < (m-m1) ){ //if m1 
	    toReturn.push_back( (m1-m2)  );
	}else{
	    toReturn.push_back( (m-m1)  );
	}
	
	m2=m1;
	m1=m;
    }

    toReturn.push_back( (m1-m2)  );    

    return toReturn;
}


inline string getCWD(char *arg){
    string tm=string(arg);
    char actualpath [PATH_MAX+1];
    char * returnRealpath = realpath(arg, actualpath);
    
    if(returnRealpath == NULL){
	cerr<<"utils.h getCWD failed on  "<<*arg<<endl;
	exit(1);
    }
    vector<string> token=allTokens( string(actualpath),'/');
    token.pop_back();

    if(strEndsWith(vectorToString(token,"/"),"/")){
	return vectorToString(token,"/");
    }else{
	return vectorToString(token,"/")+"/";
    }
}

inline pair<double,double> computeMeanSTDDEV(const vector<double> & v){
    double sum = 0.0;
    for(unsigned int i=0;i<v.size();i++)
	sum += v[i];

    double m =  sum / double(v.size());

    double accum = 0.0;

    for(unsigned int i=0;i<v.size();i++)
	accum += ( (v[i] - m) * (v[i] - m) );


    double stdev = sqrt( accum / double(v.size()-1) );
    return make_pair(m,stdev);
}


inline uint64_t nChoosek( uint64_t n, uint64_t k ){
    if (k > n) return 0;
    if (k * 2 > n) k = n-k;
    if (k == 0) return 1;
    
    uint64_t result = n-k+1;
    for(uint64_t i = 2; i <= k; ++i ) {
	result *= (n-k+i);
	result /= i;
    }

    return result;
}

//to convert a DNA string (A,C,G,T) of less than 32 characters to an unsigned 64 bits integer
inline uint64_t seq2uint64(string & s){
    uint64_t toreturn = 0;
    for(unsigned int i=0;i<s.size();i++){
	toreturn =	toreturn<<2 |( (s[i] == 'A')?0:((s[i] == 'C')?1:((s[i] == 'G')?2:3 ) ));
    }

    return toreturn;
}

/* template <typename T> */
/* template <typename T2> */
template<class T, class T2>
inline vector<T>  allKeysMap(map<T,T2> & m){
    vector<T> v;
    for(typename map<T,T2>::iterator it = m.begin(); 
	it != m.end(); ++it) {
	v.push_back(it->first);
    }
    return v;
}

inline int hammingDistance(string & s1,string & s2){
    if(s1.size() != s2.size()){ 	cerr<<"ERROR: the hammingDistance() function cannot be called for strings of different lengths"<<endl; 	exit(1);     }
    int substitutions=0;
    for(unsigned int i=0;i<s1.size();i++){    
	if(s1[i] != s2[i])
	    substitutions++;
    }
    return substitutions;
}

inline vector<string> splitWS(string const & tosplit) { 
    istringstream tempIS(tosplit);
    vector<string> toReturn;

    copy(istream_iterator<string>(tempIS), 
	 istream_iterator<string>(),
         back_inserter(toReturn));
 
   return toReturn;
}



inline bool isStringNatNumber(string const & totest) { 

    for(unsigned int i=0;i<totest.size();i++){
	if(!isdigit(totest[i]))
	    return false;
    }
 
   return true;
}


inline bool isDos(string const & filetotest) { 
    igzstream myfiled (filetotest.c_str(),ios::in|ios::binary);

    if (!myfiled.good()){
	cerr << "Cannot open file  "<<filetotest<<""<<endl;
	exit(1);
    }

    unsigned int maxData=10000;
    unsigned int dataSoFar=0 ;

    char toread;
    char toread2=0;

    while(myfiled.read(&toread, sizeof (char))){
	//cout<<toread<<"\t"<<int(toread)<<endl;
	if(int(toread) ==  10 ){
	    if(int(toread2) == 13){
		return true;
	    }else{
		return false;
	    }
	}
	toread2 = toread;

	if( dataSoFar > maxData)
	    break;
    }
    myfiled.close();

    
    
    
    return false;
}


inline bool isMac(string const & filetotest) { 
    igzstream myfiled (filetotest.c_str(),ios::in|ios::binary);

    if (!myfiled.good()){
	cerr << "Cannot open file  "<<filetotest<<""<<endl;
	exit(1);
    }
	
    unsigned int maxData=10000;
    unsigned int dataSoFar=0 ;

    char toread;
    char toread2=0;

    while(myfiled.read(&toread, sizeof (char))){
	//cout<<toread<<"\t"<<int(toread)<<endl;
	if(int(toread2) == 13){ 
	    if(int(toread) !=  10 ){ 
		return true; 
	    }else{
		return false;
	    }
	}

	toread2 = toread;

	if( dataSoFar > maxData)
	    break;
    }
    myfiled.close();

    
    if(int(toread2) == 13)
	return true;
    else   
	return false;
}


// Returns log10( pow(10,x)+pow(10,y) ), but does so without causing
// overflow or loss of precision.
template <typename T>
inline double oplus( T x, T y ){
    return x > y 
        ? x + log1p( pow( 10, y-x ) ) / log(10)
        : y + log1p( pow( 10, x-y ) ) / log(10) ;
}


// Returns log( exp(x)+exp(y) ), but does so without causing
// overflow or loss of precision.
template <typename T>
inline double opluse( T x, T y ){
    return x > y 
        ? x + log1p( exp(y-x ) ) 
        : y + log1p( exp(x-y ) ) ;
}


// Returns log10( pow(10,x)+pow(10,y) ), but does so without causing
// overflow or loss of precision.
template <typename T>
inline T oplusInit(T x,T y ){

    if( x == 0 ){ //no initialized, as log = 0 should not exist
	return y;
    }

    return x > y 
        ? x + log1p( pow( 10, y-x ) ) / log(10)
        : y + log1p( pow( 10, x-y ) ) / log(10) ;
}



template <typename T>
inline pair<T,T> firstAndSecondHighestVector(const vector<T> & toSearch){
    if(toSearch.size() < 2 ){
	cerr<<"Cannot call firstAndSecondVector() on an array of length "<<toSearch.size()<<endl;
	exit(1);
    }

    T fstmax;
    T sncmax;

    if(toSearch[0] > toSearch[1]){
	fstmax  = toSearch[0];
	sncmax  = toSearch[1];
    }else{
	fstmax  = toSearch[1];
	sncmax  = toSearch[0];
    }
    
    for(unsigned int i=2;i<toSearch.size();i++){
	if(toSearch[i] > fstmax ){
	    sncmax = fstmax;
	    fstmax = toSearch[i];	    
	}else{
	    if(toSearch[i] >  sncmax ){
		sncmax = toSearch[i];
	    }
	}
    }

    pair<T,T> toreturn;
    toreturn.first  = fstmax;
    toreturn.second = sncmax;
    return toreturn;
}


template <typename T>
inline pair<T,T> firstAndSecondHighestArray(const T toSearch[] ,const int size){
    if(size < 2 ){
	cerr<<"Cannot call firstAndSecondArray() on an array of length "<<size<<endl;
	exit(1);
    }


    
    T fstmax;
    T sncmax;
    if(toSearch[0] > toSearch[1]){
	fstmax  = toSearch[0];
	sncmax  = toSearch[1];
    }else{
	fstmax  = toSearch[1];
	sncmax  = toSearch[0];
    }

    for(int i=2;i<size;i++){
	if(toSearch[i] > fstmax ){
	    sncmax = fstmax;
	    fstmax = toSearch[i];	    
	}else{
	    if(toSearch[i] >  sncmax ){
		sncmax = toSearch[i];
	    }
	}
    }

    pair<T,T> toreturn;
    toreturn.first  = fstmax;
    toreturn.second = sncmax;
    return toreturn;
}

inline string runCmdAndCaptureSTDOUTandSTDERR(string cmd) {//sorry for the long name
    string data="";

    const int bufferSize = 1024;
    char buffer[bufferSize];
    cmd+= " 2>&1 ";

    FILE * outstd = popen(cmd.c_str(), "r");
    if (outstd) {
	while (!feof(outstd)){
	    if (fgets(buffer, bufferSize, outstd) != NULL){
		data+=string(buffer);
	    }
	}
	pclose(outstd);
    }else{
	cerr<<"Problem executing or reading command "<<cmd<<" exiting"<<endl;
	exit(1);
    }

    return data;
}




inline string returnFileDescriptorStats(){
    struct stat   statFD;
    struct rlimit rlimitFD;
    string        toReturn="";

    int fileDMAX = getdtablesize();
     
    int currentFD = 0;
    for(int i=0;i<=fileDMAX; i++ ) {
	fstat(i, &statFD);
	if(errno != EBADF) 
	    currentFD++;	
    }
     
    toReturn+=
	"fds currently open      :\t"+stringify(currentFD)+
	"fds max. lim            :\t"+stringify(fileDMAX);

    getrlimit(RLIMIT_NOFILE, &rlimitFD);

    toReturn+=
	"resource currrent limit :\t"+stringify(rlimitFD.rlim_cur) +
	"resource max limit fds  :\t"+stringify(rlimitFD.rlim_max);
    
    return toReturn;
}

inline pair<double,double> computeJackknifeConfIntervals(double S,const vector<double> & allVals){
     pair<double,double> toreturn ;

     vector<double> Spseudo;
     double N= double(allVals.size());


     for(unsigned int i=0;i<allVals.size();i++){
	 Spseudo.push_back( S + (N-1.0)*(S-allVals[i]));
	 /* cout<<"ps\t"<<i<<"\t"<<Spseudo[i]<<"\t"<<allVals[i]<<"\tS="<<S<<"\t"<<(N-1.0)*( S-allVals[i])<<"\t"<<N<<endl; */
    }

    double pS=0;

    for(unsigned int i=0;i<allVals.size();i++){
        pS+=Spseudo[i];
    }
    pS=pS/N;
    /* cout<<"pS "<<pS<<endl; */
    double var=0;
    for(unsigned int i=0;i<allVals.size();i++){
        var+= ( pow( (Spseudo[i] - pS),2.0) );
    }
    var =var
        /
        (N-1.0) ;
    /* cout<<"var "<<var<<endl; */

    double sqrtVarDivN= sqrt(var/N);
    /* cout<<"sq var "<<sqrtVar<<endl; */
    /* cout<<"err "<<1.96*sqrtVar<<endl; */

    toreturn.first  = pS-1.96*sqrtVarDivN;
    toreturn.second = pS+1.96*sqrtVarDivN;
    /* pair<double,double> tempV=computeMeanSTDDEV(allVals); */
    /* //double sqrtVar= sqrt(var); */

    /* toreturn.first  = S-1.96*tempV.second; */
    /* toreturn.second = S+1.96*tempV.second; */

    return toreturn;
}

#endif


