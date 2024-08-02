#ifndef RECEIPT_HPP_
#define RECEIPT_HPP_
#include <string>
#include <opencv2/opencv.hpp>
#include <tesseract/baseapi.h>
#include <leptonica/allheaders.h>

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

    /**
     * @brief extracts text from the image.
     *
     * Takes the pre processed image and extracts text
     *
     * @param imagePath path to the receipt image
     * @return text that was recognized
     */
    std::string extractText(const std::string &imagePath);
};
#endif