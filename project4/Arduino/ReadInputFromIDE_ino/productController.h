#ifndef productController_h
#define productController_h

#include "product.h"

const int MAX = 30;

class ProductController
{
  private:
    bool State;
    Product ProductList[MAX];
  public:
    ProductController();
    void Initialize();
    bool GetState() { return State; }
    bool SetState(bool value) { State = value; }
    
    bool AddProduct(int RFIDTag, char* Description, float Price);
    bool RemoveProduct(int RFIDTag);
    Product * GetAllProducts();
};

#endif
