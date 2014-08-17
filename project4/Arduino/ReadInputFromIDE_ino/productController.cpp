#include "productController.h"

ProductController::ProductController()
{;}

void ProductController::Initialize()
{
  SetState(true);
}

bool ProductController::AddProduct(int RFIDTag, char* Description, float Price)
{
  Product product;
  product.SetRFIDTag(RFIDTag);
  product.SetDescription(Description);
  product.SetPrice(Price);

  Product * list = GetAllProducts();
  int element_count = sizeof(list)/sizeof(Product);
  
  
}
    //bool RemoveProduct(int RFIDTag);
    //Product* GetAllProducts();
