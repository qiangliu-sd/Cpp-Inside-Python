# Implement a Py-method in C++: A full example
    In case you want to extend or speed up Python with C++

### Directory structure and files for build C++ inside Python:
py_work_dir/\
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
- defined in **setup.py** & in **ql_std.cpp**
- treated as built-in module

### Build (C++) and install

1. build in dir(cpp_work_dir) where **pyproject.toml** is located:
> py -m build

If build does not work, try installing the latest version of build:
> pip install --upgrade build

2. install a local package
> pip install .\dist\ql_package-0.0.1.tar.gz

### Testing:
Download dir and files\
Build & install\
Run:
> py cpp-vs-numpy.py

### Note:
For python.h, see [Extending Python with C or C++](https://docs.python.org/3/extending/extending.html)
