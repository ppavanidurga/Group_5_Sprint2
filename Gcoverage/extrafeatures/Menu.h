#define ZERO 0
#define ONE 1
#define TWO 2
#define THREE 3
#define FOUR 4
#define FIVE 5
#define HUND 100

using namespace std;
class MenuItem
{
        public:
          string Name;
          int Price;
};
class CartItem
{
	public:
	  string Name;
	  int Qty;
	  int Price;
};
class Menu
{
public:
	bool IsAdmin=false;
	MenuItem items[HUND];
	CartItem cartItems[HUND];
	int cartItemsCount=ZERO;
	int ItemsCount=ZERO;
	Menu();
        void AddItemToCart();
	void DeleteItemToCart();
	void UpdateMenu();
	void AddMenu();
	void DeleteMenu();
	void UserTransistion();
	void AdminTransistion();
	void FeedbackForManagement();
	int SearchInMenu();

};

