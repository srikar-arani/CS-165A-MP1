#include "naiveBayes.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <istream>

using namespace std;

void read_record()
{


}

int main(int argc, char*argv[]){

  ifstream myFileStream("train.csv");
  if(!myFileStream.is_open()){
    cout << "File Failed to Open" << endl;
    return 0;
  }
  string outlook,temp,humidity,windy,play;

  string myString;
  string line;
  double linecount = 0;
  double playcount = 0;
  double negplaycount = 0;
  double golf = 0;
  double neggolf = 0;
  double sunny = 0;
  double negsunny = 0;
  double cool = 0;
  double negcool = 0;
  double high = 0;
  double neghigh = 0;
  double strong = 0;
  double negstrong = 0;

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

  cout << "Chance of Golf: "<< golf << "\nChance of no Golf: " <<neggolf << endl;
  cout << "Sunny | Golf: "<< sunny/playcount << "\nSunny | No Golf: " <<negsunny/(negplaycount) << endl;
  cout << "Cool | Golf: "<< cool/playcount << "\nCool | No Golf: " <<negcool/(negplaycount) << endl;
  cout << "High | Golf: "<< high/playcount << "\nHigh | No Golf: " <<neghigh/(negplaycount) << endl;
  cout << "Strong | Golf: "<< strong/playcount << "\nStrong | No Golf: " <<negstrong/(negplaycount) << endl;




  string myString2;
  string line2;

  ifstream myFileStream2("train2.csv");
  if(!myFileStream2.is_open()){
    cout << "File Failed to Open" << endl;
    return 0;
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
  




  return 0;
}
