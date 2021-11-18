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

//中点公式
double tyuten(int n, double h, vector<double>x){
    double kinjiti = 0.0;
    for(int i=0; i<n; i++){
        kinjiti += f((x[i]+x[i+1])/2.0);
    }
    return kinjiti * h;
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
    vector<double> x;//離散化されたx 座標を格納
    double a = 1.0, b=2.0;//積分区間
    double real_ans = log(2.0);//実際の積分値

    //出力ファイル
    ofstream tyuten_file, daikei_file, simpson_file;
    string filename_tyuten = "1_3_a_tyuten_kai.txt";
    string filename_daikei = "1_3_a_daikei_kai.txt";
    string filename_simpson = "1_3_a_simpson_kai.txt";

    tyuten_file.open(filename_tyuten, ios::out);
    daikei_file.open(filename_daikei, ios::out);
    simpson_file.open(filename_simpson, ios::out);

    //手法ごとに実行
    for(int method=0; method<3; method++){
        //分割数ごとに実行
        for(int i=0; i<=10; i++){
            int n = pow(2, i);
            double h = (b-a)/double (n);

            x.clear();
            double x_i = a;

            //座標の分点を求める
            for(int i=0; i<=n; i++){
                x.push_back(x_i);
                x_i += h;
            }

            //誤差を計算しファイルに出力
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