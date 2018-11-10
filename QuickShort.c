#include <iostream>
#include <vector>

std::vector<int> v(11);
std::vector<int> quicksort(std::vector<int> VectorDesordenado);

int main(void){

    int n1 = 100;
    int n2 = -50;

    std::cout<<"Vector Desordenado: ";
    for(int i = 0 ; i < v.size(); i++){
        v[i] = std::rand() % n1 + n2;
        std::cout<<"["<<v[i]<<"]";
    }

    std::vector<int> resultado = quicksort(v);

    std::cout<<"\n----------------------------\n";

    std::cout<<"Vector Ordenado: ";
    for(int i = 0 ; i < resultado.size(); i++){
        std::cout<<"["<<resultado[i]<<"]";
    }
    
    return 0;
}

std::vector<int> quicksort(std::vector<int> VectorDesordenado){
    if(VectorDesordenado.size() > 1){
        int pivote = VectorDesordenado[0];
        std::vector<int> menores;
        std::vector<int> iguales;
        std::vector<int> mayores;

        for(int i=0; i < VectorDesordenado.size(); i++){
            if(VectorDesordenado[i] > pivote){
                mayores.push_back(VectorDesordenado[i]);
            }
            if(VectorDesordenado[i] < pivote){
                menores.push_back(VectorDesordenado[i]);
            }
            if(VectorDesordenado[i] == pivote){
                iguales.push_back(VectorDesordenado[i]);
            }
        }

        std::vector<int> vector_final;

        std::vector<int> auxMenores = quicksort(menores);
        std::vector<int> auxIguales = iguales;
        std::vector<int> auxMayores = quicksort(mayores);

        vector_final.reserve(vector_final.size() + distance(auxMenores.begin(), auxMenores.end()));
        vector_final.insert(vector_final.end(), auxMenores.begin(), auxMenores.end());

        vector_final.reserve(vector_final.size() + distance(iguales.begin(), iguales.end()));
        vector_final.insert(vector_final.end(), iguales.begin(), iguales.end());

        vector_final.reserve(vector_final.size() + distance(auxMayores.begin(), auxMayores.end()));
        vector_final.insert(vector_final.end(), auxMayores.begin(), auxMayores.end());

        return vector_final;
    }else{
        return VectorDesordenado;
    }
};
