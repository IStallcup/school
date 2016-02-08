#ifndef PATIENTACCOUNT_H
#define PATIENTACCOUNT_H

class PatientAccount
{
	public:
		PatientAccount();
		PatientAccount(const PatientAccount &);
		~PatientAccount();
		void set_days(int);
		void charge(int);
		int days_get();
		int rate_get();
		int charges_get();
		int total_get();
	private:
		int days;
		static const int rate = 1000;
		int charges;
};

#endif