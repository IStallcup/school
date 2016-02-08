#ifndef SURGERY_H
#define SURGERY_H

#include "./patientaccount.h"

class Surgery//: public PatientAccount
{
	public:
		Surgery();
		Surgery(const Surgery &);
		~Surgery();
		int heart_get();
		int appendix_get();
		int brain_get();
		int kidney_get();
		int tonsillectomy_get();
		void charge_surgery(int);
	private:
		static const int heart = 10000;
		static const int appendix = 5000;
		static const int brain = 10000;
		static const int kidney = 3000;
		static const int tonsillectomy = 8000;
};


#endif