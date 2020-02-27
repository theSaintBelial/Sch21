from distutils.core import setup
from distutils.extension import Extension
from Cython.Build import cythonize

eq_extension = Extension(
	name="eightqueens",
	sources=["eightqueens.pyx"],
	libraries=["eq"],
	library_dirs=["lib"],
	include_dirs=["lib"]
)
setup(
	name="eightqueens",
	ext_modules=cythonize([eq_extension])
)