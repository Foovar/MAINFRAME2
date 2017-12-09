//
//  FileController.hpp
//  PROYECTO
//
//  Created by Alex Paredes on 9/12/17.
//  Copyright © 2017 Alex Paredes. All rights reserved.
//

#ifndef FileController_hpp
#define FileController_hpp
#include <fstream>
#include "iostream"
#include "Constants.hpp"

namespace DevJAD {
    class FileController {
        std::ifstream _readFile;
        std::ofstream _writeFile;
        
        void OpenWriteFile();
        void OpenReadFile();
        
    public:
        FileController();
        void SaveScore(int score);
        void CloseFile();
        void SaveFile();
        void OpenFile();
        void WriteFile(std::string data);
        void AppendFile();
        
        std::string ReadFile();
        std::string ReadLine();
        int GetScore();
    };
}

#endif /* FileController_hpp */
