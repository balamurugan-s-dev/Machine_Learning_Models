#include <iostream>
#include <fstream>
using namespace std;

int main(){
    double m, c;

    // Read trained model parameters
    ifstream file("simple-linear-regression.bin", ios::binary);
    if(!file){
        cout << "Model file not found!\n";
        return 0;
    }

    file.read((char*)&m, sizeof(m));
    file.read((char*)&c, sizeof(c));
    file.close();

    cout << "Loaded Model: y = " << m << "x + " << c << endl;

    // Test loop
    while(true){
        double x;
        cout << "\nEnter x value to predict (-1 to exit): ";
        cin >> x;

        if(x == -1) break;

        double y_pred = m*x + c;
        cout << "Predicted y = " << y_pred << endl;
    }

    return 0;
}
