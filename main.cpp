#include <iostream>
#include <bitset>
#include <math.h>
#include <iomanip>

using namespace std;

int main()
{
    
    int kolor1 = 0x00aa5500;
    int kolor2 = 0x00ffffff;
    int red1 = 0x00ff0000;
    int green1 = 0x0000ff00;
    int blue1 = 0x000000ff;
    int partded1 = (kolor1 & red1);
    int partGreen1 = (kolor1 & green1);
    int partBlue1 = (kolor1 & blue1);
    partded1 >>= 16;
    partGreen1 >>= 8;
    //cout << "czerwony1: " << hex << partded1 << endl;
    //cout << "zielony1: " << hex << partGreen1 << endl;
    //cout << "niebieski1: " << hex << setw(2) << setfill('0') << partBlue1 << endl;

    int red2 = 0x00ff0000;
    int green2 = 0x0000ff00;
    int blue2 = 0x000000ff;
    int partded2 = (kolor2 & red2);
    int partGreen2 = (kolor2 & green2);
    int partBlue2 = (kolor2 & blue2);
    partded2 >>= 16;
    partGreen2 >>= 8;
    //cout << "czerwony2: " << hex << partded2 << endl;
    //cout << "zielony2: " << hex << partGreen2 << endl;
    //cout << "niebieski2: " << hex << partBlue2 << endl;

    int deltaRed = (partded2 - partded1) / 20;
    int deltaGreen = (partGreen2 - partGreen1) / 20;
    int deltaBlue = (partBlue2 - partBlue1) / 20;

    cout << "Content-Type:text/html;charset=UTF-8" << (char)13 << (char)10
        << "\n<table>"
        << "\n<tbody>";
    for (int i = 0; i < 21; i++)
    {
        cout << "\n<tr><td bgcolor='" << hex << partded1 << partGreen1 << setw(2) << setfill('0') << partBlue1 << "'>" << hex << partded1 << partGreen1 << setw(2) << setfill('0') << partBlue1 << "</td></tr>";
        partded1 += deltaRed;
        partGreen1 += deltaGreen;
        partBlue1 += deltaBlue;

    }
    cout << "\n<tr><td bgcolor='" << partded2 << partGreen2 << partBlue2 << "'>" << partded2 << partGreen2 << partBlue2 << "</td></tr>";
    cout << "\n</tbody>";
    cout << "\n</table>";
    return 0;
}