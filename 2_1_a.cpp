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

//実行
int main(){
    double a = 1.0, b = 2.0;//積分区間
    vector<double> x, w, y;//x,w,y を離散化した分点を格納
    //2 次のGauss 型積分公式でm=1,2 の時のy_m,w_m の値を格納
    w.push_back(1.0), w.push_back(1.0);
    y.push_back(-1/sqrt(3.0)), y.push_back(1/sqrt(3.0));

    //出力ファイル
    ofstream writing_file;
    string file_name;
    file_name = "2_1_a.txt";
    writing_file.open(file_name, ios::out);

    //分割数を変えて実行
    for(int i=0; i<=10; i++){
        int N = double(pow(2.0, i));//分割数
        double dx = (b - a) / double(N);//小区間の大きさ
        x.clear();
        double x_i = a;

        //分点を格納
        for(int j=0; j<=N; j++){
            x.push_back(x_i);
            x_i += dx;
        }

        //Gauss 型積分を実行
        double ans = 0.0;
        for(int j=0; j<N; j++){
            for(int m=0; m<=1; m++){
                ans += w[m] * f((y[m]+1)*(x[j+1]-x[j])/2.0 + x[j]) * (x[j+1]-x[j]) / 2.0;
            }
        }
        //ファイルに出力
        writing_file << i << " " << ans << endl;
    }
    writing_file.close();
}