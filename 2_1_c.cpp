#include<iostream>
#include<vector>
#include<cmath>
#include<fstream>
#include<string>
using namespace std;

double f(double x){
    return 1.0+sin(x);
}

int main(){
    double a = 0.0, b = M_PI;
    vector<double> x, w, y;
    w.push_back(1.0), w.push_back(1.0);
    y.push_back(-1/sqrt(3.0)), y.push_back(1/sqrt(3.0));
    
    ofstream writing_file;
    string file_name;
    file_name = "2_1_c.txt";
    writing_file.open(file_name, ios::out);

    for(int i=0; i<=10; i++){
        int N = double(pow(2.0, i));
        double dx = (b - a) / double(N);
        x.clear();
        double x_i = a;

        for(int j=0; j<=N; j++){
            x.push_back(x_i);
            x_i += dx;
        }

        double ans = 0.0;
        for(int j=0; j<N; j++){
            for(int m=0; m<=1; m++){
                ans += w[m] * f((y[m]+1)*(x[j+1]-x[j])/2.0 + x[j]) * (x[j+1]-x[j]) / 2.0;
            }
        }

        writing_file << i << " " << ans << endl;
    }
    writing_file.close();
}