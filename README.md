
# stringore

Tidy Regular Expression Operations with Extensive Character Encoding
Support

## Description

The ‘Onigmo’ regular expression ‘C’ libary
<https://github.com/k-takata/Onigmo> — which is an extension of the
‘Onigmura’ <https://github.com/kkos/oniguruma> library — provides
support for a wide array of regular expression types and works across a
wide array of character encodings. Methods are provided to perform
searching, matching and extraction in a tidy (i.e. “data first”) manner.

[`ore`](https://github.com/jonclayden/ore) is another Onigmo-based R
package for handling regular expressions (it was the first to wrap this
library). It abstracts much of the complexity of Onigmo whereas the goal
of `stringore` is to expose all of the features and power of Onigmo
while also providing a “tidy” abstraction layer.

## NOTE

This is a WIP and the API will likely go through a few rough iterations,
so do not base any “production” work on it. If you decide to live
dangerously, you can use
[releases](https://github.com/hrbrmstr/stringore/releases) to checkpoint
your projects.

Since it is a WIP, *your* thoughts are most welcome. Please [file an
issue](https://github.com/hrbrmstr/stringore/issues) with any questions,
notes, ideas, etc.

## What’s Inside The Tin

The following functions are implemented:

  - `onigomo_library_version`: Return the version of the Onigmo library
    being used by the package

## Installation

``` r
devtools::install_github("hrbrmstr/stringore")
```

## Usage

``` r
library(stringore)

# current verison
packageVersion("stringore")
```

    ## [1] '0.1.0'

``` r
onigomo_library_version()
```

    ## [1] "6.1.3"
