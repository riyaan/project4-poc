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

  public:
    ProductController();
    void Initialize();
    bool GetState() { return State; }
    bool SetState(bool value) { State = value; }
    bool AddProduct(int RFIDTag, char* Description, int Price);
    bool RemoveProduct(int RFIDTag);
	vector<Product> GetProductList() { return ProductList;  }

};

#endif
