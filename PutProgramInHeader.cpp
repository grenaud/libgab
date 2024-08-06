/*
 * PutProgramInHeader
 * Date: Dec-04-2012 
 * Author : Gabriel Renaud gabriel.reno [at sign here ] gmail.com
 *
 */

#include "PutProgramInHeader.h"

// string returnGitHubVersion(const string  programName,const string  suffixToAdd){
//      //getting github version
//     string directoryProgram;
//     string commandPath=string(programName);
//     unsigned posSlash=commandPath.find_last_of("/");
//     if(posSlash == string::npos){
// 	directoryProgram="";
//     }else{
// 	directoryProgram=commandPath.substr(0,posSlash);
//     }
//     string gitFileLog=directoryProgram+"/"+suffixToAdd+"/.git/logs/HEAD";
//     string gitVersion="NA";
//     if(isFile(gitFileLog)){
// 	ifstream myFile;
// 	string line;
// 	myFile.open(gitFileLog.c_str(), ios::in);

// 	if (myFile.is_open()){
// 	    while ( getline (myFile,line)){
// 		vector<string> vs=allTokens(line,' ');
// 		gitVersion=vs[1];
// 	    }
// 	    myFile.close();
// 	}else{
// 	    cerr << "Unable to open github file "<<gitFileLog<<endl;
// 	    return "NA";
// 	}
//     }
//     return gitVersion;
// }



void putProgramInHeader(SamHeader    * header,
			const string & programID,
			const string & programName,
			const string & programCL,
			const string & programVersion){
    //BEGIN DETECTING PREVIOUS PROGRAM

    string previousProgram="";
    map<string,bool> program2foundasPP;

    SamProgramChain 	allPrograms =header->Programs;
    SamProgramConstIterator it;


    //we will try to find a program that was never
    //specified as PP in another program
    for(it= allPrograms.ConstBegin();
	it!=allPrograms.ConstEnd();
	it++){
	if(!it->HasID ()){
	    cerr<<"Program does not have an ID"<<endl;
	    exit(1);
	}
	// if(it->ID == programID){
	//     cerr<<"Program ID already exists"<<endl;
	//     exit(1);
	// }
	program2foundasPP.insert( pair<string,bool>(it->ID,false) );
    }
    
    for(it= allPrograms.ConstBegin();
	it!=allPrograms.ConstEnd();
	it++){
	if(!it->HasID ()){
	    cerr<<"Program does not have an ID"<<endl;
	    exit(1);
	}
	if(it->HasPreviousProgramID() )
	    program2foundasPP[	it->PreviousProgramID ] =true;
    }

    map<string,bool>::iterator program2foundasPP_it;
    for(program2foundasPP_it= program2foundasPP.begin();
	program2foundasPP_it!=program2foundasPP.end();
	program2foundasPP_it++){
	
	if(! program2foundasPP_it->second ){ //program not found as PP
	    if(previousProgram!=""){
		cerr<<"Many program without PP ex:"<<previousProgram<<" replacing with "<<program2foundasPP_it->first<<endl;
	    }
	    previousProgram=program2foundasPP_it->first;
	}
    }
    //END DETECTING PREVIOUS PROGRAM


    //cout<<previousProgram<<endl;
    //    exit(1);

    SamProgram sp;
    sp.ID          = programID;
    sp.Name        = programName;
    sp.CommandLine = programCL;
    sp.Version     = programVersion;

    if(previousProgram != ""){
	sp.PreviousProgramID=previousProgram;
    }
    header->Programs.Add(sp);
}




// }
			
