set -e
make 17
./17 17.db c
./17 17.db s 1 QQQ QQQ@qq.com
./17 17.db s 2 gantrol gantrol@github.com
./17 17.db s 3 hwang hwang@gmail.com
./17 17.db l
./17 17.db d 2
./17 17.db l
./17 17.db g 3
./17 17.db g 1