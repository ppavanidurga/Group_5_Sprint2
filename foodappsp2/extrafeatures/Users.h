#define ones 1
#define thrice 3
#define maxusers 100
#define four 4
#define sec 30

using namespace std;
class User
{
        public:
          string UserName;
          string Password;
          bool IsAdmin;
};
class Users
{
public:
	bool IsAdmin=false;
	bool LoginSuccess=false;
	string UserName;
	User users[maxusers];
	int UsersCount=0;
	Users();
        bool Login(string username,string password);
	void SignUp();
	void LoginWithRetrys();

};

