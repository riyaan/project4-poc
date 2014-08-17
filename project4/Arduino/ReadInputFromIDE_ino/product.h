#ifndef product_h
#define product_h

class Product
{
  private:
    int RFIDTag;
    char* Description;
    float Price;
  public:
    Product();
    int GetRFIDTag() { return RFIDTag; }
    void SetRFIDTag(int value) { RFIDTag = value; } 

    char* GetDescription() { return Description; }
    void SetDescription(char* value) { Description = value; } 

    float GetPrice() { return Price; }
    void SetPrice(int value) { Price = value; } 
};

#endif
