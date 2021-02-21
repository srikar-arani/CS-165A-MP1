CXX=g++

CXXFLAGS = -std=c++11 -Wall -Wextra -Wno-unused-parameter -Wno-unused-private-field

BINARIES= mp1

all: ${BINARIES}

mp1: mp1.o naiveBayes.o
	${CXX} $^ -o NaiveBayesClassifier

clean:
	/bin/rm -f ${BINARIES} *.o *.out
