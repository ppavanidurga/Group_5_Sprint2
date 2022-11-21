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
	MenuItem items[100];
	CartItem cartItems[100];
	int cartItemsCount=0;
	int ItemsCount=0;
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

