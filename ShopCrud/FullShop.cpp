#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#include <fstream>
#include <iosfwd>


using namespace std;

//Validator functions
//__________________________________________________________________________________
//function to check if input string  contains any digits

bool has_any_digits (const std::string& s)
{
    return (s.find_first_of("0123456789") !=string::npos);
}    
//function to check if our number is greater then zero
bool is_greater_then_zero(const int &i)
{
	return  i >= 0 ? true : false;
}

//function to check if our number is less then 999999 (six digit max)
bool is_six_digit(const int&i)
{
	return i <= 999999 ? true : false;
}


//check if number is in 0..999999 range (six digit max)
bool is_zero_to_six_digit(const int&i)
{
	return  i > 0 ? (i <= 999999 ? true : false) : false;
}


//Template to read file into vector of pairs
template <typename T>
void fileReaderToVector(std::string &path, vector <pair<string, T>> &vec)
{
	ifstream File(path);
	std::string temp;
	T a;
	while (File>>a)
	{
		temp = a.getName();
		vec.emplace_back(make_pair(temp, a));
	}
	File.close();
}


//Template to read file into vector 
template <typename T>
void fileReadToVector(std::string &path, vector <T> &vec)
{
	ifstream File(path);
	T a;
	while (File>>a)
	{
		vec.emplace_back(a);

	}
	File.close();
}


class Shop
{
 private:
	std::string name;
    int number;

 public:
	Shop() {};
	Shop(std::string Name,  int Number)
	{
		this->name = Name;
		this->number = Number;

	}
	~Shop() {};

	friend	std::istream& operator >> (std::istream& is, Shop& sh)
	{

		is >> sh.name;
		is >> sh.number;
		return is;
	}

	friend	std::ostream& operator << (std::ostream& os, Shop& sh)
	{

		os << sh.getName() << "    " << sh.getNumber() << endl;
		return os;
	}

	//getters
	std::string getName()
	{
		return this->name;
	}
	 int getNumber()
	{
		return this->number;
	}


	 //-----------------------------------------------------------------------------------------------------//
	 //----------------------------------------Methods------------------------------------------------------//
	 //-----------------------------------------------------------------------------------------------------//

	//Add shops to the shoplist

	void shop_add()
	{
		int check = 1;		
		
		 while (check !=0)
		{    
			 system("cls");
			 vector <Shop> shoplist_add;
			 cout << "Input Data for Shops you wish to add in format as below" << endl;
			 cout << "Name shouldn't contain any digits" << endl;
			 cout<< " Number should be  positive and less then 6 digits" <<endl;
			 cout << "\nName  Number" << endl;

			    bool validator = false;
				Shop shop;
				cin >> shop;

				// Check if shop name doesn't contain any numbers and if  number is from 0 up to 6 digits
				if ( is_zero_to_six_digit(shop.getNumber()) && !has_any_digits(shop.getName()) )

				{
					validator = true;
					shoplist_add.push_back(shop);
					cout << "Added  " << shop.getName() << "  successfully"<<std::endl;				
					cout << "Writing new Shop data to the Shop list..." << std::endl;
					//open file in append mode to add new data
					ofstream outputFile("shoplist.txt", ios::app);
					for (auto &vsa : shoplist_add)
					{
						outputFile << vsa;
					}
					outputFile.close();
				
				}

				//check if incorect input format in the shop list
				else 
				{
					std::cout << "Enter shop data in correct format " << std::endl;
					std::cout << "Name shouldn't contain any digits, Number should be in (0...999999) range" << std::endl;
				}
			//clearing vector
			shoplist_add.clear();
			cout << "Continue input?\n1 - yes\t0 - no\n" << endl;
			cin >> check;
		 } 
	  

	}

	//Edit shops in shoplist
	void shop_edit()
   	{
		int loop_val = 1;
		while (loop_val != 0)
		{
			system("cls");
			std::vector < pair<std::string, Shop>> shop_vector_edit;
			std::string path = "shoplist.txt";
			std::string lookfor;
			bool checker = false;

			fileReaderToVector(path, shop_vector_edit);

			cout << "Enter the  name of the Shop you wish to modify in the shop list  " << endl;
			cin >> lookfor;

			for (auto &v : shop_vector_edit)
			{
				if (v.first == lookfor)
				{
					cout << "There is shop with name " << v.first << " .You can modify it" << std::endl;
					checker = true;
				}
			}

			// if name found in the file
			if (checker == true)
			{
				cout << "Please enter  input for   Product with name  " << lookfor << "  in format as listed below" << endl;
         		cout << "Name shouldn't contain any digits" << endl;
				cout << "Number should be positive and less then 6 digits" << endl;
                cout << "\nName    Number" << endl;
				bool validator = false;
				Shop sh;
				cin >> sh;

				// Check if shop name doesn't contain any numbers and if  number is from 0 up to 6 digits
				if (is_zero_to_six_digit(sh.getNumber()) && !has_any_digits(sh.getName()))
				{
					validator = true;
				
					//lambda predicate				
				  
					for (auto const &vecx : shop_vector_edit)
					{
						if (vecx.first == lookfor)
						{					


							auto pred = std::remove_if
							(
								shop_vector_edit.begin(),
								shop_vector_edit.end(),
								[&lookfor](std::pair<string, Shop> const& data)
							{
								if (data.first == lookfor) return true;
								else return false;
							}
							);
							//erase from vector if predicate is true
							shop_vector_edit.erase(pred, shop_vector_edit.end());
													
							// put edited element in the vector
							shop_vector_edit.emplace_back(make_pair(lookfor, sh));						
							

						}

					}
					
                    // Displaying Shop list after editing
					cout << "\nShop list after editing";
					for (auto &scve : shop_vector_edit)
					{
					    cout <<scve.second << endl;

					}
					
					//input into file edited entry
					std::ofstream outFile(path);
					for (auto &vse : shop_vector_edit) { outFile << vse.second; }
					cout << "Finished modifying file with new  " << lookfor << "  values";
					outFile.close();
				}
				//check if incorect input format in the shop list
				else 
				{
					std::cout << "Enter shop data in correct format " << std::endl;
					std::cout << "Name shouldn't contain any digits, Number should be in (0...999999) range" << std::endl;
				}

			}

			// if name not found in the file
			if (checker == false)
			{
				cout << "There are no products with " << lookfor << " name in the Product list" << std::endl;
			}
				cout << "\n Continue editing in Shop list?\n1 - yes\t0 - no\n" << endl;
				shop_vector_edit.clear();
				cin >> loop_val;
		}
	};

	//Delete shops in shoplist
	void shop_remove()
	{
		int loop_val = 1;
		while (loop_val != 0)
		{

			system("cls");
			std::vector < pair<std::string, Shop>> shop_vector_remove;
			std::string path = "shoplist.txt";
			std::string lookfor;
			bool checker = false;
			
			//read Shop list to vector
			fileReaderToVector(path, shop_vector_remove);

			cout << "Enter name of the shop you wish to remove from the shop list   " << endl;
			cin >> lookfor;

			for (auto &v : shop_vector_remove)
			{
				if (v.first == lookfor)
				{
					cout << "There is shop with name   " << v.first << "  .Deleting it"<<std::endl;
					checker = true;
				}
			}			

			//if Name found in the file
			if (checker == true)
			{
				
				//lambda predicate
				auto pred = std::remove_if
				    (
						shop_vector_remove.begin(),
						shop_vector_remove.end(),
						[lookfor](std::pair<string, Shop> const& data) 
					  {
						if (data.first==lookfor) return true;
						else return false;
					   }
				     );
				    //erase from vector if predicate is true
					shop_vector_remove.erase(pred, shop_vector_remove.end());


					//renew file  with  renewed vector 
					std::ofstream outFile(path);
					for (auto &svr : shop_vector_remove) { outFile << svr.second; }
					cout << "Finished deleting  "<<lookfor<<std::endl;
					outFile.close();					
			}

			//if there is no such Name in our file
			if (checker == false)
			{
			cout << "There are no shops with " << lookfor << " name in the Shop list" << std::endl;
			}

			cout << "\n Continue with delete in the Shop List?\n1 - yes\t0 - no\n" << endl;
			shop_vector_remove.clear();
			cin >> loop_val;
		}

			
	}
	



	// Display shops in shoplist
   	void shop_display()
	{
		//string line;
		int checker=1;
		while (checker != 0)
		{
			system("cls");
			std::string line;
			std::ifstream inFile("shoplist.txt");
			if (!inFile.is_open()) 
			{
				std::cout << "Can't open file";
				exit(1);
			}
			
			while (getline(inFile, line))
			{
				cout << line << endl;
			}
			inFile.close();
			
			cout << "\n\nContinue display Shop List?\n1 - yes\t0 - no\n";
			cin >> checker;
			
		}

	}

	

};



class Product
{
	//class fields
private:
	std::string  name;
	std::string  date;
	std::string  measurement;
	int typecode;
	int checknumber;
	int price;
	int quantity;
	long int totalprice;

public:
	//class constructors
	

	//custom constructors
	Product() {};
	Product(std::string Name, std::string Date, std::string Measurement, int Typecode, int Checknumber, int Price, int Quantity, long int TotalPrice)
	{
		this->name = Name;
		this->date = Date;
		this->measurement = Measurement;
		this->typecode = Typecode;
		this->checknumber = Checknumber;
		this->price = Price;
		this->quantity = Quantity;
		this->totalprice = getQuantity()*getPrice();
	};

	//Class destructor
	~Product() {};

	// getter methods
	string getName()
	{
		return this->name;
	}

	int getTypeCode()
	{
		return this->typecode;
	}
	int getCheckNumber()
	{
		return this->checknumber;
	}
	int getPrice()
	{
		return this->price;
	}

	int getQuantity()
	{
		return this->quantity;
	}


	//overload of cin  operator for custom class for input
	friend std::istream& operator >> (std::istream& is, Product& p) 
	{
		
		is >> p.name >> p.date >> p.measurement >> p.typecode >> p.checknumber >> p.price >> p.quantity >> p.totalprice;
		p.totalprice = p.price*p.quantity;
		return is;
	}

	//overload of cout operator for custom class for output
	friend std::ostream& operator << (std::ostream& os, Product& p)
	{
		os << p.name << "  " << p.date << "  " << p.measurement << "  "<<p.typecode 
			<< "  " << p.checknumber << "  " << p.price << "  " <<p.quantity << "  " << p.totalprice << " " << std::endl;
		return os;
	}


	//-----------------------------------------------------------------------------------------------------//
	//----------------------------------------Methods------------------------------------------------------//
	//-----------------------------------------------------------------------------------------------------//
	
	//Add  new Product to the Product list
	void product_add()
	{
		int check = 1;
		
		while (check != 0)
		{
			system("cls");
			bool validator;
			//create vector of Products
			std::vector <Product> productlist_add;
			cout << " Add Product to the Product list in format as below" << endl;
			cout << "Name must not contain any numbers" << endl;
			cout << "All digits	must be positive" << endl;
			cout << "Checknumber,TypeCode should be  less then 6 digits " << endl;
			cout << "\nName Date Measurement TypeCode CheckNumber Price Quantity TotalPrice" << endl;

			//Read new Product to add to the Product list
			Product prdct;
			cin >> prdct;

			//Check if our product name  doesn't contain numbers and numbers are greater then zero
			//and Checknumber,TypeCode are less then 6 digits


			if ( !has_any_digits(prdct.getName()) &&
				is_zero_to_six_digit(prdct.getCheckNumber()) &&
				is_zero_to_six_digit(prdct.getTypeCode()) &&
				is_greater_then_zero(prdct.getPrice()) &&
				is_greater_then_zero(prdct.getQuantity()) )

			{
				productlist_add.push_back(prdct);
				cout << "Added " << prdct.getName() << "  successfully" << std::endl;
				validator = true;
			}
 
			if (validator = true)
			{
				// Write to file only after input is finished in append mode, so we add new data
				ofstream outputFile("productlist.txt", ios::app);

				//output data from vector into file
				for (auto &vpa : productlist_add)
				{
					outputFile << vpa;
				}
				cout << "Writing values to Product list..." << std::endl;
				//closing file
				outputFile.close();
			}

			//check if incorect input format in the product list
			else 
			{
				std::cout << "Enter Product data in the correct format " << std::endl;
				cout << "Name must not contain any numbers must be positive" << endl;
				cout << " Checknumber,TypeCode should be  less then 6 digits " << endl;

			}
			
			//clearing vector
			productlist_add.clear();
			//continue console input marker
			std::cout << "Continue adding Products?\n1 - yes\t0 - no\n" << endl;
			std::cin >> check;
		}

		
	}

	//edit products in the product list
	void product_edit()
	{
		int loop_val = 1;
		while (loop_val != 0)
		{
			system("cls");
			std::vector < pair<std::string, Product>> product_vector_edit;
			std::string path = "productlist.txt";
			std::string lookfor;
			bool checker = false;

			fileReaderToVector(path, product_vector_edit);

			cout << "Enter the name of  the product you wish to modify in the product list    " << endl;
			cin >> lookfor;

			for (auto &v : product_vector_edit)
			{
				if (v.first == lookfor)
				{
					cout << "There is product with name  " << v.first << " .  You can modify it" << std::endl;
					checker = true;
				}
			}


			if (checker == true)
			{
				    bool validator=false;
					cout << "Enter data you wish to change   " << lookfor << "  values in the Product list in format as below" << endl;
			    	cout <<"Name must not contain any numbers"<<endl;
					cout<<"All digits must be positive" << endl;
					cout <<"Checknumber and TypeCode should be  less then 6 digits " << endl;
					cout << "\nName Date Measurement TypeCode CheckNumber Price Quantity TotalPrice" << endl;
					Product pr;
					cin >> pr;
					
					//Check if our product name  doesn't contain numbers and numbers are greater then zero
				    //and Checknumber,TypeCode are less then 6 digits
					if (!has_any_digits(pr.getName()) &&
						is_zero_to_six_digit(pr.getCheckNumber()) &&
						is_zero_to_six_digit(pr.getTypeCode()) &&
						is_greater_then_zero(pr.getPrice()) &&
						is_greater_then_zero(pr.getQuantity()))
					{
						validator = true;
	
						//lambda predicate				

						for (auto const &vecz : product_vector_edit)
						{
							if (vecz.first == lookfor)
							{


								auto pred = std::remove_if
								(
									product_vector_edit.begin(),
									product_vector_edit.end(),
									[&lookfor](std::pair<string, Product> const& data)
								{
									if (data.first == lookfor) return true;
									else return false;
								}
								);

								//erase from vector if predicate is true
								product_vector_edit.erase(pred, product_vector_edit.end());

								// put edited element in the vector
								product_vector_edit.emplace_back(make_pair(lookfor, pr));

							}
						}
								// Displaying edited Product list
								cout << "\nShop list after editing ";
								for (auto &pcve : product_vector_edit)
								{
									cout <<  pcve.second;

								}


						//edit values in the file
						std::ofstream outFile(path);
						for (auto &vpe : product_vector_edit) { outFile << vpe.second; }
						cout << "Finished modifying file with new values";
						outFile.close();
					}

					//check if incorect input format in the product list
					else 
					{
						cout << "Enter Product data in the correct format " << endl;
						cout << "Name must not contain any numbers must be positive" << endl;
						cout << "Checknumber,TypeCode should be  less then 6 digits " << endl;
					}
				
			}

			if (checker == false)
			{
				cout << "There are no products with " << lookfor << " name in the Product list" << std::endl;
			}
			product_vector_edit.clear();
			cout << "\n Continue with editing in Product List?\n1 - yes\t0 - no\n";
			cin >> loop_val;
		}
	}




	//remove products from the productlist
	void product_remove()
	{
		int loop_val = 1;
		while (loop_val != 0)
		{
			system("cls");
			std::vector < pair<std::string, Product>> product_vector_remove;
			std::string path = "productlist.txt";
			std::string lookfor;
			bool checker = false;

			fileReaderToVector(path, product_vector_remove);

			//Check if name exists in file
			cout << "Enter  name of the product you wish to  remove from the Product list      " << endl;
			cin >> lookfor;

			for (auto &pvrx : product_vector_remove)
			{
				if (pvrx.first == lookfor)
				{
					cout << "There is product with name " << pvrx.first << "  in the product list.  Deleting it..";
					checker = true;
					//true if such name exists in file
				}
			}

			//if there is such Name in our file delete it
			if (checker == true)
			{
					//lambda predicate
					auto pred = std::remove_if
					(
						product_vector_remove.begin(),
						product_vector_remove.end(),
						[&lookfor](std::pair<string, Product> const& data)
					{
						if (data.first == lookfor) return true;
						else return false;
					}
					);
					//erase from vector if predicate is true
					product_vector_remove.erase(pred,product_vector_remove.end());

					// put new values to file after delete
					std::ofstream outFile(path);
					for (auto&vpr : product_vector_remove) { outFile << vpr.second; }
					cout <<" Finished deleting product   " << lookfor << std::endl;
					outFile.close();
			}

				//if there is no such Name in our file
				if (checker == false)
				{
					cout << "There are no products with " << lookfor << "  name in the Product list" << std::endl;

				}

			product_vector_remove.clear();
			cout << "\n Continue with delete in Product List?\n1 - yes\t0 - no\n";
			cin >> loop_val;
		}


	}

	// Display products in the product list
	void product_display()
	{
		int checker = 1;
		while (checker != 0)
		{
			string line;
			system("cls");
			std::ifstream inFile("productlist.txt");
			if (!inFile.is_open())
			{
				std::cout << "Can't open file";
				exit(1);
			}
			cout << "\n   Product data: " << std::endl;
			cout << "\nName|Type|Date|Measurement|CheckNumber| Price|Quantity|TotalPrice|" << std::endl;
	

			while (getline(inFile, line))
			{
				cout << line << endl;
			}
			//closing file 
			inFile.close();
			//check if continue output
			cout << "\n\nContinue output?\n1 - yes\t0 - no\n";
			cin >> checker;

		}
	}

	
	
};


class Starter {
public:

	void Start()
	{
		//create class instances on the heap

		Shop *shp = new Shop();
		Product *prd = new Product();

	
		int choice = -1;
		do
		{
			
		menu:
			system("cls");
			cout << "Menu:";
			cout << "\n0 - Exit";
			cout << "\n1 - Shop operations";
			cout << "\n2 - Product operations\n";
			int menuchoice = -1;
			cin >> menuchoice;
			


			if (menuchoice == 0)
				{
					exit(1);
				}
				if (menuchoice == 1)
				{
					int shopchoice = -1;
					while (true)
					{
						system("cls");
						cout << "Shop info:";
						cout << "\n0 - Back to menu";
						cout << "\n1 - Add shop";
						cout << "\n2 - Edit shop";
						cout << "\n3 - Delete shop";
						cout << "\n4 - Display shops\n";
						cin >> shopchoice;

						if (shopchoice == 0)
						{
							goto menu;
						}
						if (shopchoice == 1)
						{
							shp->shop_add(); 
						}

						if (shopchoice == 2)
						{
							shp->shop_edit(); 
						}

						if (shopchoice == 3)
						{
							shp->shop_remove(); 
						}
						if (shopchoice == 4)
						{

							shp->shop_display(); 
						}

						else
						{
							continue;
						}

					}
				}

				if (menuchoice == 2)
				{
					int productchoice = -1;
					while (true)
					{
						system("cls");
						cout << " Input Product info:";
						cout << "\n0 - Back to menu";
						cout << "\n1 - Add product";
						cout << "\n2 - Edit product";
						cout << "\n3 - Delete product";
						cout << "\n4 - Display products \n";
						cin >> productchoice;

						if (productchoice == 0)
						{
							goto menu;
						}

						if (productchoice == 1)
						{
							prd->product_add(); 

						}

						if (productchoice == 2)
						{
							prd->product_edit(); 
						}
						if (productchoice == 3)
						{
							prd->product_remove(); 

						}
						if (productchoice == 4)
						{
							prd->product_display(); 
						}
						else 
						{
							continue;
						}

					}
				}

				else
				{
					continue;
				}

			
		}
		while (choice != 0);

		delete prd, shp;
	}

};


int main()
{
	//Allocate Starter class on the heap
	Starter* st = new Starter();

	//after creating instance of Starter we call static Start Method 
	//All logic incapsulated inside Starter class
	st->Start();
	
	//calling destructor to clear memory
	delete st;
	return 0;
}











