set terminal eps color enhanced
set output "kadai1_3_a.eps"
set xlabel "log_2n"
set ylabel "loss"
set key 
plot "1_3_a_tyuten.txt" with linespoints title "{Midpoint rule}" ,\
"1_3_a_daikei.txt" with linespoints title "{Trapezoidal rule}",\
"1_3_a_simpson.txt" with linespoints title "{Simpson rule}"
