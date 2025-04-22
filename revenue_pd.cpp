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
    string project[5];
    while(getline(infile, line))
    {
        
        cout << " - " << endl ;
        cout << line.length() << line << endl ;
        for (int i = 0; i < line.length(); i++)
        {
            cout << " + " << endl ;
            if (line[i] == 'r')
            {
                project[day] = "repairs";
                day++;
                // outfile << "Day " << day << ": " << project << endl;
            }
            else if (line[i] == 'c')
            {
                project[day] = "construction";
                project[day - 1] = "none";
                day++;
                // outfile << "Day " << day << ": " << project << endl;
            } 
            else if (line[i] == 'n')
            {
                project[day] = "none";
                day++;
                // outfile << "Day " << day << ": " << project << endl;
            }  
        }
        
    }
    for (int i = 0; i < 4; i++)
        {
            outfile << "Day " << i+ 1 << ": " << project[i] << endl;
        }
    infile.close();
    outfile.close();
    return 0;
}
