git pull --recurse-submodules
git submodule update --init --recursive
mkdir build64_all
cd build64_all
cmake .. -G "Visual Studio 18 2026" -A x64 -DDEVELOPER_MODE=ON
cmake --build . --config Release
