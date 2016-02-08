void movie::setvalues(string iname, int istars, int inum_cast, string* icast, string irating, int icopies, int irented)
{
	name = iname;
	stars = istars;
	num_cast = inum_cast;
	cast = new string[num_cast];
	for (int i = 0; i < num_cast; i++)
	{
		cast[i] = icast[i];
	}
	rating = irating;
	copies = icopies;
	rented = irented;
}

void movie_input()
{	
	string iname;
	int istars;
	int inum_cast;
	string *icast;
	string irating;
	int icopies;
	int irented;
	
	//read_movie_input(iname, istars, inum_cast, icast, irating, icopies, irented);
	
	cout << "What is the movie's name?" << endl;
	cin.ignore();
	getline(cin, iname);
	
	cout << "How many stars does the movie get?" << endl;
	cin >> istars;
	
	cout << "How many actors star?" << endl;
	cin >> inum_cast;
	
	icast = new string[inum_cast];
	for (int i = 0; i < inum_cast; i++)
	{
		cout << "Who stars?" << endl;
		cin.ignore();
		std::getline(cin, icast[i]);
	}
	
	cout << "What is its rating?" << endl;
	cin >> irating;
	
	cout << "How many copies available?" << endl;
	cin >> icopies;
	
	cout << "How many are rented out?" << endl;
	cin >> irented;
	
	cout << "Creating movie..." << endl;
	
	movie input;
	
	input.setvalues(iname, istars, inum_cast, icast, irating, icopies, irented);
	
	fstream netflix;
	
	netflix.open("netflix.dat", ios::out | ios::app);
	
	netflix << endl << input.get_name() << "|";
	netflix << input.get_stars() << "|" << input.get_rating() << "|";
	netflix << input.get_copies() << "|" << input.get_rented() << "|";
	
	netflix.close();
}