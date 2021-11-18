#include<iostream>
#include<vector>
#include<cmath>
#include<fstream>
#include<string>
using namespace std;

//被積分関数を定義
double f(double x){
    return 1.0/x;
}

//中点公式を定義
double tyuten(int n, double h, vector<double>x){
    double kinjiti = 0.0;
    for(int i=0; i<n; i++){
        kinjiti += f((x[i]+x[i+1])/2.0);
    }
    return kinjiti * h;
}

//台形公式を定義
double daikei(int n, double h, vector<double>x){
    double kinjiti = 0.0;
    for(int i=1; i<n; i++){
        kinjiti += f(x[i]);
    }
    kinjiti += f(x[0])/2.0;
    kinjiti += f(x[n])/2.0;
    return kinjiti * h;
}

//Simpson 公式を定義
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
    vector<double> x;//離散化したx 座標を格納する
    double a = 1.0, b=2.0;//積分区間

    //出力ファイル
    ofstream tyuten_file, daikei_file, simpson_file;
    string filename_tyuten = "1_2_a_tyuten.txt";
    string filename_daikei = "1_2_a_daikei.txt";
    string filename_simpson = "1_2_a_simpson.txt";

    tyuten_file.open(filename_tyuten, ios::out);
    daikei_file.open(filename_daikei, ios::out);
    simpson_file.open(filename_simpson, ios::out);

    //手法ごとに計算
    for(int method=0; method<3; method++){
        //分割数n ごとに計算
        for(int i=0; i<=10; i++){
            int n = pow(2, i);//区間分割数
            double h = (b-a)/double (n);//刻み幅

            x.clear();
            double x_i = a;
            //離散化したx 座標を計算
            for(int i=0; i<=n; i++){
                x.push_back(x_i);
                x_i += h;
            }
            //計算結果の出力
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