
#include <iostream>
#include <string>
#include <fstream>
#include <conio.h>
#include <windows.h>
#include <cmath> 
#include <ctime>
#include <unistd.h>

using namespace std;
//______________________________Functions__________________________________________
void Admin_dashboard();
void function_to_register_user();
void User_Login();
void Teacher_dashboard();
void Student_dashboard();
void Update_information();
void quiz_creation();
void view_quiz_results();
void	edit_quiz();
void	assign_quiz_to_student();
void fun_assigned_quiz_veiw();
void attempt_quiz();
void fun_quiz_grades();
void 	result_quiz_fun() ;
void fun_quiz_attempt();
void fun_to_edit_quiz();
void grades_quiz_fun();
void user_credentials();

int current_user_id = -1;     //Global variable.
//structure for registration.
typedef struct
{
	int id;
	string username;
	string password;
	string email;
	string phone;
	string designation;
	string role;
}
registration;
//structure for login.
typedef struct
{
	string username;
	string password;
}loginuser;
//strcture for quiz info.
typedef struct
{
	string quizName;
	string subject;
	string questions[10];
	string options[10][4];
	int correct_answer[10];
	int marks;
	} quiz_info;
	
	
	//_____________________________Function to register user_________________________________ 
	void function_to_register_user()
{

	system("cls");
	cout << "Registration" << endl;
 registration user;

	// Find the highest existing ID
	int maxId = 0;
	ifstream infile("user.txt");
	if (infile)
	{
		string line;
		while (getline(infile, line))
		{
			if (line.empty())
			 continue;
			int id = stoi(line);
			for (int i = 0; i < 6; i++) 
			 getline(infile, line);
			if (id > maxId)
			 maxId = id;
		}
		infile.close();
	}
	user.id = maxId + 1;

	ofstream file("user.txt", ios::app);
	if (!file)
	{
		cout << "Error opening file!" << endl;
		return;
	}
	cout << "Assigned User ID: " << user.id << endl;

	// Username validation
	while (true)
	{
		cout << "Enter Username (no spaces): ";
		getline(cin, user.username);
		if (user.username.length() >= 2 && user.username.find(' ') == string::npos)
	 break;
		cout << "Invalid username format." << endl;
		
	}

	// Password validation
	while (true) 
	{
		cout << "Enter Password (at least 4 characters): ";
		getline(cin, user.password);
		if (user.password.length() >= 4)
			break;
		cout << "Invalid password format." << endl;
	}

	// Email validation
	while (true)
	{
		cout << "Enter Email (username@gmail.com): ";
		getline(cin, user.email);
		if (user.email.length() >= 5 && user.email.find('@') != string::npos && user.email.find('.') != string::npos)
			break;
		cout << "Invalid email format." << endl;
	}

	// Phone validation
	while (true)
	{
		cout << "Enter you mobile number (11 digits): ";
		getline(cin, user.phone);
		//if (user.phone.length() == 11 && user.phone.find_first_not_of("01234567890") == string)
		if (user.phone.length() == 11 && user.phone.find_first_not_of("0123456789") == std::string::npos) {
}
			break;
		cout << "Invalid phone format." << endl;
	}
// Designation validation
	while (true)
	{
		cout << "Enter Designation (student/teacher/admin): ";
		getline(cin, user.designation);
		if (user.designation == "student" || user.designation == "teacher" || user.designation == "admin")
			break;
		cout << "Invalid designation. Must be 'student', 'teacher', or 'admin'." << endl;
	}

	// Role validation
	while (true)
	{
		cout << "Enter Role (at least 3 characters): ";
		getline(cin, user.role);
		if (user.role.length() >= 3)
			break;
		cout << "Invalid role format." << endl;
	}

	file << user.id << "\n"
		<< user.username << "\n"
		<< user.password << "\n"
		<< user.email << "\n"
		<< user.phone << "\n"
		<< user.designation << "\n"
		<< user.role << "\n";
	file.close();
	system("cls");
	cout << "Successfully registered! Your assigned ID is : " << user.id << endl;
	sleep(2);
	cout << " Plz wait! Process continuing in 3 seconds" << endl;
}
//____________________________________________________Function to login user_____________________________________________________________
void User_Login()
{
	system("cls");
	loginuser user;
	ifstream file("user.txt");
	if (!file)
	{
		cout << "Error! found while opening file." << endl;
		return;
	}
	cout << "Enter Username: ";
	getline(cin, user.username);
	cout << "Enter Password: ";
	getline(cin, user.password);
	string line;
	bool found = false;
	string designation;
	int id;
	while (getline(file, line))
	{
		id = stoi(line);
		string username, password, email, phone, desig, role;
		getline(file, username);
		getline(file, password);
		getline(file, email);
		getline(file, phone);
		getline(file, desig);
		getline(file, role);
		if (username == user.username && password == user.password)
		{
			found = true;
			designation = desig;            
			current_user_id = id; //to set user id.
			break;
		}
	}
	file.close();
	if (found)
	{
		cout << "Login successful!" << endl;
		cout << "Your designation is: " << designation << endl;
		sleep(2);
		cout << "Please wait! Process continuing " << endl;
		if (designation == "admin")
		{
			Admin_dashboard();
		}
		else if (designation == "teacher")
		{
			Teacher_dashboard();
		}
		else if (designation == "student")
		{
			Student_dashboard();
		}
		else
		{
	  cout << "Invalid designation!" << endl;
			sleep(2000);
					}
	}
	else
	{
		cout << "Invalid username or password!" << endl;
	 sleep(2000);
	}
}
//_____________________________________Admin Dashboard__________________________________
void Admin_dashboard()
{
system("cls");   // To clear console 
int choice;
do {
	cout << " Welcome to the Admin Dashboard!" << endl;
	cout << "1. Access Teacher dashboard" << endl;
	cout << "2. Update Info" << endl;
	cout << "3. Register New User" << endl;
	cout << "4. Generate User Credentials" << endl;
	cout << "5. Remove User" << endl;
	cout << "6. Search User" << endl;
	cout << "7. Exit" << endl;
	cin >> choice;
	switch (choice)
	{
	case 1:
		system("cls");
		cout << "Accessing Teacher Dashboard..." << endl;
		Teacher_dashboard();
		break;
	case 2:
		system("cls");
		cout << "Updating Information ....." << endl;
	 Update_information();
		break;
	case 3:
		system("cls");
		cout << "Registering New User   ..." << endl;
		function_to_register_user();
		break;
	case 4:
		system("cls");
		cout << "Generating User Credentials..." << endl;
		user_credentials();
		break;
	case 5:
		system("cls");
		cout << "Removing User..." << endl;
		//remove_user();
		break;
	case 6:
		system("cls");
		cout << "Exiting Admin Dashboard..." << endl;
		return;
	default:
		system("cls");
		cout << "Invalid choice! Please try again." << endl;
		break;
	}
} while (choice != 7);
}
//_______________________________________________Teacher Dashboard_____________________________________________________________
void Teacher_dashboard()
{
	int choice=1;
	for( ;choice!=6; )
		system("cls");
		cout << "Welcome to the teacher Dashboard!" << endl;
		cout << "1. Update info" << endl;
		cout << "2.create quizzes" << endl;
		cout << "3.edit existing quizzes" << endl;
		cout << "4.view student results" << endl;
		cout << "5.assign quiz to class" << endl;
		cout << "6.exit" << endl;
		cout << "Please enter your choice :";
		cin >> choice;
		cin.ignore();
		switch (choice)
		{
		case 1:
			system("cls");
			cout << "Updating Information..." << endl;
			Update_information();
			break;
		case 2:
			system("cls");
			cout << "Creating Quizzes..." << endl;
			quiz_creation();
			break;
		case 3:
			system("cls");
			cout << "Editing Existing Quizzes..." << endl;
			fun_to_edit_quiz();
			break;
		case 4:
			system("cls");
			cout << "Viewing Student Results..." << endl;
			result_quiz_fun();
			break;
		case 5:
			system("cls");
			cout << "Assigning Quiz to Class..." << endl;
			assign_quiz_to_student();
			break;
		case 6:
			system("cls");
			cout << "Exiting Teacher Dashboard..." << endl;
			return;
		default:
			system("cls");
			cout << "Invalid! choice try again " << endl;
			break;
		}
	}

//____________________________________________Function to create Quiz_________________________________________________________
void quiz_creation()
{
	system("cls");
	quiz_info quiz;
	ofstream file("quiz.txt", ios::app);
	if (!file)
	{
		cout << "Error found while opening file!" << endl;
		return;
	}
	cout << "Enter Quiz Title: ";
	getline(cin, quiz.quizName);
	cout << "Enter Subject: ";
	getline(cin, quiz.subject);
	cout << "Enter total Marks: ";
	cin >> quiz.marks;
	cin.ignore();
	for (int i = 0; i < 10; i++)
	{
		cout << "Enter Question " << (i + 1) << ": ";
		getline(cin, quiz.questions[i]);
		for (int j = 0; j < 4; j++)
		{
			cout << "Enter Option " << (j + 1) << ": ";
			getline(cin, quiz.options[i][j]);
		}
		cout << "Enter correct option (1-4): ";
		cin >> quiz.correct_answer[i];
		cin.ignore();
	}
	file << quiz.quizName << "\n"
		    << quiz.subject << "\n"
	    	<< quiz.marks << "\n";
	for (int i = 0; i < 10; i++)
	{
		file << quiz.questions[i] << "\n";
		for (int j = 0; j < 4; j++)
		{
			file << quiz.options[i][j] << "\n";
		}
		file << quiz.correct_answer[i] << "\n";
	}
	file.close();
	cout << "Quiz created successfully!" << endl;
	sleep(2000);
	cout << "Please wait! process countiouing" << endl;
}
//____________________________________________Function to edit quiz___________________________________________________________
	void fun_to_edit_quiz()
	{
	system("cls");
	string quiz_name;
	cout << "Please enter the name of the quiz you want to edit: ";
	getline(cin, quiz_name);

	ifstream infile("quiz.txt");
	if (!infile)
	{
		cout << "Error opening file!" << endl;
		return;
	}
	ofstream outfile("temp.txt");
	if (!outfile)
	{
		cout << "Error opening temp file!" << endl;
		infile.close();
		return;
	}

	bool found = false;
	while (true)
	{
		quiz_info quiz;
		//  Quiz name
		if (!getline(infile, quiz.quizName)) break;
		// Subject and marks
		if (!getline(infile, quiz.subject)) break;
		string marksStr;
		if (!getline(infile, marksStr)) break;
		quiz.marks = stoi(marksStr);
		for (int i = 0; i < 10; i++) 
		{
			if (!getline(infile, quiz.questions[i])) break;
			for (int j = 0; j < 4; j++) 
			{
				if (!getline(infile, quiz.options[i][j])) break;
			}
			string correctStr;
			if (!getline(infile, correctStr)) break;
			quiz.correct_answer[i] = stoi(correctStr);
		}

		if (quiz.quizName == quiz_name)
		{
			found = true;
			cout << "Quiz found. Editing quiz:..... " << quiz.quizName << endl;
			cout << "Enter new quiz name: ";
			getline(cin, quiz.quizName);
			cout << "Enter new subject: ";
			getline(cin, quiz.subject);
			cout << "Enter new marks: ";
			cin >> quiz.marks;
			cin.ignore();
			for (int i = 0; i < 10; i++)
			{
				cout << "Enter Question " << (i + 1) << ": ";
				getline(cin, quiz.questions[i]);
				for (int j = 0; j < 4; j++) 
				{
					cout << "Enter Option " << (j + 1) << ": ";
					getline(cin, quiz.options[i][j]);
				}
				cout << "Enter correct option (1-4): ";
				cin >> quiz.correct_answer[i];
				cin.ignore();
			}
		}
  
		// Write (possibly edited) quiz to temp file
		outfile << quiz.quizName << "\n"
			<< quiz.subject << "\n"
			<< quiz.marks << "\n";
		for (int i = 0; i < 10; i++) 
		{
			outfile << quiz.questions[i] << "\n";
			for (int j = 0; j < 4; j++) 
			{
				outfile << quiz.options[i][j] << "\n";
			}
			outfile << quiz.correct_answer[i] << "\n";
		}
	}

	infile.close();
	outfile.close();

	if (!found)
	{
		cout << "Quiz with name '" << quiz_name << "' not found." << endl;
		remove("temp.txt");
		return;
	}

	remove("quiz.txt");
	rename("temp.txt", "quiz.txt");
	cout << "Quiz has been edited successfully!" << endl;
	sleep(2000);
	cout << "Process Continuing. Plz wait! " << endl;
}


//________________________________________Function to update Information______________________________________________________
void Update_information()
{
	system("cls");
	if (current_user_id == -1){
		cout << "Currently no user is logged in" << endl;
		return;
	}
	int searchId = current_user_id;

	ifstream infile("user.txt");
	if (!infile)
	{
		cout << "Error found while opening file!" << endl;
		return;
	}
	ofstream outfile("temp.txt");
	if (!outfile)
	{
		cout << "Error found while opening temp file!" << endl;
		infile.close();
		return;
	}
	string line;
	bool found = false;

	while (getline(infile, line))
	{
		registration user;
		user.id = stoi(line);
		getline(infile, user.username);
		getline(infile, user.password);
		getline(infile, user.email);
		getline(infile, user.phone);
		getline(infile, user.designation);
		getline(infile, user.role);
		if (user.id == searchId)
		{
			found = true;
			cout << "User found. Please enter new details :" << endl;
			cout << "Current Username: " << user.username << "\n Enter your New Username: ";
			string input;
			getline(cin, input);
			if (!input.empty()) user.username = input;

			cout << "Current Password: " << user.password << "\nNew Password: ";
			getline(cin, input);
			if (!input.empty()) user.password = input;

			cout << "Current Email: " << user.email << "\nNew Email: ";
			getline(cin, input);
			if (!input.empty()) user.email = input;

			cout << "Current Phone: " << user.phone << "\nNew Phone: ";
			getline(cin, input);
			if (!input.empty()) user.phone = input;

			cout << "Current Designation: " << user.designation << "\nNew Designation: ";
			getline(cin, input);
			if (!input.empty()) user.designation = input;

			cout << "Current Role: " << user.role << "\nNew Role: ";
			getline(cin, input);
			if (!input.empty()) user.role = input;
		}
		outfile << user.id << "\n"
			<< user.username << "\n"
			<< user.password << "\n"
			<< user.email << "\n"
			<< user.phone << "\n"
			<< user.designation << "\n"
			<< user.role << "\n";
	}
	infile.close();
	outfile.close();

	if (!found)
	{
		cout << "User with ID " << searchId << " not found." << endl;
		sleep(2000);
		cout << "Continuing in 3 seconds" << endl;
		remove("temp.txt");
		return;
	}
}
//______________________________________________Student Dashboard_____________________________________________________________
void Student_dashboard(){
	int choice;
	do {
		system("cls");
		cout << "Welcome to the student Dashboard!" << endl;
		cout << "1.update info" << endl;
		cout << "2.view assigned quizzes" << endl;
		cout << "3.attempt quizzes" << endl;
		cout << "4.view results" << endl;
		cout << "5.view grades" << endl;
		cout << "6.exit" << endl;
		cout << "enter your choice" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
			system("cls");
			cout << "Updating Information ....." << endl;
			Update_information();
			break;
		case 2:
			system("cls");
			cout << "Viewing Assigned Quizzes....." << endl;
			fun_assigned_quiz_veiw();
			break;
		case 3:
			system("cls");
			cout << "Attempting Quizzes....." << endl;
			fun_quiz_attempt();
			break;
		case 4:
			system("cls");
			cout << "Viewing Results....." << endl;
			result_quiz_fun();
			break;
		case 5:
			system("cls");
			cout << "Viewing Grades....." << endl;
		 grades_quiz_fun();
			break;
		case 6:
			system("cls");
			cout << "Exiting Student Dashboard..." << endl;
			return;
		default:	
			system("cls");
			cout << "Invalid choice! Please try again." << endl;
			break;
		}


	} while (choice != 6);
}
//__________________________________________________________________Function to veiw assigned quiz 	____________________________________________________________
	void fun_assigned_quiz_veiw()
	{
	system("cls");
	int studentId;
	cout << "Enter your student ID to view assigned quizzes: ";
	cin >> studentId;
	cin.ignore();

	ifstream assignFile("assignments.txt");
	if (!assignFile)
	{
		cout << "Error opening assignments file!" << endl;
		return;
	}

	bool found = false;
	int fileStudentId;
	string quizName;
	while (assignFile >> fileStudentId)
	{
		assignFile.get(); // Skip the space
		getline(assignFile, quizName);
		if (fileStudentId == studentId)
		{
			cout << "Assigned Quiz: " << quizName << endl;
			sleep(2000);
			cout << "Process Continuing. Plz wait!" << endl;
			found = true;
		}
	}
	assignFile.close();

	if (!found) 
	{
		cout << "No quizzes assigned to student ID " << studentId << "." << endl;
		sleep(1);
		cout << "Process Continuing. Plz wait!" << endl;
	}
}
//____________________________________________________function to assign quiz to student. _______________________________________________________
void assign_quiz_to_student() 
{
	system("cls");
	int studentId;
	string quizName;
	cout << "Enter the student ID to assign the quiz: ";
	cin >> studentId;
	cin.ignore();
	cout << "Enter the quiz name to assign: ";
	getline(cin, quizName);
	bool studentFound = false;
	ifstream userFile("user.txt");
	string line;
	while (getline(userFile, line))
	{
		registration user;
		user.id = stoi(line);
		getline(userFile, user.username);
		getline(userFile, user.password);
		getline(userFile, user.email);
		getline(userFile, user.phone);
		getline(userFile, user.designation);
		getline(userFile, user.role);
		if (user.id == studentId && user.designation == "student")
		{
			studentFound = true;
			break;
		}
	}
	userFile.close();
	if (!studentFound) 
	{
		cout << "Student with ID " << studentId << " not found." << endl;
		sleep(1);
		cout << "Porcess Continuing. Plz wait!" << endl;
		return;
	}
	bool quizFound = false;
	ifstream quizFile("quiz.txt");
	while (getline(quizFile, line))
	{
		if (line == quizName) 
		{
			quizFound = true;
			break;
		}
	}
	quizFile.close();
	if (!quizFound) 
	{
		cout << "Quiz with name '" << quizName << "' not found." << endl;
		sleep(1);
		cout << "Process Continuing. Plz wait!" << endl;
		return;
	}

	ofstream assignFile("assignments.txt", ios::app);
	if (!assignFile)
	{
		cout << "Error opening assignments file!" << endl;
		return;
	}
	assignFile << studentId << " " << quizName << endl;
	assignFile.close();
	cout << "Quiz '" << quizName << "' assigned to student ID " << studentId << " successfully!" << endl;
	sleep(1);
		cout << "Process Continuing. Plz wait!" << endl;
}

	
//___________________________________________________________________attempt quiz_____________________________________________________________________
void fun_quiz_attempt() 
{
	system("cls");
	int studentId;
	string quizName;
	cout << "Enter your student ID: ";
	cin >> studentId;
	cin.ignore();
	cout << "Enter the quiz name you want to attempt: ";
	getline(cin, quizName);

	// Check if the quiz is assigned to the student
	ifstream assignFile("assignments.txt");
	if (!assignFile)
	{
		cout << "Error opening assignments file!" << endl;
		return;
	}
	bool assigned = false;
	int StudentId;
	string assignedQuizName;
	while (assignFile >> StudentId)
	{
		assignFile.get(); // skip space
		getline(assignFile, assignedQuizName);
		if (StudentId == studentId && assignedQuizName == quizName) {
			assigned = true;
			break;
		}
	}
	assignFile.close();

	if (!assigned)
	{
		cout << "You are not assigned this quiz or quiz does not exist." << endl;
		sleep(1);
		cout << "Process Continuing. Plz wait!" << endl;
		return;
	}

	// Find and load the quiz
	ifstream quizFile("quiz.txt");
	if (!quizFile)
	{
		cout << "Error opening quiz file!" << endl;
		return;
	}
	quiz_info quiz;
	bool found = false;
	while (getline(quizFile, quiz.quizName)) 
	{
		getline(quizFile, quiz.subject);
		string marksStr;
		getline(quizFile, marksStr);
		quiz.marks = stoi(marksStr);
		for (int i = 0; i < 10; i++) 
		{
			getline(quizFile, quiz.questions[i]);
			for (int j = 0; j < 4; j++) 
			{
				getline(quizFile, quiz.options[i][j]);
			}
			string correctStr;
			getline(quizFile, correctStr);
			quiz.correct_answer[i] = stoi(correctStr);
		}
		if (quiz.quizName == quizName)
		{
			found = true;
			break;
		}
	}
	quizFile.close();

	if (!found) 
	{
		cout << "Quiz not found in quiz file." << endl;
		return;
	}

	// Attempt the quiz
	int score = 0;
	int answer;
	cout << "Starting quiz: " << quiz.quizName << " (" << quiz.subject << ")" << endl;
	int timeLimit = 10; // seconds per question, adjust as needed

	for (int i = 0; i < 10; i++)
	{
		cout << "\nQ" << (i + 1) << ": " << quiz.questions[i] << endl;
		for (int j = 0; j < 4; j++)
		{
			cout << (j + 1) << ". " << quiz.options[i][j] << endl;
		}

		cout << "You have " << timeLimit << " seconds to answer." << endl;
		cout << "Enter your answer (1-4): ";

		 answer = 0;
		int elapsed = 0;
		bool answered = false;

		while (elapsed < timeLimit)
		{
			if (_kbhit())
			{
				char ch = _getch();
				if (ch >= '1' && ch <= '4')
				{
					answer = ch - '0';
					cout << answer << endl;
					answered = true;
					break;
				}
			}
			Sleep(1000);
			elapsed++;
		}

		if (!answered)
		{
			cout << "\nTime's up! Moving to next question." << endl;
		}
		else if (answer == quiz.correct_answer[i])
		{
			score++;
		}
	}

	cout << "\nQuiz completed!" << endl;
	cout << "Your score: " << score << " out of 10" << endl;
	ofstream resultsFile("results.txt", ios::app);
	if (resultsFile)
	{
		resultsFile << studentId << " " << quizName << " " << score << endl;
		resultsFile.close();
	}
	else 
	{
		cout << "Error saving results!" << endl;
	}
}


//__________________________________________________________________Quiz result ___________________________________________________________________
void 	result_quiz_fun() 
{
	system("cls");
	int studentId;
	cout << "Enter your student ID to view your quiz results: ";
	cin >> studentId;
	cin.ignore();

	ifstream resultsFile("results.txt");
	if (!resultsFile)
	{
		cout << "No quiz results found." << endl;
		sleep(1);
		cout << "Process Continuing. Plz wait!" << endl;
		return;
	}

	bool found = false;
	int fileStudentId, score;
	string quizName;
	while (resultsFile >> fileStudentId)
	{
		resultsFile >> quizName >> score;
		if (fileStudentId == studentId)
		{
			cout << "Quiz: " << quizName << " | Score: " << score << " out of 10" << endl;
			sleep(1);
		cout << "Process Continuing. Plz wait!" << endl;
			found = true;
		}
	}
	resultsFile.close();

	if (!found) 
	{
		cout << "No quiz results found for student ID " << studentId << "." << endl;
	sleep(1);
		cout << "Process Continuing. Plz wait!" << endl;
	}
}
//_________________________________________________Function to veiw quiz grades_______________________________________________
void grades_quiz_fun()
{
	system("cls");
	int studentId;
	cout << "Enter your student ID to view your quiz grades: ";
	cin >> studentId;
	cin.ignore();

	ifstream resultsFile("results.txt");
	if (!resultsFile)
	{
		cout << "No quiz results found." << endl;
		sleep(2000);
				cout << "Process continuing. Plz wait! " << endl;
		return;
	}

	bool found = false;
	int fileStudentId, score;
	string quizName;
	while (resultsFile >> fileStudentId)
	{
		resultsFile >> quizName >> score;
		if (fileStudentId == studentId)
		{
			char grade;
			if (score >= 9) grade = 'A';
			else if (score >= 7) grade = 'B';
			else if (score >= 5) grade = 'C';
			else if (score >= 3) grade = 'D';
			else grade = 'F';

			cout << "Quiz: " << quizName << " | Score: " << score << " out of 10 | Grade: " << grade << endl;
			found = true;
		}
	}
	resultsFile.close();

	if (!found) 
	{
		cout << "No quiz results found for student ID " << studentId << "." << endl;
		sleep(2000);
		cout << "Process Continuing. Plz wait! " << endl;
	}
} 
//______________________________________Function for user caredentials_________________________________________________________
void user_credentials() 
{
	system("cls");
	int searchId;
	cout << "Enter the ID of the user to display: ";
	cin >> searchId;
	cin.ignore();

	ifstream infile("user.txt");
	if (!infile)
	{
		cout << "Error opening file!" << endl;
		return;
	}

	string line;
	bool found = false;

	while (getline(infile, line))
	{
		registration user;
		user.id = stoi(line);
		getline(infile, user.username);
		getline(infile, user.password);
		getline(infile, user.email);
		getline(infile, user.phone);
		getline(infile, user.designation);
		getline(infile, user.role);

		if (user.id == searchId)
		{
			found = true;
			cout << "User Credentials:" << endl;
			cout << "ID: " << user.id << endl;
			cout << "Username: " << user.username << endl;
			cout << "Password: " << user.password << endl;
			cout << "Email: " << user.email << endl;
			cout << "Phone: " << user.phone << endl;
			cout << "Designation: " << user.designation << endl;
			cout << "Role: " << user.role << endl;
			sleep(2000);
		cout << "Process Continuing. Plz wait! " << endl;
			break;
		}
	}
	infile.close();

	if (!found) 
	{
		cout << "User with ID " << searchId << " not found." << endl;
		sleep(2000);
		cout << "Process Continuing. Plz wait! " << endl;
	}
}
//_________________________________________________Main Function ______________________________________________________________

int main()
{
	system("cls");
	int choice=1;
	for( ;choice!=3; ){
		cout << "   *******************************  Quiz Maker  *******************************  " << endl ;
		cout << "1. Admin" << endl;
		cout << "2. login "<< endl;
		cout << "3. Exit " << endl;
		cout << "Please enter your choice:  ";
		cin >> choice;
		cin.ignore();
		if (!(cin >> choice)) { 
    cin.clear();        
    cin.ignore(1000, '\n'); 
    cout << "Invalid input! PLease enter integers only." << endl;
    continue;           
   }
		
		switch (choice) 
		{
		case 1:
			function_to_register_user();
			break;
		case 2:
			User_Login();
			break;
		case 3:
			cout << "Exiting the program." << endl;
			break;
		default:
			cout << "Invalid choice! Please try again." << endl;
		}
	}
	return 0;
}