//Here is the sorting function.

void itemSort(int item_Names[], string item_Num[], int p_Order[], double man_Price[],
     double sell_Price[], int rows)
{
     int firstOutOfOrder, location;
     int temp1, temp2, temp3, temp4, temp5;
     // make sure "rows" updated in main to compare this to.             
     for(firstOutOforder = 1; firstOutOfOrder < rows; firstOutOfOrder++)
        if(item_Names[firstOutOfOrder] < item_Names[firstOutOfOrder-1])
        {
            temp1 = item_Names[firstOutOfOrder];
            temp2 = item_Num[firstOutOfOrder];
            temp3 = p_Order[firstOutOfOrder];
            temp4 = man_Price[firstOutOfOrder];
            temp5 = sell_Price[firstOutOfOrder];
            location = firstOutOfOrder;
            
            do
            {
                item_Names[location] = item_Names[location - 1];
                item_Num[location] = item_Num[location - 1];
                p_Order[location] = p_Order[location - 1];
                man_Price[location] = man_Price[location - 1];
                sell_Price[location] = sell_Price[location - 1];
                location--;
            }
            while(location > 0 && item_Names[location - 1] > temp1);
            
            item_Names[location] = temp1;
            item_Num[location] = temp2;
            p_Order[location] = temp3;
            man_Price[location] = temp4;
            sell_Price[location] = temp5;
            
        }
}// end itemSort           
