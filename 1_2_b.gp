set terminal eps color enhanced
set output "kadai1_2_b.eps"
set xlabel "log_2n"
set ylabel "I(f)"
set key 
plot "1_2_b_tyuten.txt" with linespoints title "{Midpoint rule}" ,\
"1_2_b_daikei.txt" with linespoints title "{Trapezoidal rule}",\
"1_2_b_simpson.txt" with linespoints title "{Simpson rule}"
