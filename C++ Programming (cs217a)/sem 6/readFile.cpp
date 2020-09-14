//Here is the vector loading function.

void readFile(ifstream& inData, int item_ID[], string item_Name[], int p_Ordered[], 
              double manuf_Price[], double selling_Price[], int& rows)
     {
         int position = 0;
         
         while(inData)
         {
                      item_ID.push_back(inData);
                  getline(inData, item_Name.push_back(inData);
                  inData >> p_Ordered[position] >> manuf_Price[position]
                         >> selling_Price[position];
                         
                         position++;
         }
         rows = item_ID.size();
     }
 
