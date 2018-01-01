#include <Rcpp.h>
#include <string>

#include "onig/onigmo.h"

using namespace Rcpp;

// [[Rcpp::export]]
void onigmo_init() {
   onig_init();
}

// [[Rcpp::export]]
void onigmo_cleanup() {
   onig_end();
}
