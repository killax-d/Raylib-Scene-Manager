Readme

# %APP-NAME% - Game

...

## Story

...

## Installation

...

### Installation (gcc, CMake and git): 

```bash 
sudo apt update
sudo apt install 
sudo apt install build-essential git cmake
sudo apt install libasound2-dev mesa-common-dev libx11-dev libxrandr-dev libxi-dev xorg-dev libgl1-mesa-dev libglu1-mesa-dev 
```
### Compile and install Raylib 3.0.0 
```bash
# Go into a Temporary Folder
cd ~/Downloads

# You need to clone the raylib repository
git clone https://github.com/raysan5/raylib.git raylib
cd raylib
git checkout '3.5.0'

# Make the build Directory and process the build
mkdir build && cd build
cmake -DSHARED=ON -DSTATIC=ON ..
make 


# Install the builded files
sudo make install
 
# Optional, remove the folder
cd ../..
rm -Rf ~/Downloads/raylib
```

## Start the Game

```bash
# Clone the repository
git clone %LINK%

# Build and start the game
make
cd /dist
./%APP-NAME%
```

### Controls

...

## Version

Last stable release : ...
