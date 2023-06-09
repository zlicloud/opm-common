# Find Valgrind.
#
# This module defines:
#  VALGRIND_INCLUDE_DIR, where to find valgrind/memcheck.h, etc.
#  VALGRIND_PROGRAM, the valgrind executable.
#  Valgrind_FOUND, If false, do not try to use valgrind.
#
# If you have valgrind installed in a non-standard place, you can define
# VALGRIND_ROOT to tell cmake where it is.

find_path(VALGRIND_INCLUDE_DIR valgrind/memcheck.h
  /usr/include /usr/local/include ${VALGRIND_ROOT}/include)

# if VALGRIND_ROOT is empty, we explicitly add /bin to the search
# path, but this does not hurt...
find_program(VALGRIND_PROGRAM NAMES valgrind PATH ${VALGRIND_ROOT}/bin)

find_package_handle_standard_args(Valgrind DEFAULT_MSG
  VALGRIND_INCLUDE_DIR
  VALGRIND_PROGRAM)

mark_as_advanced(VALGRIND_ROOT VALGRIND_INCLUDE_DIR VALGRIND_PROGRAM)
