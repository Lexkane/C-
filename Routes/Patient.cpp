#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <algorithm>
#include <string>
#include <fstream>

using namespace std;


class Patient 
{
private:
	string name;
	string surname;
	string id;
public:
	const string& get_name()const {
		return name;
	}
	const string& get_surname()const {
		return surname;
	}
	const string& get_id()const {
		return id;
	}

	friend istream& operator >> (istream& is, Patient& p) {
		is >> p.id >> p.name >> p.surname;
		return is;
	}

	friend bool operator<(const Patient& p1, const Patient& p2) {
		return p1.get_id() < p2.get_id();
	}
};

class Medicine {
private:
	string patient_id;
	string date;
	string title;
	double doze = 0;
	unsigned per_day = 0;
public:
	const string& get_patient_id()const {
		return patient_id;
	}
	const string& get_date()const {
		return date;
	}
	const string& get_title()const {
		return title;
	}
	const double& get_doze()const {
		return doze;
	}
	const double& get_count_per_day()const {
		return per_day;
	}

	friend istream& operator >> (istream& is, Medicine& med) {
		is >> med.patient_id >> med.date >> med.title >> med.doze >> med.per_day;
		return is;
	}

	friend bool operator<(const Medicine& m1, const Medicine& m2) {
		if (m1.title != m2.title)
			return m1.title < m2.title;
		if (m1.doze != m2.doze)
			return m1.doze < m2.doze;
		if (m1.patient_id != m2.patient_id)
			return m1.patient_id < m2.patient_id;
		return false;
	}
};

template<typename T>
void read_from_file(set<T>& seq, string path) {
	ifstream fin(path);
	if (fin.is_open()) {
		while (!fin.eof()) {
			T p;
			fin >> p;
			seq.insert(p);
		}
	}
	fin.close();
}

int main() 
{
#pragma region ReadingData

	set<Patient> patients;
	read_from_file(patients, "Patient1.txt");
	read_from_file(patients, "Patient2.txt");

	set<Medicine> medicines;
	read_from_file(medicines, "Med1.txt");
	read_from_file(medicines, "Med2.txt");

#pragma endregion

#pragma region TASK1
	cout << "\t\tTASK1\n\n";
	//double - сумарна к-сть мг
	map<Patient, map<Medicine, double>> patients_med;
	for (auto patient : patients) {
		for (auto medicine : medicines) {
			if (medicine.get_patient_id() == patient.get_id())
				patients_med[patient][medicine] += medicine.get_doze()*medicine.get_count_per_day();
		}
	}

	for (auto data : patients_med) {
		cout << data.first.get_name() << " " << data.first.get_surname() << endl;;
		for (auto med : data.second) {
			cout << "\t" << med.first.get_title() << ": " << med.second << endl;
		}
	}

#pragma endregion

#pragma region TASK2

	cout << "\t\tTASK2\n\n";

	map < string, map < Medicine, double >> per_dates;
	for (auto med : medicines) {
		per_dates[med.get_date()][med] += med.get_doze()*med.get_count_per_day();
	}

	for (auto data : per_dates) {
		cout << data.first << endl;
		for (auto med : data.second) {
			cout << "\t" << med.first.get_title() << ": " << med.second << endl;
		}
	}

#pragma endregion

#pragma region Task3

	cout << "\t\tTASK3\n\n";

	auto pred_by_tytle = [](const Medicine& m1, const Medicine& m2) {
		return m1.get_title() < m2.get_title();
	};

	map<Medicine, double, decltype(pred_by_tytle)> general_data(pred_by_tytle);
	for (auto medicine : medicines) {
		general_data[medicine] += medicine.get_doze()*medicine.get_count_per_day();
	}

	for (auto data : general_data)
		cout << data.first.get_title() << ": " << data.second << endl;
#pragma endregion

	system("pause");
}