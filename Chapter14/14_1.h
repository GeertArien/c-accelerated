#ifndef GUARD_14_1_H
#define GUARD_14_1_H

#include "ptr.h"
#include "student_info.h"

inline bool compare_Core_Ptr(const Ptr<Core> hc1, const Ptr<Core> hc2)
{
  return compare(*hc1, *hc1);
}

int ex14_1();

#endif // !GUARD_14_1_H