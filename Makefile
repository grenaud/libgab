
BAMTOOLS= $(realpath ../bamtools/)
SAMTOOLS= $(realpath ../samtools/)
HTSLIB= $(realpath ../htslib/)


#defined via user
ifdef BAMTOOLSINC
	BAMTOOLSINCAPI=${BAMTOOLSINC}
	BAMTOOLSINCSHARED=${BAMTOOLSINC}
else
	BAMTOOLSINCAPI=${BAMTOOLS}/build/src/
	BAMTOOLSINCSHARED=${BAMTOOLS}/src/
endif

ifdef BAMTOOLSLIB
	BAMTOOLSLIBOBJ=${BAMTOOLSLIB}/libbamtools.a 
else
	BAMTOOLSLIBOBJ=${BAMTOOLS}/build/src/libbamtools.a 
endif

ifeq ($(CXX),)
CXX := g++ #-g  -pg 
endif

ifeq ($(SAMTOOLSINC),)#no defined 
SAMTOOLSINC := ${SAMTOOLS}
endif

ifeq ($(HTSLIBINC),)#no defined 
HTSLIBINC := ${HTSLIB}
endif


CXXFLAGS += -Wall  -lm -O3 -I. -Igzstream/ -I${BAMTOOLSINCAPI} -I${BAMTOOLSINCSHARED} 
LDLIBS   += -lz
LDLIBSHTS = ${SAMTOOLSINC}/bedidx.o ${HTSLIBINC}/libhts.a  ${SAMTOOLSINC}/libst.a 
CXXFLAGSHTS = -I${HTSLIBINC} -I${SAMTOOLSINC}

#.PHONY: clean all 

bamtools_target  = $(BAMTOOLSINCAPI)-$(wildcard $(BAMTOOLSINCAPI))
bamtools_present = $(BAMTOOLSINCAPI)-$(BAMTOOLSINCAPI)
bamtools_absent  = $(BAMTOOLSINCAPI)-

samtools_target  = $(SAMTOOLS)-$(wildcard $(SAMTOOLS))
samtools_present = $(SAMTOOLS)-$(SAMTOOLS)
samtools_absent  = $(SAMTOOLS)-

all:  | $(bamtools_target) $(samtools_target)  libgab.o testUtils targetTest  PutProgramInHeaderHTS.o gzstream/gzstream.o FastQObj.o FastQParser.o libgab.a
#	all: libgab.o testUtils ReconsReferenceBAM.o PutProgramInHeader.o PutProgramInHeaderHTS.o gzstream/gzstream.o FastQObj.o FastQParser.o testRecons testRecons.o


$(bamtools_present):
	@echo "bamtools found"
	@make ReconsReferenceBAM.o
	@make PutProgramInHeader.o
	@make testRecons.o
	@make testRecons
	ar cr libgabbamtools.a ReconsReferenceBAM.o PutProgramInHeader.o

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
	ar cr libgabbamhts.a BamFunctions.o

gzstream/libgzstream.a:
	make CXX=${CXX} CPPFLAGS="${CXXFLAGS}" -C gzstream/

gzstream/gzstream.o:
	make CXX=${CXX} CPPFLAGS="${CXXFLAGS}" -C gzstream/

testUtils:	testUtils.o  libgab.a gzstream/libgzstream.a
	${CXX} $(LDFLAGS) -o $@ $^ $(LDLIBS)

targetTest:	targetTest.o libgab.a gzstream/libgzstream.a
	${CXX} $(LDFLAGS) -o $@ $^ $(LDLIBS)

testRecons:	testRecons.o libgab.a ${BAMTOOLSLIBOBJ}  ReconsReferenceBAM.o gzstream/libgzstream.a
	${CXX} $(LDFLAGS) -o $@ $^ $(LDLIBS)

libgab.a: libgab.o FastQObj.o FastQParser.o PutProgramInHeaderHTS.o
	ar cr libgab.a libgab.o FastQObj.o FastQParser.o PutProgramInHeaderHTS.o

test:	all
	./test.sh

%.o: %.cpp
	${CXX} ${CXXFLAGS} -c $^ -o $@

clean :
	rm -f testRecons testUtils *.o  *.a
	make  -C gzstream/ clean

.PHONY: all
