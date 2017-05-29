#ifndef GUARD_14_6_H
#define GUARD_14_6_H

#include "ptr_r.h"
#include "student_info.h"

inline bool compare_Core_Ptr_r(const Ptr_r<Core> hc1, const Ptr_r<Core> hc2)
{
  return compare(*hc1, *hc1);
}

int ex14_6();

#endif // !GUARD_14_6_H