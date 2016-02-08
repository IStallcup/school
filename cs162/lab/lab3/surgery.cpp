#include "./patientaccount.h"
#include "./surgery.h"
#include "./pharmacy.h"
#include <iostream>
#include <fstream>

int Surgery::heart_get()
{
	return heart;
}

int Surgery::appendix_get()
{
	return appendix;
}

int Surgery::brain_get()
{
	return brain;
}

int Surgery::kidney_get()
{
	return kidney;
}

int Surgery::tonsillectomy_get()
{
	return tonsillectomy;
}

Surgery::Surgery() {}

Surgery::~Surgery() {}

//void Surgery::charge_surgery(