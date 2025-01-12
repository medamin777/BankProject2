#pragma once
#include "User.h"
#include "Date.h"
#include "Global.h"
#include "String.h"
#include <fstream>
class LoginUser:public User
{
private:
	string _Time;
	static string _PerepareLogin(string sep="#//#")
	{
		string Line;
		Line += date::GetSystemAll() + sep;
		Line += CurrentUser.UserName + sep;
		Line +=CurrentUser.Password + sep;
		Line += to_string(CurrentUser.Permession);
		return Line;
	}
	static LoginUser _ConvertLinetoObject(string Line,string sep="#//#")
	{
		vector<string> vString = String::Split(Line, sep);
		return LoginUser(vString[0], vString[1], vString[2], stoi(vString[3]));
	}
public:
	LoginUser(string Time, string UserName, string Password, int Permession) :User(UserName, Password, Permession)
	{
		_Time = Time;
	}

	string getTime()
	{
		return _Time;
	}
	string getUserName()
	{
		return UserName;
	}
	string getPassword()
	{
		return Password;
	}
	int getPermession()
	{
		return Permession;
	}
	static void RegisterLogin()
	{
		fstream Myfile;
		Myfile.open("RegisterLogin.txt", ios::out | ios::app);
		if (Myfile.is_open())
		{
			Myfile << _PerepareLogin() << endl;
			Myfile.close();
		}
	}
	static vector<LoginUser> GetAllLoginUsers()
	{
		fstream Myfile;
		vector<LoginUser> LoginUsers;
		Myfile.open("RegisterLogin.txt", ios::in);
		if (Myfile.is_open())
		{
			string Line;
			while (getline(Myfile, Line))
			{
				LoginUsers.push_back(_ConvertLinetoObject(Line));
			}
			Myfile.close();
		}
		return LoginUsers;
	}


};

