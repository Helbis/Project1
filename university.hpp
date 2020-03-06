#ifndef UNIVERSITY_HPP
#define UNIVERSITY_HPP

class University{
	private:
		const int N;
		std::vector<Degree> degrees;	

	public:
		University(void);
		University(int temp);

		//Getters
		int getSize(void);
		std::vector<Degree> getDegrees(void);

};


University::University(void) : N(128){
	degrees.reserve(N);
}

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



#endif
