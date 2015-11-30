#include <string>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <vector>

int main ( int argc, char *argv[] )
{

    if(argc != 2)
    {
        std::cerr << "Usage: " << argv[0] << " InputFilename: matrix, InuputCircosfile : maps.links.txt " << std::endl;
        return 0;
    }
    // Get the filename from the command line
    std::string fileName = argv[1];
    std::ifstream inputFile ;
    inputFile.open( fileName.c_str() , std::ios::in ) ;
    std::string labelLine ;
    int nb_lines = 0;
    if(inputFile.good())
    {
        while(!inputFile.eof())
        {
            getline(inputFile,labelLine);
            std::cout<<labelLine<<std::endl;
            nb_lines ++;
        }
    }
    inputFile.close();
    std::cout<<nb_lines<<std::endl;
    nb_lines=nb_lines-1;

    inputFile.open( fileName.c_str() , std::ios::in ) ;
    std::vector< std::vector<float> > mat;
    std::string::iterator str_it, str_end;
    std::string number="";
    int k = 0;
    if(inputFile.good())
    {
        for(int i=0 ; i < nb_lines ; i++)
        {
            getline(inputFile,labelLine);
            std::vector<float> vec ;
            for(str_it=labelLine.begin() , str_end=labelLine.end() ; str_it!=str_end ; ++str_it )
            {

                std::cout<<*str_it<<std::endl;
                if( *str_it !=' ' &&  *str_it !='\n' )
                {
                    number += *str_it ;
                }
                else if( *str_it ==' ' || *str_it =='\n' )
                {
                    double val = atof(number.c_str());
                    vec.push_back(val);
                    //std::cout<<"Coord"<<i<<","<<k<<" Mat value "<<val<<std::endl;
                    k++;
                    number="";
                }
            }
            double val = atof(number.c_str());
           mat.push_back(vec);
            k=0;
        }
    }
    inputFile.close();


    for(int i=0 ; i < nb_lines ; i++)
    {
        for(int j=0 ; j < nb_lines ; j++)
        {
            std::cout<<"Coord "<<i<<","<<j<<" Mat val "<<mat[i][j]<<std::endl; ;
        }
    }

    return 0 ;
}
