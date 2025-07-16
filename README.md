# GroundControlStation

**GroundControlStation** is a base project serving as a prototype for a ground control station application.

## Download

Pre-built binaries are available on the [Releases page](https://github.com/Meherzad-C/GroundControlStation/releases).

## Runtime Requirement

To enable local video playback, install the [K-Lite Codec Pack (Basic)](https://codecguide.com/download_k-lite_codec_pack_basic.htm)

Ensure the [Microsoft Visual C++ Redistributables](https://learn.microsoft.com/en-us/cpp/windows/latest-supported-vc-redist) are installed (ignore if already installed):  

## Build Instructions

### Recommended: Qt Creator

1. Install [Qt Creator](https://www.qt.io/download) and make sure the following Qt 6 components are available:
   - Core  
   - Gui  
   - Widgets  
   - Multimedia  
   - MultimediaWidgets  
   - Location  
   - Positioning  
   - Quick  
   - QuickWidgets  
   - Qml  
   - Network  
   - Concurrent  

2. Open the project by loading `CMakeLists.txt` in Qt Creator.

3. Select a Qt 6 kit with C++20 support.

4. Build and run the project directly within Qt Creator.

### Alternative: CMake with vcpkg

The project can also be built using vcpkg to manage dependencies.  
However, this approach is **not recommended** for now.