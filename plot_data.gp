set terminal pngcairo size 800,600 enhanced font 'Verdana,10'
set output 'plot_results.png'

set title "Numerical and Exact Solutions"
set xlabel "x"
set ylabel "u(x)"
set grid

# Plot the data files
plot "Variable_exactSolution.data" with lines title "Numerical Solution", \
     "Variable_initialCondition.data" with linespoints title "Exact Solution", \
     "Variable_jacobiSolution.data" with points title "Initial Condition"
