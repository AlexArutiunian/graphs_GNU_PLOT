#include <iostream>
#include <fstream>
#include <string>


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
    std::ifstream filein;
    filein.open("gs_t.gnu");
    std::string contents = getfile(filein); 
    std::ifstream file_tex("table_gs.tex");
    std::string content_tex = getfile(file_tex);

    std::ofstream fileout;
    fileout.open("gs.gnu");
    std::string default_s[3] = {"default title", "defaultX", "defaultY"};
    std::string s[3];
    std::ifstream f_ngs("names_gs.txt");
    
    int i = 0;
    while(getline(f_ngs, s[i])){
        ++i;     
    }

    std::string s1[40];
    std::ifstream f_1("out_gs.txt");
    
    
    std::string tex_cont = getfile(f_1);
    f_1.close();
    i = 0;
    int flag = 0;
    std::ifstream f_("out_gs.txt");
    std::ifstream data_f("data_out.txt");
    while(getline(f_, s1[i])){
        if(s1[i] == R"(            \hline)") flag += 1;
        std::cout << flag;
        if(flag == 2){
            std::cout << s1[i] << std::endl;
            int j = 0;
            std::string s_temp[100];
            while(getline(data_f, s_temp[j])){
                std::cout << s_temp[j];
                find_and_replace(tex_cont, s1[i + j], s_temp[j]);
                ++j;
            } 
         //   break;  
        }   
        ++i;
    }
 
    std::cout << tex_cont << std::endl;
    data_f.close();
    f_.close();

    for(int i = 0; i != 3; ++i){
        find_and_replace(contents, default_s[i], s[i]);
        find_and_replace(content_tex, default_s[i], s[i]);
        
    }    
    
    fileout << contents;

    std::ofstream tex_out("out_gs.tex");
    tex_out << content_tex;

    filein.close();
    fileout.close();
    file_tex.close();
    f_ngs.close();

    add_ref(16, 2);


}