#include "Employee_Store.h"

Employee_Store::Employee_Store(std::string path)
: employeeStore(read(path)) {}

/**
* Testing and backup data in case
* read file fails
* @author Cian McAteer
* @return backup
*/
std::vector<Employee*> Employee_Store::load() {

    Office* o1 = new Office("Cian McAteer", 22, 40,"cian@email.com", 1200);
    Office* o2 = new Office("John Smith", 27, 35, "john@email.com", 1600);
    Office* o3 = new Office("Matthew McCardle", 44, 38, "matthew@email", 1500);
    Office* o4 = new Office("Jamie Simmons", 30, 25, "jamie@email.com", 900);

    Factory* f1 = new Factory("Barry Smith", 19, 45, 420);
    Factory* f2 = new Factory("Michael Sweeney", 21, 30, 270);
    Factory* f3 = new Factory("Phil Bowlington", 18, 20, 210);
    Factory* f4 = new Factory("Carl Bingham", 25, 10, 400);

    std::vector<Employee*> backup;

    backup.push_back(o1);
    backup.push_back(f1);
    backup.push_back(o3);
    backup.push_back(f2);

    backup.push_back(o2);
    backup.push_back(f2);
    backup.push_back(o4);
    backup.push_back(f4);

    return backup;
}

inline std::vector<Employee*> Employee_Store::getEmployeeStore() const {
    return employeeStore;
}
/**
* @author Ciaran Maher
*/
void Employee_Store::print() {
    std::cout << "Current number of employees: " << employeeStore.size() << "." << std::endl;

    for(Employee* e : employeeStore) {
        e->print();
    }
}

/**
* Destructor must delete heap allocated object pointers
*/
Employee_Store::~Employee_Store() {
    for(Employee* e : employeeStore) {
        delete e;
    }
    employeeStore.clear();
}

/**
* @author Cian McAteer
*/
void Employee_Store::add(Employee* e) {
    employeeStore.push_back(e);
}

/**
* @author Cian McAteer
*/
bool Employee_Store::inRange(int& index) {
    return index < employeeStore.size();
}

/**
* @author Cian McAteer
*/
void Employee_Store::show_index() {
    for(unsigned int i = 0;i < employeeStore.size();++i) {
        std::cout << "Index: " << i << " Name: " << employeeStore[i]->getName() << "." << std::endl;
    }
}

/**
* @author Cian McAteer
*/
void Employee_Store::erase(int& index) {
    employeeStore.erase(employeeStore.begin() + index);
}

/**
* @author Cian McAteer
*/
void Employee_Store::clear() {
    employeeStore.clear();
}

/***
* @author Ciaran Maher
*/
void Employee_Store::updateEmployee(int& employee_type)
{
	int index;
	std::string search;

	if(employee_type == 1) {
		std::cout << "Factory Employees:" << std::endl;
		for(Employee* e : employeeStore)
		{
			if(dynamic_cast<Factory*>(e)) {
				e->print();

			}
		}
	}
	else{
		std::cout << "Office Employees:" << std::endl;
			for(Employee* e : employeeStore)
			{
				if(dynamic_cast<Office*>(e)) {
					e->print();

			}
		}

	}

	std::cout << "\nEnter employee name to begin editing"<< std::endl;
	std::cout << "> ";
	std::cin.ignore();
	std::getline(std::cin,search);

	bool menu = true;

	std::string newName;
	int newAge;
	int newHours;
	std::string newEmail;
	float newWage;
	float newSalary;

	while(menu){

		for(unsigned int i = 0;i < employeeStore.size();++i) {
			if(search == employeeStore[i]->getName())
			{
				index = i;
			}
		}

		std::cout << "\nEdit "<< employeeStore[index]->getName()<<"'s details" <<std::endl;
		if(employee_type == 1) {

			display_file("/Users/CianMcAteer/year_3/semester_1/C++/C++_CA2/menus/factory_edit.txt");
		}
		else{
			display_file("/Users/CianMcAteer/year_3/semester_1/C++/C++_CA2/menus/office_edit.txt");
		}

		int menuSelect;
		std::cin >> menuSelect;
		std::cin.ignore();

			switch(menuSelect) {
				case 1 :
					std::cout << "Edit name:";
					std::getline(std::cin,newName);
					employeeStore[index]->setName(newName);
					std::cout << employeeStore[index]->getName()<<" "<<employeeStore[index]->getAge() <<" "<<employeeStore[index]->getHours()<< std::endl;
                    addLog("Name of employee edited on");
					break;
				case 2 :
					std::cout << "Edit Age:";
					std::cin >> newAge;
					employeeStore[index]->setAge(newAge);
					std::cout <<employeeStore[index]->getName()<<" "<<employeeStore[index]->getAge() <<" "<<employeeStore[index]->getHours()<< std::endl;
                    addLog("Age of employee edited on");
					break;

				case 3 :
					std::cout << "Edit Hours:";
					std::cin >> newHours;
					employeeStore[index]->setHours(newHours);
					std::cout <<employeeStore[index]->getName()<<" "<<employeeStore[index]->getAge() <<" "<<employeeStore[index]->getHours()<< std::endl;
                    addLog("Hours of employee edited on");
					break;
				case 4 : {
					std::cout << "Edit Email:";
					std::getline(std::cin,newEmail);
					Office* off1 = dynamic_cast<Office*>(employeeStore[index]);
					off1->setEmail(newEmail);
					std::cout <<employeeStore[index]->getName()<<" "<<employeeStore[index]->getAge() <<" "<<employeeStore[index]->getHours()<<" "<< off1->getEmail()<<" "<< off1->getSalary()<< std::endl;
                    addLog("Email of office staff edited on");
					break;
				}
				case 5 : {
					std::cout << "Edit Salary:";
					std::cin >> newSalary;
					Office* off2 = dynamic_cast<Office*>(employeeStore[index]);
					off2->setSalary(newSalary);
					std::cout <<employeeStore[index]->getName()<<" "<<employeeStore[index]->getAge() <<" "<<employeeStore[index]->getHours()<< " "<<off2->getEmail()<<" "<< off2->getSalary() << std::endl;
                    addLog("Salary of office staff edited on");
					break;
				}
				case 6 : {
					std::cout << "Edit Wages:";
					std::cin >> newWage;
					Factory* f1 = dynamic_cast<Factory*>(employeeStore[index]);
					f1->setWage(newWage);
					std::cout <<employeeStore[index]->getName()<<" "<<employeeStore[index]->getAge() <<" "<<employeeStore[index]->getHours()<<" "<< f1->getWage() << std::endl;
                    addLog("Wages edited on");
					break;
				}
				case 0 :
					menu = false;
					break;
			}


	  }

}

/**
* Writes employee objects to save file
* using a virtual save method
* for each subclass
* @author Cian McAteer
* @param fileName
*/
void Employee_Store::save(std::string fileName) {

    std::ofstream employeefileWrite;
	employeefileWrite.open(fileName.c_str());

    if(employeefileWrite.is_open()) {
        for(Employee* e : employeeStore) {
            employeefileWrite << e->save();
        }
    } else {
        std::cerr << "Could not save data" << std::endl;
    }

}

/**
* @author Cian McAteer
*/
void Employee_Store::history() {
    // Append students instead of overwritting students
    std::ofstream employeeRecords("records.txt",std::fstream::in | std::ios::out | std::ios::app);

    if(employeeRecords.is_open()) {
        for(Employee* e : employeeStore) {
            employeeRecords << e-> save();
        }
    } else {
        std::cerr << "Records could not be accessed" << std::endl;
    }
}

/**
* @author Cian McAteer
*/
std::set<Employee*> Employee_Store::getRecords() {
    std::set<Employee*> records;
    std::ifstream history("records.txt");

    if(history.is_open()) {

        std::string line;
        std::set<std::string> lines;

        while(getline(history, line)) {
            lines.insert(line);
        }

        std::string type;
        std::string name;
        int age;
        int hours;
        float wages;

        std::string email;
        float salary;
        for(const std::string& line : lines) {
            std::stringstream ss(line);
            while(ss >> type) {
                if(type == "Factory") {
                    while(ss >> name >> age >> hours >> wages) {
                        std::replace(name.begin(), name.end(), '-', ' ');
                        Employee* e = new Factory(name, age, hours, wages);
                        records.insert(e);
                    }
                } else {
                    while(ss >> name >> age >> hours >> email >> salary) {
                        std::replace(name.begin(), name.end(), '-', ' ');
                        Employee* e = new Office(name, age, hours, email, salary);
                        records.insert(e);
                    }
                }
            }

        }
    } else {
        std::cerr << "Could not retrieve records from database" << std::endl;
    }
    return records;
}

/**
* @author Cian McAteer
*/
void Employee_Store::show_history() {
    std::set<Employee*> records = getRecords();

    for(Employee* e : records) {
        e->print();
    }
}

/**
* @author Ciaran Maher
*/
void Employee_Store::printEmployees(bool type) {

    if(type) {
        for(Employee* e : employeeStore) {
            if(dynamic_cast<Office*>(e)) {
                e->print();
            }
        }
    } else {
        for(Employee* e : employeeStore) {
            if(dynamic_cast<Factory*>(e)) {
                e->print();
            }
        }
    }

}

/**
* @author Cian McAteer
*/
std::vector<Employee*> Employee_Store::read(std::string path) {
    std::ifstream data(path);

    std::vector<Employee*> employees;
    if(data.is_open()) {
        std::string line;
        std::vector<std::string> lines;

        while(getline(data, line)) {
            lines.push_back(line);
        }

        std::string type;
        std::string name;
        int age;
        int hours;
        float wages;

        std::string email;
        float salary;
        for(unsigned int i = 0;i < lines.size();++i) {
            std::stringstream ss(lines[i]);
            while(ss >> type) {

                if(type == "Factory") {
                    while(ss >> name >> age >> hours >> wages) {
                        std::replace(name.begin(), name.end(), '-', ' ');
                        Employee* e = new Factory(name, age, hours, wages);
                        employees.push_back(e);
                    }
                } else {
                    while(ss >> name >> age >> hours >> email >> salary) {
                        std::replace(name.begin(), name.end(), '-', ' ');
                        Employee* e = new Office(name, age, hours, email, salary);
                        employees.push_back(e);
                    }
                }
            }
        }
    } else {
        std::cerr << "Unable to open save file" << std::endl;
    }

    return employees;
}

/**
* @author Cian McAteer
*/
std::stack<std::string> Employee_Store::readLog() {
    std::stack<std::string> logs;
    std::ifstream readLogs("logs.txt");

    if(readLogs.is_open()) {
        std::string line;
        while(getline(readLogs, line)) {
            logs.push(line);
        }
    } else {
        std::cerr << "Error opening log file" << std::endl;
    }
    return logs;
}

/**
* @author Ciaran Maher
*/
void Employee_Store::sortEmployees() {
	std::string search;
	std::cout << "\nEnter any of the following to sort:\n name, age, hours, email, salary, wages \n> " ;
	std::cin.ignore();
	std::getline(std::cin,search);
	std::cout << std::endl;

	if(search == "name"){
		sort(employeeStore.begin(), employeeStore.end(), [](const Employee* e1, const Employee* e2){
				return e1->getName() < e2->getName();
		});
	}
	if(search == "age"){
		sort(employeeStore.begin(), employeeStore.end(), [](const Employee* e1, const Employee* e2){
			return e1->getAge() < e2->getAge();
		});
	}
	if(search == "hours"){
		sort(employeeStore.begin(), employeeStore.end(), [](const Employee* e1, const Employee* e2){
			return e1->getHours() < e2->getHours();
		});
	}
	if(search == "email"){

		sort(employeeStore.begin(), employeeStore.end(), [](const Employee* e1, const Employee* e2){
			const Office* o1 = dynamic_cast<const Office*>(e1);
			const Office* o2 = dynamic_cast<const Office*>(e2);
			if(o1 != nullptr) {
				return o1->getEmail() < o2->getEmail();
			}
		});
	}
	if(search == "salary"){

		sort(employeeStore.begin(), employeeStore.end(), [](const Employee* e1, const Employee* e2) {
			const Office* o1 = dynamic_cast<const Office*>(e1);
			const Office* o2 = dynamic_cast<const Office*>(e2);
			if(o1 != nullptr) {
				return o1->getSalary() < o2->getSalary();
			}
		});
	}
    if(search == "wages") {
        sort(employeeStore.begin(), employeeStore.end(), [](const Employee* e1, const Employee* e2) {
			const Factory* f1 = dynamic_cast<const Factory*>(e1);
			const Factory* f2 = dynamic_cast<const Factory*>(e2);
			if(f1 != nullptr) {
				return f1->getWage() < f2->getWage();
			}
		});
    }

	print();

}

/**
* @author Ciaran Maher
*/
void Employee_Store::createWebpage() {
    std::ofstream html_page("worker_catalogue.html");
    // HTML header tags
    html_page << "<!DOCTYPE html><html><head>"; // Header tags
    html_page << "<link href=\"worker_page.css\" rel=\"stylesheet\">"; // Style sheet link
    html_page << "</head><body>";
    html_page << "<h1></h1>";
    html_page << "<img>";
    html_page << "<table border='1'>";
    html_page << "<h2>Office Workers</h2>";
    html_page << "<tr><td class='title'>Name</td><td class='title'>Age</td><td class='title'>Hours</td><td class='title'>Email</td><td class='title'>Salary</td></tr>";
    for(Employee* e : employeeStore) {
		if(dynamic_cast<Office*>(e)){
			Office* o = dynamic_cast<Office*>(e);
            html_page << "<tr>";
			html_page << "<td>" << e->getName() << "</td>"; // Converts to HTML string
			html_page << "<td>" << e->getAge() << "</td>"; // Converts to HTML string
			html_page << "<td>" << e->getHours() << "</td>"; // Converts to HTML string
			html_page << "<td>" << o->getEmail() << "</td>"; // Converts to HTML string
			html_page << "<td>" << o->getSalary() << "</td>"; // Converts to HTML string
		}
        html_page << "</tr>";
    }

    html_page << "</table>";
	html_page << "<table border='1'>";
    html_page << "<h2>Factory Workers</h2>";
    html_page << "<tr><td class='title'>Name</td><td class='title'>Age</td><td class='title'>Hours</td><td class='title'>Wages</td></tr>";
    for(Employee* e : employeeStore) {
		if(dynamic_cast<Factory*>(e)) {
			Factory* f = dynamic_cast<Factory*>(e);
			html_page << "<tr>";
			html_page << "<td>" << e->getName() << "</td>"; // Converts to HTML string
			html_page << "<td>" << e->getAge() << "</td>"; // Converts to HTML string
			html_page << "<td>" << e->getHours() << "</td>"; // Converts to HTML string
			html_page << "<td>" << f->getWage() << "</td>"; // Converts to HTML string
		}
        html_page << "</tr>";
    }
    html_page << "</table>";

    // Close off page and end connection
    html_page << "</body></html>";
    html_page.close();

}

/**
* @author Cian McAteer
*/
void Employee_Store::displayLogs() {

    std::stack<std::string> logs = readLog();
    std::cout << "Log size " << logs.size() << std::endl;

    while(!logs.empty()) {
        // Print last element added to stack
        std::cout << logs.top() << std::endl;
        logs.pop(); // Pop element off to print next element
    }
}

float Employee_Store::averagePayment() {
    std::vector<float> payments;

    for(Employee* e : employeeStore) {
        if(dynamic_cast<Factory*>(e)) {
            Factory* f = dynamic_cast<Factory*>(e);
            payments.push_back(f->getWage());
        } else {
            Office* o = dynamic_cast<Office*>(e);
            payments.push_back(o->getSalary());
        }
    }
    return average(payments);
}

float Employee_Store::averageHours() {
    std::vector<int> hours;

    for(Employee* e : employeeStore) {
        hours.push_back(e->getHours());
    }

    return average(hours);
}

std::ostream& operator<<(std::ostream& output_stream, const Employee_Store& et) {

    std::map<std::string,std::vector<Employee*> > map;

    std::vector<Employee*> office_staff;
    std::vector<Employee*> factory_workers;

    for(Employee* e : et.employeeStore) {
        if(dynamic_cast<Office*>(e)) {
            office_staff.push_back(e);
        } else {
            factory_workers.push_back(e);
        }
    }

    map.insert(std::pair<std::string, std::vector<Employee*> >("Office", office_staff));
    map.insert(std::pair<std::string, std::vector<Employee*> >("Factory", factory_workers));


    for(const auto& s : map) {
        output_stream << " Number of " << s.first << " employees: " << s.second.size() << std::endl;

        for(Employee* e : s.second) {
            output_stream << '\t' << e->toString() << std::endl;
        }
    }

    return output_stream;
}
