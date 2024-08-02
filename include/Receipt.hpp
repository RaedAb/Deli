#ifndef RECEIPT_HPP_
#define RECEIPT_HPP_
#include <string>
#include <opencv2/opencv.hpp>

class Receipt
{
public:
    /**
     * @brief Read and process image
     *
     * Reads the image from image and converts to black and white
     *
     * @param imagePath path to the receipt image
     */
    void preprocessImage(const std::string &imagePath);
};

#endif