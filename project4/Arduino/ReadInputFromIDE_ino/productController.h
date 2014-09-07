#ifndef productController_h
#define productController_h

#include "product.h"
#include <StandardCplusplus.h>
#include <vector>
using std::vector;

class ProductController
{
  private:
    bool State;
    vector<Product> ProductList;
	vector<Product> AllShopProducts;

  public:
    ProductController();
    void Initialize();
    bool GetState() { return State; }
    bool SetState(bool value) { State = value; }
    bool AddProduct(char* RFIDTag, char* Description, int Price);
    bool RemoveProduct(char* RFIDTag);
	Product FindProductUsingRFIDTag(char* RFIDTag);
	Product FindProductInShoppingBasketUsingRFIDTag(char* RFIDTag);
	vector<Product> GetProductList() { return ProductList;  }

	// Shop functionality
	bool AddShopProducts();
	vector<Product> GetAllShopProducts() { return AllShopProducts;  }
};

#endif
