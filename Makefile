
BAMTOOLS= $(realpath ../bamtools/)
SAMTOOLS= $(realpath ../samtools/)


#defined via user
ifdef BAMTOOLSINC
	BAMTOOLSINCAPI=${BAMTOOLSINC}
	BAMTOOLSINCSHARED=${BAMTOOLSINC}
else
	BAMTOOLSINCAPI=${BAMTOOLS}/src/
	BAMTOOLSINCSHARED=${BAMTOOLS}/src/
endif

ifdef BAMTOOLSLIB
	BAMTOOLSLIBOBJ=${BAMTOOLSLIB}/libbamtools.a 
else
	BAMTOOLSLIBOBJ=${BAMTOOLS}/build/src/api/libbamtools.a 
endif


CXX      = g++ #-g  -pg
CXXFLAGS = -Wall  -lm -O3 -I. -Igzstream/ -I${BAMTOOLSINCAPI} -I${BAMTOOLSINCSHARED} 
LDLIBS   = -lz
LDLIBSHTS = ../lib/samtools/bedidx.o ../lib/htslib/libhts.a ../lib/samtools/libbam.a ../lib/samtools/libst.a 
CXXFLAGSHTS = -I../lib/samtools/ -I../lib/htslib/   

#.PHONY: clean all 

bamtools_target  = $(BAMTOOLSINCAPI)-$(wildcard $(BAMTOOLSINCAPI))
bamtools_present = $(BAMTOOLSINCAPI)-$(BAMTOOLSINCAPI)
bamtools_absent  = $(BAMTOOLSINCAPI)-

samtools_target  = $(SAMTOOLS)-$(wildcard $(SAMTOOLS))
samtools_present = $(SAMTOOLS)-$(SAMTOOLS)
samtools_absent  = $(SAMTOOLS)-

all:  | $(bamtools_target) $(samtools_target)  utils.o testUtils   PutProgramInHeaderHTS.o gzstream/gzstream.o FastQObj.o FastQParser.o
#	all: utils.o testUtils ReconsReferenceBAM.o PutProgramInHeader.o PutProgramInHeaderHTS.o gzstream/gzstream.o FastQObj.o FastQParser.o testRecons testRecons.o


$(bamtools_present):
	@echo "bamtools found"
	@make ReconsReferenceBAM.o
	@make PutProgramInHeader.o
	@make testRecons.o
	@make testRecons

$(bamtools_absent):
	@echo "Warning: bamtools not found"
	@echo "You can specify bamtools using make BAMTOOLSINC=/path to bamtools/src/ BAMTOOLSLIB=/path to bamtools/build/src/api/ "; 


$(samtools_present):
	@echo "samtools found"
	@make BamFunctions.o

$(samtools_absent):
	@echo "Warning: samtools not found"

BamFunctions.o:
	${CXX} ${CXXFLAGS} ${CXXFLAGSHTS} -c -o BamFunctions.o BamFunctions.cpp

gzstream/libgzstream.a:
	make -C gzstream/

gzstream/gzstream.o:
	make -C gzstream/


testUtils:	testUtils.o  utils.o gzstream/libgzstream.a
	${CXX} $(LDFLAGS) -o $@ $^ $(LDLIBS)

testRecons:	testRecons.o  utils.o ${BAMTOOLSLIBOBJ}  ReconsReferenceBAM.o gzstream/libgzstream.a
	${CXX} $(LDFLAGS) -o $@ $^ $(LDLIBS)

%.o: %.cpp
	${CXX} ${CXXFLAGS} -c $^ -o $@

clean :
	rm -f testRecons testUtils *.o 
	make -C gzstream/ clean

.PHONY: all
