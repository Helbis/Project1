#ifndef DEGREE_HPP
#define DEGREE_HPP 


enum MESSAGES : int{
	NOT_FOUND = -1
};


class Degree{
	private:
		std::string name;
//		const int N;
		std::vector<Student> students;

	public:
		Degree(std::string temp);
		
		//Getters
		std::string &getName(void);
		int getSize(void);
		std::vector<Student> &getStudents(void);
		
		//Setters
		void setName(std::string temp);

		void addStudent(std::string temp_name, std::string temp_DNI);
		void addStudent(Student stu);
		int findStudent(std::string temp_DNI);

		Student &operator [](int i);
		bool operator == (Degree other);
};


Degree::Degree(std::string temp){ 
	name = temp;
}

//Getters
std::string &Degree::getName(void){
	return name;
}


int Degree::getSize(void){
	return students.size();
}


std::vector<Student> &Degree::getStudents(void){
	return students;
}
		

//Setters
void Degree::setName(std::string temp){
	name = temp;
}


void Degree::addStudent(std::string temp_name, std::string temp_DNI){
	students.push_back(Student(temp_name, temp_DNI));
}


void Degree::addStudent(Student stu){
	students.push_back(stu);
}


int Degree::findStudent(std::string temp_DNI){
	for(int i=0; i<getSize(); i++){
		if(students[i].getDNI() == temp_DNI){
			//Found the student in given degree
			return i;
		}
	}
	
	return NOT_FOUND;
}


Student &Degree::operator [](int i){
	return students[i];
}


bool Degree::operator == (Degree other){
	return (this->name.compare(other.name) == 0) ? true : false;
}


#endif
