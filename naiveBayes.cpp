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
  deadCount = 0;
  _deadCount = 0;
  dead = 0;
  _dead = 0;
  sex_1 = 0;
	sex_2 = 0;
	_sex_1 = 0;
	_sex_2 = 0;
  patient_type_1 = 0;
	patient_type_2 = 0;
	_patient_type_1 = 0;
	_patient_type_2 = 0;
  intubed_1 = 0;
  intubed_2 = 0;
  _intubed_1 = 0;
  _intubed_2 = 0;
  pneumonia_1 = 0;
  pneumonia_2 = 0;
  _pneumonia_1 = 0;
  _pneumonia_2 = 0;
  pregnancy_1 = 0;
  pregnancy_2 = 0;
  _pregnancy_1 = 0;
  _pregnancy_2 = 0;
  diabetes_1 = 0;
	diabetes_2 = 0;
	_diabetes_1 = 0;
	_diabetes_2 = 0;
  copd_1 = 0;
  copd_2 = 0;
  _copd_1 = 0;
  _copd_2 = 0;
  asthma_1 = 0;
	asthma_2 = 0;
	_asthma_1 = 0;
	_asthma_2 = 0;
  inmsupr_1 = 0;
	inmsupr_2 = 0;
	_inmsupr_1 = 0;
	_inmsupr_2 = 0;
  hypertension_1 = 0;
	hypertension_2 = 0;
	_hypertension_1 = 0;
	_hypertension_2 = 0;
  other_disease_1 = 0;
	other_disease_2 = 0;
	_other_disease_1 = 0;
	_other_disease_2 = 0;
  cardiovascular_1 = 0;
	cardiovascular_2 = 0;
	_cardiovascular_1 = 0;
	_cardiovascular_2 = 0;
  obesity_1 = 0;
	obesity_2 = 0;
	_obesity_1 = 0;
	_obesity_2 = 0;
  renal_chronic_1 = 0;
	renal_chronic_2 = 0;
	_renal_chronic_1 = 0;
	_renal_chronic_2 = 0;
  tobacco_1 = 0;
	tobacco_2 = 0;
	_tobacco_1 = 0;
	_tobacco_2 = 0;
  contact_other_covid_1 = 0;
	contact_other_covid_2 = 0;
	_contact_other_covid_1 = 0;
	_contact_other_covid_2 = 0;
  covid_res_1 = 0;
	covid_res_2 = 0;
	_covid_res_1 = 0;
	_covid_res_2 = 0;
  icu_1 = 0;
	icu_2 = 0;
	_icu_1 = 0;
	_icu_2 = 0;
  age_1 = 0;
	age_2 = 0;
	_age_1 = 0;
	_age_2 = 0;
}

NaiveBayes::~NaiveBayes() {
  //Destructor
}

void NaiveBayes::readTraining(string fileName) {

  ifstream myFileStream(fileName);
  if(!myFileStream.is_open()){
    cout << "File Failed to Open" << endl;
  }

  string line;

  string sex,patient_type,entry_date,date_symptoms,date_died,intubed,pneumonia,age,pregnancy,diabetes,copd,asthma,inmsupr,hypertension,other_disease,cardiovascular,obesity,renal_chronic,tobacco,contact_other_covid,covid_res,icu;

  std::getline(myFileStream, line);
  while(getline(myFileStream, line)) {
    stringstream ss(line);
    getline(ss, sex, ',');
    getline(ss, patient_type, ',');
    getline(ss, entry_date, ',');
    getline(ss, date_symptoms, ',');
    getline(ss, date_died, ',');
    getline(ss, intubed, ',');
    getline(ss, pneumonia, ',');
    getline(ss, age, ',');
    getline(ss, pregnancy, ',');
    getline(ss, diabetes, ',');
    getline(ss, copd, ',');
    getline(ss, asthma, ',');
    getline(ss, inmsupr, ',');
    getline(ss, hypertension, ',');
    getline(ss, other_disease, ',');
    getline(ss, cardiovascular, ',');
    getline(ss, obesity, ',');
    getline(ss, renal_chronic, ',');
    getline(ss, tobacco, ',');
    getline(ss, contact_other_covid, ',');
    getline(ss, covid_res, ',');
    getline(ss, icu, ',');

    if (date_died != "9999-99-99") {
      if (sex == "1") {
        sex_1++;
      } else if (sex == "2") {
        sex_2++;
      }
      if (patient_type == "1") {
        patient_type_1++;
      } else if (patient_type == "2") {
        patient_type_2++;
      }
      if (intubed == "1") {
        intubed_1++;
      } else if (intubed == "2") {
        intubed_2++;
      }
      if (pneumonia == "1") {
        pneumonia_1++;
      } else if (pneumonia == "2") {
        pneumonia_2++;
      }
      if (pregnancy == "1") {
        pregnancy_1++;
      } else if (pregnancy == "2") {
        pregnancy_2++;
      }
      if (diabetes == "1") {
        diabetes_1++;
      } else if (diabetes == "2") {
        diabetes_2++;
      }
      if (copd == "1") {
        copd_1++;
      } else if (copd == "2") {
        copd_2++;
      }
      if (asthma == "1") {
        asthma_1++;
      } else if (asthma == "2") {
        asthma_2++;
      }
      if (inmsupr == "1") {
        inmsupr_1++;
      } else if (inmsupr == "2") {
        inmsupr_2++;
      }
      if (hypertension == "1") {
        hypertension_1++;
      } else if (hypertension == "2") {
        hypertension_2++;
      }
      if (other_disease == "1") {
        other_disease_1++;
      } else if (other_disease == "2") {
        other_disease_2++;
      }
      if (cardiovascular == "1") {
        cardiovascular_1++;
      } else if (cardiovascular == "2") {
        cardiovascular_2++;
      }
      if (obesity == "1") {
        obesity_1++;
      } else if (obesity == "2") {
        obesity_2++;
      }
      if (renal_chronic == "1") {
        renal_chronic_1++;
      } else if (renal_chronic == "2") {
        renal_chronic_2++;
      }
      if (tobacco == "1") {
        tobacco_1++;
      } else if (tobacco == "2") {
        tobacco_2++;
      }
      if (contact_other_covid == "1") {
        contact_other_covid_1++;
      } else if (contact_other_covid == "2") {
        contact_other_covid_2++;
      }
      if (covid_res == "1") {
        covid_res_1++;
      } else if (covid_res == "2") {
        covid_res_2++;
      }
      if (icu == "1") {
        icu_1++;
      } else if (icu == "2") {
        icu_2++;
      }
      if (stoi(age) >= 50 && stoi(age) < 100) {
        age_1++;
      } else {
        age_2++;
      }
      deadCount++;

      //cout << age << endl;
    } else {
      if (sex == "1") {
        _sex_1++;
      } else if (sex == "2") {
        _sex_2++;
      }
      if (patient_type == "1") {
        _patient_type_1++;
      } else if (patient_type == "2") {
        _patient_type_2++;
      }
      if (intubed == "1") {
        _intubed_1++;
      } else if (intubed == "2") {
        _intubed_2++;
      }
      if (pneumonia == "1") {
        _pneumonia_1++;
      } else if (pneumonia == "2") {
        _pneumonia_2++;
      }
      if (pregnancy == "1") {
        _pregnancy_1++;
      } else if (pregnancy == "2") {
        _pregnancy_2++;
      }
      if (diabetes == "1") {
        _diabetes_1++;
      } else if (diabetes == "2") {
        _diabetes_2++;
      }
      if (copd == "1") {
        _copd_1++;
      } else if (copd == "2") {
        _copd_2++;
      }
      if (asthma == "1") {
        _asthma_1++;
      } else if (asthma == "2") {
        _asthma_2++;
      }
      if (inmsupr == "1") {
        _inmsupr_1++;
      } else if (inmsupr == "2") {
        _inmsupr_2++;
      }
      if (hypertension == "1") {
        _hypertension_1++;
      } else if (hypertension == "2") {
        _hypertension_2++;
      }
      if (other_disease == "1") {
        _other_disease_1++;
      } else if (other_disease == "2") {
        _other_disease_2++;
      }
      if (cardiovascular == "1") {
        _cardiovascular_1++;
      } else if (cardiovascular == "2") {
        _cardiovascular_2++;
      }
      if (obesity == "1") {
        _obesity_1++;
      } else if (obesity == "2") {
        _obesity_2++;
      }
      if (renal_chronic == "1") {
        _renal_chronic_1++;
      } else if (renal_chronic == "2") {
        _renal_chronic_2++;
      }
      if (tobacco == "1") {
        _tobacco_1++;
      } else if (tobacco == "2") {
        _tobacco_2++;
      }
      if (contact_other_covid == "1") {
        _contact_other_covid_1++;
      } else if (contact_other_covid == "2") {
        _contact_other_covid_2++;
      }
      if (covid_res == "1") {
        _covid_res_1++;
      } else if (covid_res == "2") {
        _covid_res_2++;
      }
      if (icu == "1") {
        _icu_1++;
      } else if (icu == "2") {
        _icu_2++;
      }
      if (stoi(age) >= 50 && stoi(age) < 100) {
        _age_1++;
      } else {
        _age_2++;
      }
      _deadCount++;
    }
    linecount++;
  }

  myFileStream.close();

  dead = deadCount/linecount;
  _dead = _deadCount/linecount;

}

void NaiveBayes::readUnknown(string fileName) {

  ifstream myFileStream2(fileName);
  if(!myFileStream2.is_open()){
    cout << "File Failed to Open" << endl;
  }
  string line;

  string sex,patient_type,entry_date,date_symptoms,date_died,intubed,pneumonia,age,pregnancy,diabetes,copd,asthma,inmsupr,hypertension,other_disease,cardiovascular,obesity,renal_chronic,tobacco,contact_other_covid,covid_res,icu;


  double accuracyRight = 0;
  double accuracyWrong = 0;

  int k  = 0;

  std::getline(myFileStream2, line);
  while(getline(myFileStream2, line)) {
    double probTrue = 1;
    double probFalse = 1;
    stringstream ss(line);
    getline(ss, sex, ',');
    getline(ss, patient_type, ',');
    getline(ss, entry_date, ',');
    getline(ss, date_symptoms, ',');
    getline(ss, date_died, ',');
    getline(ss, intubed, ',');
    getline(ss, pneumonia, ',');
    getline(ss, age, ',');
    getline(ss, pregnancy, ',');
    getline(ss, diabetes, ',');
    getline(ss, copd, ',');
    getline(ss, asthma, ',');
    getline(ss, inmsupr, ',');
    getline(ss, hypertension, ',');
    getline(ss, other_disease, ',');
    getline(ss, cardiovascular, ',');
    getline(ss, obesity, ',');
    getline(ss, renal_chronic, ',');
    getline(ss, tobacco, ',');
    getline(ss, contact_other_covid, ',');
    getline(ss, covid_res, ',');
    getline(ss, icu, ',');

    if (sex == "1") {
      probTrue*= ((sex_1+k)/(deadCount + (k*2)));
      probFalse*= ((_sex_1+k)/(_deadCount + (k*2)));
    } else if (sex == "2") {
      probTrue*= ((sex_2+k)/(deadCount + (k*2)));
      probFalse*= ((_sex_2+k)/(_deadCount + (k*2)));
    }
    if (patient_type == "1") {
      probTrue*= ((patient_type_1+k)/(deadCount + (k*2)));
      probFalse*= ((_patient_type_1+k)/(_deadCount + (k*2)));
    } else if (patient_type == "2") {
      probTrue*= ((patient_type_2+k)/(deadCount + (k*2)));
      probFalse*= ((_patient_type_2+k)/(_deadCount + (k*2)));
    }
    if (intubed == "1") {
      probTrue*= ((intubed_1+k)/(deadCount + (k*2)));
      probFalse*= ((_intubed_1+k)/(_deadCount + (k*2)));
    } else if (intubed == "2"){
      probTrue*= ((intubed_2+k)/(deadCount + (k*2)));
      probFalse*= ((_intubed_2+k)/(_deadCount + (k*2)));
    }
    if (pneumonia == "1") {
      probTrue*= ((pneumonia_1+k)/(deadCount + (k*2)));
      probFalse*= ((_pneumonia_1+k)/(_deadCount + (k*2)));
    } else if (pneumonia == "2") {
      probTrue*= ((pneumonia_2+k)/(deadCount + (k*2)));
      probFalse*= ((_pneumonia_2+k)/(_deadCount + (k*2)));
    } else {
      probTrue*= ((pneumonia_1+k)/(deadCount + (k*2)));
      probFalse*= ((_pneumonia_1+k)/(_deadCount + (k*2)));
    }
    if (pregnancy == "1") {
      probTrue*= ((pregnancy_1+k)/(deadCount + (k*2)));
      probFalse*= ((_pregnancy_1+k)/(_deadCount + (k*2)));
    } else if (pregnancy == "2") {
      probTrue*= ((pregnancy_2+k)/(deadCount + (k*2)));
      probFalse*= ((_pregnancy_2+k)/(_deadCount + (k*2)));
    } else {
      probTrue*= ((pregnancy_2+k)/(deadCount + (k*2)));
      probFalse*= ((_pregnancy_2+k)/(_deadCount + (k*2)));
    }
    if (diabetes == "1") {
      probTrue*= ((diabetes_1+k)/(deadCount + (k*2)));
      probFalse*= ((_diabetes_1+k)/(_deadCount + (k*2)));
    } else if (diabetes == "2") {
      probTrue*= ((diabetes_2+k)/(deadCount + (k*2)));
      probFalse*= ((_diabetes_2+k)/(_deadCount + (k*2)));
    }
    if (copd == "1") {
      probTrue*= ((copd_1+k)/(deadCount + (k*2)));
      probFalse*= ((_copd_1+k)/(_deadCount + (k*2)));
    } else if (copd == "2") {
      probTrue*= ((copd_2+k)/(deadCount + (k*2)));
      probFalse*= ((_copd_2+k)/(_deadCount + (k*2)));
    }
    if (asthma == "1") {
      probTrue*= ((asthma_1+k)/(deadCount + (k*2)));
      probFalse*= ((_asthma_1+k)/(_deadCount + (k*2)));
    } else if (asthma == "2") {
      probTrue*= ((asthma_2+k)/(deadCount + (k*2)));
      probFalse*= ((_asthma_2+k)/(_deadCount + (k*2)));
    }
    if (inmsupr == "1") {
      probTrue*= ((inmsupr_1+k)/(deadCount + (k*2)));
      probFalse*= ((_inmsupr_1+k)/(_deadCount + (k*2)));
    } else if (inmsupr == "2") {
      probTrue*= ((inmsupr_2+k)/(deadCount + (k*2)));
      probFalse*= ((_inmsupr_2+k)/(_deadCount + (k*2)));
    } else {
      probTrue*= ((inmsupr_2+k)/(deadCount + (k*2)));
      probFalse*= ((_inmsupr_2+k)/(_deadCount + (k*2)));
    }
    if (hypertension == "1") {
      probTrue*= ((hypertension_1+k)/(deadCount + (k*2)));
      probFalse*= ((_hypertension_1+k)/(_deadCount + (k*2)));
    } else if (hypertension == "2") {
      probTrue*= ((hypertension_2+k)/(deadCount + (k*2)));
      probFalse*= ((_hypertension_2+k)/(_deadCount + (k*2)));
    }
    if (other_disease == "1") {
      probTrue*= ((other_disease_1+k)/(deadCount + (k*2)));
      probFalse*= ((_other_disease_1+k)/(_deadCount + (k*2)));
    } else if (other_disease == "2") {
      probTrue*= ((other_disease_2+k)/(deadCount + (k*2)));
      probFalse*= ((_other_disease_2+k)/(_deadCount + (k*2)));
    } else {
      probTrue*= ((other_disease_1+k)/(deadCount + (k*2)));
      probFalse*= ((_other_disease_1+k)/(_deadCount + (k*2)));
    }
    if (cardiovascular == "1") {
      probTrue*= ((cardiovascular_1+k)/(deadCount + (k*2)));
      probFalse*= ((_cardiovascular_1+k)/(_deadCount + (k*2)));
    } else if (cardiovascular == "2") {
      probTrue*= ((cardiovascular_2+k)/(deadCount + (k*2)));
      probFalse*= ((_cardiovascular_2+k)/(_deadCount + (k*2)));
    }
    if (obesity == "1") {
      probTrue*= ((obesity_1+k)/(deadCount + (k*2)));
      probFalse*= ((_obesity_1+k)/(_deadCount + (k*2)));
    } else if (obesity == "2") {
      probTrue*= ((obesity_2+k)/(deadCount + (k*2)));
      probFalse*= ((_obesity_2+k)/(_deadCount + (k*2)));
    }
    if (renal_chronic == "1") {
      probTrue*= ((renal_chronic_1+k)/(deadCount + (k*2)));
      probFalse*= ((_renal_chronic_1+k)/(_deadCount + (k*2)));
    } else if (renal_chronic == "2") {
      probTrue*= ((renal_chronic_2+k)/(deadCount + (k*2)));
      probFalse*= ((_renal_chronic_2+k)/(_deadCount + (k*2)));
    } else {
      probTrue*= ((renal_chronic_1+k)/(deadCount + (k*2)));
      probFalse*= ((_renal_chronic_1+k)/(_deadCount + (k*2)));
    }
    if (tobacco == "1") {
      probTrue*= ((tobacco_1+k)/(deadCount + (k*2)));
      probFalse*= ((_tobacco_1+k)/(_deadCount + (k*2)));
    } else if (tobacco == "2") {
      probTrue*= ((tobacco_2+k)/(deadCount + (k*2)));
      probFalse*= ((_tobacco_2+k)/(_deadCount + (k*2)));
    }
    if (contact_other_covid == "1") {
      probTrue*= ((contact_other_covid_1+k)/(deadCount + (k*2)));
      probFalse*= ((_contact_other_covid_1+k)/(_deadCount + (k*2)));
    } else if (contact_other_covid == "2") {
      probTrue*= ((contact_other_covid_2+k)/(deadCount + (k*2)));
      probFalse*= ((_contact_other_covid_2+k)/(_deadCount + (k*2)));
    }
    if (covid_res == "1") {
      probTrue*= ((covid_res_1+k)/(deadCount + (k*2)));
      probFalse*= ((_covid_res_1+k)/(_deadCount + (k*2)));
    } else /*if (covid_res == "2")*/ {
      probTrue*= ((covid_res_2+k)/(deadCount + (k*2)));
      probFalse*= ((_covid_res_2+k)/(_deadCount + (k*2)));
    }
    if (icu == "1") {
      probTrue*= ((icu_1+k)/(deadCount + (k*2)));
      probFalse*= ((_icu_1+k)/(_deadCount + (k*2)));
    } else if (icu == "2") {
      probTrue*= ((icu_2+k)/(deadCount + (k*2)));
      probFalse*= ((_icu_2+k)/(_deadCount + (k*2)));
    } else {
      probTrue*= ((icu_1+k)/(deadCount + (k*2)));
      probFalse*= ((_icu_1+k)/(_deadCount + (k*2)));
    }
    if (stoi(age) >= 50 && stoi(age) < 100) {
      probTrue*= ((age_1+k)/(deadCount + (k*2)));
      probFalse*= ((_age_1+k)/(_deadCount + (k*2)));
    } else {
      probTrue*= ((age_2+k)/(deadCount + (k*2)));
      probFalse*= ((_age_2+k)/(_deadCount + (k*2)));
    }




    //cout << "Probability dead: " << (probTrue*dead) << endl;
    //cout << "Probability No dead: " << (probFalse*_dead) << endl;
    if ((probTrue*dead) > (probFalse*_dead)) {
      cout << "1" << endl;
      if (date_died != "9999-99-99") {
        accuracyRight++;
      } else {
        accuracyWrong++;
      }
    } else if ((probTrue*dead) < (probFalse*_dead)){
      cout << "0" << endl;
      if (date_died == "9999-99-99") {
        accuracyRight++;
      } else {
        accuracyWrong++;
      }
    }
  }
  //CALCULATE ACCURACY
  //cout << "Accuracy: " << (accuracyRight)/(accuracyRight+accuracyWrong) << endl;
  myFileStream2.close();
}
