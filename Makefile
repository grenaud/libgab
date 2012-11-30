CXX      = g++ -g  #-pg
CXXFLAGS = -Wall -lm -O3   -c


all: utils.o testUtils ReconsReferenceBAM.o


utils.o:	utils.cpp
	${CXX} ${CXXFLAGS} utils.cpp


testUtils.o:	testUtils.cpp
	${CXX} ${CXXFLAGS} testUtils.cpp


testUtils:	testUtils.o ${LIBGAB}utils.o  utils.o
	${CXX} $(LDFLAGS) -o $@ $^ $(LDLIBS)

ReconsReferenceBAM.o: ReconsReferenceBAM.cpp
	${CXX} ${CXXFLAGS} ReconsReferenceBAM.cpp

clean :
	rm -f utils.o testUtils.o testUtils ReconsReferenceBAM.o

