#include<iostream>
#include<fstream>

using namespace std;

//declare functions
void initialize(int scores[]);
void countRanges(ifstream& inScore, int stuScore, int scoreCount[]);
void printRanges(ofstream& outRange, int prRange[]);

main()
{
      int scoreRanges[8];
      int score;
      ifstream infile;
      ofstream outfile;
      
      cout << "The following program will determine the number of "
           << "students with scores in each of the following ranges"
           << ": 0-24, 25-49, 50-74, 75-99, 100-124, 125-149, 150-174"
           << ", and 175-200." << endl;
           
      infile.open("C:\\ART\\C++\\scoresin.txt");
      
      if(!infile)
      {
           cout << "Cannot open the input file." << endl;
           system("pause");
           return 1;
      }
      
      outfile.open("C:\\ART\\C++\\scoresout.txt");
      
      initialize(scoreRanges);
      
      infile >> score;
      
      countRanges(infile, score, scoreRanges);
      printRanges(outfile, scoreRanges);
      
      infile.close();
      outfile.close();
      
      cout << "Press any key to terminate program.";
      cin >> score;      
      
      return 0;
} //end main

void initialize(int scores[])
{
     for(int count = 0; count < 8; count++)
               scores[count] = 0;
} //end initialize

void countRanges(ifstream& inScore, int stuScore, int scoreCount[])
{
     while(inScore)
     {
           int limit = 25;
           int range = 0;
                   
           while(stuScore > limit)
           {
                range++;
                        
                if(range == 7)
                    limit = limit + 26;
                else
                    limit = limit + 25;
           } //end while
           
           scoreCount[range]++;
           inScore >> stuScore;
     } //end while
} // end countRanges

void printRanges(ofstream& outRange, int prRange[])
{
     int range = 0;
     
     while (range < 8)
     {
           outRange << "There were " << prRange[range] << " students to receive"
                    << " a score in the range of ";
                    
           switch(range)
           {
           case 0:
                outRange << "0 to 24." << endl;
                break;
           case 1:
                outRange << "25 to 49." << endl;
                break;
           case 2:
                outRange << "50 to 74." << endl;
                break;
           case 3:
                outRange << "75 to 99." << endl;
                break;
           case 4:
                outRange << "100 to 124." << endl;
                break;
           case 5:
                outRange << "125 to 149." << endl;
                break;
           case 6:
                outRange << "150 to 174." << endl;
                break;
           case 7:
                outRange << "175 to 200." << endl;
                break;
           } // end switch
           
           range++;
     } // end while
} // end printRanges
           
