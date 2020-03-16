#ifndef UNIVERSITY_HPP
#define UNIVERSITY_HPP


#define FNAME "./uniDB.txt"


class University{
	private:
		//const int N;
		std::vector<Degree> degrees;	

	public:
		University(void){}

		//Getters
		int getSize(void);
		std::vector<Degree> &getDegrees(void);
		Degree &getDegree(int i);	
	
		Student &getStudent(int i, int j);
		std::vector<std::vector<int>> findStudentAll(Student stu);
		int getTotalNumStudents(void);
		void removeEmptyDegrees(void);
		void modifyStudent(Student temp);
		void addDegree(std::string temp);
		void addDegree(Degree temp);
		void addStudent(Student stu, Degree deg);
		void removeStudent(Student stu, std::string deg);

		void removeAll(void);
		void load(void);
		void save(void);
};


//Getters
int University::getSize(void){
	return degrees.size();
}

std::vector<Degree> &University::getDegrees(void){
	return degrees;
}


Degree &University::getDegree(int i){
	return degrees[i];
}	


Student &University::getStudent(int i, int j){
	return (degrees[i][j]);
}

std::vector<std::vector<int>> University::findStudentAll(Student stu){
	std::vector<std::vector<int>> result;

	//Go through all of the degrees
	for(int i=0; i<getSize(); i++){
		result.push_back(degrees[i].findStudent(stu));
	}

	return result;
}


int University::getTotalNumStudents(void){
	/*
	int total = 0, 
		sub_end = 0;	

	for(int i=0; i<getSize()-1; i++){	//Go through every degree
		for(int j=0; j<degrees[i].getSize(); j++, total++){	//Go through every degree's student list
			
			//Compare against every other list	
			for(int k=i+1; k<getSize(); k++){	//Every *next* list of students
				for(int l=0; l<degrees[k].getSize(); l++){
					//Compare student from list i, j with k,l
					if(degrees[i][j] == degrees[k][l]){
						//Duplicate student
						sub_end++;
						
					}	
				}
			}
		}	
	}
	
	return total - sub_end;
	*/

	int total = 0;
	
	for(int i=0; i<getSize(); i++){
		total += degrees[i].getSize();
	}
	
	return total;
}



void University::removeEmptyDegrees(void){
	for(int i=0; i<getSize(); i++){
		if(degrees[i].empty()){
			degrees.erase(degrees.begin() + i);
		}
	}
}


void University::modifyStudent(Student temp){
	for(int i=0; i<getSize(); i++){
		for(int j=0; j<degrees[i].getSize(); j++){
			//Look everywhere and change each occurence of this student
			if(temp == getStudent(i, j)){
				getStudent(i, j).setName(temp.getName());
			}
		}
	}
}


void University::addDegree(std::string temp){
	Degree deg(temp);
	degrees.push_back(deg);
}


void University::addDegree(Degree temp){
	degrees.push_back(temp);
}


void University::addStudent(Student stu, Degree deg){
	for(int i=0; i<getSize(); i++){
		if(deg == degrees[i]){
			degrees[i].addStudent(stu);
			return;
		}
	}

	addDegree(deg);
	degrees[getSize()-1].addStudent(stu);
}
	

void University::removeStudent(Student stu, std::string temp){
	Degree deg(temp);

	for(int i=0; i<getSize(); i++){
		if(deg == degrees[i]){
			degrees[i].removeStudent(stu);
		}
	}	
}


void University::removeAll(void){
	for(int i=getSize()-1; i>=0; i--){
		degrees[i].clear();
	}

	//while(degrees.size() != 0){
	//	degrees.back().clear();
	//}

	degrees.clear();
}


void University::load(void){
	std::ifstream fs;
	fs.open(FNAME);
	std::string line;

	removeAll();
	/*
		DDegree(name)\n
		SStudent(name, dni)\n
		.
		.
		.
		Other Degree...	
	*/
	
	if(fs.is_open() and !fs.eof()){
    	while(getline(fs, line)){

			std::cout << "line[last] :\t" << line.back() << '\n';
			switch(line[0]){
				case 'D':{
					//New degree
					//line.pop_back();
					line.erase(0, 1);
					degrees.push_back(Degree(line));
					break;
				}
				case 'S':{
					//Student in given degree
					//line.pop_back();
					line.erase(0, 1);
					std::istringstream ss(line);
					do{
						//Read word by word
						std::string temp_name, temp_DNI;
						ss >> temp_name;
						ss >> temp_DNI;
	
						degrees.back().addStudent(temp_name, temp_DNI);	
					}while(ss);	
					
					break;
				}
				default:{
					std::cout << "File is corrupted";
					std::cout << "At line\n\t" << line;
					break;
				}
			}
		}
  	}else{
		std::cout << "Unable to open file";
	}
	
	fs.close();
}


void University::save(void){
	std::ofstream fs(FNAME);
		
	if (fs.is_open()){
		//Writing to the file
			for(int i=0; i<getSize(); i++){	
				//Write Degree
				fs << "D" + degrees[i].getName() + "\n";	

				for(int j=0; j<degrees[i].getSize(); j++){
					//Write students from degree
					fs << "S" + degrees[i][j].getName() + " " + degrees[i][j].getDNI() + "\n";	
				}
			}
	}else{
		std::cout << "Unable to open file";
	}

	fs.close();
}


#endif
