set terminal eps color enhanced
set output "kadai1_1_c.eps"
set xlabel "x"
set ylabel "f(x)"
set key 
plot[-1:1] "1_1_c_n2.txt" title "{n=2}" with lines  linewidth 5 ,\
"1_1_c_n4.txt" title "{n=4}" with lines  linewidth 5 ,\
"1_1_c_n8.txt" title "{n=8}" with lines  linewidth 5 ,\
"1_1_c_n16.txt" title "{n=16}" with lines  linewidth 5
