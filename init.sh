apt update
apt install libsfml

git submodule init
git submodule update

mkdir lib/FTXUI/build
cd lib/FTXUI/build

cmake ..
