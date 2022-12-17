set encoding utf8
set terminal png size 1280,720 enhanced font 'Verdana, 12'
set output "result.png"
set xrange [*:*]
set yrange [*:*]

# настройка миллиметровки на фоне 
set xtics auto
set ytics auto
set mxtics 5
set mytics 5
set grid xtics ytics mxtics mytics
# конец настройки миллиметровки

set title "заголовок шаблона"
set xlabel "абсцисса шаблона"
set ylabel "ордината шаблона"

# работа с легендой
set key inside bottom right # расположение легенды вне графиков
set key box linestyle 1 # обводка легенды в прямоугольник
# конец работы с легендой

f(x) = k*x+b
fit f(x) "data.txt" using ($3):($2) via k, b
plot f(x) title "approx. x(m)" lw 3 lt 22, "data.txt" using ($3):($2) pt 7 ps 2