#include<iostream>
#include<string>
#include<fstream>
#include"Header.h"
using namespace std; 
bool Signin(Admin& Obj, string username, string password)
{            

	if (Obj.get_username() == username)
	{

		if (Obj.get_password() == password) 
		{
			return  true;
		}
		else 
		{
			cout << "Invalid Password" << endl;
			return false;
		}
	}
	else 
	{
		return false;
	}
}
int main() 
{

	while (1) 
	{
		try 
		{
			Admin admin;
			Voter voter;
			Candidate candidate;
			Polling_Station polling_station;
			cout << "Welcome to E-Voting System" << endl;
			cout << "Instructions are following" << endl;
			cout << "1.If you are a Admin press 1" << endl;
			cout << "2.If you are a Voter press 2" << endl;
			cout << "3.If you are a Candidate press 3" << endl;
			cout << "4.If you want to exit press 4" << endl;
			int choice = 0;
			cout << "Enter your Choice: ";
			cin >> choice;
			system("Cls");
			if (choice == 1) {

				string username, password;
				ifstream fin("Admin.txt");
				fin >> username >> password;
				fin.close();
				admin.set_username(username);
				admin.set_password(password);
				cout << "Enter your username: ";
				cin >> username;
				cout << "Enter your password: ";
				cin >> password;
				bool flag = Signin(admin, username, password);
				system("Cls");
		
		
			while (1)
			{
				if (flag)
				{

					cout << "Instructions for Admin" << endl;
					cout << "1.Press 1 to add a new voter" << endl;
					cout << "2.Press 2 to check a voter's eligibility" << endl;
					cout << "3.Press 3 to add a new Polling Station" << endl;
					cout << "4.Press 4 to check Polling Station" << endl;
					cout << "5.Press 5 to Nominate a new candidate" << endl;
					cout << "6.Press 6 to Generate Voters report" << endl;
					cout << "7.Press 7 to Remove a Polling Station" << endl;
					cout << "8.Press 8 to Generate Candidate's Report" << endl;
					cout << "9.Press 9 to Generate Admin's Report" << endl;
					cout << "10.Press 10 to exit" << endl;
					int op = 0;
					cout << "Enter your choice: ";
					cin >> op;
					system("Cls");
					if (op == 1) {

						int count = 0;
						ifstream fin("VoterCount.txt");
						fin >> count;
						fin.close();
						admin.Add_Voter(voter, count);
					}
					else if (op == 2) {

						bool flag = admin.Voter_Eligibility(voter);
						if (flag == true) {

							cout << "Voter is eligible" << endl;
						}
						else {

							cout << "Voter is not eligible" << endl;
						}
					}
					else if (op == 3) {

						int count = 0;
						ifstream fin("PollingStationCount.txt");
						fin >> count;
						fin.close();
						admin.Add_Polling_Station(polling_station, count);
					}
					else if (op == 4) {

						admin.Check_Polling_Station();
					}
					else if (op == 5) {

						ifstream fin("NominatedCandidatecount.txt");
						int count = 0;
						fin >> count;
						fin.close();
						admin.Nominate_Candidate(count);

					}
					else if (op == 6) {

						admin.Generate_Report();
					}
					else if (op == 7) {

						ifstream fin("PollingStationcount.txt");
						int count = 0;
						fin >> count;
						fin.close();
						admin.Remove_Polling_Station(count);

					}
					else if (op == 8) {

						admin.Generate_Report_Candidate();
					}
					else if (op == 9)
					{
						admin.Generate_Report_Admin();
					}
					else if (op == 10)
					{
						break;
					}
				}
				else {

					cout << "Invalid username or password" << endl;
					system("Cls");
					break;
				}

			}
		}
		else if (choice == 2) {


			while (1) {

				cout << "1.To Cast vote press 1" << endl;
				cout << "2.To Change Polling Station press 2" << endl;
				cout << "3.To exit press 3" << endl;
				int op = 0;
				cout << "Enter your choice: ";
				cin >> op;
				system("Cls");
				if (op == 1) {

					int count = 0;
					ifstream fin("VoterCount.txt");
					fin >> count;
					fin.close();
					voter.CastVote(count);

				}
				else if (op == 2) {

					int count = 0;
					ifstream fin("VoterCount.txt");
					fin >> count;
					fin.close();
					voter.Change_Polling_Station(count);
				}
				else if (op == 3) {

					break;
				}
			}
		}
		else if (choice == 3) {

			while (1) {

				cout << "1.To Register Candidate press 1" << endl;
				cout << "2.To exit press 2" << endl;
				int op = 0;
				cout << "Enter your choice: ";
				cin >> op;
				if (op == 1) {

					ifstream fin("CandidateCount.txt");
					int count = 0;
					fin >> count;
					fin.close();
					candidate.Add_Candidate(candidate, count);
				}
				else if (op == 2) {

					break;
				}
			}
		}
		else 
		{
			cout << "Invalid Input" << endl;
			break;

		}

	}
	catch (const exception& e) {
		cerr << "Error: " << e.what() << endl;
	}
	catch (...) {
		cerr << "An unknown error occurred" << endl;
	}
	}

	return 0;
}