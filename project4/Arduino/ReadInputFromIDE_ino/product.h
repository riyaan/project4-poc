#ifndef product_h
#define product_h

class Product
{
  private:
    char* RFIDTag;
    char* Description;
    int Price;
  public:
	  Product() {}
	  Product(char* rfidTag, char* description, int price) { RFIDTag = rfidTag; Description = description; Price = price; }
	  ~Product() {}
    char* GetRFIDTag() { return RFIDTag; }
    void SetRFIDTag(char* value) { RFIDTag = value; } 

    char* GetDescription() { return Description; }
    void SetDescription(char* value) { Description = value; } 

    int GetPrice() { return Price; }
    void SetPrice(int value) { Price = value; } 
};

#endif
