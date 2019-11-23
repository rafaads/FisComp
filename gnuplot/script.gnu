#set t wxt font ",15"
set t png
set output "teste.png"
set xlabel "{/Symbol=20 l} (nm)"
set ylabel "I (W/m^2/nm)"
set format y "%.1f"
p 'dataAM0AM1_new.csv' u 1:2 w l t 'topo atm', \
'' u 1:3 w l t 'solo'

