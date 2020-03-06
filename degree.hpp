#ifndef DEGREE_HPP
#define DEGREE_HPP 

class Degree{
	private:
		std::string name;
		const int N;
		std::vector<Student> students;

	public:
		Degree(void);
		Degree(int temp_size);
		
		//Getters
		std::string getName(void);
		int getSize(void);
		std::vector<Student> getStudents(void);
		
		//Setters
		void setName(std::string temp);
};


Degree::Degree(void) : N(128){
	students.reserve(N);
}


Degree::Degree(int temp_size) : N(temp_size){
	students.reserve(N);
}

#endif
