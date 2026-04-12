#include <iostream>
#include <limits>

int main(){
        int a;
        long b;
        short c;
        float d;
        double e;
        char f;
        bool g;

        std::cout<<"int"<<std::endl;
        std::cout<<"Ukuran : "<<sizeof(a)<<" Byte"<<std::endl;
        std::cout<<"Nilai Maksimum : "<<std::numeric_limits<int>::max()<<std::endl;
        std::cout<<"Nilai Minimum : "<<std::numeric_limits<int>::min()<<std::endl;

        std::cout<<"\nlong"<<std::endl;
        std::cout<<"Ukuran : "<<sizeof(b)<<" Byte"<<std::endl;
        std::cout<<"Nilai Maksimum : "<<std::numeric_limits<long>::max()<<std::endl;
        std::cout<<"Nilai Minimum : "<<std::numeric_limits<long>::min()<<std::endl;

        std::cout<<"\nshort"<<std::endl;
        std::cout<<"Ukuran : "<<sizeof(c)<<" Byte"<<std::endl;
        std::cout<<"Nilai Maksimum : "<<std::numeric_limits<short>::max()<<std::endl;
        std::cout<<"Nilai Minimum : "<<std::numeric_limits<short>::min()<<std::endl;

        std::cout<<"\nfloat"<<std::endl;
        std::cout<<"Ukuran : "<<sizeof(d)<<" Byte"<<std::endl;
        std::cout<<"Nilai Maksimum : "<<std::numeric_limits<float>::max()<<std::endl;
        std::cout<<"Nilai Minimum : "<<std::numeric_limits<float>::min()<<std::endl;

        std::cout<<"\ndouble"<<std::endl;
        std::cout<<"Ukuran : "<<sizeof(e)<<" Byte"<<std::endl;
        std::cout<<"Nilai Maksimum : "<<std::numeric_limits<double>::max()<<std::endl;
        std::cout<<"Nilai Minimum : "<<std::numeric_limits<double>::min()<<std::endl;

        std::cout<<"\nchar"<<std::endl;
        std::cout<<"Ukuran : "<<sizeof(f)<<" Byte"<<std::endl;
        std::cout<<"Nilai Maksimum : "<<std::numeric_limits<char>::max()<<std::endl;
        std::cout<<"Nilai Minimum : "<<std::numeric_limits<char>::min()<<std::endl;

        std::cout<<"\nbool"<<std::endl;
        std::cout<<"Ukuran : "<<sizeof(g)<<" Byte"<<std::endl;
        std::cout<<"Nilai Maksimum : "<<std::numeric_limits<bool>::max()<<std::endl;
        std::cout<<"Nilai Minimum : "<<std::numeric_limits<bool>::min()<<std::endl;
        
        return 0;
}