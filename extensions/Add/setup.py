import os
from distutils.core import setup, Extension


libshared_dir = os.path.join("..", "..", "libshared_source")
libshared_cpp = os.path.join(libshared_dir, "libshared.cpp")
setup(
	name = "mylib",
	version = "1.0",
	ext_modules = [Extension(name="mylib",
        include_dirs=[libshared_dir],
        sources=["bind.cpp", "wrapper.cpp", libshared_cpp],
        language="c++",
        )]
	);
