#include "./patientaccount.h"
#include "./surgery.h"
#include "./pharmacy.h"
#include <iostream>
#include <fstream>
//#include <string>

using namespace std;
using std::fstream;
using std::ios;

int main()
{
	
	
	Surgery operation;
	Pharmacy drugs;
	PatientAccount account;
	int *total_charges = new int;
	int choice;
	int choice2;
	int days_q;
	int surgery_array[5] = {operation.heart_get(), operation.appendix_get(), operation.brain_get(), operation.kidney_get(), operation.tonsillectomy_get()};
	string words_surgery[5] = {"Heart|", "Appendix|", "Brain|", "Kidney|", "Tonsillectomy|"};
	int pharmacy_array[5] = {drugs.ibuprofen_get(), drugs.norco_get(), drugs.aspirin_get(), drugs.adderall_get(), drugs.tylenol_get()};
	string words_pharmacy[5] = {"Ibuprofen|", "Norco|", "Aspirin|", "Adderall|", "Tylenol|"};
	
	fstream charges;
	
	charges.open("charges.txt", ios::out);
	cout << "What is your name? ";
	char name[64];
	cin >> name;
	charges << name << "|";
	charges.close();
	
	while(1)
	{
		cout << "Select an operation 0-Surgery 1-Pharmacy 2-Add days 3-Check out: ";
		cin >> choice;
		switch(choice)
		{
			case 0:
				cout << "Select surgery 1-Heart 2-Appendix 3-Brain 4-Kidney 5-Tonsillectomy: ";
				cin >> choice2;
				cout << surgery_array[choice2-1] << endl;
				*total_charges = *total_charges + surgery_array[choice2-1];
				charges.open("charges.txt", ios::out | ios::app);
				charges << words_surgery[choice2-1] << surgery_array[choice2-1] << "|";
				charges.close();
				break;
			case 1:
				cout << "Select drug 1-Ibuprofen 2-Norco 3-Aspirin 4-Adderall 5-Tylenol: ";
				cin >> choice2;
				cout << pharmacy_array[choice2-1] << endl;
				*total_charges = *total_charges + pharmacy_array[choice2-1];
				charges.open("charges.txt", ios::out | ios::app);
				charges << words_pharmacy[choice2-1] << pharmacy_array[choice2-1] << "|";
				charges.close();
				break;
			case 2:
				cout << "How many days? ";
				days_q = account.days_get();
				*total_charges = *total_charges + account.rate_get() * days_q;
				charges.open("charges.txt", ios::out | ios::app);
				charges << days_q << "|";
				charges.close();
				break;
			case 3:
				cout << "Total charge = " << *total_charges << "!!" << endl;
				charges.open("charges.txt", ios::out | ios::app);
				charges << *total_charges << "|";
				charges.close();
				return 0;
				break;
		}
	}
	
	return 0;
}