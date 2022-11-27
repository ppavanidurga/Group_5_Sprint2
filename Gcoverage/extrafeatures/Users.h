#define ZERO 0
#define ONE 1
#define THREE 3
#define MAXUSERS 100
#define FOUR 4
#define SEC 30
#define MINPH 1000000000
#define MAXPH 9999999999

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
	User users[MAXUSERS];
	int UsersCount=ZERO;
	Users();
        bool Login(string username,string password);
	void SignUp();
	void LoginWithRetrys();

};

