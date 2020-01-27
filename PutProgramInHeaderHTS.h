/*
 * putProgramInHeaderHTS
 * Date: Jan-23-2020
 * Author : Gabriel Renaud gabriel.reno [at sign here] gmail.com
 *
 */

#ifndef PutProgramInHeaderHTS_h
#define PutProgramInHeaderHTS_h

/* #include <vector> */
/* #include <map> */
/* #include <stdlib.h> */


#include "utils.h"

using namespace std;

typedef struct{
    string id;
    string pn;
    string cl;
    string vn;
    string pp;
    bool haspp;
    bool hasid;
    bool haspn;

} pgfield;

int lastDigits(const string & s);

void putProgramInHeaderHTS(string * header,
			   const string & programID,
			   const string & programName,
			   const string & programCL,
			   const string & programVersion="NA");



#endif
