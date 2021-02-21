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
  double deadCount;
  double _deadCount;
  double dead;
  double _dead;
  double sex_1;
	double sex_2;
	double _sex_1;
	double _sex_2;
	double patient_type_1;
	double patient_type_2;
	double _patient_type_1;
	double _patient_type_2;
	double intubed_1;
	double intubed_2;
	double _intubed_1;
	double _intubed_2;
	double pneumonia_1;
	double pneumonia_2;
	double _pneumonia_1;
	double _pneumonia_2;
	double pregnancy_1;
  double pregnancy_2;
  double _pregnancy_1;
  double _pregnancy_2;
	double diabetes_1;
	double diabetes_2;
	double _diabetes_1;
	double _diabetes_2;
	double copd_1;
	double copd_2;
	double _copd_1;
	double _copd_2;
	double asthma_1;
	double asthma_2;
	double _asthma_1;
	double _asthma_2;
	double inmsupr_1;
	double inmsupr_2;
	double _inmsupr_1;
	double _inmsupr_2;
	double hypertension_1;
	double hypertension_2;
	double _hypertension_1;
	double _hypertension_2;
	double other_disease_1;
	double other_disease_2;
	double _other_disease_1;
	double _other_disease_2;
	double cardiovascular_1;
	double cardiovascular_2;
	double _cardiovascular_1;
	double _cardiovascular_2;
	double obesity_1;
	double obesity_2;
	double _obesity_1;
	double _obesity_2;
	double renal_chronic_1;
	double renal_chronic_2;
	double _renal_chronic_1;
	double _renal_chronic_2;
	double tobacco_1;
	double tobacco_2;
	double _tobacco_1;
	double _tobacco_2;
	double contact_other_covid_1;
	double contact_other_covid_2;
	double _contact_other_covid_1;
	double _contact_other_covid_2;
	double covid_res_1;
	double covid_res_2;
	double _covid_res_1;
	double _covid_res_2;
	double icu_1;
	double icu_2;
	double _icu_1;
	double _icu_2;
	double age_1;
	double age_2;
	double _age_1;
	double _age_2;
};

#endif
