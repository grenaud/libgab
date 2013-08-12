BAMTOOLS= $(realpath ../bamtools/)

CXX      = g++ #-g  -pg
CXXFLAGS = -Wall -lm -O3 -I. -Igzstream/ -I${BAMTOOLS}/include/ -c 


all: utils.o testUtils ReconsReferenceBAM.o PutProgramInHeader.o gzstream/gzstream.o FastQObj.o


gzstream/libgzstream.a:
	make -C gzstream/

testUtils:	testUtils.o ${LIBGAB}utils.o  utils.o
	${CXX} $(LDFLAGS) -o $@ $^ $(LDLIBS)

%.o: %.cpp
	${CXX} ${CXXFLAGS} $^ -o $@


clean :
	rm -f utils.o testUtils.o testUtils ReconsReferenceBAM.o PutProgramInHeader.o
	make -C gzstream/ clean
