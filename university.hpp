#ifndef UNIVERSITY_HPP
#define UNIVERSITY_HPP

class University{
	private:
		const int N;
		std::vector<Degree> degrees;	

	public:
		University(int temp);

		//Getters
		int getSize(void);
		std::vector<Degree> getDegrees(void);

};


University::University(int temp) : N(temp){
	degrees.reserve(N);
}


//Getters
int University::getSize(void){
	return N;
}

std::vector<Degree> University::getDegrees(void){
	return degrees;
}


int University::getTotalNumStudents(void){
	int total = 0, 
		sub_end = 0;	

	for(int i=0; i<getSize()-1; i++){	//Go through every degree
		for(int j=0; j<degrees[i].getSize(); j++){	//Go through every degree's student list
			
			//Compare against every other list	
			for(int k=i+1; k<getSize(); k++){	//Every *next* list of students
				for(int l=0; l<degrees[k].getSize(); l++){
					//Compare student from list i, j with k,l
					if(degrees[i][j] == degrees[k][l])	
				}
			}
		}	
	}
	
	return total - sub_end;
}


#endif
