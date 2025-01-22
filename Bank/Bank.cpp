#include "LoginScreen.h"

using namespace std;
int main()
{
	
	while (true)
	{
		if (!LoginScreen::ShowLogin())
			break;
	}
	system("pause>0");
	return 0;

}