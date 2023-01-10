
from distutils.core import setup, Extension
 
module = Extension('calculator', sources = ['calculator.c'])
 
setup (name = 'MyCalc',
        version = '1.0',
        ext_modules = [module])
