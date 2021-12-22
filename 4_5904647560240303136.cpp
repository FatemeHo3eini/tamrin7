
#include<iostream>
#include<string>
#include<fstream>

using namespace std;

int n,choice = 0,k=0;
struct product_info{
	int id = 0;
	string name = "";
	int price = 0;
	int count = 0;
}*products;

void menu();
void show_list();
void load();
int main(){
	cout << "Enter number products: ";
	cin >> n;
	ofstream Product_info;
	Product_info.open("products.txt");
	Product_info << "100,apple,30000,40" << endl;
	Product_info << "101,mango,40000,20" << endl;
	Product_info << "103,watermelone,5000,100";
	Product_info.close();

	products = new product_info[n];

	while (choice != 7){
		load();
		menu();
		switch (choice){
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			show_list();
			break;
		case 6:
			break;
		}
	}
	return 0;
}

void show_list(){
	for (int i = 0; i < n; i++) {
		cout << "Product " << i + 1 << ":" << endl;
		cout << "id:" << products[i].id << endl;
		cout << "name:" << products[i].name << endl;
		cout << "price:" << products[i].price << endl;
		cout << "count:" << products[i].count << endl;
	}
}
void load(){
	string line;
	ifstream Product_info;
	Product_info.open("products.txt");
	while (getline(Product_info, line))
	{
		string array[4];
		int j = 0;
		for (int i = 0; i < line.length(); i++)
		{
			if (line[i] != ',')
				array[j] = array[j] + line[i];
			if(line[i]==',' || i == line.length()-1){
				switch (j){
				case 0:
					products[k].id = stoi(array[j]);
					break;
				case 1:
					products[k].name = array[j];
					break;
				case 2:
					products[k].price = stoi(array[j]);
					break;
				case 3:
					products[k].count = stoi(array[j]);
					break;
				}
				j++;
			}
		}
		k++;
	}
	Product_info.close();
}
void menu(){
	int choice;
	cout << "\tSTORE MENU\n1-Add Product\n2-Edit Product\n3-Delete Product\n4-Search\n5-Show list\n6-Buy\n7-Exit\n";
	cin >> choice;
}
