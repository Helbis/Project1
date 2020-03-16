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
		std::vector<int> findStudent(Student stu);
	
		void remove(int j);
		void removeStudent(Student stu);

		bool empty(void);
		
		Student &operator [](int i);
		bool operator == (Degree other);

		void clear(void);
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


std::vector<int> Degree::findStudent(Student stu){
	std::vector<int> result;

	for(int i=0; i<getSize(); i++){
		if(students[i] == stu){
			//Found the student in given degree
			result.push_back(i);	
		}
	}
	
	if(result.size() == 0){
		result.push_back(NOT_FOUND);
	}
	
	return result;
}


void Degree::remove(int j){
	students.erase(students.begin() + j);
}


void Degree::removeStudent(Student stu){
	for(int i=0; i<getSize(); i++){
		if(stu == students[i]){
			remove(i);
		}
	}
}


bool Degree::empty(void){
	return students.empty();
}


Student &Degree::operator [](int i){
	return students[i];
}


bool Degree::operator == (Degree other){
	return (this->name.compare(other.name) == 0) ? true : false;
}


void Degree::clear(void){
	students.clear();
}

#endif
