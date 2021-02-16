#include "naiveBayes.h"

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <istream>

using namespace std;

NaiveBayes::NaiveBayes() {
  //Constructor
  linecount = 0;
  playcount = 0;
  negplaycount = 0;
  golf = 0;
  neggolf = 0;
  sunny = 0;
  negsunny = 0;
  cool = 0;
  negcool = 0;
  high = 0;
  neghigh = 0;
  strong = 0;
  negstrong = 0;
}

NaiveBayes::~NaiveBayes() {
  //Destructor
}

void NaiveBayes::readTraining(string fileName) {

  ifstream myFileStream(fileName);
  if(!myFileStream.is_open()){
    cout << "File Failed to Open" << endl;
  }
  string outlook,temp,humidity,windy,play;

  while(getline(myFileStream, line)) {
    stringstream ss(line);
    getline(ss, outlook, ',');
    getline(ss, temp, ',');
    getline(ss, humidity, ',');
    getline(ss, windy, ',');
    getline(ss, play, ',');
    if (play == "yes") {
      if (outlook == "sunny") {
        sunny++;
      }
      if (temp == "cool") {
        cool++;
      }
      if (humidity == "high") {
        high++;
      }
      if (windy == "true") {
        strong++;
      }
      playcount++;
    } else {
      if (outlook == "sunny") {
        negsunny++;
      }
      if (temp == "cool") {
        negcool++;
      }
      if (humidity == "high") {
        neghigh++;
      }
      if (windy == "true") {
        negstrong++;
      }
      negplaycount++;
    }
    linecount++;
  }

  myFileStream.close();

  golf = playcount/linecount;
  neggolf = negplaycount/linecount;

}

void NaiveBayes::readUnknown(string fileName) {
  string myString2;
  string line2;

  ifstream myFileStream2(fileName);
  if(!myFileStream2.is_open()){
    cout << "File Failed to Open" << endl;
  }

  string outlook2,temp2,humidity2,windy2,play2;



  while(getline(myFileStream2, line2)) {
    double probTrue = 1;
    double probFalse = 1;
    stringstream ss2(line2);
    getline(ss2, outlook2, ',');
    getline(ss2, temp2, ',');
    getline(ss2, humidity2, ',');
    getline(ss2, windy2, ',');
    if (outlook2 == "sunny") {
      probTrue*= (sunny/playcount);
      probFalse*= (negsunny/negplaycount);
    } else {
      probTrue*= 1-(sunny/playcount);
      probFalse*= 1-(negsunny/negplaycount);
    }
    if (temp2 == "cool") {
      probTrue*= (cool/playcount);
      probFalse*= (negcool/(negplaycount));
    } else {
      probTrue*= 1-(cool/playcount);
      probFalse*= 1-(negcool/(negplaycount));
    }
    if (humidity2 == "high") {
      probTrue*= (high/playcount);
      probFalse*= (neghigh/(negplaycount));
    } else {
      probTrue*= 1-(high/playcount);
      probFalse*= 1-(neghigh/(negplaycount));
    }
    if (windy2 == "true") {
      probTrue*= (strong/playcount);
      probFalse*= (negstrong/(negplaycount));
    } else {
      probTrue*= 1-(strong/playcount);
      probFalse*= 1-(negstrong/(negplaycount));
    }

    cout << "Probability Golf: " << (probTrue*golf) << endl;
    cout << "Probability No Golf: " << (probFalse*neggolf) << endl;
  }

  myFileStream2.close();
}
