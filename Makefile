
BAMTOOLS= $(realpath ../bamtools/)

#defined via user
ifdef BAMTOOLSINC
	BAMTOOLSINCAPI=${BAMTOOLSINC}
	BAMTOOLSINCSHARED=${BAMTOOLSINC}
else
	BAMTOOLSINCAPI=${BAMTOOLS}/build/src/api/include/
	BAMTOOLSINCSHARED=${BAMTOOLS}/build/src/include/
endif

ifdef BAMTOOLSLIB
	BAMTOOLSLIBOBJ=${BAMTOOLSLIB}/libbamtools.a 
else
	BAMTOOLSLIBOBJ=${BAMTOOLS}/build/src/api/libbamtools.a 
endif





CXX      = g++ #-g  -pg
CXXFLAGS = -Wall  -lm -O3 -I. -Igzstream/ -I${BAMTOOLSINCAPI} -I${BAMTOOLSINCSHARED}  -c 
LDLIBS   = -lz


all: utils.o testUtils ReconsReferenceBAM.o PutProgramInHeader.o gzstream/gzstream.o FastQObj.o FastQParser.o testRecons testRecons.o


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
