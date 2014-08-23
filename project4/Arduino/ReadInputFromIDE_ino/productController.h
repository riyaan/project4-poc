#ifndef productController_h
#define productController_h

#include <StandardCplusplus.h>
#include <vector>

#include "product.h"

const int MAX = 30;

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
    
    bool AddItemToList(Product product);
    
    bool AddProduct(int RFIDTag, char* Description, int Price);
    bool RemoveProduct(int RFIDTag);
    vector<Product> GetAllProducts() { return ProductList; }
};

#endif
