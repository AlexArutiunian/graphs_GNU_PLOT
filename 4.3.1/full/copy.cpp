#include <iostream>
#include <fstream>
#include <string>
#include <vector>


void find_and_replace(std::string& file_contents, 
    const std::string& morn, const std::string& night) {
  // This searches the file for the first occurence of the morn string.
  auto pos = file_contents.find(morn);
  while (pos != std::string::npos) {
    file_contents.replace(pos, morn.length(), night);
    // Continue searching from here.
    pos = file_contents.find(morn, pos);
  }
}

void add_ref(int num_elem, int num_colons){
    std::ifstream input_file("data.txt");
    std::ofstream output_file("data_out.txt"); 
    size_t n = num_elem;
    double c[n];
    for(int i = 0; i != n; ++i){
        input_file >> c[i]; 
    }
    for(int i = 1; i != n + 1; ++i){
        output_file << c[i - 1];
        if(!(i % num_colons)){
            output_file << R"( \\)" << "\n";
        }
        else output_file << " & ";
    }
    input_file.close();
    output_file.close();
}

std::string getfile(std::ifstream& is) {
  std::string contents;
  // Here is one way to read the whole file
  for (char ch; is.get(ch); contents.push_back(ch)) {}
  return contents;
}

int main(){
    int i = 0;
    std::string s1[40];
    std::ifstream f_1("out_gs.txt");
    
    
    std::string tex_cont = getfile(f_1);
    f_1.close();
    i = 0;
    int flag = 0;
    std::ifstream f_("out_gs.txt");
    std::ifstream data_f("data_out.txt");
    int j = 0;
    std::string s_temp[100];
    while(getline(data_f, s_temp[j])){
     //   std::cout << s_temp[j] << std::endl;
        ++j;
    } 

    std::vector<std::string> save_inside;
    while(getline(f_, s1[i])){
        if(s1[i] == R"(            \hline)") flag += 1;
       // std::cout << flag;
        if(flag == 2){
          ///  std::cout << s1[i] << std::endl;
            save_inside.push_back(s1[i]); 
            
          //  for(int a = 0; a != j; ++a) find_and_replace(tex_cont, s1[i + j], s_temp[j]);
          //  break;  
        }   
        
        ++i;
    }
    int a = 0;
    
    for(auto i = std::next(save_inside.begin()); i != (save_inside.end()); ++i){
        std::cout << "ЧТО" << *i << std::endl;
        std::cout << "на что" << s_temp[a] << std::endl;
        find_and_replace(tex_cont, *i, "\t\t\t" + s_temp[a]);
        ++a;
    }
 
    std::cout << tex_cont << std::endl;
    std::ofstream out_gs("out_gs.tex");
    out_gs << tex_cont;
    out_gs.close();
    data_f.close();
    f_.close();

}