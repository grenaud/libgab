/*
 * BamFunctions
 * Date: Feb-04-2020 
 * Author : Gabriel Renaud gabriel.reno [at sign here] gmail.com
 *
 */

#ifndef BamFunctions_h
#define BamFunctions_h

using namespace std;


#define bam_is_reverse(b)     (((b)->core.flag&BAM_FREVERSE)    != 0)
#define bam_is_unmapped(b)    (((b)->core.flag&BAM_FUNMAP)      != 0)
#define bam_is_paired(b)      (((b)->core.flag&BAM_FPAIRED)     != 0)
#define bam_is_propaired(b)   (((b)->core.flag&BAM_FPROPER_PAIR) != 0)
#define bam_is_read1(b)       (((b)->core.flag&BAM_FREAD1)      != 0)

#define bam_is_qcfailed(b)    (((b)->core.flag&BAM_FQCFAIL)     != 0)
#define bam_is_rmdup(b)       (((b)->core.flag&BAM_FDUP)        != 0)
#define bam_is_sec(b)         (((b)->core.flag&BAM_FSECONDARY)        != 0)
#define bam_is_supp(b)        (((b)->core.flag&BAM_FSUPPLEMENTARY)    != 0)

#define bam_is_failed(b)      ( bam_is_qcfailed(b) || bam_is_rmdup(b) || bam_is_sec(b) || bam_is_supp(b) )

#define bam_mqual(b)          ((b)->core.qual)
#define bam_isize(b)          ((b)->core.isize)
#define bam_lqseq(b)          ((b)->core.l_qseq)

#define bam_get_size_aux(b)   ((b)->l_data-(((b)->core.n_cigar<<2) + (b)->core.l_qname + (((b)->core.l_qseq + 1)>>1) + (b)->core.l_qseq))
//#define bam_get_size_aux(b)   ((b)->l_data-(((b)->core.n_cigar<<2) + (b)->core.l_qname + (((b)->core.l_qseq + 1)>>1) + (b)->core.l_qseq))



#if HTS_ALLOW_UNALIGNED != 0 && ULONG_MAX == 0xffffffffffffffff

// Macro that operates on 64-bits at a time.
#define COPY_MINUS_N(to,from,n,l,failed)                        \
    do {                                                        \
        uint64_u *from8 = (uint64_u *)(from);                   \
        uint64_u *to8 = (uint64_u *)(to);                       \
        uint64_t uflow = 0;                                     \
        size_t l8 = (l)>>3, i;                                  \
        for (i = 0; i < l8; i++) {                              \
            to8[i] = from8[i] - (n)*0x0101010101010101UL;       \
            uflow |= to8[i];                                    \
        }                                                       \
        for (i<<=3; i < (l); ++i) {                             \
            to[i] = from[i] - (n);                              \
            uflow |= to[i];                                     \
        }                                                       \
        failed = (uflow & 0x8080808080808080UL) > 0;            \
    } while (0)

#else

// Basic version which operates a byte at a time
#define COPY_MINUS_N(to,from,n,l,failed) do {                \
        uint8_t uflow = 0;                                   \
        for (i = 0; i < (l); ++i) {                          \
            (to)[i] = (from)[i] - (n);                       \
            uflow |= (uint8_t) (to)[i];                      \
        }                                                    \
        failed = (uflow & 0x80) > 0;                         \
    } while (0)

#endif

extern "C" {
    //#include "tabix.h"
    //#include "bam.h"
#include "htslib/sam.h"
#include "htslib/bgzf.h"
#include "bam.h"

#include "samtools.h"
#include "sam_opts.h"
#include "bedidx.h"

}


#define bam_is_reverse(b)     (((b)->core.flag&BAM_FREVERSE)    != 0)
#define bam_is_unmapped(b)    (((b)->core.flag&BAM_FUNMAP)      != 0)
#define bam_is_paired(b)      (((b)->core.flag&BAM_FPAIRED)     != 0)
#define bam_is_propaired(b)   (((b)->core.flag&BAM_FPROPER_PAIR) != 0)
#define bam_is_read1(b)       (((b)->core.flag&BAM_FREAD1)      != 0)

#define bam_is_qcfailed(b)    (((b)->core.flag&BAM_FQCFAIL)     != 0)
#define bam_is_rmdup(b)       (((b)->core.flag&BAM_FDUP)        != 0)
#define bam_is_sec(b)         (((b)->core.flag&BAM_FSECONDARY)        != 0)
#define bam_is_supp(b)        (((b)->core.flag&BAM_FSUPPLEMENTARY)    != 0)

#define bam_is_failed(b)      ( bam_is_qcfailed(b) || bam_is_rmdup(b) || bam_is_sec(b) || bam_is_supp(b) )

#define bam_mqual(b)          ((b)->core.qual)
#define bam_isize(b)          ((b)->core.isize)
#define bam_lqseq(b)          ((b)->core.l_qseq)

#define bam_get_size_aux(b)   ((b)->l_data-(((b)->core.n_cigar<<2) + (b)->core.l_qname + (((b)->core.l_qseq + 1)>>1) + (b)->core.l_qseq))
//#define bam_get_size_aux(b)   ((b)->l_data-(((b)->core.n_cigar<<2) + (b)->core.l_qname + (((b)->core.l_qseq + 1)>>1) + (b)->core.l_qseq))



#if HTS_ALLOW_UNALIGNED != 0 && ULONG_MAX == 0xffffffffffffffff

// Macro that operates on 64-bits at a time.
#define COPY_MINUS_N(to,from,n,l,failed)                        \
    do {                                                        \
        uint64_u *from8 = (uint64_u *)(from);                   \
        uint64_u *to8 = (uint64_u *)(to);                       \
        uint64_t uflow = 0;                                     \
        size_t l8 = (l)>>3, i;                                  \
        for (i = 0; i < l8; i++) {                              \
            to8[i] = from8[i] - (n)*0x0101010101010101UL;       \
            uflow |= to8[i];                                    \
        }                                                       \
        for (i<<=3; i < (l); ++i) {                             \
            to[i] = from[i] - (n);                              \
            uflow |= to[i];                                     \
        }                                                       \
        failed = (uflow & 0x8080808080808080UL) > 0;            \
    } while (0)

#else

// Basic version which operates a byte at a time
#define COPY_MINUS_N(to,from,n,l,failed) do {                \
        uint8_t uflow = 0;                                   \
        for (i = 0; i < (l); ++i) {                          \
            (to)[i] = (from)[i] - (n);                       \
            uflow |= (uint8_t) (to)[i];                      \
        }                                                    \
        failed = (uflow & 0x80) > 0;                         \
    } while (0)

#endif


inline bool hasTag(const bam1_t    *al,const string & tag){
    uint8_t *rgtag = bam_aux_get(al,tag.c_str());
    if(rgtag){
        delete(rgtag);
        return true;
    }else
        return false;        
}

inline void getSeq(const bam1_t * al,string * strseq){
    uint8_t * s = bam_get_seq(al);
    //if (ks_resize(str, str->l+2+2*c->l_qseq) < 0) goto mem_err;
    //char *cp = str->s + str->l;
    strseq->resize(al->core.l_qseq);
    int lq2 = (al->core.l_qseq / 2);
    int i;
    for(i=0;i<lq2;i++){
        uint8_t b = s[i];
        strseq->at(i*2+0) = "=ACMGRSVTWYHKDBN"[b>>4];
        strseq->at(i*2+1) = "=ACMGRSVTWYHKDBN"[b&0xf];
    }
    
    for(i*=2;i<(al->core.l_qseq); ++i){ 
        strseq->at(i) = "=ACMGRSVTWYHKDBN"[ bam_seqi(s, i) ];
    }
}

inline void getQual(const bam1_t * al,string * strqual){
    uint8_t *  s = bam_get_qual(al);
    int i = 0;
    strqual->resize(al->core.l_qseq);
    if (s[0] == 0xff) {
        strqual->at(i++) = '*';
    }else{
        for (i = 0; i < al->core.l_qseq; ++i)
            strqual->at(i)=s[i]+33;
    }
    //cp[i] = 0;

}

inline void addTagi(bam1_t    *al,const string & tag,const int32_t val){
    
    bam_aux_append(al, tag.c_str(), 'i', 4, (uint8_t*)(&val));

}

inline void addTaga(bam1_t    *al,const string & tag,const char val){    
    bam_aux_append(al, tag.c_str(), 'a', 1, (uint8_t*)(&val));
}

inline void addTagZ(bam1_t    *al,const string & tag,const string & val){
    bam_aux_append(al, tag.c_str(), 'Z', (val.size()+1), (uint8_t*)(val.c_str()));
}

inline string getTagZ(bam1_t    *al,const string & tag){

    uint8_t *rettag = bam_aux_get(al,tag.c_str());

    if(rettag){
        string tagToReturn ( (char *)rettag );
        return tagToReturn;
    }else{
        cerr<<"Cannot get tag"<<tag<<" for read "<<bam_get_qname(al)<<endl;
        exit(1);
    }

}

inline void editZQTag(bam1_t    *al,const char code){

    uint8_t *rettag = bam_aux_get(al,"ZQ");

    if(rettag){//has zq
        string zqtag ( (char *)rettag );
        int deltag = bam_aux_del(al, rettag); //bam_aux_get(b,"RG"));
        
        if(deltag){ 
            cerr<<"Cannot remove tag"<<endl; 
            exit(1);    
        }else{
            //fine
        }
        zqtag=sortUniqueChar(zqtag);
        addTagZ(al,"ZQ",zqtag);
        
    }else{
        addTaga(al,"ZQ",code);
    }
    

}

inline void removeTag(bam1_t  *al,const string & tag){

    uint8_t *rettag = bam_aux_get(al,tag.c_str());

    if(rettag!=NULL){
        int deltag = bam_aux_del(al, rettag);//bam_aux_get(b,"RG"));

        if(deltag){
            cerr<<"Cannot remove tag"<<endl;
            exit(1);
        }else{
            //fine
        }
    }else{
        //nothing to do
    }
    
}


inline void removeTag(const string & qname,const string & seqtoadd,const string & qualtoadd){
    bam1_t    *n = bam_init1();	
    // //test create empty bam record
    n->core.flag = 4;
    n->core.tid       =-1;
    n->core.pos       =-1;
    n->core.mtid       =-1;
    n->core.mpos       =-1;

    //data = bam_get_qname, bam_get_cigar, bam_get_seq, bam_get_qual and bam_get_aux
    //       
    //CREATING A FAKE RECORD
	
    /* string fakeDNA="NACGT"; */
    /* string fakeQC ="!!!!!"; */
    // string fakeDNA="ACGT";
    // string fakeQC ="!!!!";
    n->core.l_qseq  = seqtoadd.size();
    //string qname = "TESTREAD";
    unsigned int lqs2 = seqtoadd.size()&~1;//length seq
	
    //           qname           cigar   seq                    qual              aux
    n->l_data = (qname.size()+1)+0+( (seqtoadd.size()+1)>>1 )+qualtoadd.size()+bam_get_size_aux(b);//no aux	
    n->core.l_qname = qname.size()+1;

    n->data   = new uint8_t[n->l_data];
    n->m_data = b->m_data;

    memcpy(n->data,              qname.c_str(), qname.size());
    n->data[ qname.size() ] = 0;
	
    n->data[ qname.size()+1 ] = '*';

    uint8_t * t = n->data + ((qname.size()+1)+0);
	
    unsigned int i;
    const char * q = seqtoadd.c_str();
    for (i = 0; i < lqs2;          i+=2){
	uint8_t towrite=(seq_nt16_table[(unsigned char)q[i]] << 4) | seq_nt16_table[(unsigned char)q[i+1]];

	t[i>>1] = towrite;

    }
	
    for (     ; i < seqtoadd.size(); ++i){
	uint8_t towrite =  seq_nt16_table[(unsigned char)q[i]] << ((~i&1)<<2);
	t[i>>1] = towrite;
    }
    t = n->data + ((qname.size()+1)+0+( (seqtoadd.size()+1)>>1 ));
    int failed = 0;
    COPY_MINUS_N(t, qualtoadd.c_str(), 33, qualtoadd.size(), failed);
	
    if(failed!=0){
	cerr<<"Found invalid quality character in: "<<qualtoadd<<endl; exit(1);
    }
	
    t = n->data + ((qname.size()+1)+0+( (seqtoadd.size()+1)>>1 )+seqtoadd.size());//no aux
    memcpy(t , bam_get_aux(b),bam_get_size_aux(b));
	
    return n;
}

/* class BamFunctions{ */
/* private: */

/* public: */
/* BamFunctions(); */
/* BamFunctions(const BamFunctions & other); */
/* ~BamFunctions(); */
/* BamFunctions & operator= (const BamFunctions & other); */

/* }; */
#endif
