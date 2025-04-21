#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    int n = 4;
    int r[] = {1000, 100, 1000, 1000};
    int c[] = {500, 5000, 500, 100};
    
    int day[n + 1];
    day[0] = 0;
    day[1] = max(r[0], c[0]);
    for(int i = 2; i < n + 1; i++)
    {
        // cout << i <<endl;
        // cout << day[i - 1] << " " << r[i - 1] << "  "<< day[i - 2] << " " << c[i - 1 ] << endl;
        if(day[i - 1] + r[i - 1] > day[i - 2] + c[i - 1])
        {
            day[i] = day[i - 1] + r[i - 1];
        }
        else
        {
            day[i] = day[i - 2] + c[i - 1];
        }
        
        // day[i] = max(day[i - 1] + r[i], day[i - 2] + c[i]);
    }
    ofstream out("revenue_pb_out.txt");
    for (int i = 1; i <= n; i++) {
        out << "Day " << i << ": " << day[i] << "\n";
    }
    out << "\nTotal Revenue: " << day[n] << "\n";
    out.close();
    return 0;
}
