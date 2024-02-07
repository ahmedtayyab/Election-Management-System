#include"Header.h"
#include<iostream>
#include<fstream>
using namespace std;

int Voter :: operator+(Voter&obj)
{
	return sum + obj.sum;

}


Election::Election()
{

}
Election::~Election()
{

}

int Polling_Station::get_count() 

{
	return count;
}
int Polling_Station::count = 0;

Polling_Station::Polling_Station()
{
	name = "";
	capcity = 0;
	voting_machine = 0;
}
Polling_Station::Polling_Station(string name, int voting_machine, int capacity) {
	this->name = name;
	this->voting_machine = voting_machine;
	this->capcity = capacity;
}
void Polling_Station::set_name(string name) {
	this->name = name;
}
string Polling_Station::get_name() {
	return name;
}
void Polling_Station::set_count(int count) {
	this->count = count;
}
Polling_Station::~Polling_Station() {}
void Polling_Station::set_capcity(int capcity) {
	this->capcity = capcity;
}
int Polling_Station::get_capcity() {
	return capcity;
}
void Polling_Station::set_voting_machine(int voting_machine) {
	this->voting_machine = voting_machine;
}
int Polling_Station::get_voting_machine() {
	return voting_machine;
}
Candidate::Candidate() {

	name = "";
	party = "";
	cnic = "";
	votes = 0;
}
Candidate::Candidate(string name, int age, string party, string cnic, string nationality,int votes) :Person(name, age, nationality) {
	this->cnic = cnic;
	this->party = party;
	this->votes = votes;
}
Candidate::~Candidate() {}
void Candidate::set_party(string party) {
	this->party = party;
}
string Candidate::get_party() {
	return party;
}
void Candidate::set_cnic(string cnic) {
	this->cnic = cnic;
}
string Candidate::get_cnic() {
	return cnic;
}
void Candidate::set_count(int count) {
	this->count = count;
}
int Candidate::get_count() {
	return count;
}
int Candidate::count = 0;
Person::Person() {
	name = "";
	age = 0;
	nationality = "";
}
Person::Person(string name, int age, string nationality) {
	this->name = name;
	this->age = age;
	this->nationality = nationality;
}
Person::~Person() {}
void Person::set_name(string name) {
	this->name = name;
}
void Person::set_age(int age) {
	this->age = age;
}
void Person::set_nationality(string nationality) {
	this->nationality = nationality;
}
string Person::get_name() {
	return name;
}
string Person::set_nationality() {
	return nationality;
}
int Person::get_age() {
	return age;
}
string Person::get_nationality() {
	return nationality;

}
Admin::Admin() {
	username = "";
	password = "";
}
Admin::Admin(string username, string password) {
	this->username = username;
	this->password = password;
}
Admin::~Admin() {}
void Admin::set_username(string username) 
{
	this->username = username;
}
void Admin::set_password(string password) {
	this->password = password;
}
string Admin::get_username() {
	return username;
}
string Admin::get_password() {
	return password;
}
Voter::Voter() {

	++count;
	address = "";
	cnic = "";
	polling_station = 0;
}
Voter::~Voter() {}
Voter::Voter(string address, int age, string name, string nationality, string cnic,int polling_station) :Person(name, age, nationality) {
	this->cnic = cnic;
	this->address = address;
	this->polling_station = polling_station;
	++count;
}
void Voter::set_address(string address) {
	this->address = address;
}
string Voter::get_address() {
	return address;
}
void Voter::set_cnic(string cnic) {
	this->cnic = cnic;
}
string Voter::get_cnic() {
	return cnic;
}
void Voter::set_count(int count) {
	this->count = count;
}
int Voter::get_count() {
	return count;
}
int Voter::count = 0;
void Voter::set_polling_station(int polling_station) {
	this->polling_station = polling_station;
}
int Voter::get_polling_station() {
	return polling_station;
}
void Admin::Add_Voter(Voter& Obj, int& count) {

	string name, nationality, cnic, address;
	int age = 0, polling_station = 0;
	cout << "Enter Name: ";
	cin >> name;
jump:
	cout << "Enter Age: ";
	cin >> age;
	if (age < 18) {
		cout << "Age must be greater than 18 so enter again" << endl;
		goto jump;
	}
	cout << "Enter Nationality: ";
	cin >> nationality;
	cout << "Enter CNIC: ";
	cin >> cnic;
	cout << "Enter Address: ";
	cin >> address;
	cout << "Enter Polling Station Number: ";
	cin >> polling_station;
	Obj.set_name(name);
	Obj.set_age(age);
	Obj.set_address(address);
	Obj.set_cnic(cnic);
	Obj.set_nationality(nationality);
	Obj.set_polling_station(polling_station);
	++count;
	ofstream file("Voter.txt", ios::app);
	ofstream file1("VoterCount.txt");
	file << cnic << " " << name << " " << " " << age << " " << nationality << " " << address << " " << polling_station << endl;
	file1 << count << endl;
	file.close();
	file1.close();
}
bool Admin::Voter_Eligibility(Voter& Obj) {

	cout << "Enter the cnic of voter: ";
	string cnic;
	cin >> cnic;
	string name, cnic1, nationality, address;
	int age = 0, polling_station = 0;
	ifstream file("Voter.txt");
	bool flag = false;
	while (file >> cnic >> name >> age >> nationality >> address >> polling_station) {

		if (cnic1 == cnic) {

			flag = true;
			Obj.set_cnic(cnic);
			Obj.set_name(name);
			Obj.set_age(age);
			Obj.set_nationality(nationality);
			Obj.set_address(address);
			Obj.set_polling_station(polling_station);
			if (Obj.get_age() >= 18 && Obj.set_nationality() == "Pakistan") {

				return true;

			}
			else {
				return false;
			}
		}
	}
	if (!flag) {

		cout << "Voter not found" << endl;

	}

}
void Admin::Add_Polling_Station(Polling_Station& Obj, int& count) {

	string name;
	int capacity = 0, voting_machine = 0;
	cout << "Enter Name: ";
	cin >> name;
	cout << "Enter Capacity: ";
	cin >> capacity;
	cout << "Enter Numbers of Voting Machine: ";
	cin >> voting_machine;
	Obj.set_name(name);
	Obj.set_capcity(capacity);
	Obj.set_voting_machine(voting_machine);
	++count;
	ofstream file("PollingStation.txt", ios::app);
	ofstream file1("PollingStationCount.txt");
	file << count << " " << name << " " << capacity << " " << voting_machine << endl;
	file1 << count << endl;
	file.close();
	file1.close();
}
void Admin::Check_Polling_Station() {

	int polling_station_num = 0;
	cout << "Enter Polling Station Number: ";
	cin >> polling_station_num;
	ifstream file("PollingStation.txt");
	string name;
	int capacity = 0, voting_machine = 0, count = 0;
	bool flag = false;
	while (file >> count >> name >> capacity >> voting_machine) {

		if (polling_station_num == count) {
			flag = true;
			if (voting_machine < 10 || capacity < 1000) {
				cout << "Not Eligible" << endl;

			}
			else {

				cout << "Eligible" << endl;
			}
			
		}
	}
	if (!flag) {

		cout << "Polling Station Not Found" << endl;

	}
	file.close();
}
void Voter::Change_Polling_Station(int count) {

	string cnic1;
	cout << "Enter your Cnic: ";
	cin >> cnic1;
	string cnic, name, nationality, address;
	int polling_station;
	int age = 0;
	ifstream file("Voter.txt");
	Voter* voter = new Voter[count];
	bool found = false;
	int i = 0;
	while (file >> cnic >> name >> age >> nationality >> address >> polling_station) {

		voter[i].set_cnic(cnic);
		voter[i].set_name(name);
		voter[i].set_age(age);
		voter[i].set_nationality(nationality);
		voter[i].set_address(address);
		voter[i].set_polling_station(polling_station);
		if (cnic == cnic1) {

			cout << "Enter new Polling Station : ";
			cin >> polling_station;
			voter[i].set_polling_station(polling_station);
			cnic1 = "";
			found = true;
		}
		++i;
	}
	file.close();
	remove("Voter.txt");
	ofstream file1("Voter.txt");
	for (int i = 0; i < count; ++i) {

		file1 << voter[i].get_cnic() << " " << voter[i].get_name() << " " << voter[i].get_age() << " " << voter[i].get_nationality() << " " << voter[i].get_address() << " " << voter[i].get_polling_station() << endl;
	}
	if (!found) {

		cout << "Voter Not found" << endl;
		return;
	}
	delete[]voter;
}
void Admin::Remove_Polling_Station(int& count) {

	int polling_station_num = 0;
	cout << "Enter Polling Station Number: ";
	cin >> polling_station_num;
	int polling_station_num1 = 0, voting_machines = 0, capacity = 0;
	string name;
	ifstream file("PollingStation.txt");
	Polling_Station* polling_station = new Polling_Station[count];
	bool found = false;
	int i = 0;
	while (file >> polling_station_num1 >> name >> capacity >> voting_machines) {

		if (polling_station_num1 != polling_station_num) {

			found = true;
			polling_station[i].set_count(polling_station_num1);
			polling_station[i].set_name(name);
			polling_station[i].set_capcity(capacity);
			polling_station[i].set_voting_machine(voting_machines);
			++i;
		}
	}
	file.close();
	remove("PollingStation.txt");
	ofstream file1("PollingStation.txt");
	--count;
	ofstream file2("PollingStationCount.txt");
	file2 << count << endl;
	for (int i = 0; i < count; ++i) {

		file1 << polling_station[i].get_count() << " " << polling_station[i].get_name() << " " << polling_station[i].get_capcity() << " " << polling_station[i].get_voting_machine() << endl;
	}
	if (!found) {

		cout << "Polling station not found" << endl;

	}
	file1.close();
	delete[]polling_station;
}
void Admin::Generate_Report() {

	string cnic, name, nationality, address;
	int age = 0, polling_station_num = 0;
	ifstream file("Voter.txt");
	int i = 1;
	while (file >> cnic >> name >> age >> nationality >> address >> polling_station_num) {

		cout << "Data of Voter# " << i << endl;
		cout << "----------------------------------" << endl;
		cout << "CNIC: " << cnic << endl;
		cout << "Name: " << name << endl;
		cout << "Age: " << age << endl;
		cout << "Nationality: " << nationality << endl;
		cout << "Address: " << address << endl;
		cout << "Polling Station# : " << polling_station_num << endl;
		cout << "----------------------------------" << endl;
		++i;

	}
}
void Admin::Generate_Report_Candidate() {

	string cnic, name, nationality, address;
	int age = 0, polling_station_num = 0;
	ifstream file("Candidate.txt");
	int i = 1;
	while (file >> cnic >> name >> age >> nationality) {

		cout << "Data of Candidate# " << i << endl;
		cout << "----------------------------------" << endl;
		cout << "CNIC: " << cnic << endl;
		cout << "Name: " << name << endl;
		cout << "Age: " << age << endl;
		cout << "Nationality: " << nationality << endl;
		cout << "----------------------------------" << endl;
		++i;

	}
}
void Admin::Generate_Report_Admin() {

	string name;
	int capacity = 0, voting_machine = 0;
	int age = 0, polling_station_num = 0;
	ifstream file("PollingStation.txt");
	int i = 1;
	while (file >> polling_station_num >> name >> capacity >> age) {

		cout << "Data of Candidate# " << i << endl;
		cout << "----------------------------------" << endl;
		cout << "Plling Station: " << polling_station_num << endl;
		cout << "City: " << name << endl;
		cout << "Capacity: " << capacity << endl;
		cout << "Age: " << age << endl;
		cout << "----------------------------------" << endl;
		++i;

	}
}
void Candidate::Add_Candidate(Candidate& Obj, int& count) {

	string name, party, cnic, nationality;
	int age = 0;
	cout << "Enter Name: ";
	cin >> name;
jump:
	cout << "Enter Age: ";
	cin >> age;
	if (age < 18) {
		cout << "Age must be greater than 18 so enter again" << endl;
		goto jump;
	}
	cout << "Enter Nationality: ";
	cin >> nationality;
	cout << "Enter CNIC: ";
	cin >> cnic;
	cout << "Enter name: ";
	Obj.set_name(name);
	Obj.set_cnic(cnic);
	Obj.set_nationality(nationality);
	Obj.set_party(party);
	Obj.set_age(age);
	++count;
	ofstream file("Candidate.txt", ios::app);
	ofstream file1("CandidateCount.txt");
	file << cnic << " " << name << " " << party << " " << age << " " << nationality  << endl;
	file1 << count << endl;
	file.close();
	file1.close();
}
void Admin::Nominate_Candidate(int& count) {
	string cnic;
	ifstream infile("Candidate.txt");
	cout << "Enter Cnic: ";
	cin >> cnic;
	ifstream file("Candidate.txt");
	string cnic1, name, party, nationality;
	int age = 0;
	while (file >> cnic1 >> name >> party >> nationality >> age) 
	{


		if (age > 18 && cnic == cnic1 && nationality == "Pakistan") {
			int choice;
			cout << "1) MNA" << endl;
			cout << "2) MPA" << endl;
			cin >> choice;
			ofstream file1;
			if (choice == 1) {
				file1.open("MNA.txt", ios::app);
			}
			else if (choice == 2) {
				file1.open("MPA.txt", ios::app);
			}
			if (file1.is_open()) {
				file1 << cnic1 << " " << name << " " << party << " " << nationality << " " << age << endl;
				file1.close();
				ofstream countFile("NominatedCandidatecount.txt");
				++count;
				countFile << count << endl;
				countFile.close();

				cout << "Candidate Nominated" << endl;
			}
			else {
				cout << "Error opening file for writing" << endl;
			}
		}
		else {
			cout << "Candidate Not Nominated" << endl;
		}
	}
}

int Candidate::get_votes() {

	return votes;
}
void Candidate::set_votes(int votes) {

	this->votes = votes;

}



void Person::CastVote(int& count) {
	cout << "Enter your CNIC: ";
	string cnic;
	cin >> cnic;

	ifstream file("Voter.txt");
	ofstream file2("AlreadyVoted.txt", ios::app);

	string name, nationality, cnic1, address;
	int age = 0, polling_station = 0;
	Candidate* candidateMNA = new Candidate[count];
	Candidate* candidateMPA = new Candidate[count];
	int iMNA = 0, iMPA = 0;

	while (file >> cnic1 >> name >> age >> nationality >> address >> polling_station) {
		if (cnic1 == cnic) {
			cout << "Cast your vote for MNA: " << endl;
			cout << "Enter the CNIC of your MNA candidate: ";
			string cnicMNA;
			cin >> cnicMNA;

			cout << "Cast your vote for MPA: " << endl;
			cout << "Enter the CNIC of your MPA candidate: ";
			string cnicMPA;
			cin >> cnicMPA;

			ifstream file1MNA("NominatedCandidate_MNA.txt");
			ifstream file1MPA("NominatedCandidate_MPA.txt");

			string cnicMNA1, nameMNA, partyMNA, nationalityMNA;
			int ageMNA = 0, votesMNA = 0;
			while (file1MNA >> cnicMNA1 >> nameMNA >> partyMNA >> nationalityMNA >> ageMNA >> votesMNA) {
				if (cnicMNA == cnicMNA1) {
					file2 << cnic1 << endl;

					candidateMNA[iMNA].set_cnic(cnicMNA);
					candidateMNA[iMNA].set_name(nameMNA);
					candidateMNA[iMNA].set_party(partyMNA);
					candidateMNA[iMNA].set_nationality(nationalityMNA);
					candidateMNA[iMNA].set_age(ageMNA);
					candidateMNA[iMNA].set_votes(votesMNA + 1);
					++iMNA;
				}
			}
			file1MNA.close();

			string cnicMPA1, nameMPA, partyMPA, nationalityMPA;
			int ageMPA = 0, votesMPA = 0;
			while (file1MPA >> cnicMPA1 >> nameMPA >> partyMPA >> nationalityMPA >> ageMPA >> votesMPA) {
				if (cnicMPA == cnicMPA1) {
					file2 << cnic1 << endl;

					candidateMPA[iMPA].set_cnic(cnicMPA);
					candidateMPA[iMPA].set_name(nameMPA);
					candidateMPA[iMPA].set_party(partyMPA);
					candidateMPA[iMPA].set_nationality(nationalityMPA);
					candidateMPA[iMPA].set_age(ageMPA);
					candidateMPA[iMPA].set_votes(votesMPA + 1);
					++iMPA;
				}
			}
			file1MPA.close();
		}
		else {
			string cnic4;
			ifstream temp("AlreadyVoted.txt");
			while (temp >> cnic4) {
				if (cnic4 == cnic1) {
					cout << "You have already voted" << endl;
					return;
				}
			}
			temp.close();
		}
	}

	// Update MNA file
	ofstream file3MNA("NominatedCandidate_MNA.txt");
	for (int i = 0; i < iMNA; ++i) {
		file3MNA << candidateMNA[i].get_cnic() << " " << candidateMNA[i].get_name() << " "
			<< candidateMNA[i].get_party() << " " << candidateMNA[i].get_nationality() << " "
			<< candidateMNA[i].get_age() << " " << candidateMNA[i].get_votes() << endl;
	}
	file3MNA.close();







	// Update MPA file
	ofstream file3MPA("NominatedCandidate_MPA.txt");
	for (int i = 0; i < iMPA; ++i) {
		file3MPA << candidateMPA[i].get_cnic() << " " << candidateMPA[i].get_name() << " "
			<< candidateMPA[i].get_party() << " " << candidateMPA[i].get_nationality() << " "
			<< candidateMPA[i].get_age() << " " << candidateMPA[i].get_votes() << endl;
	}
	file3MPA.close();

	delete[] candidateMNA;
	delete[] candidateMPA;
}