set term postscript eps enhanced solid color "Helvetica" 25
set output "modelo.eps"

set key Right top right
#unset key
set size 1.7,1.5

set ylabel "{/=30 Intensidade (W/m^2 nm^{-1})}"
set xlabel "{/Symbol=36 l} {/=30 (nm)}"

#set xtics 12
#set mxtics 3

set xrange[200:3000]
set autoscale y

#set logscale y

hc = 1240 #eV*nm
c = 2.99792458e17 #nm/s
kB = 8.6173324e-5 # eV/K
f(x,T) = 2*hc*c / x**5 /(exp(hc/kB/x/T)-1.)

p 'dataAM0AM1_new.csv' u 1:2 w p pt 6 t 'espectro solar', \
f(x,6000)/1e5 t '6000K corpo negro' linecolor rgb "royalblue" lw 5


################# comentários sobre dados e conversão para png ###################
#  http://www.pveducation.org/pvcdrom/appendices/standard-solar-spectra
#  baixar tabela tipo "excel", abrir no libreoffice calc e salvar como "texto csv"
#  sed 's/,/\./g' AM0AM1_5.csv > dataAM0AM1_new.csv
#  convert -density 100 modelo.eps -flatten modelo.png
##################################################################################