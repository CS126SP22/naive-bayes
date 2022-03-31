//
// Created by Serena Gong on 30/03/22.
//
#pragma once
#include <vector>
#include <sstream>
#include <fstream>
#include <string>

#ifndef NAIVE_BAYES_PICTURE_H
#define NAIVE_BAYES_PICTURE_H

#endif //NAIVE_BAYES_PICTURE_H

namespace naivebayes {

class Picture {
  /**
  * Shows a picture in dataset, checks if each pixel is shaded (black, grey)
   * or unshaded.
  */
 public:
  Picture();
  Picture(const std::vector<std::vector<bool>> &pic);
  Picture(const std::vector<std::vector<bool>> &pic, size_t class_name, size_t pic_size);


  /**
   * Operator overloading function for each individual picture
   * @param is istream object (file) for operator overloading
   * @param picture to save the input into
   */
  std::istream& operator>>(std::istream& is, Picture& picture);

  std::vector<std::vector<bool>> GetPicture() const;

  void SetClassName(size_t class_name);

  void SetPictureSize(size_t pic_size);

  size_t GetPicSize() const;

  size_t GetClassName() const;

 private:
  // 2D vector for each picture where col/rol holds shade, bool for if pixel is shaded
  std::vector<std::vector<bool>> picture_;
  size_t class_name_;
  size_t pic_size_;
};


} //namespace naivebayes