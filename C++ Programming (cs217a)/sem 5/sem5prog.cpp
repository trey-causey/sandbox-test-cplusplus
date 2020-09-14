/*This program will input student test scores from a file.
The scores will be placed in one of eight categories.
The program will write the results into a file.*/
#include<iostream>
#include<fstream>

using namespace std;

// declare functions
void readScore(ifstream& inputScore, int theScore, int array[]);
void outputScore(ofstream& outputScore, int count, int lastArray[]); 

int main() // main function
{
    int scoreArray[8]; // orginal array
    int scores;
    int counter;
    ifstream inScore; // input variable
    ofstream outScore; // output variable
    
    inScore.open("C:\\Documents and Settings\\Trey Causey\\My Documents\\cs217a\\sem 5\\scores.txt");
    
    if(!inScore)
      {
           cout << "Cannot open the input file." << endl;
           system("pause");
           return 1;
      }  
      
    outScore.open("E:\\C++ programs\\results.txt");

    for (counter = 0; counter < 8; counter++)
    scoreArray[counter] = 0;
    
    inScore >> scores;
    
    readScore(inScore, scores, scoreArray); 
    
    outputScore(outScore, counter, scoreArray);

return 0;    
}

void readScore(ifstream& inputScore, int theScore, int array[])
{
     while(inputScore)
     {
                      if (theScore >= 0 && theScore <= 24)
                         array[0]++;
                      else if (theScore >=25 && theScore <=49)
                           array[1]++;
                      else if (theScore >=50 && theScore <=74)
                           array[2]++;
                      else if (theScore >=75 && theScore <=99)
                           array[3]++;
                      else if (theScore >=100 && theScore <=124)
                           array[4]++;
                      else if (theScore >=125 && theScore <=149)
                           array[5]++;
                      else if (theScore >=150 && theScore <=174)
                           array[6]++;
                      else if (theScore >=175 && theScore <=200)
                           array[7]++;
     
     inputScore >> theScore;
     }
}

void outputScore(ofstream& outputScore, int count, int lastArray[])
{
     count = 0;
     
     while (count < 8)
     {
           outputScore << "There were " << lastArray[count] << " student(s) to score in the"
           << " range of "; 
               
               switch(count)
               {
                            case 0:
                                 outputScore << "0 - 24" << endl;
                                 break;
                            case 1:
                                 outputScore << "25 - 49" << endl;
                                 break;
                            case 2:
                                 outputScore << "50 - 74" << endl;
                                 break;
                            case 3:
                                 outputScore << "75 - 99" << endl;
                                 break;
                            case 4:
                                 outputScore << "100 - 124" << endl;
                                 break;
                            case 5:
                                 outputScore << "125 - 149" << endl;
                                 break;
                            case 6:
                                 outputScore << "150 - 174" << endl;
                                 break;
                            case 7:
                                 outputScore << "175 - 200" << endl;
                                 break;
               }
               
                                 count++;
     }
}
                                    
