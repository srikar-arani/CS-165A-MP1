#include "naiveBayes.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <istream>
#include <time.h>

using namespace std;


int main(int argc, char*argv[]){
  //TIME CALCULATION
  //clock_t tStart = clock();

  NaiveBayes nb;
  nb.readTraining(argv[1]);
/*
  string myString = nb.myString;
  string line = nb.line;
  double linecount = nb.linecount;
  double deadCount = nb.deadCount;
  double _deadCount = nb._deadCount;
  double dead = nb.dead;
  double _dead = nb._dead;
  double sex_1 = nb.sex_1;
  double sex_2 = nb.sex_2;
  double _sex_1 = nb._sex_1;
  double _sex_2 = nb._sex_2;
  double patient_type_1 = nb.patient_type_1;
  double patient_type_2 = nb.patient_type_2;
  double _patient_type_1 = nb._patient_type_1;
  double _patient_type_2 = nb._patient_type_2;
  double intubed_1 = nb.intubed_1;
  double intubed_2 = nb.intubed_2;
  double _intubed_1 = nb._intubed_1;
  double _intubed_2 = nb._intubed_2;
  double pneumonia_1 = nb.pneumonia_1;
  double pneumonia_2 = nb.pneumonia_2;
  double _pneumonia_1 = nb._pneumonia_1;
  double _pneumonia_2 = nb._pneumonia_2;
*/
/*
  cout << "Chance of dead: "<< dead << "\nChance of no dead: " <<_dead << endl;
  cout << "sex_1 | dead: "<< sex_1/deadCount << "\nsex_1 | No dead: " <<_sex_1/(_deadCount) << endl;
  cout << "sex_2 | dead: "<< sex_2/deadCount << "\nsex_2 | No dead: " <<_sex_2/(_deadCount) << endl;
  cout << "patient_type_1 | dead: "<< patient_type_1/deadCount << "\npatient_type_1 | No dead: " <<_patient_type_1/(_deadCount) << endl;
  cout << "patient_type_2 | dead: "<< patient_type_2/deadCount << "\npatient_type_2 | No dead: " <<_patient_type_2/(_deadCount) << endl;
  cout << "intubed_1 | dead: "<< intubed_1/deadCount << "\nintubed_1 | No dead: " <<_intubed_1/(_deadCount) << endl;
  cout << "intubed_2 | dead: "<< intubed_2/deadCount << "\nintubed_2 | No dead: " <<_intubed_2/(_deadCount) << endl;
  cout << "pneumonia_1 | dead: "<< pneumonia_1/deadCount << "\npneumonia_1 | No dead: " <<_pneumonia_1/(_deadCount) << endl;
  cout << "pneumonia_2 | dead: "<< pneumonia_2/deadCount << "\npneumonia_2 | No dead: " <<_pneumonia_2/(_deadCount) << endl;
*/
  nb.readUnknown(argv[2]);

  //END TIME CALCULATION
  //printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
  return 0;
}
