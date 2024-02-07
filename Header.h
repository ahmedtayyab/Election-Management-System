#pragma once
#include<string>
using namespace std;
class Election {
protected:
	int poling_station;
	int num;
public:
	Election();
	~Election();
};
class Person 
{
protected:
	string name;
	int age;
	string nationality;
public:
	Person();
	~Person();
	Person(string, int, string);
	void set_name(string);
	void set_age(int);
	void set_nationality(string);
	string get_name();
	string set_nationality();
	int get_age();
	string get_nationality();
	void CastVote(int&);
};
class Polling_Station 
{
protected:
	string name;
	static int count;
	int capcity;
	int voting_machine;
	Election election;
public:

	Polling_Station();
	~Polling_Station();
	Polling_Station(string, int, int);
	void set_name(string);
	string get_name();
	void set_count(int);
	int get_count();
	int get_capcity();
	int get_voting_machine();
	void set_capcity(int);
	void set_voting_machine(int);
};
class Voter :public Person 
{

protected:
	int sum;
	string address;
	string cnic;
	static int count;
	int polling_station;
	Election* election;
public:
	Voter();
	~Voter();
	Voter(string, int, string, string, string, int);
	void set_address(string);
	string get_address();
	void set_cnic(string);
	string get_cnic();
	void set_count(int);
	void set_polling_station(int);
	int get_polling_station();
	int get_count();
	void Change_Polling_Station(int count);
	int operator+(Voter& obj);

};
class Candidate :public Person 
{

protected:
	string cnic;
	string party;
	static int count;
	int votes;
public:
	Candidate();
	~Candidate();
	Candidate(string, int, string, string, string, int);
	void set_cnic(string);
	string get_cnic();
	void set_party(string);
	string get_party();
	void set_count(int);
	int get_count();
	void set_votes(int);
	int get_votes();
	void Add_Candidate(Candidate&, int&);
};
class Admin :public Person 
{
protected:
	string username;
	string password;
public:

	Admin();
	~Admin();
	Admin(string, string);
	void set_username(string);
	void set_password(string);
	string get_username();
	string get_password();
	void Add_Voter(Voter& l, int&);
	bool Voter_Eligibility(Voter&);
	void Check_Polling_Station();
	void Add_Polling_Station(Polling_Station&, int&);
	void Remove_Polling_Station(int&);
	void Generate_Report();
	void Generate_Report_Candidate();
	void Generate_Report_Admin();
	void Nominate_Candidate(int&);

};