/*
 * testUtils
 * Date: Aug-20-2012 
 * Author : Gabriel Renaud gabriel.reno [at sign here ] gmail.com
 *
 */

#include <iostream>
#include <fstream>
#include <memory>

#include "api/BamMultiReader.h"
#include "api/BamReader.h"
#include "api/BamWriter.h"
#include "api/BamAux.h"

#include "ReconsReferenceBAM.h"
#include "utils.h"

using namespace std;

int main (int argc, char *argv[]) {
    
     string bamfiletopen = string(argv[1]);
     BamReader reader;

     if ( !reader.Open(bamfiletopen) ) {
    	cerr << "Could not open input BAM files." << endl;
    	return 1;
     }

    BamAlignment al;
    while ( reader.GetNextAlignment(al) ) {
	string reconstructedReference = reconstructRef(&al);
	cout<<al.QueryBases<<endl;
	cout<<reconstructedReference<<endl;

	
	pair< string, vector<int> >  reconP = reconstructRefWithPos(&al);
	for(unsigned int i=0;i<reconP.first.size();i++){
	    cout<<reconP.first[i]<<"\t"<<reconP.second[i]<<endl;
	}

    }
    reader.Close();

    return 0;
}

