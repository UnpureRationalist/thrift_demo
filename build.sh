
./bootstrap.sh
./configure --disable-dependency-tracking --without-go --without-cl --with-cpp
cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=ON -DBUILD_JAVASCRIPT=OFF -DBUILD_JAVA=OFF -DBUILD_KOTLIN=OFF ..