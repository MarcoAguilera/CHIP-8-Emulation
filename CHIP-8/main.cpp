//
//  main.cpp
//  CHIP-8
//
//  Created by Marco Aguilera on 1/16/18.
//  Copyright © 2018 Marco Aguilera. All rights reserved.
//

#include <iostream>
//#include <fstream>
//#include <vector>
//#include <sys/stat.h>
#include <SFML/Graphics.hpp>
using namespace std;

int main(){
    sf::RenderWindow window( sf::VideoMode(640, 480), "Awsome Game");
    
    while(window.isOpen()){
        
        sf::Event event;
        
        while(window.pollEvent(event)){
            switch (event.type) {
                case sf::Event::Closed:
                    window.close();
                    break;
                default:
                    break;
            }
        }
        
        window.clear();
        
        window.display();
    }
        
    return 0;
}


////RETURNS NUMBER OF BYTES IN ROM FILE
//size_t getRomSize(const char* filename)
//{
//    struct stat st;
//    
//    if(stat(filename, &st) != 0)
//    {
//        return -1;
//    }
//    return st.st_size;
//}
//
//typedef unsigned char BYTE;
//int main()
//{
//
////    ifstream input("/Users/marcoaguilera/Desktop/c8games/BLITZ", ios::binary);
////    vector<unsigned char> buffer((istream_iterator<unsigned char>(input)), (istream_iterator<unsigned char>()));
////    
////    cout << buffer.size() << endl;
////    
////    for(auto hex : buffer)
////    {
////        cout << int(hex) << endl;
////    }
////    input.close();
////    
//
////    size_t size = getRomSize("/Users/marcoaguilera/Desktop/c8games/BLITZ");
////    char buffer[4096];
////    ifstream file("/Users/marcoaguilera/Desktop/c8games/UFO", ios::in | ios::binary);
////    file.read(buffer, size);
////    
////    if(!file)
////    {
////        cout << "NUMBER OF BYTES READ : " << file.gcount() << endl;
////        file.clear();
////    }
////    
////    for(unsigned i = 0; i < size; i++)
////    {
////        cout << int(buffer[i]) << endl;
////    }
////    
////    cout << size << endl;
////    file.close();
//    
//    return 0;
//}
