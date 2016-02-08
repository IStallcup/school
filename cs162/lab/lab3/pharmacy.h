#ifndef PHARMACY_H
#define PHARMACY_H

#include "./patientaccount.h"

class Pharmacy//: public PatientAccount
{
	public:
		Pharmacy();
		Pharmacy(const Pharmacy &);
		~Pharmacy();
		int ibuprofen_get();
		int norco_get();
		int aspirin_get();
		int adderall_get();
		int tylenol_get();
		void charge_medicine(int);
	private:
		static const int ibuprofen = 10;
		static const int norco = 20;
		static const int aspirin = 30;
		static const int adderall = 200;
		static const int tylenol = 10;
};


#endif