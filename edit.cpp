void Movie::edit(map<string, vector<Movie> >& movies, string search, string newTitle, int setter, string newValue)
{
	for(auto& m : movies) {
		for(auto& s : m.second) {
			if(m.first == search || m.first == newTitle){
				if(setter == 1)
				{
					s.setDirector(newValue);
				}
				else if(setter == 2)
				{
					s.setLead(newValue);
				}
				else if(setter == 3)
				{
					s.setGenre(newValue);
				}
				else if(setter == 4)
				{
					int newYear;
					istringstream(newValue) >> newYear;
					if(newYear == 0) {
						outputMessage("Invalid input, year must be a number");
					} else {
						s.setReleaseYear(newYear);
					}
				}
				else if(setter == 5)
				{
					float newRating;
					int ratingCheck;
					
					istringstream(newValue) >> ratingCheck;
					if(!(isdigit(newValue[0])) || ratingCheck > 10) {
						outputMessage("Invalid input, raing must be a number in range 1-10");
					} else {
						newRating = stof(newValue);
						s.setRating(newRating);
					}
				}
				else if(setter == 6)
				{
					cout << m.first << " : ";
					s.print();
				}
			}
		}
	}
}

map<string, vector<Movie> > Movie::editMovie(map<string, vector<Movie> >& movies)
{
	bool menu = true;
	int menuSelect;
	string search;
	
	string newTitle;
	string newDirector;
	string newLead;
	string newGenre;
	string newYear;
	string newRating;
	
	vector<Movie> mapVector;
	
		cout << "\nEnter movie title to begin editing"<< endl;
		cout << "> ";
	
		getline(cin,search);
		string lowerCaseSearch = toLowerCase(search);
		cin.clear();
		
		if ( movies.find(lowerCaseSearch) == movies.end() ) {
			outputMessage("Movie is not in the library");
		} else {
		while(menu == true){
			cout << "+----------------------------+" << endl;
			cout << "|      ::Editing Menu::      |" << endl;
			cout << "|                            |" << endl;
			cout << "|-Edit title.............[1] |" << endl;
			cout << "|-Edit director..........[2] |" << endl;
			cout << "|-Edit lead actor........[3] |" << endl;
			cout << "|-Edit genre.............[4] |" << endl;
			cout << "|-Edit release year......[5] |" << endl;
			cout << "|-Edit rating............[6] |" << endl;
			cout << "|-Display changes........[7] |" << endl;
			cout << "|-Edit another movie.....[8] |" << endl;
			cout << "|-Return to main menu....[9] |" << endl;
			cout << "+----------------------------+" << endl;
			cout << "\n> ";
			cin >> menuSelect;
			cin.ignore(); 
		
			switch(menuSelect) {
				case 1 :
					cout << "Edit Title: ";
					getline(cin,newTitle);
					newTitle = toLowerCase(newTitle);
					for(auto& m : movies) {
						for(auto& s : m.second) {
							if(m.first == search){
								Movie newMovie(s.getDirector(),s.getLead(),s.getGenre(),s.getReleaseYear(),s.getRating());
								mapVector.push_back(newMovie);
								movies[newTitle] = mapVector;
							}
						}
					}
					movies.erase(search);
					break; 
				case 2 :
					cout << "Edit Director: ";
					getline(cin,newDirector);
					newDirector = toLowerCase(newDirector);
					edit(movies, search, newTitle, 1, newDirector);
					break;
				case 3 :
					cout << "Edit Lead Actor: ";
					getline(cin,newLead);
					newLead = toLowerCase(newLead);
					edit(movies, search, newTitle, 2, newLead);
					break;
				case 4 :
					cout << "Edit Genre: ";
					getline(cin,newGenre);
					newGenre = toLowerCase(newGenre);
					edit(movies, search, newTitle, 3, newGenre);
					break;
				case 5 :
					cout << "Edit Release Year: ";
					getline(cin,newYear);
					edit(movies, search, newTitle, 4, newYear);
					break;
				case 6 :
					cout << "Edit Rating: ";
					getline(cin,newRating);
					edit(movies, search, newTitle, 5, newRating);
					break;	
				case 7 :
					edit(movies, search, newTitle, 6, "");
					break;
				case 8 : 
					editMovie(movies);
					menu = false;
					break;
				case 9 :
					menu = false;
					break;
				default :
					if(!(isdigit(menuSelect))) 
					{
						outputMessage("Invalid input, menu selection must be a number in range 1-9");
						cin.clear();
						cin.ignore(999, '\n');
					}
			}
		
		}
				
	}	
	
	return movies;
	
}