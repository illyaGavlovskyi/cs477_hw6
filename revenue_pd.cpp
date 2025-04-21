#include <iostream>
#include <fstream>
#include <string>
using namespace std;


int main()
{

    ifstream infile("revenue_pc_out.txt");
    ofstream outfile("revenue_pd_out.txt");
    string line;
    int day = 0;
    while(getline(infile, line) && line !="Choice Table:" )
    {

    }
    while(getline(infile, line))
    {
        string project;
        cout << " - " << endl ;
        cout << line.length() << line << endl ;
        for (int i = 0; i < line.length(); i++)
        {
            cout << " + " << endl ;
            if (line[i] == 'r')
            {
                project = "repairs";
                day++;
                outfile << "Day " << day << ": " << project << endl;
            }
            else if (line[i] == 'c')
            {
                project = "construction";
                day++;
                outfile << "Day " << day << ": " << project << endl;
            } 
            else if (line[i] == 'n')
            {
                project = "none";
                day++;
                outfile << "Day " << day << ": " << project << endl;
            }  
        }
        
    }
    infile.close();
    outfile.close();
    return 0;
}