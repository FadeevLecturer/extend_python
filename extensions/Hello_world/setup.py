from distutils.core import setup, Extension

setup(
	name = "helloworld",
	version = "1.0",
	ext_modules = [Extension(name="helloworld", 
        sources=["bind.cpp", "libhelloworld.cpp"],
        language="c++",
        )]
	);
