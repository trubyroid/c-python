from setuptools import setup, Extension
# from Cython.Build import cythonize


setup(
    name="calculator",
    version='1',
    ext_modules=[Extension('_calculator', ['_calculator.c'])]
)

    # ext_modules = cythonize("calculator.c")