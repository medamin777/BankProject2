#pragma once
#include "Person.h"
#include <vector>
#include <string>
#include <fstream>
#include "String.h"
using namespace std;
class User : public Person
{
private:
	enum Mode { EmptyMode = 1, UpdateMode = 2, AddMode = 3 };
	Mode   _Mode;
	string _Password;
	string _UserName;
	int    _Permession;
	bool   _MarKForDelete = false;
	static User _ConvertLineToUserObject(string Line, string sep = "#//#")
	{
		vector<string> vString = String::Split(Line, sep);
		return User(Mode::UpdateMode, vString[0], vString[1], vString[2], vString[3], vString[4], vString[5], stoi(vString[6]));
	}
	static string _ConvertObjectToLine(User user, string spe = "#//#")
	{
		string Line = "";
		Line += user.FirstName + spe;
		Line += user.LastName + spe;
		Line += user.Email + spe;
		Line += user.Phone + spe;
		Line += user.UserName + spe;
		Line += user.Password + spe;
		Line += to_string(user.GetPermession());
		return Line;
	}
	static vector<User>  _LoadUsersDataFromFile()
	{
		fstream Myfile;
		vector<User> Users;
		Myfile.open("User.txt", ios::in);
		if (Myfile.is_open())
		{
			string Line;
			while (getline(Myfile, Line))
			{
				Users.push_back(_ConvertLineToUserObject(Line));
			}
			Myfile.close();
		}
		return Users;
	}
	static void _SaveUsersDataToFile(vector<User> Users)
	{
		fstream Myfile;
		Myfile.open("User.txt", ios::out);
		if (Myfile.is_open())
		{
			for (User user : Users)
			{
				if (user._MarKForDelete == false)
					Myfile << _ConvertObjectToLine(user) << endl;
			}
			Myfile.close();
		}
	}
	
	void  _Add()
	{
		fstream Myfile;
		Myfile.open("User.txt", ios::out | ios::app);
		if (Myfile.is_open())
		{
			Myfile << _ConvertObjectToLine(*this) << endl;
			Myfile.close();
		}
	}
	void _Update()
	{
		vector<User> Users = _LoadUsersDataFromFile();

		for (User& user : Users)
		{
			if (user.UserName == this->UserName)
			{
				user = *this;
			}
		}
		_SaveUsersDataToFile(Users);
	}
	void _MarkForDelete()
	{
		_MarKForDelete = true;
	}
public:
	User(Mode Mode, string FirstName, string LastName, string Email, string Phone, string UserName, string Password, int Permession) :Person(FirstName, LastName, Email, Phone)
	{
		_Mode = Mode;
		_UserName = UserName;
		_Password = Password;
		_Permession = Permession;
	}
	bool IsEmpty()
	{
		return(_Mode == Mode::EmptyMode);
	}
	string GetPassword()
	{
		return _Password;
	}
	void SetPassword(string Password)
	{
		_Password = Password;
	}
	__declspec(property(get = GetPassword, put = SetPassword)) string Password;
	int GetPermession()
	{
		return _Permession;
	}
	void SetPermession(int Permession)
	{
		_Permession = Permession;
	}
	__declspec(property(get = GetPermession, put = SetPermession)) int Permession;
	string GetUserName()
	{
		return _UserName;
	}
	void SetUserName(string UserName)
	{
		_UserName = UserName;
	}
	__declspec(property(get = GetUserName, put = SetUserName)) string UserName;
	static User _GetEmpyObject()
	{
		return User(Mode::EmptyMode, "", "", "", "", "", "", 0);
	}
	static  User Find(string UserName)
	{
		fstream Myfile;
		Myfile.open("User.txt", ios::in);

		if (Myfile.is_open())
		{
			string Line;
			while (getline(Myfile, Line))
			{
				User user = _ConvertLineToUserObject(Line);
				if (user.UserName == UserName)
				{
					Myfile.close();
					return user;
				}
			}
		}
		return _GetEmpyObject();

	}
	static  User Find(string UserName, string Password)
	{
		fstream Myfile;
		Myfile.open("User.txt", ios::in);

		if (Myfile.is_open())
		{
			string Line;
			while (getline(Myfile, Line))
			{
				User user = _ConvertLineToUserObject(Line);
				if (user.UserName == UserName && user.Password == Password)
				{
					Myfile.close();
					return user;
				}
			}
		}
		return _GetEmpyObject();
	}
	static bool IsUserExist(string UserName)
	{
		return!(Find(UserName).IsEmpty());
	}
	bool Delete()
	{
		vector<User> Users = _LoadUsersDataFromFile();
		for (User& user : Users)
		{
			if (user.UserName == this->UserName)
			{
				user._MarkForDelete();
			}
		}
		_SaveUsersDataToFile(Users);
		*this = _GetEmpyObject();
		return true;
	}
	enum SaveResults { SaveFaild = 0, SaveSucced = 1 };
	SaveResults Save()
	{
		switch (_Mode)
		{
		case Mode::AddMode:
			_Add();
			_Mode = Mode::UpdateMode;
			return SaveResults::SaveSucced;
		case Mode::EmptyMode:
			return SaveResults::SaveFaild;
		case Mode::UpdateMode:
			_Update();
			return SaveResults::SaveSucced;
		}
	}
	static User GetAddNewUser(string UserName)
	{
		return User(Mode::AddMode, "", "", "", "", UserName, "", 0);
	}
	static vector<User> GetAllUsers()
	{
		return _LoadUsersDataFromFile();
	}		
	static enum ePermession { All = -1, ClientList = 1, AddClient = 2, DeleteClient = 4, UpdateClient = 8, FindClient = 16, TransactionMenue = 32, ManageUsers = 64 };
		bool CheckAccesPersmission(ePermession Permession)
		{
		if (this->_Permession == ePermession::All)
				return true;
		if ((this->_Permession & Permession) == Permession)
				return true;
		else
		
			return false;
		}
};

