#ifndef utils_h
#define utils_h

#include <string> 
#include <vector> 
#include <stdio.h>
#include <stdlib.h>
#include <sstream> 
#include <iostream> 
#include <map> 
#include <iomanip>
#include <algorithm> 
#include <functional> 
#include <sys/time.h> //for srand

//For directory/file operations
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h> 
#include <dirent.h>


using namespace std;



inline char upper(const char c){
    return char(toupper(c));
}



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



inline bool starsWith(const string & header,const string & tocheck){
    return (header.substr(0, min(header.length(),tocheck.length()) ) == tocheck);
}



	
inline string boolStringify(const bool b){
    return b ? "true" : "false";
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



inline vector<string> allTokens(const string  & toparse,const string & delim){
    if(delim.size() == 0){
	cerr<<"Utils.cpp: allTokens: delim must have at least one char"<<endl;
	exit(1);
    }
    if(delim.size() == 1)
	return allTokens(toparse,delim[0]);

    cerr<<"Utils.cpp: allTokens: to implement"<<endl;
    exit(1);

    /* vector<string> toReturn; */

 
		
    /* return toReturn; */
}


inline bool isInsert(const string & toCheck){
    vector<string> allt =allTokens(toCheck,',');
    for(unsigned int i=0;i<allt.size();i++){
	if(allt[i].length() > 1)
	    return true;
    }
    return false;
}




inline map<string, string> info2map(const string & info){
    map<string, string> toReturn;
    vector<string> fields    =allTokens(info,';');
    for(unsigned int i=0;i<fields.size();i++){
	size_t found = fields[i].find("=");
	if (found!=string::npos){
	    toReturn[fields[i].substr(0,found)]=fields[i].substr(found+1);
	}else{
	    toReturn[fields[i]]="";
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
	cerr<<"Utils.cpp: Unable to convert string=\""<<s<<"\""<<endl;
	exit(1);
    }
    return x;
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
inline string vectorToString(const vector<T> toPrint,const string separator=","){
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



//! To trim white spaces
/*!
 *
 * Trims white spaces at the beginning and end of a string

  \param str : Address of string to trim
*/
static inline void trimWhiteSpacesBothEnds(string * str) { 
    str->erase(str->begin(), find_if(str->begin(), str->end(), not1(ptr_fun<int, int>(isspace))));
    str->erase(find_if(str->rbegin(), str->rend(), not1(std::ptr_fun<int, int>(isspace))).base(), str->end());


}


/* static inline void trimWhiteSpacesBothEnds(string * str) { */
/*     stringstream trimVar; */
/*     trimVar << *str; */
/*     str->clear(); */
/*     trimVar >> *str;    */
/* } */




#endif
