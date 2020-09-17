#!/bin/bash

if [ $(find . -maxdepth 1 -type d -name "SFML-2.5.1-Compiled" | wc -l) -eq 0 ]
then
	echo "Installing SFML..."
	sudo apt install libfreetype6-dev libxrandr-dev libudev-dev libogg-dev libflac-dev libvorbis-dev libopenal-dev
	ROOT_DIR=$PWD
	wget $ROOT_DIR "https://www.sfml-dev.org/files/SFML-2.5.1-sources.zip"
	unzip SFML-2.5.1-sources.zip
	cd SFML-2.5.1
	cmake -DCMAKE_INSTALL_PREFIX="$ROOT_DIR"/SFML-2.5.1-Compiled
	make
	make install
	cd ..
	rm -R SFML-2.5.1
	rm SFML-2.5.1-sources.zip
else
	echo "SFML is already installed. If something went wrong, delete the directory 'SFML-2.5.1-Compiled'"
fi
mkdir build
cd build
cp -r ../images images
cmake ..
make
