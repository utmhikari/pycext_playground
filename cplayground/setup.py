from setuptools import setup, Extension


cplayground_module = Extension(
    name='cplayground',
    sources=['cplayground.cpp']
)


setup(
    name='cplayground',
    version='0.0.1',
    description='cplayground: a c-extension for Python',
    ext_modules=[cplayground_module]
)
