mkdir build-win-x64
chdir build-win-x64

set RTM_ROOT=C:\Program Files\OpenRTM-aist\1.1
set OMNI_ROOT=C:\Program Files\OpenRTM-aist\1.1\omniORB\4.1.7_vc12
cmake ../ -G "Visual Studio 12 2013 Win64" -DOpenRTM_DIR="C:/Program Files/OpenRTM-aist/1.1/cmake/"

chdir ../