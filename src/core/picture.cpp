//
// Created by Serena Gong on 30/03/22.
//

#include "../../include/core/picture.h"
#include <core/picture.h>

namespace naivebayes {

Picture::Picture() {}

Picture::Picture(const std::vector<std::vector<bool>> &pic) {
  picture_ = pic;
}

Picture::Picture(const std::vector<std::vector<bool>> &pic, size_t class_name, size_t pic_size) {
  picture_ = pic;
  class_name_ = class_name;
  pic_size_ = pic_size;
}

std::istream &operator>>(std::istream &is, Picutre &picture) {
  std::string curr_line_in_pic;
  size_t count_line = 0;
  size_t row_in_pic = 0;

  while (std::getline(is, curr_line_in_pic) && count_line <= picture.size_) {
    if (curr_line_in_pic.size() == 1 && count_line == 0) {
      picture.class_name_ = std::stoi(curr_line_in_pic); // for first line, getting class type of picture
      count_line++;
    } else if (curr_line_in_pic.size() == 0) {
      count_line++; // if line only has space, do nothing and add to count_line
    } else {
      std::vector<bool> inside;
      inside.resize(line.size());
      picture.picture.push_back(inside); // initilise the inner vector

      for (size_t i = 0; i < picture.pic_size_; i++) {
        if (curr_line_in_pic[i] == ' ') {
          picutre.picture_[row_in_pic][i] = false; // unshaded pixel

        } else if (curr_line_in_pic[i] == '+' || curr_line_in_pic[i] == '#') {
          picture.picture_[row_in_pic][i] = true; // shaded pixel (black or grey)
        }
      }
      row_in_pic++;
      curr_line_in_pic++;
    }
  }
  return is;
}


std::vector<std::vector<bool>> Picture::GetPicture() const {
  return picture_;
}

size_t Picture::GetClassName() const {
  return class_name_;
}

void Picture::SetClassName(size_t class_name) {
  class_name_ = class_name;
}

void Picture::SetPictureSize(size_t pic_size) {
  pic_size_ = pic_size;
}

size_t Picture::GetPicSize() const {
  return pic_size_;
}

}