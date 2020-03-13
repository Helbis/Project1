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


#endif
