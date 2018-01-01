library(stringore)

.sore <- SORE$sore

v <- new(.sore, "a(.*)b|[e-f]+")
x <- new(.sore, "[A-Z]")
y <- new(.sore, "([A-Z])")
z <- new(.sore, "[A-Z]*([0-9]+)")
u <- new(.sore, "([[:digit:]])[[:space:]]([[:alnum:]])[[:space:]]")

v$capture_group_count()
x$capture_group_count()
y$capture_group_count()
z$capture_group_count()
u$capture_group_count()

v$search("zzzzaffffffffb")
x$search("1 A 2 B 3 C")
y$search("1 A 2 B 3 C")
z$search("1 A 2 B 3 C")
u$search("1 A 2 B 3 C")

