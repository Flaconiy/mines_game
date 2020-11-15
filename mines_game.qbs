import qbs

Project {
    minimumQbsVersion: "1.7.1"

    CppApplication {
        consoleApplication: true

        cpp.cxxLanguageVersion: "c++17"

        property path graph_lib_dir: "../_lib/Graph_lib"

        files: [
            "sidebar.h",
            graph_lib_dir +"/Graph.cpp",
            graph_lib_dir +"/GUI.cpp",
            graph_lib_dir +"/Window.cpp",
            "main.cpp",
        ]

        cpp.includePaths: "../_lib/fltk_win64/include"
        cpp.libraryPaths: "../_lib/fltk_win64/lib"
        cpp.cxxFlags: "-Wno-unused-parameter"
        cpp.driverLinkerFlags: "-mwindows"
        cpp.staticLibraries: [
            "fltk_images",
            "fltk",
            "fltk_png",
            "z",
            "fltk_jpeg",
            "ole32",
            "uuid",
            "comctl32",
        ]

        Group {     // Properties for the produced executable
            fileTagsFilter: "application"
            qbs.install: true
        }
    }
}
