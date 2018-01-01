#ifndef SORE_H
#define SORE_H

#include <Rcpp.h>
#include <string>

#include "onig/onigmo.h"

//' @export sore
class sore {

public:

  sore(std::string pattern);
  sore(std::string pattern, Rcpp::CharacterVector options, std::string encoding, std::string syntax);

  int capture_group_count();

  Rcpp::CharacterVector search(std::string str);

  ~sore();

private:

  std::string pat;
  regex_t* reg;
  OnigErrorInfo err;

};

#endif