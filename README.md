# Chess
This project is under development. Tested on Ubuntu 20.04

### Dependencies

##### Install SDL 2 development library
```
sudo apt-get install libsdl2-dev
```
##### Install SDL 2 Image

###### Install from source (not work)
```
wget https://www.libsdl.org/projects/SDL_image/release/SDL2_image-2.0.5.zip 
unzip SDL2_image-2.0.5.zip -d sdl_image
cd sdl_image
./configure
make
sudo make install
```
###### Install from package manager

```
sudo apt install libsdl2-image-dev
```

### How to build
```
# Set source folder is current folder and build folder is "build" folder
cmake -S . -B build
cd build
make
