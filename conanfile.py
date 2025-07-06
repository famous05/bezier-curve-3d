from conan import ConanFile
from conan.tools.cmake import CMake, cmake_layout

class BezierCurve3D(ConanFile):
    name = "bezier-curve-3d"
    version = "1.0"
    license = "MIT"
    author = "Famous Okhuahesogie"
    url = "https://github.com/famous05/bezier-curve-3d"
    description = "3D bezier curve creation library"
    settings = "os", "compiler", "build_type", "arch"
    requires = [
        "eigen/3.4.0",
        "gtest/1.14.0"
    ]
    generators = "CMakeDeps", "CMakeToolchain"
    exports_sources = "CMakeLists.txt", "include/*", "src/*", "test/*"

    def layout(self):
        cmake_layout(self)

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()

    def test(self):
        if not self.conf.get("tools.build:skip_test", default=False):
            self.run(os.path.join(self.cpp.build.bindir, "test_point3d"), env="conanrun")