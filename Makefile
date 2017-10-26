BAMTOOLS= $(realpath ../bamtools/)
CXX      = g++ #-g  -pg
CXXFLAGS = -Wall  -lm -O3 -I. -Igzstream/ -I${BAMTOOLS}/build/src/api/include/ -I${BAMTOOLS}/build/src/include/  -c 
LDLIBS   = -lz


all: utils.o testUtils ReconsReferenceBAM.o PutProgramInHeader.o gzstream/gzstream.o FastQObj.o FastQParser.o testRecons testRecons.o


gzstream/libgzstream.a:
	make -C gzstream/

gzstream/gzstream.o:
	make -C gzstream/

testUtils:	testUtils.o  utils.o gzstream/libgzstream.a
	${CXX} $(LDFLAGS) -o $@ $^ $(LDLIBS)


testRecons:	testRecons.o  utils.o ${BAMTOOLS}/build/src/api/libbamtools.a   ReconsReferenceBAM.o gzstream/libgzstream.a
	${CXX} $(LDFLAGS) -o $@ $^ $(LDLIBS)

%.o: %.cpp
	${CXX} ${CXXFLAGS} $^ -o $@


clean :
	rm -f testRecons testUtils *.o 
	make -C gzstream/ clean
