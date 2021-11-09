#include<iostream>
#include<vector>
#include<cmath>
#include<fstream>
#include<string>
using namespace std;

double l(int n, int i, double x, vector<double> X){
    double bunsi=1.0, bunbo=1.0;

    for(int j=0; j<n; j++){
        if(i == j) continue;
        bunsi = bunsi * (x-X[j]);
        bunbo = bunbo * (X[i]-X[j]);
    }

    return bunsi/bunbo;
}

double f(double x){
    return log(x);
}

int main(){
    vector<double> X;
    double dx = 0.01;
    double a=1.0, b=2.0;
    int step_num = (int)(b-a)/dx;
    
    for(int n=2; n<=16; n=n*2){
        double x = a;
        X.clear();
        double x_component = a;
        for(int k=0; k<n; k++){
            X.push_back(x_component);
            x_component += (b-a)/double (n-1);
        }

        ofstream writing_file;
        string file_name;
        if(n==2) file_name = "1_a_n2.txt";
        if(n==4) file_name = "1_a_n4.txt";
        if(n==8) file_name = "1_a_n8.txt";
        if(n==16) file_name = "1_a_n16.txt";
        writing_file.open(file_name, ios::out);

        writing_file << a << " " << log(a) << endl;

        for(int j=1; j<=step_num; j++){
            double P = 0;
            x += dx;
            for(int i=0; i<n; i++){
                P += log(X[i])*l(n, i, x, X);
            }
            writing_file << x << " " << P << endl;
        }

        writing_file.close();
    }
}