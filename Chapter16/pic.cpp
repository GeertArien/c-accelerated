#include "stdafx.h"
#include "pic.h"

#include <vector>
using std::vector;

#include <string>
using std::string;

#include <iostream>
using std::ostream;
using std::endl;

#include <algorithm>
using std::max;


Picture frame(const Picture& pic) {
  return new Frame_Pic(pic.p);
}

Picture frame(const Picture& pic, const char corner, const char top_bottom, const char side) {
  return new Frame_Pic(pic.p, corner, top_bottom, side);
}

Picture hcat(const Picture& l, const Picture& r)
{
  return new HCat_Pic(l.p, r.p);
}

Picture vcat(const Picture& t, const Picture& b)
{
  return new VCat_Pic(t.p, b.p);
}

Picture::Picture(const vector<string>& v) :
  p(new String_Pic(v)) { }ostream& operator<<(ostream& os, const Picture& picture)
{
  const Pic_base::ht_sz ht = picture.p->height();
  for (Pic_base::ht_sz i = 0; i != ht; ++i) {
    picture.p->display(os, i, false);
    os << endl;
  }
  return os;
};


Pic_base::wd_sz String_Pic::width() const {
  Pic_base::wd_sz n = 0;
  for (Pic_base::ht_sz i = 0; i != data.size(); ++i)
    n = max(n, data[i].size());
  return n;
}void String_Pic::display(ostream& os, ht_sz row, bool do_pad) const
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

void VCat_Pic::display(ostream& os, ht_sz row, bool do_pad) const
{
  wd_sz w = 0;
  if (row < top->height()) {
    // we are in the top subpicture
    top->display(os, row, do_pad);
    w = top->width();
  }
  else if (row < height()) {
    // we are in the bottom subpicture
    bottom->display(os, row - top->height(), do_pad);
    w = bottom->width();
  }
  if (do_pad)
    pad(os, w, width());
}

void HCat_Pic::display(ostream& os, ht_sz row, bool do_pad) const
{
  ht_sz left_row = row;
  ht_sz right_row = row;

  if (left->height() > right->height())
  {
    ht_sz index = ((left->height() - right->height()) / 2);

    if (row >= index)
      right_row = row - index;
    else
      right_row = right->height();
  }
  else
  {
    ht_sz index = ((right->height() - left->height()) / 2);

    if (row >= index)
      left_row = row - index;
    else
      left_row = left->height();
  }

  left->display(os, left_row, do_pad || right_row < right->height());
  right->display(os, right_row, do_pad);
}

void Frame_Pic::display(ostream& os, ht_sz row, bool do_pad) const
{
  if (row >= height()) {
    // out of range
    if (do_pad)
      pad(os, 0, width());
  }
  else {
    if (row == 0 || row == height() - 1) {
      // top or bottom row
      os << corner << string(width() - 2, top_bot) << corner;
    }
    else if (row == 1 || row == height() - 2) {
      // second from top or bottom row
      os << side;
      pad(os, 1, width() - 1);
      os << side;
    }
    else {
      // interior row
      os << side << ' ';
      p->display(os, row - 2, true);
      os << ' ' << side;
    }
  }
}void Pic_base::pad(std::ostream& os, wd_sz beg, wd_sz end) {
  while (beg != end) {
    os << " ";
    ++beg;
  }
}