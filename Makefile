BAMTOOLS= /mnt/solexa/bin/bamtools-2.2.2/

CXX      = g++ #-g  -pg
CXXFLAGS = -Wall -lm -O3 -I. -I${BAMTOOLS}/include/ -c 


all: utils.o testUtils ReconsReferenceBAM.o PutProgramInHeader.o


testUtils:	testUtils.o ${LIBGAB}utils.o  utils.o
	${CXX} $(LDFLAGS) -o $@ $^ $(LDLIBS)

%.o: %.cpp
	${CXX} ${CXXFLAGS} $^ -o $@


clean :
	rm -f utils.o testUtils.o testUtils ReconsReferenceBAM.o PutProgramInHeader.o

