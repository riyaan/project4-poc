#include "product.h"
#include <Logging.h>
#include <StandardCplusplus.h>
#include <vector>
#include "productController.h"

using std::vector;

vector<Product> tempVector;
vector<Product>::iterator it;

vector<Product> shopVector;
vector<Product>::iterator shopIt;

vector<Product> ProductController::GetProductList() 
{
	return tempVector;
}

ProductController::ProductController() 
{
	//Log.Info("Product Controller constructor");	
}

void ProductController::Initialize()
{
	Log.Info("ProductController - Initialize"CR);
	SetState(true);	

	tempVector = GetProductList();
	it = tempVector.begin();

	shopVector = GetAllShopProducts();
	shopIt = shopVector.begin();

	AddShopProducts();
}

bool ProductController::AddShopProducts()//(char* RFIDTag, char* Description, int Price)
{ 
	//Log.Info("AddProductsToShop"CR);

	Product whiteSugar("8500908889", "Isha - HTC compatible cellphone charger", 400);
	Product regularCoke("8500904E47", "Cepacol - Lozenges - Blackcurrant Flavour", 29);
	Product omo("17001FBEAF", "Canon EF 50mm f/1.8 II Lens", 1295);

  shopIt = shopVector.insert(shopIt, whiteSugar);
  shopIt = shopVector.insert(shopIt, regularCoke);
  shopIt = shopVector.insert(shopIt, omo);

  return true;
}

bool ProductController::AddProduct(char* RFIDTag, char* Description, int Price)
{ 
  Product product;
  product.SetRFIDTag(RFIDTag);
  product.SetDescription(Description);
  product.SetPrice(Price);

  it = tempVector.insert(it, product);

  //Log.Info("List contains %d items."CR, tempVector.size());

  return true;
}

bool ProductController::RemoveProduct(char* RFIDTag)
{
	it = tempVector.begin();

	for(int i=0; i<tempVector.size(); i++)
	{
		if(tempVector[i].GetRFIDTag() == RFIDTag)	
		{
			tempVector.erase(tempVector.begin()+i);

			//Log.Info("Item removed."CR);
			return true;
		}
	}

	return false;
}

Product ProductController::FindProductUsingRFIDTag(char* RFIDTag, bool queryShopInventory)
{
	//Log.Info("FindProductUsingRFIDTag Begin"CR);

	vector<Product> temp;
	if(queryShopInventory)
		temp = shopVector;
	else
		temp = tempVector;

	for(int i=0; i<temp.size(); i++)
	{
		char* rfidTag = temp[i].GetRFIDTag();
		if(strcmp(rfidTag, RFIDTag) == 0)	
		{
			//Log.Info("Match found."CR);			
			return temp[i];			
		}
	}
	
	//Log.Info("FindProductUsingRFIDTag End"CR);

	// A quick work-around as you cannot return a null object only a null pointer.
	Product product; product.SetRFIDTag("-1"); 	product.SetDescription("-1"); 	product.SetPrice(1);

	return product;
}