
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
CXXFLAGS = -Wall  -lm -O3 -I. -Igzstream/ -I${BAMTOOLSINCAPI} -I${BAMTOOLSINCSHARED}  -c 
LDLIBS   = -lz

#.PHONY: clean all 

bamtools_target  = $(BAMTOOLSINCAPI)-$(wildcard $(BAMTOOLSINCAPI))
bamtools_present = $(BAMTOOLSINCAPI)-$(BAMTOOLSINCAPI)
bamtools_absent  = $(BAMTOOLSINCAPI)-

all:  | $(bamtools_target)  utils.o testUtils   PutProgramInHeaderHTS.o gzstream/gzstream.o FastQObj.o FastQParser.o
#	all: utils.o testUtils ReconsReferenceBAM.o PutProgramInHeader.o PutProgramInHeaderHTS.o gzstream/gzstream.o FastQObj.o FastQParser.o testRecons testRecons.o



$(bamtools_present):
	@echo "bamtools found"
	@make ReconsReferenceBAM.o
	@make PutProgramInHeader.o
	@make testRecons.o
	@make testRecons

$(bamtools_absent):
	@echo "bamtools not found"
	@echo "You can specify bamtools using make BAMTOOLSINC=/path to bamtools/src/ BAMTOOLSLIB=/path to bamtools/build/src/api/ "; \

gzstream/libgzstream.a:
	make -C gzstream/

gzstream/gzstream.o:
	make -C gzstream/

testUtils:	testUtils.o  utils.o gzstream/libgzstream.a
	${CXX} $(LDFLAGS) -o $@ $^ $(LDLIBS)

testRecons:	testRecons.o  utils.o ${BAMTOOLSLIBOBJ}  ReconsReferenceBAM.o gzstream/libgzstream.a
	${CXX} $(LDFLAGS) -o $@ $^ $(LDLIBS)

%.o: %.cpp
	${CXX} ${CXXFLAGS} $^ -o $@

clean :
	rm -f testRecons testUtils *.o 
	make -C gzstream/ clean

.PHONY: all
