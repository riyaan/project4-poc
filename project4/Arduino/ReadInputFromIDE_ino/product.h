#ifndef product_h
#define product_h

class Product
{
  private:
    int RFIDTag;
    char* Description;
    int Price;
  public:
	  Product() {}
	  ~Product() {}
    int GetRFIDTag() { return RFIDTag; }
    void SetRFIDTag(int value) { RFIDTag = value; } 

    char* GetDescription() { return Description; }
    void SetDescription(char* value) { Description = value; } 

    int GetPrice() { return Price; }
    void SetPrice(int value) { Price = value; } 
};

#endif
