# Cpp-inside-Python
  A full example for calling C++ inside Python

In case you want to extend or speedup Python with C++

### Directory structure and files for build C++ inside Python:
package_cpp_dir/\
├── pyproject.toml\
├── setup.py\
├── src/\
│   └── ql_package/\
│       ├── __init__.py\
│       ├── ql_std.cpp\
│       └── ql_std_jit.py

[ql_package]:
- defined in **pyproject.toml**
- contain module [ql_std_jit]

module [ql_std_cpp]:
- defined in **setup.py & in ql_std.cpp**
- treated as built-in module

### Build C++ and install

1. build from the same dir where **pyproject.toml** is located:
> py -m build

if build does not work, try install the latest version of build:
> pip install --upgrade build

2. install a local package
> pip install .\dist\ql_package-0.0.1.tar.gz

### Testing:
Download dir and files\
Build & install\
Run **cpp_numpy-bigA.py**
