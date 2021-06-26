apt update
apt-get install -y libboost-dev libboost-date-time-dev libboost-filesystem-dev libboost-program-options-dev libboost-system-dev libboost-thread-dev libboost-regex-dev libboost-test-dev swig cmake build-essential pkg-config gnuradio-dev libconfig++-dev libgmp-dev liborc-0.4-0 liborc-0.4-dev liborc-0.4-dev-bin nlohmann-json3-dev libpng++-dev libvorbis-dev git python3-libhamlib2 python3-dialog python3 python3-six python3-mako python3-soapysdr python3-dev gcc gnuradio-dev gnuradio libsoapysdr-dev libconfig++-dev libgmp-dev liborc-0.4-0 liborc-0.4-dev liborc-0.4-dev-bin python3-pip soapysdr-tools rtl-sdr librtlsdr-dev libxml2 libxml2-dev bison flex libaio-dev libboost-all-dev libgmp-dev liborc-0.4-dev libusb-1.0-0-dev libserialport-dev graphviz doxygen g++ python3-numpy python3-sphinx python3-lxml libfftw3-dev libsdl1.2-dev libgsl-dev libqwt-qt5-dev libqt5opengl5-dev python3-pyqt5 liblog4cpp5-dev libzmq3-dev python3-yaml python3-click python3-click-plugins python3-zmq python3-scipy python3-gi python3-gi-cairo gobject-introspection gir1.2-gtk-3.0
git clone https://gitlab.com/librespacefoundation/gr-soapy.git
cd gr-soapy/
mkdir build
cd build/
cmake .. -DCMAKE_INSTALL_PREFIX:PATH=/usr
make
make install
cd ../..
git clone https://gitlab.com/librespacefoundation/satnogs/gr-satnogs.git
cd gr-satnogs/
mkdir build
cd build/
cmake .. -DCMAKE_INSTALL_PREFIX:PATH=/usr
make 
make install
cd ../..
git clone https://gitlab.com/librespacefoundation/satnogs/satnogs-flowgraphs.git
cd satnogs-flowgraphs/
mkdir build
cd build/
cmake .. -DCMAKE_INSTALL_PREFIX:PATH=/usr
make 
make install
