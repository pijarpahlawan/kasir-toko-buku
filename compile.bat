g++ src\*.cpp lib\*.cpp -o kasir
mkdir export
cd export
mkdir history
type nul > database.csv
echo jumlah buku saat ini = 0 > amount.txt