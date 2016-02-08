
	/*This psuedofunction calculates the max and min signed and unsigned
	 * value for certain variable types, displays the macro values from
	 * climits then displays the caluclated values.*/

	cout << "Signed short Values:" << endl;	

	short sshrtmax = pow(2, (8*sizeof(signed short) - 1)) - 1;

	short sshrtmin =  -pow(2,(8*sizeof(signed short) - 1));

	cout << "Signed SHRT_MIN:\t" << SHRT_MIN;
	cout <<  "\t" << "Signed SHRT_MAX:\t" << SHRT_MAX << endl;

	cout << "Calculated SHRT_MIN:\t" << sshrtmin << "\t";
	cout  << "Calculated SHRT_MAX:\t" << sshrtmax << endl << endl;

	cout << "Unsigned short Values:" << endl;

	unsigned short ushrtmax = pow(2, 8*sizeof(unsigned short)) - 1;

	cout << "Unsigned USHRT_MIN:\t0\tUnsigned USHRT_MAX:\t" << USHRT_MAX << endl;

	cout << "Calculated USHRT_MIN:\t0\tCalculated USHRT_MAX:\t" << ushrtmax << endl << endl;


	cout << "Signed int Values:" << endl;

	int sintmax = pow(2, (8*sizeof(signed int) - 1)) - 1;

	int sintmin = -pow(2, (8*sizeof(signed int) - 1));

	cout << "Signed INT_MIN:\t\t" << INT_MIN <<  "\t";
	cout << "Signed INT_MAX:\t\t" << INT_MAX << endl;	

	cout << "Calculated INT_MIN:\t" << sintmin << "\t";
	cout  << "Calculated INT_MAX:\t" << sintmax << endl << endl;

	cout << "Unsigned int Values:" << endl;	

	unsigned int uintmax = pow(2, 8*sizeof(unsigned int)) - 1;

	cout << "Unsigned UINT_MIN:\t0\tUnsigned UINT_MAX:\t" << UINT_MAX << endl;

	cout << "Calculated UINT_MIN:\t0\tCalculated UINT_MAX:\t" << uintmax << endl << endl;


	cout << "Signed long Values:" << endl;

	long slngmax = pow(2, (8*sizeof(signed long) - 1)) - 1;

