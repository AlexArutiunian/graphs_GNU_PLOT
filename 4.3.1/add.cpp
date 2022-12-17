#include <iostream>
#include <fstream>

int main(){
    std::ifstream input_file("data.txt");
    std::ofstream output_file("data_out.txt"); 
    size_t n = 24;
    double c[n];
    for(int i = 0; i != n; ++i){
        input_file >> c[i]; 
    }
    for(int i = 1; i != n + 1; ++i){
        output_file << c[i - 1];
        if(!(i % 3)){
            output_file << R"( \\)" << "\n";
        }
        else output_file << " & ";

    }


    input_file.close();
    output_file.close();
}