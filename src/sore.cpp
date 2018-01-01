#include <Rcpp.h>
#include <string>

#include <cstring>

#include "onig/onigmo.h"
#include "sore.h"

using namespace Rcpp;

sore::sore(std::string pattern) {

  int ret = onig_new(
    &reg,
    (const UChar*)pattern.c_str(),
    (const UChar*)(pattern.c_str()+pattern.size()),
    ONIG_OPTION_NONE, ONIG_ENCODING_UTF_8, ONIG_SYNTAX_POSIX_EXTENDED,
    &err
  );

  pat = pattern;

  if (ret != ONIG_NORMAL) Rcpp::Rcout << ret << std::endl;

}

sore::sore(std::string pattern, Rcpp::CharacterVector options,
           std::string encoding, std::string syntax) {

  pat = pattern;

  int ret = onig_new(
    &reg,
    (const UChar*)pattern.c_str(),
    (const UChar*)(pattern.c_str()+pattern.size()),
    ONIG_OPTION_NONE, ONIG_ENCODING_UTF_8, ONIG_SYNTAX_POSIX_EXTENDED,
    &err
  );

  if (ret != ONIG_NORMAL) Rcpp::Rcout << ret << std::endl;

}

sore::~sore() {
  onig_free(reg);
}

int sore::capture_group_count() {
  return(onig_number_of_captures(reg));
}

Rcpp::CharacterVector sore::search(std::string str) {

  OnigRegion *region = NULL;
  unsigned char *start, *range, *end;

  end = (unsigned char *)(str.c_str() + str.size());
  start = (unsigned char *)str.c_str();
  range = end;

  int i, ret;

  region = onig_region_new();
  ret = onig_search(reg, (UChar*)str.c_str(), end, start, range, region, ONIG_OPTION_NONE);

  Rcpp::CharacterVector out;

  if (ret >= 0) {

    Rcpp::CharacterVector results(region->num_regs);

    int len;
    for (i = 0; i < region->num_regs; i++) {
      len = region->end[i] - region->beg[i];
      //Rcpp::Rcout << "Region begin: " << region->beg[i] << std::endl;
      results[i] = std::string(str, region->beg[i], len);
    }
    out = results;

  } else if (ret == ONIG_MISMATCH) {
    Rcpp::Rcout << "ONIG_MISMATCH" << std::endl;
  } else {
    Rcpp::Rcout << "Other Error" << std::endl;
  }

  onig_region_free(region, 1 /* 1:free self, 0:free contents only */);

  return(out);

}


RCPP_MODULE(SORE) {

  using namespace Rcpp;

  class_<sore>("sore")
     .constructor<std::string>("sore easy constructor")
     .constructor<std::string, Rcpp::CharacterVector, std::string, std::string>("sore primary constructor")
     .method("capture_group_count", &sore::capture_group_count)
     .method("search", &sore::search)
    ;

}
