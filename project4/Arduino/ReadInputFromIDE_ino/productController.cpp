#include "product.h"
#include <Logging.h>

#include <StandardCplusplus.h>
#include <vector>
using std::vector;

#include "productController.h"

vector<Product> tempVector;
vector<Product>::iterator it;

ProductController::ProductController() 
{
	Log.Info("Product Controller constructor");	
}

void ProductController::Initialize()
{
  Log.Info("ProductController - Initialize"CR);
  SetState(true);

	tempVector = GetProductList();
	it = tempVector.begin();
}

bool ProductController::AddProduct(int RFIDTag, char* Description, int Price)
{
  Log.Info("Adding product..."CR);
  Log.Debug("RFID Tag: %d"CR, RFIDTag);
  Log.Debug("Description: %s"CR, Description);
  Log.Debug("Price: R%d.00"CR, Price);
  
  Product product;
  product.SetRFIDTag(RFIDTag);
  product.SetDescription(Description);
  product.SetPrice(Price);

  it = tempVector.insert(it, product);

  Log.Info("List contains %d items."CR, tempVector.size());

  return true;
}