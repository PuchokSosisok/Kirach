// Заголовочные файлы 
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <windows.h>
#include <iomanip>
#include <limits>

using namespace std;

// Класс Студент
class Student
{
public:
	bool hasSubject(const string& subject) const // Функция для проверки, есть ли у студента предмет с заданным названием
	{
		for (const auto& subj : subjectGrades)
		{
			if (subj.first == subject)
			{
				return true;
			}
		}
		return false;
	}
	string name;
	string lastName;
	string middleName;
	string birthDate;
	int enrollmentYear;
	string faculty;
	string department;
	string group;
	string recordBookNumber;
	string gender;
	vector<pair<string, int>> subjectGrades;

public: Student()
{
	name = "";
	lastName = "";
	middleName = "";
	birthDate = "";
	enrollmentYear = 0;
	faculty = "";
	department = "";
	group = "";
	recordBookNumber = "";
	gender = "";
}

	  Student(string rbNumber)
	  {
		  recordBookNumber = rbNumber;
	  }

	  Student(string name, string lastName, string middleName, string birthDate, int enrollmentYear, string faculty, string department, string group, string recordBookNumber, string gender, vector<pair<string, int>> subjectGrades) : name(name), lastName(lastName), middleName(middleName), birthDate(birthDate), enrollmentYear(enrollmentYear), faculty(faculty), department(department), group(group), recordBookNumber(recordBookNumber), gender(gender), subjectGrades(subjectGrades) {}

	  string getName() const
	  {
		  return name;
	  }

	  void setName(string name)
	  {
		  this->name = name;
	  }

	  string getLastName() const
	  {
		  return lastName;
	  }

	  void setLastName(string lastName)
	  {
		  this->lastName = lastName;
	  }

	  string getMiddleName() const
	  {
		  return middleName;
	  }

	  void setMiddleName(string middleName)
	  {
		  this->middleName = middleName;
	  }

	  string getBirthDate() const
	  {
		  return birthDate;
	  }

	  void setBirthDate(string birthDate)
	  {
		  this->birthDate = birthDate;
	  }

	  int getEnrollmentYear() const
	  {
		  return enrollmentYear;
	  }

	  void setEnrollmentYear(int enrollmentYear)
	  {
		  this->enrollmentYear = enrollmentYear;
	  }

	  string getFaculty() const
	  {
		  return faculty;
	  }

	  void setFaculty(string faculty)
	  {
		  this->faculty = faculty;
	  }

	  string getDepartment() const
	  {
		  return department;
	  }

	  void setDepartment(string department)
	  {
		  this->department = department;
	  }

	  string getGroup() const
	  {
		  return group;
	  }

	  void setGroup(string group)
	  {
		  this->group = group;
	  }

	  string getRecordBookNumber() const
	  {
		  return recordBookNumber;
	  }

	  void setRecordBookNumber(string recordBookNumber)
	  {
		  this->recordBookNumber = recordBookNumber;
	  }

	  string getGender() const
	  {
		  return gender;
	  }

	  void setGender(string gender)
	  {
		  this->gender = gender;
	  }

	  vector<pair<string, int>> getSubjectGrades() const
	  {
		  return subjectGrades;
	  }

	  void setSubjectGrades(vector<pair<string, int>> subjectGrades)
	  {
		  this->subjectGrades = subjectGrades;
	  }

	  void addSubjectGrade(string subject, int grade)
	  {
		  subjectGrades.push_back(make_pair(subject, grade));
	  }

	  double getAverageGrade() const
	  {
		  double sum = 0;
		  for (auto subjectGrade : subjectGrades)
		  {
			  sum += subjectGrade.second;
		  }

		  return sum / subjectGrades.size();
	  }
};

// Функция для добавления нового студента в список
void addStudent(vector<Student>& students)
{
	// Ввод данных о студенте
	string name, lastName, middleName, birthDate, faculty, department, group, recordBookNumber, gender;
	int enrollmentYear, countSubjectGrades, numSubjects;
	cout << "Введите имя студента: ";
	cin >> name;
	cout << "Введите фамилию студента: ";
	cin >> lastName;
	cout << "Введите отчество студента: ";
	cin >> middleName;
	cout << "Введите дату рождения студента (дд.мм.гггг): ";
	cin >> birthDate;
	cin.ignore();
	cout << "Введите год поступления студента: ";
	cin >> enrollmentYear;
	cin.ignore();
	cout << "Введите факультет, на котором учится студент: ";
	cin >> faculty;
	cin.ignore();
	cout << "Введите кафедру, на которой учится студент: ";
	cin >> department;
	cout << "Введите группу, в которой учится студент: ";
	cin >> group;
	cin.ignore();
	cout << "Введите номер зачетной книжки студента: ";
	cin >> recordBookNumber;
	cin.ignore();
	cout << "Введите количество предметов у студента: ";
	cin >> numSubjects;
	cin.ignore();

	vector<string> subjectNames;	// Вектор для хранения названий предметов

	for (int i = 0; i < numSubjects; i++)
	{
		string subjectName;
		cout << "Введите название предмета: ";
		getline(cin, subjectName);
		subjectNames.push_back(subjectName);
	}

	// Создайте вектор для хранения оценок студента
	vector<int> marks;

	// Заполняем вектор оценок
	for (int i = 0; i < numSubjects; i++)
	{
		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);
		int mark;
		cout << "Введите оценку по предмету " << subjectNames[i] << ": ";
		cin >> mark;

		if (mark < 0 || mark > 10)
		{
			cout << "Ошибка! Оценка должна быть в диапазоне от 0 до 10." << endl;
			return;
		}
		else
		{
			marks.push_back(mark);
		}
	}

	// Вводим пол студента
	cout << "Введите пол студента (м/ж): ";
	cin >> gender;

	// Создаем новый объект класса Student и добавляем его в вектор
	vector<pair<string, int>> subjectGrades;
	for (int i = 0; i < numSubjects; i++)
	{
		subjectGrades.push_back(make_pair(subjectNames[i], marks[i]));
	}

	Student student(name, lastName, middleName, birthDate, enrollmentYear, faculty, department, group, recordBookNumber, gender, subjectGrades);
	students.push_back(student);
	cout << "Студент успешно добавлен в список!" << endl;
}

void displayStudents(vector<Student>& students) {
	if (students.size() == 0) {
		cout << "Ошибка! Нет данных о студентах." << endl;
		return;
	}

	// Вывод заголовка таблицы
	cout << left << "|" << setw(4) << "№" << "|" << setw(27) << "ФИО" << "|" << setw(18) << "Дата рождения" << "|" << setw(19) << "Год поступления" << "|" << setw(14)
		<< "Факультет" << "|" << setw(22) << "Кафедра" << "|" << setw(11) << "Группа" << "|" << setw(18) << "Зачет. книжка" << "|" << setw(29) << "Предметы и оценки" << "|" << endl;
	cout << setfill('-') << setw(155) << "-" << endl;
	cout << setfill(' ');

	// Вывод данных по каждому студенту в таблице
	int num = 1;
	for (auto student : students) {
		// Вывод номера студента
		cout << left << "|" << setw(4) << num++;

		// Вывод ФИО студента
		cout << "|" << setw(26) << student.getLastName() + " " + student.getName() + " " + student.getMiddleName() << "|";

		// Вывод даты рождения
		cout << setw(17) << student.getBirthDate() << "|";

		// Вывод года поступления
		cout << setw(18) << student.getEnrollmentYear() << "|";

		// Вывод факультета
		cout << setw(13) << student.getFaculty() << "|";

		// Вывод кафедры
		cout << setw(21) << student.getDepartment() << "|";

		// Вывод группы
		cout << setw(10) << student.getGroup() << "|";

		// Вывод номера зачетной книжки
		cout << setw(17) << student.getRecordBookNumber() << "|";

		// Вывод предметов и оценок студента
		cout << setw(30) << "";
		for (auto subjectGrade : student.getSubjectGrades()) {
			cout << right << setw(12) << subjectGrade.first << ": " << setw(5) << subjectGrade.second << " | ";
		}
		cout << endl;
	}

	cout << setfill('-') << setw(155) << "-" << endl;
	cout << setfill(' ');
}


void editStudent(vector<Student>& students)
{
	// Запрашиваем номер зачетной книжки для редактирования
	string recordBookNumber;
	cout << "Введите номер зачетной книжки студента для редактирования: ";
	cin >> recordBookNumber;

	// Ищем студента с заданным номером зачетной книжки
	auto student = find_if(students.begin(), students.end(), [=](const Student& s)
		{
			return s.getRecordBookNumber() == recordBookNumber;
		});

	if (student != students.end())
	{
		// Выводим текущие данные о студенте
		cout << "Текущие данные:" << endl;
		cout << "Имя: " << student->getName() << endl;
		cout << "Фамилия: " << student->getLastName() << endl;
		cout << "Отчество: " << student->getMiddleName() << endl;
		cout << "Дата рождения: " << student->getBirthDate() << endl;
		cout << "Факультет: " << student->getFaculty() << endl;
		cout << "Кафедра: " << student->getDepartment() << endl;
		cout << "Группа: " << student->getGroup() << endl;
		cout << "Пол: " << student->getGender() << endl;
		cout << "Предметы и оценки: " << endl;
		for (auto subjectGrade : student->getSubjectGrades())
		{
			cout << "\t" << subjectGrade.first << ": " << subjectGrade.second << endl;
		}

		cout << "Средний балл: " << student->getAverageGrade() << endl;

		// Предлагаем изменить данные
		cout << "Введите новые данные (или нажмите Enter, чтобы пропустить):" << endl;
		string name, lastName, middleName, faculty, department, group, birthDate, gender;
		vector<pair<string, int>> subjectGrades;

		cout << "Имя: ";
		getline(cin, name);
		if (name != "")
		{
			student->setName(name);
		}

		cout << "Фамилия: ";
		getline(cin, lastName);
		if (lastName != "")
		{
			student->setLastName(lastName);
		}

		cout << "Отчество: ";
		getline(cin, middleName);
		if (middleName != "")
		{
			student->setMiddleName(middleName);
		}

		cout << "Дата рождения: ";
		getline(cin, birthDate);
		if (birthDate != "")
		{
			student->setBirthDate(birthDate);
		}

		cout << "Факультет: ";
		getline(cin, faculty);
		if (faculty != "")
		{
			student->setFaculty(faculty);
		}

		cout << "Кафедра: ";
		getline(cin, department);
		if (department != "")
		{
			student->setDepartment(department);
		}

		cout << "Группа: ";
		getline(cin, group);
		if (group != "")
		{
			student->setGroup(group);
		}

		cout << "Пол: ";
		getline(cin, gender);
		if (gender != "")
		{
			student->setGender(gender);
		}

		// Запрашиваем количество предметов в списке
		int numSubjects;
		cout << "Введите количество предметов у студента: ";
		cin >> numSubjects;
		cin.ignore();

		// Запрашиваем предметы и оценки
		for (int i = 0; i < numSubjects; i++)
		{
			string sub, markStr;
			int mark;
			cout << "Введите название предмета " << i + 1 << ": ";
			getline(cin, sub);
			cout << "Введите оценку по предмету " << sub << ": ";
			getline(cin, markStr);
			mark = stoi(markStr);
			subjectGrades.push_back(make_pair(sub, mark));
		}

		// Устанавливаем новый список предметов и оценок
		if (!subjectGrades.empty())
		{
			student->setSubjectGrades(subjectGrades);
		}

		cout << "Данные студента успешно обновлены!" << endl;
	}
	else
	{
		cout << "Студент с таким номером зачетной книжки не найден" << endl;
	}
}

void printAllStudents(vector<Student>& students)
{
	// Определяем ширину каждого поля
	const int nameWidth = 15;
	const int birthDateWidth = 12;
	const int enrollmentYearWidth = 6;
	const int facultyWidth = 20;
	const int departmentWidth = 20;
	const int groupWidth = 6;
	const int recordBookNumberWidth = 15;
	const int genderWidth = 6;

	// Вывод списка студентов
	cout << left << setw(nameWidth) << "Имя"
		<< setw(birthDateWidth) << "Дата рождения"
		<< setw(enrollmentYearWidth) << "Год"
		<< setw(facultyWidth) << "Факультет"
		<< setw(departmentWidth) << "Кафедра"
		<< setw(groupWidth) << "Группа"
		<< setw(recordBookNumberWidth) << "№ зачетной"
		<< setw(genderWidth) << "Пол"
		<< "Предметы и оценки" << endl;

	for (auto student : students)
	{
		cout << left << setw(nameWidth) << student.getName()
			<< setw(birthDateWidth) << student.getBirthDate()
			<< setw(enrollmentYearWidth) << student.getEnrollmentYear()
			<< setw(facultyWidth) << student.getFaculty()
			<< setw(departmentWidth) << student.getDepartment()
			<< setw(groupWidth) << student.getGroup()
			<< setw(recordBookNumberWidth) << student.getRecordBookNumber()
			<< setw(genderWidth) << student.getGender();

		for (auto subjectGrade : student.getSubjectGrades())
		{
			cout << "\n"
				<< setw(nameWidth + birthDateWidth + enrollmentYearWidth + facultyWidth + departmentWidth + groupWidth + recordBookNumberWidth + genderWidth + 1) << ""
				<< setw(20) << subjectGrade.first
				<< subjectGrade.second;
		}

		cout << "\n"
			<< setw(nameWidth + birthDateWidth + enrollmentYearWidth + facultyWidth + departmentWidth + groupWidth + recordBookNumberWidth + genderWidth + 1 + 20) << ""
			<< "Средний балл: " << student.getAverageGrade()
			<< "\n"
			<< "----------------------------------------"
			<< endl;
	}
}
// Функция для поиска студентов по заданным критериям
void searchStudents(vector<Student>& students)
{
	// Ввод критериев поиска
	int searchBy;
	cout << "Введите параметр, по которому будут осуществляться поиск и фильтрация студентов:" << endl;
	cout << "1. Факультет" << endl;
	cout << "2. Год поступления" << endl;
	cout << "3. Дату рождения" << endl;
	cin >> searchBy;	// Обработка критериев и вывод результатов поиска
	switch (searchBy)
	{
	case 1:
	{
		// Поиск студентов по факультету
		string faculty; cout << "Введите название факультета: "; cin >> faculty; vector<Student> filteredStudents;
		for (auto student : students)
		{
			if (student.getFaculty() == faculty)
			{
				filteredStudents.push_back(student);
			}
		}

		printAllStudents(filteredStudents);
		break;
	}

	case 2:
	{
		// Поиск студентов по году поступления
		int enrollmentYear; cout << "Введите год поступления: "; cin >> enrollmentYear; vector<Student> filteredStudents;
		for (auto student : students)
		{
			if (student.getEnrollmentYear() == enrollmentYear)
			{
				filteredStudents.push_back(student);
			}
		}

		printAllStudents(filteredStudents);
		break;
	}

	case 3:
	{
		// Поиск студентов по году рождения
		string birthDate; cout << "Введите дату рождения: "; cin >> birthDate; vector<Student> filteredStudents;
		for (auto student : students)
		{
			if (student.getBirthDate() == birthDate)
			{
				filteredStudents.push_back(student);
			}
		}

		printAllStudents(filteredStudents);
		break;
	}

	case 4:
	{
		// Поиск студентов по предмету и/или оценке
		string subjectName;
		cout << "Введите название предмета (оставьте пустым, если не хотите фильтровать по предмету): ";
		cin.ignore();
		getline(cin, subjectName);
		int minGrade = 0, maxGrade = 100;
		cout << "Введите минимальный балл (оставьте пустым, если не хотите фильтровать по оценке): ";
		string input;
		getline(cin, input);
		if (!input.empty())
		{
			minGrade = stoi(input);
		}
		cout << "Введите максимальный балл (оставьте пустым, если не хотите фильтровать по оценке): ";
		input.clear();
		getline(cin, input);
		if (!input.empty())
		{
			maxGrade = stoi(input);
		}

		vector<Student> filteredStudents;
		for (auto student : students)
		{
			if (subjectName.empty() || student.hasSubject(subjectName))
			{
				bool hasGradeInRange = false;
				for (auto subjectGrade : student.getSubjectGrades())
				{
					if ((subjectGrade.first == subjectName || subjectName.empty()) && subjectGrade.second >= minGrade && subjectGrade.second <= maxGrade)
					{
						hasGradeInRange = true;
						break;
					}
				}
				if (hasGradeInRange)
				{
					filteredStudents.push_back(student);
				}
			}
		}

		cout << "Найдено " << filteredStudents.size() << " студентов:" << endl;
		printAllStudents(filteredStudents);
		break;
	}

	default:
		cout << "Ошибка! Неверный параметр поиска." << endl;
	}
}

// Функция для сохранения списка студентов в файл
void saveToFile(vector<Student>& students, string filename)
{
	// Открытие файла и запись данных о студентах
	ofstream file(filename, std::ios_base::app);
	if (file.is_open())
	{
		for (auto student : students)
		{
			file << student.getName() << endl;
			file << student.getLastName() << endl;
			file << student.getMiddleName() << endl;
			file << student.getBirthDate() << endl;
			file << student.getEnrollmentYear() << endl;
			file << student.getFaculty() << endl;
			file << student.getDepartment() << endl;
			file << student.getGroup() << endl;
			file << student.getRecordBookNumber() << endl;
			file << student.getGender() << endl;
			file << student.getSubjectGrades().size() << endl;
			for (auto subjectGrade : student.getSubjectGrades())
			{
				file << subjectGrade.first << endl;
				file << subjectGrade.second << endl;
			}
		}

		cout << "Данные успешно сохранены в файл!" << endl;

		// Проверка размера файла
		file.seekp(0, std::ios_base::end);
		long fileSize = file.tellp();
		file.close();
		if (fileSize >= 1024 * 1024) // Если размер файла превысил 1 МБ
		{
			cout << "Размер файла слишком большой (" << fileSize / 1024 << " КБ). Желаете выбрать новое имя файла или удалить старый? (y/n)" << endl;
			char answer;
			cin >> answer;
			if (tolower(answer) == 'y') // Запрос на выбор нового имени файла или удаление старого
			{
				string newFilename;
				cout << "Введите новое имя файла: ";
				cin >> newFilename;
				saveToFile(students, newFilename);
			}
			else if (tolower(answer) == 'n')
			{
				cout << "Старый файл будет удален." << endl;
				remove(filename.c_str());
			}
			else
			{
				cout << "Неверный выбор. Старый файл будет удален." << endl;
				remove(filename.c_str());
			}
		}
	}
	else
	{
		cout << "Ошибка! Невозможно сохранить данные в файл." << endl;
	}
}

// Функция для загрузки списка студентов из файла
void loadFromFile(vector<Student>& students, string filename)
{
	ifstream file(filename);
	if (file.is_open())
	{
		students.clear(); // Очистка вектора перед загрузкой новых данных
		string name, lastName, middleName, birthDate, faculty, department, group, recordBookNumber, gender, subject;
		int enrollmentYear, countSubjectGrades, grade;
		while (getline(file, lastName, ',') && getline(file, name, ',') && getline(file, middleName, '"') &&
			file.ignore(1) && getline(file, birthDate, ',') && file >> enrollmentYear >> faculty >> department >>
			group >> recordBookNumber >> gender >> countSubjectGrades)
		{
			vector<pair<string, int>> subjectGrades;
			file.ignore(1); // Пропуск пробела после количества предметов и оценок
			for (int i = 0; i < countSubjectGrades; i++)
			{
				getline(file, subject, ':');
				file >> grade;
				subjectGrades.push_back(make_pair(subject, grade));
			}

			// Создание нового объекта Student и добавление его в вектор students
			Student student(name, lastName, middleName, birthDate, enrollmentYear, faculty, department, group, recordBookNumber, gender, subjectGrades);
			students.push_back(student);

			file.ignore(INT_MAX, '\n'); // Пропуск оставшейся части строки (если есть)
		}

		cout << "Данные успешно загружены из файла!" << endl;
	}
	else
	{
		cout << "Ошибка! Невозможно загрузить данные из файла." << endl;
	}

	file.close(); // Закрытие файла после конца чтения
}

// Функция для удаления студента из списка
void removeStudent(vector<Student>& students)
{
	// Ввод номера зачетной книжки студента, которого нужно удалить
	string recordBookNumber;
	cout << "Введите номер зачетной книжки студента, которого нужно удалить: ";
	cin >> recordBookNumber;	// Поиск и удаление студента из списка
	auto it = find_if(students.begin(), students.end(), [&recordBookNumber](const Student& student)
		{
			return student.getRecordBookNumber() == recordBookNumber;
		});
	if (it != students.end())
	{
		students.erase(it);
		cout << "Студент успешно удален из списка!" << endl;
	}
	else
	{
		cout << "Ошибка! Студент с указанным номером зачетной книжки не найден." << endl;
	}
}

void splitGroupByGrades(vector<Student>& group)
{
	vector<Student> excellent;	// список отличников
	vector<Student> good;	// список хорошистов
	vector<Student> bad;	// список троечников
	int currentYear = 2021;	// текущий год

	// разделяем группу на 3 части в зависимости от среднего балла
	for (auto& student : group)
	{
		int averageGrade = 0;
		for (auto& subject : student.subjectGrades)
		{
			averageGrade += subject.second;
		}

		averageGrade /= student.subjectGrades.size();
		if (averageGrade >= 4)
		{
			excellent.push_back(student);
		}
		else if (averageGrade >= 3)
		{
			good.push_back(student);
		}
		else
		{
			bad.push_back(student);
		}
	}

	// сортируем каждую часть по алфавиту
	sort(excellent.begin(), excellent.end(), [](const Student& a, const Student& b)
		{
			return (a.lastName + " " + a.name < b.lastName + " " + b.name);
		});
	sort(good.begin(), good.end(), [](const Student& a, const Student& b)
		{
			return (a.lastName + " " + a.name < b.lastName + " " + b.name);
		});
	sort(bad.begin(), bad.end(), [](const Student& a, const Student& b)
		{
			return (a.lastName + " " + a.name < b.lastName + " " + b.name);
		});

	// выводим результат на экран
	cout << "Отличники:\n";
	for (auto& student : excellent)
	{
		cout << student.lastName << " " << student.name << " " << student.birthDate << " " << student.faculty << " " << student.department << "\n";
	}

	cout << "\nХорошисты:\n";
	for (auto& student : good)
	{
		cout << student.lastName << " " << student.name << " " << student.birthDate << " " << student.faculty << " " << student.department << "\n";
	}

	cout << "\nТроечники:\n";
	for (auto& student : bad)
	{
		cout << student.lastName << " " << student.name << " " << student.birthDate << " " << student.faculty << " " << student.department << "\n";
	}
}



vector<char> readFileToBinary(const string& fileName) {
	// Открываем файл в бинарном режиме чтения
	ifstream file(fileName, ios::in | ios::binary);

	if (!file.is_open()) {
		cerr << "Ошибка открытия файла " << fileName << " для чтения!" << endl;
		return vector<char>();
	}

	// Определяем размер файла
	file.seekg(0, ios::end);
	long fileSize = file.tellg();
	file.seekg(0, ios::beg);

	// Инициализируем вектор байтов и считываем данные из файла
	vector<char> bytes(fileSize);
	file.read(&bytes[0], fileSize);

	// Закрываем файл и возвращаем вектор байтов
	file.close();

	cout << "Файл " << fileName << " прочитан в бинарном формате." << endl;

	return bytes;
}

int main()
{
	setlocale(LC_ALL, "Russian");	// Установка русской локали
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	vector<Student> group;
	vector<Student> students;	// Список студентов

	while (true)
	{
		// Вывод меню
		cout << "----------------------------------------" << endl;
		cout << "МЕНЮ:" << endl;
		cout << "0. Разделить группу на три части по среднему баллу" << endl;
		cout << "1. Добавить нового студента" << endl;
		cout << "2. Вывести список всех студентов" << endl;
		cout << "3. Редактировать данные студента" << endl;
		cout << "4. Поиск студентов по заданным критериям" << endl;
		cout << "5. Сохранить список студентов в файл" << endl;
		cout << "6. Загрузить список студентов из файла" << endl;
		cout << "7. Удалить студента из списка" << endl;
		cout << "8. Выход из программы" << endl;
		cout << "----------------------------------------" << endl;

		// чтение выбора пользователя
		int choice;	// Обработка выбора пользователя
		cout << "Выберите действие (введите номер пункта меню): ";
		cin >> choice;
		switch (choice)
		{
		case 0:
			splitGroupByGrades(group);
			break;
		case 1:
			addStudent(students);
			break;
		case 2:
			displayStudents(students);
			break;
		case 3:
			editStudent(students);
			break;
		case 4:
			searchStudents(students);
			break;
		case 5:
		{
			string filename;
			cout << "Введите имя файла: ";
			cin >> filename;
			saveToFile(students, filename);
			break;
		}

		case 6:
		{
			string filename;
			cout << "Введите имя файла: ";
			cin >> filename;
			loadFromFile(students, filename);
			break;
		}

		case 7:
			removeStudent(students);
			break;

		case 8:
			return 0;
		default:

			cout << "Ошибка! Неверный выбор." << endl;
		}
	}
}