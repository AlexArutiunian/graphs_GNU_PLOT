set yrange
set xrange
set terminal png size 800, 600
set output "result.png"
f(x) = k*x + b
fit f(x) "data.dat" using ($1):($2) via k, b
set title "cos(x) on x" font "Helvetica Bold, 20"
plot f(x), "data.dat" using ($1):($2) with linespoints lw 2 ps 4 pt 6 dt 5 lt 26

