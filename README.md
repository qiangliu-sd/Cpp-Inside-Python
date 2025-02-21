# Cpp-inside-Python
    A full example for calling a Py-method coded in C++

In case you want to extend or speed up Python with C++

### Directory structure and files for build C++ inside Python:
cpp_work_dir/\
├─ pyproject.toml\
├─ setup.py\
├─ src/\
│&nbsp;&nbsp;&nbsp;&nbsp;└─ ql_package/\
│&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;├── \_\_init__.py\
│&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;├── ql_std.cpp\
│&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;└── ql_std_jit.py
 
package [ql_package]:
- defined in **pyproject.toml** & is sub-dir of dir(src)
- contains module [ql_std_jit]

module [ql_std_cpp]:
- defined in **setup.py & in ql_std.cpp**
- treated as built-in module

### Build C++ and install

1. build in dir(cpp_work_dir) where **pyproject.toml** is located:
> py -m build

if build does not work, try install the latest version of build:
> pip install --upgrade build

2. install a local package
> pip install .\dist\ql_package-0.0.1.tar.gz

### Testing:
Download dir and files\
Build & install\
Run **cpp_numpy-bigA.py**
