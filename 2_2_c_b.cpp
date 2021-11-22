#include<iostream>
#include<vector>
#include<cmath>
#include<fstream>
#include<string>
#include <iomanip>
using namespace std;

//変数変換ありの被積分関数
double f(double x){
    return 2.0 * exp(-x*x) - 2.0;
}

//最後に2 を足すこと以外は(b) と同じ
int main(){
    double a = 0.0, b = 1.0;
    vector<double> x, w, y;
    ofstream writing_file, writing_file_gosa;
    string file_name, file_name_gosa;

    for(int M=2; M<=3; M++){
        x.clear(), y.clear(), w.clear();
        if(M == 2){
            w.push_back(1.0), w.push_back(1.0);
            y.push_back(-1/sqrt(3.0)), y.push_back(1/sqrt(3.0));
            file_name = "2_2_c_b_m2.txt";
            file_name_gosa = "2_2_c_b_m2_gosa.txt";
            writing_file.open(file_name, ios::out);
            writing_file_gosa.open(file_name_gosa, ios::out);
        }
        if(M == 3){
            w.push_back(5.0/9.0),w.push_back(8.0/9.0),w.push_back(5.0/9.0);
            y.push_back(-sqrt(3.0/5.0)),y.push_back(0.0),y.push_back(sqrt(3.0/5.0));
            file_name = "2_2_c_b_m3.txt";
            file_name_gosa = "2_2_c_b_m3_gosa.txt";
            writing_file.open(file_name, ios::out);
            writing_file_gosa.open(file_name_gosa, ios::out);
        }
    

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
                for(int m=0; m<M; m++){
                    ans += w[m] * f((y[m]+1)*(x[j+1]-x[j])/2.0 + x[j]) * (x[j+1]-x[j]) / 2.0;
                }
            }
            ans += 2.0;//手計算で求めた2 を足す
            writing_file << i << " " << setprecision(12) << ans << endl;
            ans -= 1.49364826562;
            writing_file_gosa << i << " " << setprecision(12) <<ans << endl;
        }
        writing_file.close();
        writing_file_gosa.close();
    }
}