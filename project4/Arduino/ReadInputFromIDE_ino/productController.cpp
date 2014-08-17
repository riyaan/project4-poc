#include <Logging.h>
#include "productController.h"

Product ProductList[MAX];

ProductController::ProductController()
{;}

void ProductController::Initialize()
{
  Log.Info("Begin ProductController Initializing... "CR);
  Log.Info("Set the state "CR);
  SetState(true);
}

bool ProductController::AddProduct(int RFIDTag, char* Description, float Price)
{
  Log.Info("Adding product."CR);
  Log.Debug("RFID Tag: %d"CR, RFIDTag);
  Log.Debug("Description: %s"CR, Description);
  Log.Debug("Price: %d"CR, Price);
  
  Product product;
  product.SetRFIDTag(RFIDTag);
  product.SetDescription(Description);
  product.SetPrice(Price);
  
  return AddItemToList(product);
}

bool ProductController::AddItemToList(Product product)
{
  Product* list = GetAllProducts();  
  int element_count = sizeof(list)/sizeof(Product);
  
  Log.Debug("There are %d items in the basket"CR, element_count);
  
  if(element_count > 0)
  {
      list[element_count-1] = product;
  }
  return true;
}
    //bool RemoveProduct(int RFIDTag);
    //Product* GetAllProducts();
