CXX=clang++

CXXFLAGS = -std=c++11 -Wall -Wextra -Wno-unused-parameter -Wno-unused-private-field

BINARIES= NaiveBayesClassifier

all: ${BINARIES}

project3: mp1.o NaiveBayes.o
	${CXX} $^ -o NaiveBayesClassifier.out

clean:
	/bin/rm -f ${BINARIES} *.o *.out
