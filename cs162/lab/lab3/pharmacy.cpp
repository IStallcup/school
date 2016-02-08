#include "./patientaccount.h"
#include "./surgery.h"
#include "./pharmacy.h"
#include <iostream>
#include <fstream>

Pharmacy::Pharmacy(){}

Pharmacy::~Pharmacy(){}

int Pharmacy::ibuprofen_get()
{
	return ibuprofen;
}

int Pharmacy::norco_get()
{
	return norco;
}

int Pharmacy::aspirin_get()
{
	return aspirin;
}

int Pharmacy::adderall_get()
{
	return adderall;
}

int Pharmacy::tylenol_get()
{
	return tylenol;
}