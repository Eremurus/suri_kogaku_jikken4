#include<iostream>
#include<vector>
#include<cmath>
#include<fstream>
#include<string>
using namespace std;

double f(double x){
    return 1.0/x;
}

double tyuten(int n, double h, vector<double>x){
    double kinjiti = 0.0;
    for(int i=0; i<n; i++){
        kinjiti += f((x[i]+x[i+1])/2.0);
    }
    return kinjiti * h;
}

double daikei(int n, double h, vector<double>x){
    double kinjiti = 0.0;
    for(int i=1; i<n; i++){
        kinjiti += f(x[i]);
    }
    kinjiti += f(x[0])/2.0;
    kinjiti += f(x[n])/2.0;
    return kinjiti * h;
}

double simpson(int n, double h, vector<double>x){
    double kinjiti = 0.0;
    for(int i=1; i<n; i++){
        kinjiti += f(x[i])*2.0;
    }
    kinjiti += f(x[0]);
    kinjiti += f(x[n]);

    for(int i=0; i<n; i++){
        kinjiti += 4*f((x[i]+x[i+1])/2.0);
    }

    return kinjiti*h / 6.0;
}

int main(){
    vector<double> x;
    double a = 1.0, b=2.0;
    double real_ans = log(2.0);

    ofstream tyuten_file, daikei_file, simpson_file;
    string filename_tyuten = "1_3_a_tyuten_kai.txt";
    string filename_daikei = "1_3_a_daikei_kai.txt";
    string filename_simpson = "1_3_a_simpson_kai.txt";

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
                double ans = tyuten(n, h, x)-real_ans;
                tyuten_file << i << " " << ans << endl;
            }
            if(method==1){
                double ans = daikei(n, h, x)-real_ans;
                daikei_file << i << " " << ans << endl;
            }
            if(method==2){
                double ans = simpson(n, h, x)-real_ans;
                simpson_file << i << " " << ans << endl;
            }
        }
    }
    tyuten_file.close();
    daikei_file.close();
    simpson_file.close();
}