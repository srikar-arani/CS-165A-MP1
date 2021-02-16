#include "naiveBayes.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <istream>

using namespace std;


int main(int argc, char*argv[]){

  NaiveBayes nb;
  nb.readTraining("train.csv");

  string myString = nb.myString;
  string line = nb.line;
  double linecount = nb.linecount;
  double playcount = nb.playcount;
  double negplaycount = nb.negplaycount;
  double golf = nb.golf;
  double neggolf = nb.neggolf;
  double sunny = nb.sunny;
  double negsunny = nb.negsunny;
  double cool = nb.cool;
  double negcool = nb.negcool;
  double high = nb.high;
  double neghigh = nb.neghigh;
  double strong = nb.strong;
  double negstrong = nb.negstrong;

  cout << "Chance of Golf: "<< golf << "\nChance of no Golf: " <<neggolf << endl;
  cout << "Sunny | Golf: "<< sunny/playcount << "\nSunny | No Golf: " <<negsunny/(negplaycount) << endl;
  cout << "Cool | Golf: "<< cool/playcount << "\nCool | No Golf: " <<negcool/(negplaycount) << endl;
  cout << "High | Golf: "<< high/playcount << "\nHigh | No Golf: " <<neghigh/(negplaycount) << endl;
  cout << "Strong | Golf: "<< strong/playcount << "\nStrong | No Golf: " <<negstrong/(negplaycount) << endl;

  nb.readUnknown("train2.csv");

  return 0;
}
