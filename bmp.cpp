#include <cstdio>
#include "bitmap_image.hpp"
#include <locale.h>
#include <time.h>
using namespace std;
int main(){
    setlocale(LC_ALL, "Portuguese");
    string nome_arquivo;
    bool problema_ler_arquivo;
    do{
        problema_ler_arquivo=false;
        cout<<"Digite o nome do arquivo sem a extensão: ";
        getline(cin, nome_arquivo);
        bitmap_image image(nome_arquivo+".bmp");
        if(!image){
            cout << endl;
            cout << "Ocorreu algum erro ao abrir o arquivo " << nome_arquivo << ".bmp";
            cout << endl;
            problema_ler_arquivo=true;
        }
        else{
            //srand (time(NULL));
            //int valor = rand()%10;
            unsigned char red;
            unsigned char green;
            unsigned char blue;
            const unsigned int height = image.height();
            const unsigned int width  = image.width();
            unsigned int total_number_of_pixels = height*width;
            cout << endl;
            cout << "Número de pixels na horizontal: " << width << endl;
            cout << "Número de pixels na vertical: " << height << endl;
            cout << "Número total de pixels: " << total_number_of_pixels << endl;
            cout << endl;
            int r, g, b, temp;
            for(int y=0; y<height; y++){
                for(int x=0; x<width; x++){
                    image.get_pixel(x, y, red, green, blue);
                    r=red;
                    g=0;
                    b=0;
                    image.set_pixel(x, y, r, g, b);
                }
            }
            image.save_image(nome_arquivo+"_editado.bmp");
        }
    }while(problema_ler_arquivo);
    return 0;
}
