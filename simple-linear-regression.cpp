#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int main(){
    double m = 0;
    double c = 0;
    double lr = 0.001;


    vector<vector<int>> data = {
        {1, 42}, {2, 55}, {3, 69}, {4, 82}, {5, 96},
        {6, 112}, {7, 131}, {8, 148}, {9, 159}, {10, 176},
        {11, 192}, {12, 208}, {13, 222}, {14, 238}, {15, 255},
        {16, 266}, {17, 284}, {18, 298}, {19, 313}, {20, 330},
        {21, 340}, {22, 356}, {23, 370}, {24, 385}, {25, 401},
        {26, 420}, {27, 438}, {28, 450}, {29, 465}, {30, 478},
        {31, 492}, {32, 510}, {33, 525}, {34, 540}, {35, 556},
        {36, 573}, {37, 590}, {38, 606}, {39, 618}, {40, 635},
        {41, 649}, {42, 668}, {43, 683}, {44, 698}, {45, 715},
        {46, 731}, {47, 745}, {48, 758}, {49, 774}, {50, 790}
    };


    long train = 50000;
    long long perf = 0;
    for(int epoch= 0; epoch <train; epoch++){
        double dm = 0;
        double dc = 0;

        for(auto &row: data){
            double x = row[0];
            double y = row[1];

            double y_pred = m*x + c;
            double error = y - y_pred;
            if(epoch == train-1) perf = error * error;

            dm += error * x;
            dc += error;
        }

        dm /= data.size();
        dc /= data.size();

        m = m + lr * dm;
        c = c + lr * dc;
    }

    ofstream filet("simple-linear-regression.txt");
    filet << m << " " << c;
    filet.close();

    ofstream file("simple-linear-regression.bin", ios::binary);
    file.write((char*)&m, sizeof(m));
    file.write((char*)&c, sizeof(c));
    file.close();

    cout << "Final : " << m << endl;
    cout << "Final : " << c << endl;
    cout << "Performance : " << perf << endl;
}