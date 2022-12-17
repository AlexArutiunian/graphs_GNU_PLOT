#include <iostream>
#include <fstream>


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

std::string getfile(std::ifstream& is) {
  std::string contents;
  // Here is one way to read the whole file
  for (char ch; is.get(ch); contents.push_back(ch)) {}
  return contents;
}

int main(){
    std::ifstream filein;
    filein.open("graphs.gnu");
    std::string contents = getfile(filein); 
    find_and_replace(contents, "default", "cos(x) on x");
    std::ofstream fileout;
    fileout.open("graphs.gnu");
    fileout << contents;
    filein.close();
    fileout.close();

}