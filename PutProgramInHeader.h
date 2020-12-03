/*
 * putProgramInHeader
 * Date: Dec-04-2012 
 * Author : Gabriel Renaud gabriel.reno [at sign here] gmail.com
 *
 */

#ifndef PutProgramInHeader_h
#define PutProgramInHeader_h

#include <vector>
#include <map>
#include <stdlib.h>


#include <api/SamHeader.h>
#include <api/BamMultiReader.h>
#include <api/BamReader.h>
#include <api/BamWriter.h>
#include <api/BamAux.h>

#include "libgab.h"

using namespace std;
using namespace BamTools;

void putProgramInHeader(SamHeader * header,
			const string & programID,
			const string & programName,
			const string & programCL,
			const string & programVersion="NA");

//string returnGitHubVersion(string programName,string suffixToAdd);

#endif
