#include<iostream>
#include<vector>
#include<cmath>
#include<fstream>
#include<string>
using namespace std;

double f_2(double x){
    return 2.0/(x*x*x);
}

double f_4(double x){
    return 24.0/double (pow(x, 5));
}

double tyuten(int n, double h, vector<double>x){
    double gosa = 0.0;
    for(int i=0; i<n; i++){
        gosa += f_2((x[i]+x[i+1])/2.0);
    }
    return h * h * h * gosa/24.0;
}

double daikei(int n, double h, vector<double>x){
    double gosa = 0.0;
    for(int i=1; i<n; i++){
        gosa += f_2(x[i]);
    }
    gosa += h * f_2(x[0]) / 2.0;
    gosa += h * f_2(x[n]) / 2.0;
    return -h*h*h*gosa / 12.0;
}

double simpson(int n, double h, vector<double>x){
    double gosa = 0.0;
    for(int i=1; i<n; i++){
        gosa += f_4(x[i])/3.0;
    }
    gosa += f_4(x[0])/6.0;
    gosa += f_4(x[n])/6.0;

    for(int i=0; i<n; i++){
        gosa += 2.0*f_4((x[i]+x[i+1])/2.0)/3.0;
    }
    return -(pow(h, 5))*gosa/2880.0;
}

int main(){
    vector<double> x;
    double a = 1.0, b=2.0;

    ofstream tyuten_file, daikei_file, simpson_file;
    string filename_tyuten = "1_3_a_tyuten.txt";
    string filename_daikei = "1_3_a_daikei.txt";
    string filename_simpson = "1_3_a_simpson.txt";

    tyuten_file.open(filename_tyuten, ios::out);
    daikei_file.open(filename_daikei, ios::out);
    simpson_file.open(filename_simpson, ios::out);

    for(int method=0; method<3; method++){
        for(int i=0; i<=10; i++){
            int n = pow(2, i);
            double h = (b-a)/double (n);

            x.clear();
            double x_i = a;
            for(int i=0; i<=n; i++){
                x.push_back(x_i);
                x_i += h;
            }

            if(method==0){
                double ans = tyuten(n, h, x);
                tyuten_file << i << " " << ans << endl;
            }
            if(method==1){
                double ans = daikei(n, h, x);
                daikei_file << i << " " << ans << endl;
            }
            if(method==2){
                double ans = simpson(n, h, x);
                simpson_file << i << " " << ans << endl;
            }
        }
    }
    tyuten_file.close();
    daikei_file.close();
    simpson_file.close();
}