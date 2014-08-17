using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Business.Product
{
    public class Reader
    {
        public string FileName { get; set; }

        public Reader(string fileName)
        {
            FileName = fileName;
        }

        public Store.Product FindProduct(string barcode)
        {
            bool found = false;

            // Check if the item exists
            string fileContents = ReadFile();

            string[] c = {"\r", "\n"};
            string[] products = fileContents.Split(c, StringSplitOptions.RemoveEmptyEntries);

            char[] delimiter = {','};
            foreach (string s in products)
            {
                string[] temp = s.Split(delimiter);
                Store.Product product = new Store.Product()
                {
                     Barcode = temp[0],                      
                     Brand = temp[1],
                     Description = temp[2],
                     Price = Decimal.Parse(temp[3])
                };

                if(product.Barcode.Equals(barcode))
                {
                    found = true;
                    return product;
                }
            }

            return null;
        }

        public string ReadFile()
        {
            StreamReader reader = new StreamReader(FileName);
            reader.ReadLine(); // the first line is not necessary
            string fileContents = reader.ReadToEnd();
            reader.Close();
            return fileContents;
        }
    }
}