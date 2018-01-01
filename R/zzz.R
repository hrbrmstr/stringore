# required by Onigmo
.onLoad <- function (libname, pkgname) {
  onigmo_init()
}

# required by Onigmo
.onUnload <- function (libpath) {
  onigmo_cleanup()
}