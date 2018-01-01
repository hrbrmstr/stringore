#include <Rcpp.h>
#include <string>

#include "onig/onigmo.h"

using namespace Rcpp;

//' Return the version of the Onigmo library being used by the package
//'
//' @export
//' @examples
//' onigomo_library_version()
// [[Rcpp::export]]
std::string onigomo_library_version() {
  return(std::string(onig_version()));
}
