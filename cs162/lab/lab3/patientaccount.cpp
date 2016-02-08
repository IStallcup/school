#include "./patientaccount.h"
#include "./surgery.h"
#include "./pharmacy.h"
#include <iostream>
#include <fstream>

PatientAccount::PatientAccount(){}

PatientAccount::~PatientAccount(){}

int PatientAccount::days_get()
{
	int days_t;
	std::cin >> days_t;
	std::cout << days_t << std::endl;
	days = days_t;
	std::cout << "You have selected " << days << " days." << std::endl;
	return days;
}

int PatientAccount::rate_get()
{
	return rate;
}