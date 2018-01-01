#' Tidy Regular Expression Operations with Extensive Character Encoding Support
#'
#' The 'Onigmo' regular expression 'C' libary <https://github.com/k-takata/Onigmo> --
#' which is an extension of the 'Onigmura' <https://github.com/kkos/oniguruma> library --
#' provides support for a wide array of regular expression types and works across a
#' wide array of character encodings. Methods are provided to perform searching, matching
#' and extraction in a tidy (i.e. "data first") manner.
#'
#' [`ore`](https://github.com/jonclayden/ore) is another Onigmo-based R package for
#' handling regular expressions (it was the first to wrap this library). It abstracts
#' much of the complexity of Onigmo whereas the goal of `stringore` is to expose all
#' of the features and power of Onigmo while also providing a "tidy" abstraction layer.
#'
#' @md
#' @name stringore
#' @docType package
#' @author Bob Rudis (bob@@rud.is)
#' @useDynLib stringore, .registration = TRUE
#' @importFrom Rcpp sourceCpp
#' @importFrom magrittr %>%
NULL

#' @title pipe
#' @description pipe
#' @name %>%
#' @export
NULL