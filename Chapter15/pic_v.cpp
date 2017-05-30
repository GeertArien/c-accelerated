#include "stdafx.h"
#include "pic_v.h"

#include <iostream>
using std::ostream;
using std::endl;

#include <algorithm>
using std::max;

#include "vec.h"
#include "str.h"

Picture_v frame(const Picture_v& pic) {
  return new Frame_Pic_v(pic.p);
}

Picture_v hcat(const Picture_v& l, const Picture_v& r)
{
  return new HCat_Pic_v(l.p, r.p);
}

Picture_v vcat(const Picture_v& t, const Picture_v& b)
{
  return new VCat_Pic_v(t.p, b.p);
}

Picture_v::Picture_v(const Vec<Str>& v) :
  p(new String_Pic_v(v)) { }ostream& operator<<(ostream& os, const Picture_v& Picture_v)
{
  const Pic_base_v::ht_sz ht = Picture_v.p->height();
  for (Pic_base_v::ht_sz i = 0; i != ht; ++i) {
    Picture_v.p->display(os, i, false);
    os << endl;
  }
  return os;
};


Pic_base_v::wd_sz String_Pic_v::width() const {
  Pic_base_v::wd_sz n = 0;
  for (Pic_base_v::ht_sz i = 0; i != data.size(); ++i)
    n = max(n, data[i].size());
  return n;
}void String_Pic_v::display(ostream& os, ht_sz row, bool do_pad) const
{
  wd_sz start = 0;
  // write the row if we're still in range
  if (row < height()) {
    os << data[row];
    start = data[row].size();
  }
  // pad the output if necessary
  if (do_pad)
    pad(os, start, width());
}

void VCat_Pic_v::display(ostream& os, ht_sz row, bool do_pad) const
{
  wd_sz w = 0;
  if (row < top->height()) {
    // we are in the top subPicture_v
    top->display(os, row, do_pad);
    w = top->width();
  }
  else if (row < height()) {
    // we are in the bottom subPicture_v
    bottom->display(os, row - top->height(), do_pad);
    w = bottom->width();
  }
  if (do_pad)
    pad(os, w, width());
}

void HCat_Pic_v::display(ostream& os, ht_sz row, bool do_pad) const
{
  left->display(os, row, do_pad || row < right->height());
  right->display(os, row, do_pad);
}

void Frame_Pic_v::display(ostream& os, ht_sz row, bool do_pad) const
{
  if (row >= height()) {
    // out of range
    if (do_pad)
      pad(os, 0, width());
  }
  else {
    if (row == 0 || row == height() - 1) {
      // top or bottom row
      os << Str(width(), '*');
    }
    else if (row == 1 || row == height() - 2) {
      // second from top or bottom row
      os << '*';
      pad(os, 1, width() - 1);
      os << '*';
    }
    else {
      // interior row
      os << "* ";
      p->display(os, row - 2, true);
      os << " *";
    }
  }
}void Pic_base_v::pad(std::ostream& os, wd_sz beg, wd_sz end) {
  while (beg != end) {
    os << " ";
    ++beg;
  }
}