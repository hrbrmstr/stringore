#include <Rcpp.h>
#include <string>

#include "onig/onigmo.h"

using namespace Rcpp;

// [[Rcpp::export]]
void onigmo_init() {
  onig_init();
  onig_set_warn_func((OnigWarnFunc)&Rf_warning);
  onig_set_verb_warn_func((OnigWarnFunc)&Rf_warning);
}

// [[Rcpp::export]]
void onigmo_cleanup() {
  onig_end();
}
