#include <iostream>
#include <string>
#include <SDL2/SDL.h>
#include <filesystem>

void displayUsage(const std::string& programName) {
    std::cout << "Usage: " << programName << " [-m <mode>] [-o <output>] [-v] [-h]" << std::endl;
    std::cout << "Options:" << std::endl;
    std::cout << "  -m <mode>     Specify the mode." << std::endl;
    std::cout << "  -o <output>   Specify the output file." << std::endl;
    std::cout << "  -v            Enable verbose mode." << std::endl;
    std::cout << "  -h            Show usage information." << std::endl;
}

int main(int argc, char* argv[]) {
    std::string mode;
    std::string output;
    bool verbose = false;

    // Parsing command line arguments
    for (int i = 1; i < argc; i++) {
        std::string arg = argv[i];
        if (arg == "-m") {
            if (i + 1 < argc) {  // Ensure there is another argument
                mode = argv[++i];
            } else {
                std::cerr << "Error: -m requires an argument." << std::endl;
                return 1;
            }
        } else if (arg == "-o") {
            if (i + 1 < argc) {  // Ensure there is another argument
                output = argv[++i];
            } else {
                std::cerr << "Error: -o requires an argument." << std::endl;
                return 1;
            }
        } else if (arg == "-v") {
            verbose = true;
        } else if (arg == "-h") {
            displayUsage(argv[0]);
            return 0;
        } else {
            std::cerr << "Error: Unknown argument '" << arg << "'." << std::endl;
            return 1;
        }
    }

    // Print usage if no arguments are provided
    // if (argc <= 1) {
    //     displayUsage(argv[0]);
    //     return 0;
    // }

    // Branching based on the mode
    if (mode == "mode1") {
        // Implement mode1 functionality
        std::cout << "Mode 1 selected." << std::endl;
    } else if (mode == "mode2") {
        // Implement mode2 functionality
        std::cout << "Mode 2 selected." << std::endl;
    } else if (!mode.empty()) {
        std::cerr << "Error: Unknown mode '" << mode << "'." << std::endl;
        return 1;
    }

    // Print the output file if provided
    if (!output.empty()) {
        std::cout << "Output file: " << output << std::endl;
    }

    // Print verbose information if enabled
    if (verbose) {
        std::cout << "Verbose mode enabled." << std::endl;
    }



namespace fs = std::filesystem;


    std::string projectPath = "."; // Replace with your desired project path

    // Create folders
    fs::create_directory(projectPath);
    fs::create_directory(projectPath + "/src");
    fs::create_directory(projectPath + "/include");
    fs::create_directory(projectPath + "/lib");
    fs::create_directory(projectPath + "/build");
    fs::create_directory(projectPath + "/docs");
    fs::create_directory(projectPath + "/tests");
    fs::create_directory(projectPath + "/resources");
    fs::create_directory(projectPath + "/bin");
    fs::create_directory(projectPath + "/scripts");
    fs::create_directory(projectPath + "/extras");

    // Create subfolders in src
    fs::create_directory(projectPath + "/src/utils");
    fs::create_directory(projectPath + "/src/models");
    fs::create_directory(projectPath + "/src/views");
    fs::create_directory(projectPath + "/src/controllers");
    fs::create_directory(projectPath + "/src/tests");

    // Create subfolders in include
    fs::create_directory(projectPath + "/include/utils");
    fs::create_directory(projectPath + "/include/models");
    fs::create_directory(projectPath + "/include/views");
    fs::create_directory(projectPath + "/include/controllers");

    std::cout << "Folder hierarchy created successfully!\n";


    return 0;
}
