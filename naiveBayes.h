#ifndef NAIVEBAYES_H
#define NAIVEBAYES_H

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <istream>

class NaiveBayes{
public:
	NaiveBayes();
	~NaiveBayes();

	void readTraining(std::string fileName);
	void readUnknown(std::string fileName);


	std::string myString;
  std::string line;
  double linecount;
  double playcount;
  double negplaycount;
  double golf;
  double neggolf;
  double sunny;
  double negsunny;
  double cool;
  double negcool;
  double high;
  double neghigh;
  double strong;
  double negstrong;
};

#endif
