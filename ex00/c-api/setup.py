
from distutils.core import setup, Extension
 
module = Extension('calculator', sources = ['calculator.c'])
 
setup (name = 'PackageName',
        version = '1.0',
        description = 'This is a package for calculator',
        ext_modules = [module])
