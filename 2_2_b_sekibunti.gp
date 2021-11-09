set terminal eps color enhanced
set output "kadai2_2_b_sekibunti.eps"
set xlabel "log_2n"
set ylabel "integral value"
set key 
plot "2_2_b_m2.txt" with linespoints title "{m=2}" ,\
"2_2_b_m3.txt" with linespoints title "{m=3}",\
