# C++ REST Client Examples

To build:

1. You need to have [vcpkg](https://github.com/microsoft/vcpkg) installed locally. You can do it by running

```powershell
> git clone https://github.com/microsoft/vcpkg
> .\vcpkg\bootstrap-vcpkg.bat # on Windows
```

2. Run CMake with the appropriate configuration (currently only Visual Studio supported):

```powershell
> cmake --preset windows-vs
```

3. Build

```powershell
> cmake --build build
```

4. Run one of the example built executables.

