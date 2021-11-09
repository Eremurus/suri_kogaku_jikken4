set terminal eps color enhanced
set output "kadai2_1.eps"
set xlabel "log_2n"
set ylabel "integral value"
set key 
plot "2_1_a.txt" with linespoints title "{a}" ,\
"2_1_b.txt" with linespoints title "{b}",\
"2_1_c.txt" with linespoints title "{c}",\
"2_1_d.txt" with linespoints title "{d}"
