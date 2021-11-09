set terminal eps color enhanced
set output "kadai2_2_c_b_gosa.eps"
set xlabel "log_2n"
set ylabel "loss"
set key 
plot "2_2_c_b_m2_gosa.txt" with linespoints title "{m=2}" ,\
"2_2_c_b_m3_gosa.txt" with linespoints title "{m=3}",\
