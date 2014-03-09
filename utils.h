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


using namespace std;



inline char upper(const char c){
    return char(toupper(c));
}


//Check if it is either A,C,G,T,N
inline bool isValidDNA(const char c){
    if(c ==    'A')
	return true;
    if(c ==    'C')
	return true;
    if(c ==    'G')
	return true;
    if(c ==    'T')
	return true;
    if(c ==    'N')
	return true;
    return false;
}

//Check if it is either A,C,G,T
inline bool isResolvedDNA(const char c){
    if(c ==    'A')
	return true;
    if(c ==    'C')
	return true;
    if(c ==    'G')
	return true;
    if(c ==    'T')
	return true;
    return false;
}
inline int base2int(const char c){
    if(c ==    'N')
	return 0;
    if(c ==    'A')
	return 1;
    if(c ==    'C')
	return 2;
    if(c ==    'G')
	return 3;
    if(c ==    'T')
	return 4;
    cerr<<"utils.h base2int() Invalid base "<<c<<endl;
    exit(1);
}

//Returns an index for every 2mer of different base A,C,G,T
inline int dimer2index(const char c1,const char c2){

    if(c1     ==    'A'){

	if(c2 ==    'C')
	    return 0;
	if(c2 ==    'G')
	    return 1;
	if(c2 ==    'T')
	    return 2;

	cerr<<"Utils.h:1 dimer2index invalid dimer "<<c1<<" "<<c2<<endl;
	exit(1);
    }


    if(c1     ==    'C'){

	if(c2 ==    'A')
	    return 3;
	if(c2 ==    'G')
	    return 4;
	if(c2 ==    'T')
	    return 5;

	cerr<<"Utils.h:2 dimer2index invalid dimer "<<c1<<" "<<c2<<endl;
	exit(1);
    }


    if(c1     ==    'G'){

	if(c2 ==    'A')
	    return 6;
	if(c2 ==    'C')
	    return 7;
	if(c2 ==    'T')
	    return 8;

	cerr<<"Utils.h:3 dimer2index invalid dimer "<<c1<<" "<<c2<<endl;
	exit(1);
    }



    if(c1     ==    'T'){

	if(c2 ==    'A')
	    return 9;
	if(c2 ==    'C')
	    return 10;
	if(c2 ==    'G')
	    return 11;

	cerr<<"Utils.h:4 dimer2index invalid dimer "<<c1<<" "<<c2<<endl;
	exit(1);
    }



    cerr<<"Utils.h:5 dimer2index invalid dimer "<<c1<<" "<<c2<<endl;
    exit(1);
}




//Returns an index for every 2mer of different
inline int twoBases2index(const char c1,const char c2){

    if(c1     ==    'A'){

	if(c2 ==    'A')
	    return 0;
	if(c2 ==    'C')
	    return 1;
	if(c2 ==    'G')
	    return 2;
	if(c2 ==    'T')
	    return 3;

	cerr<<"Utils.h:1 twoBases2index invalid dimer "<<c1<<" "<<c2<<endl;
	exit(1);
    }


    if(c1     ==    'C'){


	if(c2 ==    'A')
	    return 4;
	if(c2 ==    'C')
	    return 5;
	if(c2 ==    'G')
	    return 6;
	if(c2 ==    'T')
	    return 7;

	cerr<<"Utils.h:2 twoBases2index invalid dimer "<<c1<<" "<<c2<<endl;
	exit(1);
    }


    if(c1     ==    'G'){

	if(c2 ==    'A')
	    return 8;
	if(c2 ==    'C')
	    return 9;
	if(c2 ==    'G')
	    return 10;
	if(c2 ==    'T')
	    return 11;


	cerr<<"Utils.h:3 twoBases2index invalid dimer "<<c1<<" "<<c2<<endl;
	exit(1);
    }



    if(c1     ==    'T'){

	if(c2 ==    'A')
	    return 12;
	if(c2 ==    'C')
	    return 13;
	if(c2 ==    'G')
	    return 14;
	if(c2 ==    'T')
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


inline int callRand(){
    if(!srandCalled){
	timeval time;
	gettimeofday(&time, NULL);
	srand(  long((time.tv_sec * 1000) + (time.tv_usec / 1000)) );
	srandCalled=true;
    }
    return rand();
}


static bool srand48Called=false;
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

    if(bp1 == 'A'){
	if(bp2 == 'A'){
	    return 0;
	}
	if(bp2 == 'C'){
	    return 1;
	}
	if(bp2 == 'G'){
	    return 2;
	}
	if(bp2 == 'T'){
	    return 3;
	}
    }

    if(bp1 == 'C'){
	if(bp2 == 'C'){
	    return 5;
	}
	if(bp2 == 'T'){
	    return 7;
	}
	if(bp2 == 'A'){
	    return 4;
	}
	if(bp2 == 'G'){
	    return 6;
	}
    }


    if(bp1 == 'G'){
	if(bp2 == 'G'){
	    return 10;
	}
	if(bp2 == 'A'){
	    return 8;
	}
	if(bp2 == 'C'){
	    return 9;
	}
	if(bp2 == 'T'){
	    return 11;
	}
    }


    if(bp1 == 'T'){
	if(bp2 == 'T'){
	    return 15;
	}
	if(bp2 == 'G'){
	    return 14;
	}
	if(bp2 == 'A'){
	    return 12;
	}
	if(bp2 == 'C'){
	    return 13;
	}
    }


    cerr<<"Utils.h allelePair2Int invalid 2 bp: "<<bp1<<" and "<<bp2<<endl;
    exit(1);

}



inline int isPotentialTransition(const char bp1,const char bp2){

    if(bp1 == 'A'){
	if(bp2 == 'G'){
	    return true;
	}
	return false;
    }

    if(bp1 == 'C'){
	if(bp2 == 'T'){
	    return true;
	}
	return false;
    }


    if(bp1 == 'G'){
	if(bp2 == 'A'){
	    return true;
	}
	return false;
    }


    if(bp1 == 'T'){
	if(bp2 == 'C'){
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
    realpath(arg, actualpath);
    
    /* cerr<<"actualpath "<<actualpath<<endl; */
    /* exit(1); */
    vector<string> token=allTokens( string(actualpath),'/');
    token.pop_back();

    if(strEndsWith(vectorToString(token,"/"),"/")){
	return vectorToString(token,"/");
    }else{
	return vectorToString(token,"/")+"/";
    }
}

inline pair<double,double> computeMeanSTDDEV(vector<double> & v){
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


#endif
