#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main(){
    vector<vector<double>> data = {
        // sqft, bedrooms, price
        {1000, 2, 150000},
        {1200, 3, 180000},
        {950, 2, 140000},
        {1400, 3, 220000},
        {1700, 4, 300000}
    };

    int features = 2;
    vector<double> m(features, 0.0);
    double c = 0.0;
    double lr = 0.0000001;

    for(int epoch = 0; epoch < 20000; epoch++){
        vector<double> dm(features, 0.0);
        double dc = 0;

        for(auto row: data){
            double y = row[2];

            double y_pred = 0;
            for(int j = 0; j < features; j++){
                y_pred += m[j] * row[j];
            }
            y_pred += c;

            double error = y - y_pred;

            for(int j = 0; j < features; j++){
                dm[j] += error * row[j];
            }
            dc += error;
        }

        for(int i = 0; i < features; i++){
            m[i] += lr* (dm[i]/data.size());
        }
        
        c += lr*(dc/data.size());
    }

    cout << "\nTrained Weights:\n";
    cout << "m1 = " << m[0] << endl;
    cout << "m2 = " << m[1] << endl;
    cout << "c  = " << c << endl;

    // test the model
    double sqft=1500, bedrooms=3;
    double pred = m[0]*sqft + m[1]*bedrooms + c;
    cout << "\nPrediction for 1500 sqft & 3 bedrooms = " << pred << endl;

    return 0;
}