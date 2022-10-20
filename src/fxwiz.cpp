#include "retriever.hpp"

#include <iostream>


int main(int argc, char** argv)
{
  if (argc != 2)
  {
    std::cout << "usage: " << argv[0] << " URL" << std::endl;
    return 0;
  }

  fxwiz::retriever r;
  std::string res = r.fetch(argv[1]);

  std::cout << res << std::endl;

  return 0;
}