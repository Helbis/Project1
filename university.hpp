#ifndef UNIVERSITY_HPP
#define UNIVERSITY_HPP


class University{
	private:
		//const int N;
		std::vector<Degree> degrees;	

	public:
		University(void);

		//Getters
		int getSize(void);
		std::vector<Degree> getDegrees(void);
		Degree getDegree(int i);	
	
		Student getStudent(int i, int j);
		int getTotalNumStudents(void);
		void removeEmptyDegrees(void);
		void modifyStudent(Student temp);
		void addDegree(std::string temp);
		void addStudent(Student stu, Degree deg);
};


University::University(void){ 

}


//Getters
int University::getSize(void){
	return degrees.size();
}

std::vector<Degree> University::getDegrees(void){
	return degrees;
}


Degree University::getDegree(int i){
	return degrees[i];
}	


Student University::getStudent(int i, int j){
	return (degrees[i])[j];
}


int University::getTotalNumStudents(void){
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
}



void University::removeEmptyDegrees(void){
	std::vector<Degree> temp;
	
	for(int i=0; i<getSize(); i++){
		if(degrees[i].getSize() != 0){
			temp.push_back(degrees[i]);
		}
	}
	
	if(!(temp.size() == degrees.size())){
		degrees.swap(temp);
		temp.clear();
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


void University::addStudent(Student stu, Degree deg){
	for(int i=0; i<getSize(); i++){
		if(deg == degrees[i]){
			degrees[i].addStudent(stu);
		}
	}
}


#endif
