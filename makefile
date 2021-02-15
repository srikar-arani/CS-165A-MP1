CXX=clang++

CXXFLAGS = -std=c++11 -Wall -Wextra -Wno-unused-parameter -Wno-unused-private-field

BINARIES= mp1

all: ${BINARIES}

NaiveBayesClassifier: mp1.o naiveBayes.o
	${CXX} $^ -o NaiveBayesClassifier.out

clean:
	/bin/rm -f ${BINARIES} *.o *.out
