# CommonLibSSE

### Requirements
* [XMake](https://xmake.io) [2.8.2+]
* C++23 Compiler (MSVC or Clang-CL)

## Getting Started
```bat
git clone --recurse-submodules https://github.com/libxse/commonlibsse
cd commonlibsse
```

### Build
To build the project, run the following command:
```bat
xmake build
```

> ***Note:*** *This will generate a `build/windows/` directory in the **project's root directory** with the build output.*

### Project Generation (Optional)
If you want to generate a Visual Studio project, run the following command:
```bat
xmake project -k vsxmake
```

> ***Note:*** *This will generate a `vsxmakeXXXX/` directory in the **project's root directory** using the latest version of Visual Studio installed on the system.*

## Notes

CommonLibSSE is intended to replace SKSE as a static dependency. However, the runtime component of SKSE is still required.
