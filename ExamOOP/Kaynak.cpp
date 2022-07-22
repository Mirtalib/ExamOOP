#include <iostream>
#include <vector>
#include <iomanip>
#include <fstream>
#include <string>
#include <conio.h>
using namespace std;

#include"Question.h"
#include"Quiz.h"
#include"Users.h"
#include"UsersAdmin.h"
#include"Guest.h"
#include"Functions.h"
using namespace HearderFiles;


int main() {

	system("cls");

	while (true) {

		size_t select = 0;
		bool start = true;

		while (start) {

			if (select == 0)
				cout
				<< setw(50) << "<< Admin >>\n"
				<< setw(47) << "   Guest\n"
				<< setw(46) << "   Exit\n";
			else if (select == 1)
				cout
				<< setw(47) << "   Admin\n"
				<< setw(50) << "<< Guest >>\n"
				<< setw(46) << "   Exit\n";
			else if (select == 2)
				cout
				<< setw(47) << "   Admin\n"
				<< setw(47) << "   Guest\n"
				<< setw(49) << "<< Exit >>\n";



			switch (_getch()) {
			case 72:
				if (select != 0)
					select--;
				system("cls");
				break;
			case 80:
				if (select + 1 < 3)
					select++;
				system("cls");
				break;
			case '\r':
				if (select == 2)
					exit(0);
				else
					start = false;
				break;
			default:
				system("cls");
				break;
			}
		}

		if (select == 0) {

			system("cls");
			size_t select1 = 0;
			bool start1 = true;

			while (true) {


				while (start1) {
					if (select1 == 0)
						cout
						<< setw(52) << "<< Sing in >>\n"
						<< setw(67) << "   If you already have an account, create a new one\n"
						<< setw(46) << "   Exit\n";
					else if (select1 == 1)
						cout
						<< setw(49) << "   Sing in\n"
						<< setw(70) << "<< If you already have an account, create a new one >>\n"
						<< setw(46) << "   Exit\n";
					else if (select1 == 2)
						cout
						<< setw(49) << "   Sing in\n"
						<< setw(68) << "   If you already have an account, create a new one \n"
						<< setw(49) << "<< Exit >>\n";



					int control = _getch();
					switch (control) {
					case 72:
						if (select1 != 0)
							select1--;
						system("cls");
						break;
					case 80:
						if (select1 + 1 < 3)
							select1++;
						system("cls");
						break;
					case '\r':
						if (select1 == 3)
							break;
						else
							start1 = false;
						break;
					default:
						system("cls");
						break;
					}
				}
				if (select1 == 2)
				{
					system("cls");
					break;
				}

				if (select1 == 0)
				{

					system("cls");
					fstream myfile1;
					string line;
					string line2;
					fstream myfil2;
					bool trueORfalse = true;

					myfile1.open("DataBaseAdminName.txt", ios::in);
					myfil2.open("DataBaseAdminPassword.txt", ios::in);


					if (myfile1)
					{
						string name;
						string password;

						while (trueORfalse) {


							cout << setw(50) << "Enter Your Username" << endl;
							cin >> name;
							cout << setw(50) << "Enter Your Password" << endl;
							cin >> password;

							while (!myfile1.eof())
							{
								getline(myfile1, line);

								if (line == name)
								{
									while (!myfil2.eof()) {
										getline(myfil2, line2);
										if (line2 == password)
										{
											trueORfalse = false;
											cout << setw(50) << "WELVME" << endl;
											break;
										}
									}
								}
							}
							if (trueORfalse)
							{
								system("cls");
								cout << setw(50) << "Name Or Password Wrong" << endl;
							}
						}
					}
					else
					{
						cout << setw(50) << "There are no users" << endl;
						system("cls");
						break;
					}
					
				}
				else if (select1 == 1)
				{
					system("cls");
					string newName;
					string newPassword;
					fstream myfileAdmin;
					string line2;
					bool check = true;

					myfileAdmin.open("DataBaseAdminName.txt", ios::in);

					if (myfileAdmin)
					{
						while (check)
						{
							cout << setw(50) << "Enter Your Username" << endl;
							cin >> newName;
							while (!myfileAdmin.eof())
							{
								getline(myfileAdmin, line2);

								if (line2 != newName)
								{
									check = false;
								}
								else
								{
									check = true;
									cout << setw(50) << "This username is unique , please enter a new one" << endl;
									break;
								}
							}
						}

						cout << setw(50) << "Enter Your Password" << endl;
						cin >> newPassword;
						
						writeToFileAdmin(Admin(newName, newPassword));
						system("cls");
					}
					else
					{
						cout << setw(50) << "Username" << endl;
						cin >> newName;
						cout << setw(50) << "Enter Your Password" << endl;
						cin >> newPassword;

						writeToFileAdmin(Admin(newName, newPassword));
					}
				}
				start1 = true;
				system("cls");


				while (true)
				{
					size_t select3 = 0;
					bool start3 = true;

					while (start3) {

						if (select3 == 0)
							cout
							<< setw(50) << "<< Start Quiz >>\n"
							<< setw(47) << "   Creat Quiz\n"
							<< setw(46) << "   Top Score\n"
							<< setw(41) << "   Exit\n";
						else if (select3 == 1)
							cout
							<< setw(47) << "   Start Quiz\n"
							<< setw(50) << "<< Creat Quiz >>\n"
							<< setw(46) << "   Top Score\n"
							<< setw(41) << "   Exit\n";
						else if (select3 == 2)
							cout
							<< setw(47) << "   Start Quiz\n"
							<< setw(47) << "   Creat Quiz\n"
							<< setw(49) << "<< Top Score >>\n"
							<< setw(41) << "   Exit\n";
						else if (select3 == 3)
							cout
							<< setw(47) << "   Start Quiz\n"
							<< setw(47) << "   Creat Quiz\n"
							<< setw(46) << "   Top Score\n"
							<< setw(44) << "<< Exit >>\n";
						switch (_getch()) {
						case 72:
							if (select3 != 0)
								select3--;
							system("cls");
							break;
						case 80:
							if (select3 + 1 < 4)
								select3++;
							system("cls");
							break;
						case '\r':
							start3 = false;
							break;
						default:
							system("cls");
							break;
						}

					}
					if (select3 == 0)
					{
						system("cls");

						size_t correctCount = 0;
						size_t wrong = 0;
						size_t passed = 0;
						readQuiz(correctCount, wrong, passed);
					}

					if (select3 == 1)
					{
						system("cls");
						string quizName;
						string quizText;
						string quizAnwes1;
						string quizAnwes2;
						string quizAnwes3;
						string quizAnwes4;
						int sizeVariant;
						char symbol;
						int size;
						cout << setw(50) << "Quiz Name" << endl;
						cin >> quizName;
						cout << setw(54) << "Enter Size Question" << endl;
						cin >> size;
						quizes quiz(quizName);

						for (size_t i = 0; i < size; i++)
						{
							cout << setw(54) << "Enter Text Question" << endl;
							cin.ignore();
							getline(cin, quizText);

							cout << setw(50) << "Enter Size Variant (Max Variant Size 4 , Min Variant Size 2)" << endl;
							cin >> sizeVariant;

							system("cls");
							if (sizeVariant < 2 || sizeVariant > 4)
							{
								cout << setw(50) << "Size variant wrong" << endl;
								continue;
							}

							if (sizeVariant == 2)
							{
								cout << setw(50) << "Enter Variant A" << endl;
								cin >> quizAnwes1;
								cout << setw(50) << "Enter Variant B" << endl;
								cin >> quizAnwes2;
								cout << setw(50) << "Enter Correct Varient" << endl;
								cin >> symbol;
								quiz.add(Question(quizText, symbol, quizAnwes1, quizAnwes2));
							}
							else if (sizeVariant == 3)
							{
								cout << setw(50) << "Enter Variant A" << endl;
								cin >> quizAnwes1;
								cout << setw(50) << "Enter Variant B" << endl;
								cin >> quizAnwes2;
								cout << setw(50) << "Enter Variant C" << endl;
								cin >> quizAnwes3;
								cout << setw(50) << "Enter Correct Varient" << endl;
								cin >> symbol;

								quiz.add(Question(quizText, symbol, quizAnwes1, quizAnwes2, quizAnwes3));
							}
							else if (sizeVariant == 4)
							{
								cout << setw(50) << "Enter Variant A" << endl;
								cin >> quizAnwes1;
								cout << setw(50) << "Enter Variant B" << endl;
								cin >> quizAnwes2;
								cout << setw(50) << "Enter Variant C" << endl;
								cin >> quizAnwes3;
								cout << setw(50) << "Enter Variant E" << endl;
								cin >> quizAnwes4;
								cout << setw(50) << "Enter Correct Varient" << endl;
								cin >> symbol;
								quiz.add(Question(quizText, symbol, quizAnwes1, quizAnwes2, quizAnwes3, quizAnwes4));
							}
							system("cls");
						}
						quiz.writeToFile();
					}

					if (select3 == 2)
					{
						bool trueOrfale = true;
						while (trueOrfale)
						{
							system("cls");
							topScoreReadFile();
							cout << setw(20) << "Press Enter to continue" << endl;
							int secim = _getch();
							if (secim == '\r')
							{
								break;
							}
						}
						system("cls");
					}

					if (select3 == 3)
					{
						system("cls");
						break;
					}
				}
			}

		}
		else if (select == 1) {

			system("cls");
			string nameUsers;
			cout << setw(50) << "Enter Your Name" << endl;
			cin >> nameUsers;
			Guest users(nameUsers);
			
			system("cls");
			while (true)
			{

				size_t selectUser = 0;
				bool start3User = true;

				while (start3User) {

					if (selectUser == 0)
						cout
						<< setw(50) << "<< Start Quiz >>\n"
						<< setw(46) << "   Top Score\n"
						<< setw(41) << "   Exit\n";

					else if (selectUser == 1)
						cout
						<< setw(47) << "   Start Quiz\n"
						<< setw(49) << "<< Top Score >>\n"
						<< setw(41) << "   Exit\n";

					else if (selectUser == 2)
						cout
						<< setw(47) << "   Start Quiz\n"
						<< setw(46) << "   Top Score\n"
						<< setw(44) << "<< Exit >>\n";



					switch (_getch()) {
					case 72:
						if (selectUser != 0)
							selectUser--;
						system("cls");
						break;
					case 80:
						if (selectUser + 1 < 3)
							selectUser++;
						system("cls");
						break;
					case '\r':
						start3User = false;
						break;
					default:
						system("cls");
						break;
					}
				}

				if (selectUser == 0)
				{
					system("cls");
					size_t correctCount = 0;
					size_t wrong = 0;
					size_t passed = 0;

					readQuiz(correctCount, wrong, passed);
					users.topScoreWriteFile(correctCount, wrong, passed);
				}
				else if (selectUser == 1)
				{
					bool trueOrfale = true;

					while (trueOrfale)
					{
						system("cls");
						topScoreReadFile();
						cout << setw(20) << "Press Enter to continue" << endl;
						int secim = _getch();
						if (secim == '\r')
							break;

					}
					system("cls");
				}
				else if (selectUser == 2)
				{
					system("cls");
					break;
				}
			}
		}
	}
}