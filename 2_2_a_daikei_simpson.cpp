#include<iostream>
#include<vector>
#include<cmath>
#include<fstream>
#include<string>
#include <iomanip>
using namespace std;

//被積分関数
double f(double x){
    return exp(-x) / sqrt(x);
}

//台形公式
double daikei(int n, double h, vector<double>x){
    double kinjiti = 0.0;
    for(int i=1; i<n; i++){
        kinjiti += f(x[i]);
    }
    kinjiti += f(x[0])/2.0;
    kinjiti += f(x[n])/2.0;
    return kinjiti * h;
}

//Simpson 公式
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

//実行
int main(){
    vector<double> x;//x 座標
    double a = 0.0, b = 1.0;//積分区間
    double real_ans = 1.49364826562;//真の積分値

    //出力ファイル
    ofstream daikei_file, simpson_file, daikei_file_gosa, simpson_file_gosa;
    string filename_daikei = "2_2_a_daikei.txt";
    string filename_simpson = "2_2_a_simpson.txt";
    string filename_daikei_gosa = "2_2_a_daikei_gosa.txt";
    string filename_simpson_gosa = "2_2_a_simpson_gosa.txt";

    daikei_file.open(filename_daikei, ios::out);
    simpson_file.open(filename_simpson, ios::out);
    daikei_file_gosa.open(filename_daikei_gosa, ios::out);
    simpson_file_gosa.open(filename_simpson_gosa, ios::out);

    for(int method=0; method<2; method++){//手法ごとに繰り返す
        for(int i=0; i<=10; i++){
            int n = pow(2, i);//分割数
            double h = (b-a)/double (n);//刻み幅

            x.clear();
            double x_i = a;
            //x 座標を格納
            for(int i=0; i<=n; i++){
                x.push_back(x_i);
                x_i += h;
            }

            if(method==0){
                double ans = daikei(n, h, x);//台形公式で計算
                double gosa = ans - real_ans;//誤差を求める

                daikei_file << i << " " << setprecision(14) << ans << endl;
                daikei_file_gosa << i << " " << setprecision(14) << gosa << endl;
            }

            if(method==1){
                double ans = simpson(n, h, x);//Simpson 公式で計算
                double gosa = ans - real_ans;
                simpson_file << i << " " << setprecision(14) << ans << endl;
                simpson_file_gosa << i << " " << setprecision(14) << gosa << endl;
            }
        }
    }
    daikei_file.close();
    simpson_file.close();
    daikei_file_gosa.close();
    simpson_file_gosa.close();
}