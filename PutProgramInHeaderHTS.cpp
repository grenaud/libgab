/*
 * PutProgramInHeaderHTS
 * Date: Jan-23-2020
 * Author : Gabriel Renaud gabriel.reno [at sign here ] gmail.com
 *
 */

#include "PutProgramInHeaderHTS.h"



inline int lastDigits(const string & s){
    size_t found = s.find_last_of(".");
    if(found != string::npos){

	if(found <  (s.size()-1)){

	    string c=s.substr(found+1,string::npos);
	    
	    if(isInteger(c)){
		int v=destringify<int>(c);
		return v;
	    }else{
		return -1;
	    }
	}else{
	    return -1;
	}	
    }else{
	return -1;
    }
}


//@PG	ID:samtools	PN:samtools	PP:bam_merge.3	VN:1.9-218-g064361a	CL:samtools view -b ftp://ftp.1000genomes.ebi.ac.uk/vol1/ftp/phase3/data/HG02891/alignment/HG02891.mapped.ILLUMINA.bwa.GWD.low_coverage.20121211.bam 21
void putProgramInHeaderHTS(string * header,
			   const string & programID,
			   const string & programName,
			   const string & programCL,
			   const string & programVersion){
    //BEGIN DETECTING PREVIOUS PROGRAM
    string headerCpy (*header);
    string programCLCpy=programCL;
    trimWhiteSpacesBothEnds(&programCLCpy);    
    vector<string> lines = allTokens(headerCpy,'\n');
    vector<pgfield> vecPGfields;
    int lastPGLine=-1;
    for(unsigned int i=0;i<lines.size();i++){
	vector<string> fields =allTokens(lines[i],'\t');
	if(fields.size()>0){
	    if(fields[0] == "@PG"){
		lastPGLine=i;

		pgfield pgtoadd;
		pgtoadd.haspp=false;
		pgtoadd.hasid=false;
		pgtoadd.haspn=false;

		for(unsigned int j=1;j<fields.size();j++){
		    if(strBeginsWith(fields[j],"ID:")){   pgtoadd.id = fields[j].substr(3,string::npos);  pgtoadd.hasid=true;   }
		    if(strBeginsWith(fields[j],"PN:")){   pgtoadd.pn = fields[j].substr(3,string::npos);  pgtoadd.haspn=true;   }
		    if(strBeginsWith(fields[j],"PP:")){   pgtoadd.pp = fields[j].substr(3,string::npos);  pgtoadd.haspp=true;   }
		    if(strBeginsWith(fields[j],"VN:")){   pgtoadd.vn = fields[j].substr(3,string::npos);                      }
		    if(strBeginsWith(fields[j],"CL:")){   pgtoadd.cl = fields[j].substr(3,string::npos);                      }		    
		}
		//cerr<<"PG:#"<<vecPGfields.size()<<" "<<lines[i]<<endl;
		vecPGfields.push_back(pgtoadd);
	    }
	}
    }
    
    string previousProgram="";
    //for each ID, do you have a previousProgram?
    map<string,bool> program2foundasPP;

    // SamProgramChain 	allPrograms =header->Programs;
    // SamProgramConstIterator it;


    //we will try to find a program that was never
    //specified as PP in another program
    int highestCall=-1;
    for(unsigned int i=0;i<vecPGfields.size();i++){
    	if(!vecPGfields[i].hasid){
    	    cerr<<"Program does not have an ID"<<endl;
    	    exit(1);
    	}
	//for fields like:
	// @PG           ID:bwa_sam                                PN:bwa               PP:bwa_aln_fastq
	// @PG           ID:bwa_sam.1                              PN:bwa               PP:bwa_aln_fastq
	// @PG           ID:bwa_sam.2                              PN:bwa               PP:bwa_aln_fastq
	
    	if(vecPGfields[i].haspn){	    
	    int v=lastDigits(vecPGfields[i].id);
		
	    if(v==-1){//cannot detect
		if(vecPGfields[i].pn == programName){//we have already used this program on this bam file
		    if(highestCall==-1){ highestCall=0; }
		}		    
	    }else{		    
		//string newID=removeDigitsDots( vecPGfields[i].id );
	    }
	    program2foundasPP.insert( pair<string,bool>(vecPGfields[i].id,false) );
	}

    }
    
    
    for(unsigned int i=0;i<vecPGfields.size();i++){
    	// if(!vecPGfields[i].hasid){
    	//     cerr<<"Program does not have an ID"<<endl;
    	//     exit(1);
    	// }
    	//if(it->HasPreviousProgramID() )
	//cerr<<"1PP#"<<i<<"\t"<<vecPGfields[i].haspp<<"#\t#ID="<<vecPGfields[i].id<<"#\t#PN="<<vecPGfields[i].pn<<"#\tpp#"<<vecPGfields[i].pp<<endl;
	if(vecPGfields[i].haspp){	 
    	    program2foundasPP[	vecPGfields[i].pp ] = true;
	}
    }

    map<string,bool>::iterator program2foundasPP_it;
    for(program2foundasPP_it= program2foundasPP.begin();
    	program2foundasPP_it!=program2foundasPP.end();
    	program2foundasPP_it++){
	
	//cerr<<"2PP\t"<<program2foundasPP_it->first<<"\t"<<program2foundasPP_it->second<<"\t"<<previousProgram<<endl;
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
    string newHeader="";
    for(int i=0;i<int(lines.size());i++){
	//cerr<<"nh "<<i<<"\t->"<<newHeader<<"<-"<<endl;
	newHeader+=lines[i]+"\n";
	if( i==lastPGLine ){
	    newHeader+="@PG";
	    if(highestCall==-1){ newHeader+="\tID:"+programID; }else{  newHeader+="\tID:"+programID+"."+stringify(highestCall+1); }
	    newHeader+="\tPN:"+programName;
	    if(previousProgram != ""){
		newHeader+="\tPP:"+previousProgram;
	    }
	    newHeader+="\tVN:"+programVersion;
	    newHeader+="\tCL:"+programCL;
	    newHeader+="\n";	   
	}
    }

    if( lastPGLine==-1 ){//there was no PG lines
	newHeader+="@PG";
	newHeader+="\tID:"+programID;
	newHeader+="\tPN:"+programName;
	// if(previousProgram != ""){
	//     newHeader+="\tPP:"+previousProgram;
	// }
	newHeader+="\tVN:"+programVersion;
	newHeader+="\tCL:"+programCL;
	newHeader+="\n";	   
    }
    trimWhiteSpacesBothEnds(&newHeader);    
    *header=newHeader;
}




// }
			
