from setuptools  import setup, Extension

std_cpp_module = Extension('ql_std_cpp', sources=['src/ql_package/ql_std.cpp'])

setup(
   ext_modules=[std_cpp_module],
)

