//
//  FileController.cpp
//  PROYECTO
//
//  Created by Alex Paredes on 9/12/17.
//  Copyright © 2017 Alex Paredes. All rights reserved.
//

#include "FileController.hpp"

namespace DevJAD {
    FileController::FileController(){
        
    }
    
    void FileController::OpenFile(){
        this->OpenWriteFile();
        this->OpenReadFile();
    }
    
    void FileController::OpenReadFile(){
        this->_readFile.open(FILE_SETTINGS);
    }
    
    void FileController::OpenWriteFile(){
        this->_writeFile.open(FILE_SETTINGS);
    }
    
    void FileController::SaveScore(int score){
        this->OpenWriteFile();
        this->WriteFile("SCORE:" + std::to_string(score) +"|");
        this->SaveFile();
    }
    void FileController::CloseFile(){
        this->_writeFile.close();
        this->_readFile.close();
    }
    void FileController::SaveFile(){
        this->_writeFile.close();
    }
    
    void FileController::WriteFile(std::string data){
        this->_writeFile << data;
    }
    
    void FileController::AppendFile(){
        
    }
    
    std::string FileController::ReadFile(){
        return "";
    }
    std::string FileController::ReadLine(){
        return "";
    }
    
    int FileController::GetScore(){
        this->OpenReadFile();
        std::string line;
        
        if(this->_readFile.is_open()){
            getline (this->_readFile, line);
        }
        
        this->_readFile.close();
        std::cout << "Linea: " <<  line << std::endl;
        return 1*1;
    }
    
}


